#include <iostream>
#include <omp.h>
//Написать программу, в которой объявить и присвоить начальные значения элементам
//двумерного массива d[6][8], для инициализации значений использовать генератор случайных
//чисел. Используя конструкцию директивы omp parallel for и omp critical определить
//минимальное и максимальное значения элементов двумерного массива. Количество нитей
//задать самостоятельно. Результат выдать на экран.

int main() {

    int a = 6;
    int b = 8;
    int d[a][b];

    int min = INT_MAX;
    int max = INT_MIN;

    int threads = 5;
    omp_set_num_threads(threads);

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            d[i][j] = rand();
            // std::cout << d[i][j] << std::endl;
        }
    }

#pragma omp parallel for
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {


#pragma omp critical
            {
                if (d[i][j] > max) {
                    max = d[i][j];
                }
                if (d[i][j] < min) {
                    min = d[i][j];
                }
            }
        }
    }
    std::cout << "Thread num is " << omp_get_thread_num << " . Min is " << min << " . Max is " << max
              << "." << std::endl;
    return 0;
}