//
// Created by sen on 11/3/20.
//
#include "./printf_variadic.h"

int main () {
    int *pi = new int;
    printff("%d %s %p %f\n", 100, "this is string.", pi, 3.141592653);
}