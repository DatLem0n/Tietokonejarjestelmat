#include <stdio.h>
#include <stdint.h>
#include <math.h>

float lampotila(uint16_t rekisteri, float kerroin);
float kosteus(uint16_t rekisteri);
float valoisuus(uint16_t rekisteri);
uint32_t ilmanpaine(uint8_t xlsb, uint8_t lsb, uint8_t msb);

int mainViikko6() {
    printf("lampotila on :%.02f\n", lampotila(0b0011001000000000, 0.03125));
    printf("kosteus on :%.02f\n", kosteus(0b1000000000000000));
    printf("valoisuus on :%.02f\n", valoisuus(0b0110110000110101));
    printf("paine on :%u\n", ilmanpaine(0b11011110, 0b10111100, 0b00011000));
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

uint32_t ilmanpaine(uint8_t xlsb, uint8_t lsb, uint8_t msb){
    uint32_t rekisteri = (0 | msb) << 8;
    rekisteri = (rekisteri | lsb) << 8;
    rekisteri = (rekisteri | xlsb);
    return rekisteri >> 4;
}
