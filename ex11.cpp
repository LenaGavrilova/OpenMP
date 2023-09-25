#include <iostream>
#include <omp.h>

//Написать программу, в которой, объявить и заполнить случайными значениями массив целых
//чисел. Используя возможности OpenMP найти максимальное числовое значение элементов
//массива, кратное 7 Длину массива и количество потоков определить самостоятельно.
//Результат выдать на экран. Для синхронизации числовых значений максимума используется
//механизм критических секций.

int main() {

    int n = 30;
    int a[n];

    int max = INT_MIN;

    int threads = 5;
    omp_set_num_threads(threads);

#pragma omp parallel for
    for (int i = 0; i < n; i++) {
        a[i] = rand();

        //std::cout << "a = " << a[i] << std::endl;

        if (a[i] % 7 == 0 && a[i] > max) {
#pragma omp critical
            max = a[i];
        }
    }

    if (max != -2147483648) {
        std::cout << "Max element is " << max << std::endl;
    } else {
        std::cout << "No suitable elements  " << std::endl;
    }
    return 0;
}