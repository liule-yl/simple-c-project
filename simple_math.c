#include "simple_math.h"
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("错误：除数不能为0\n");
        return 0;
    }
    return a / b;
}

int is_even(int num) {
    return num % 2 == 0;
}