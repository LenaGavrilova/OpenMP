#include <iostream>
#include <omp.h>
//Написать программу, в которой объявить и присвоить начальные значения целочисленным
//массивам a[10] и b[10]. Используя конструкцию parallel for и reduction вычислить средние
//арифметические значения элементов массивов a и b, сравнить полученные значения,
//результат выдать на экран.

int main() {

    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

    int sum_a = 0;
    int sum_b = 0;

    float avg_a = 0;
    float avg_b = 0;

#pragma omp parallel for reduction(+:sum_a, sum_b)
    for (int i = 0; i < 10; i++) {
        sum_a += a[i];
        sum_b += b[i];
    }

    avg_a = sum_a / 10;
    avg_b = sum_b / 10;

    float difference = abs(avg_a - avg_b);

    std::cout << "Difference between avg arrays = " << difference << "." << std::endl;
    return 0;
}