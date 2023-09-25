#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int64_t factorial(int8_t n);
void shuffle(uint8_t *list, uint16_t list_size);
void movavg(float *array, uint8_t array_size, uint8_t window_size);
int8_t tictactoe_check(int8_t * gameboard, int win_len);

int mainViikko7(){
    printf("%ld",factorial(4));

    srand(time(NULL));
    uint8_t list[8] = { 1,2,3,4,5,6,7,8};
    shuffle(list, 8);
    printf("%s\n", list);

    float data[5] = { 1.0, 2.0, 4.0, 6.0, 9.0 };
    movavg(data, 5, 3);
}

int64_t factorial(int8_t n){
    if (n>=20) return -1;
    int64_t m = n;
    for (long i = 1; i < n; ++i) {
        m = m * (n-i);
    }
    return m;
}

void shuffle(uint8_t *list, uint16_t list_size){
    uint8_t shuffled[list_size];
    uint16_t og_size = list_size;

    for (int i = 0; i < og_size; ++i) {
        int randInt = rand()%list_size;
        shuffled[i] = list[randInt];
        list_size --;

        for (int j = randInt; j < list_size; ++j) {
            list[j] = list[j + 1];
        }
    }
    for (int i = 0; i < og_size; ++i) {
        list[i] = shuffled[i];
    }
}

void movavg(float *array, uint8_t array_size, uint8_t window_size){
    for (int i = 0; i < array_size; ++i) {
        float sum = 0, divider = window_size;

        if (i + window_size <= array_size) {
            if (i != 0) printf(", ");

            for (int j = i; j < i + window_size; ++j) {
                sum += array[j];
            }
            float average = sum / divider;
            printf("%.02f", average);
        }
        else break;
    }
}

int8_t tictactoe_check(int8_t * gameboard, int win_len){
    int x[100], o[100], x_amount = 0, o_amount = 0;
    for (int i = 0; i < 100; ++i) {
        switch (gameboard[i]) {
            case 1:{
                x[x_amount] = gameboard[i];
                x_amount ++;
            }break;
            case 2:{
                o[o_amount] = gameboard[i];
                o_amount ++;
            }break;
            default: break;
        }
    }
    if (win_len > 1){
        if (x_amount >= win_len){
            int len_x = 0, len_y = 0, len_xy = 0, k = 0;
            for (int i = 1; i < x_amount ; ++i) {
                if ((x[i - 1] + 1 == x[i]) && (x[i - 1] / 10 == x[i] / 10)){
                    len_x ++;
                }
                for (int j = i; j < x_amount; ++j) {
                    if (x[i] + 1 == x[j]){
                        do {
                            len_x++;
                            k++;
                        }while(x[i] + k == x[i + k])
                        len_x++; /////    eisaatana tästä tuu mitään
                    }
                    if (x[j] + 10 == x[i]){
                        len_y ++;
                    }
                    if (((x[j] + 10 == x[i]) && (x[i - 1] % 10 == x[i] % 10)))
                }
                if ((x[i - 1] / 10 == x[i] / 10) && (x[i - 1] % 10 == x[i] % 10)){
                    len_y ++;
                }
                if ((x[i - 1] / 10 == x[i] / 10) && (x[i - 1] % 10 == x[i] % 10)){
                    len_y ++;
                }
            }
        }
        if (o_amount >= win_len){
            int o_len = 0;
            for (int i = 1; i < o_amount ; ++i) {

            }
        }
    }
}