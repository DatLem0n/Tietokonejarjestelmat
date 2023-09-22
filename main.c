#include <stdio.h>
#include <stdint.h>
#include <math.h>

float lampotila(uint16_t rekisteri, float kerroin);
float kosteus(uint16_t rekisteri);
float valoisuus(uint16_t rekisteri);

int main() {
    printf("lampotila on :%.02f\n", lampotila(0b0011001000000000, 0.03125));
    printf("kosteus on :%.02f\n", kosteus(0b1000000000000000));
    printf("valoisuus on :%.02f\n", valoisuus(0b0110110000110101));
    return 0;
}

float lampotila(uint16_t rekisteri, float kerroin){
    uint16_t data = rekisteri >> 2;
    return data * kerroin;
}

float kosteus(uint16_t rekisteri){
    return rekisteri / pow(2, 16) * 100;
}

float valoisuus(uint16_t rekisteri){
    uint16_t exponent = rekisteri >> 12;
    uint16_t fractional = rekisteri & 0b0000111111111111;
    return 0.01 * pow(2, exponent) * fractional;
}
