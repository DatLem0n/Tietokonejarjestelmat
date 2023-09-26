#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int64_t factorial(int8_t n);
void shuffle(uint8_t *list, uint16_t list_size);
void movavg(float *array, uint8_t array_size, uint8_t window_size);
int8_t tictactoe_check(int8_t * gameboard, int win_len);
int checkLines(int* points, int pointAmount, int winLength);
int checkRows(int* board, int* points, int pointAmount, int winLength);
int checkDiag(int* board, int* points, int pointAmount, int winLength);

int mainViikko7(){
    printf("%ld",factorial(4));

    srand(time(NULL));
    uint8_t list[8] = { 1,2,3,4,5,6,7,8};
    shuffle(list, 8);
    printf("%s\n", list);

    float data[5] = { 1.0, 2.0, 4.0, 6.0, 9.0 };
    movavg(data, 5, 3);
    int8_t board[100] = {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    int8_t board2[100] = {0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    printf("\n%i", tictactoe_check(board, 3)); // 1
    printf("\n%i", tictactoe_check(board2, 9)); // 1

    return 0;
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

int8_t tictactoe_check(int8_t* gameboard, int win_len) {
    int x[100], o[100], x_amount = 0, o_amount = 0, xWin = 0, oWin = 0;
    for (int i = 0; i < 100; ++i) {
        switch (gameboard[i]) {
            case 1: {
                x[x_amount] = i;
                x_amount++;
            }
                break;
            case 2: {
                o[o_amount] = i;
                o_amount++;
            }
                break;
            default:
                break;
        }
    }
    if (win_len > 1) {
        if (x_amount >= win_len) {
          xWin = checkRows((int *) gameboard, x, x_amount, win_len) || checkLines(x, x_amount, win_len) || checkDiag((int * )gameboard, x, x_amount, win_len);
        }

        if (o_amount >= win_len) {
            oWin = checkRows((int *) gameboard, o, o_amount, win_len) || checkLines(o, o_amount, win_len) || checkDiag((int * ) gameboard, o, o_amount, win_len);
        }
    }
    if (xWin || oWin) {
        if (xWin && oWin) return 0;
        if (xWin) return 1;
        if (oWin) return 2;
    }
    return 0;
}

int checkLines(int* points, int pointAmount, int winLength) {
    int length = 0, longest = 0;

    for (int i = 0; i < pointAmount - 1; ++i) {
        if (points[i] + 1 == points[i + 1]) {
            length++;
            if (length > longest) {
                longest = length;
            }
        } else {
            length = 0;
        }
    }

    if (longest >= winLength){
        return 1;
    }
    return 0;
}

int checkRows(int* board, int* points, int pointAmount, int winLength){
    int length = 0, longest = 0;

    for (int i = 0; i < pointAmount; ++i) {
        for (int j = i; j < pointAmount; ++j) {
            if (points[i] + 10 == points[j]) {
                length++;
                do {
                    length++;
                    printf("%i", length);
                }while(board[points[i] + 10 * length] == board[i]);
                if (length > longest) {
                    longest = length;
                }
                length = 0;
            }
        }
    }
    if (longest >= winLength){
        return 1;
    }
    return 0;

}

int checkDiag(int*board, int* points, int pointAmount, int winLength){
    int length = 0, longest = 0;

    for (int i = 0; i < pointAmount; ++i) {
        for (int j = i; j < pointAmount; ++j) {
            if ((points[i] + 11 == points[j]) || (points[i] + 9 == points[j])) {
                length++;
                do {
                    length++;
                }while((board[points[i] + 11 * length] == board[j]) || (board[points[i] + 9 * length] == board[i]));
                if (length > longest) {
                    longest = length;
                }
                length = 0;
            }
        }
    }
    if (longest >= winLength){
        return 1;
    }
    return 0;
}