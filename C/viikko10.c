#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

struct sensor_data{
    float accelerometer[3];
    float gyro[3];
    float temperature;
    float humidity;
    uint16_t light;
    float pressure;
};

struct mpudata_t {
    float data[6];
};
struct piste {
    int koordinaatit[3];
    struct piste *seuraava;
};

struct polku {
    double matka;
    struct piste* pisteet;
};

void tarkistus(struct mpudata_t mpu, uint8_t index, float threshold);
void laske_kuljettu_matka(struct polku *polku);
int loopTime();

int mainViikko10(){
    struct mpudata_t values = { { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 } };
    tarkistus(values, 5, 3.21);
    loopTime();
}

void tarkistus(struct mpudata_t mpu, uint8_t index, float threshold){
    int dataAmount = 6, thresholdFlag = 0;
    if (mpu.data[index] >= threshold){
        thresholdFlag = 1;
    }
    if (thresholdFlag){
        for (int i = 0; i < dataAmount; ++i) {
            printf("%.02f", mpu.data[i]);
            if (i != dataAmount - 1) printf(",");
        }
    }
    printf("\n");
}

void laske_kuljettu_matka(struct polku *polku){
    double length = 0;
    int aCoord [3], bCoord[3];
    struct piste a = *(polku->pisteet);
    while (a.seuraava != NULL){
        struct piste b = *a.seuraava;
        for (int i = 0; i < 3; ++i) {
            aCoord[i] = a.koordinaatit[i];
            bCoord[i] = b.koordinaatit[i];
        }
        length += sqrt(pow(aCoord[0] - bCoord[0], 2) + pow(aCoord[1] - bCoord[1], 2) + pow(aCoord[2] - bCoord[2], 2));
        a = b;
    }
    polku->matka = length;

}

int loopTime() {

    uint8_t i=0,j=0;
    clock_t start,end;

    srand(time(NULL));
    start = clock();
    do {
        printf("%d < %d\n",i++,(j = rand() % UCHAR_MAX));
    } while (i < j);
    end = clock();

    printf("Loop took %f seconds to run\n", (double)(end-start) / CLOCKS_PER_SEC);

    return 0;
}
