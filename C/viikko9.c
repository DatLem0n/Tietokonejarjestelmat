#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void write_sensors(char *str, float ax, float ay, float az, float press, float temp);
void charcounter(char *str, uint8_t *result);
float mean(char *list);

int mainViikko9(){
    char str[100];
    write_sensors(str, 0.2536, -5.3272, -1.3277776, 101325.273261, 27.721667);
    printf("%s\n", str);
    uint8_t results[2];
    charcounter("aAa", results);
    printf("vowels: %i, consonants: %i\n", results[0], results[1]);
    char list[20] = "201,53,12,31,5";
    printf("mean: %f\n", mean(list));
    return 0;
}

void write_sensors(char *str, float ax, float ay, float az, float press, float temp){
    sprintf(str, "%+.02f,%+.02f,%+.02f,%.0f,%.02f",ax, ay, az, press, temp);
}

void charcounter(char *str, uint8_t *result){
    char vowelArray[6] = {'a','e','i','o','u'}, letter;
    int vowels = 0, consonants = 0, vowelFound;

    for (int i = 0; i < strlen(str); ++i) {
        vowelFound = 0;
        letter = str[i];
        if(letter >= 65 && letter <= 90){
            letter += 32;
        }
        if (letter >= 97 && letter <= 122){
            for (int j = 0; j < 5 && !vowelFound; ++j) {
                if (letter == vowelArray[j]){
                    vowels++;
                    vowelFound = 1;
                }
            }
            if (!vowelFound){
                consonants++;
            }
        }
    }
    result[0] = vowels;
    result[1] = consonants;
}

float mean(char *list){
    char* num, delim[2] = ",";

    float count = 0;
    float sum = 0;
    num = strtok(list,delim);
    do {
        sum += atoi(num);
        num = strtok(NULL,delim);
        count ++;
    } while (num != NULL);

    return sum / count;
}