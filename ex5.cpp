#include <iostream>
#include <omp.h>
//Написать программу, в которой объявить и присвоить начальные значения элементам
//двумерного массива d[6][8], для инициализации значений использовать генератор случайных
//чисел. Используя конструкцию директивы sections…section определить три секции для
//выполнения следующих операций:
// первая секция выполняет вычисление среднего арифметического значения элементов
//двумерного массива,
// вторая секция выполняет вычисление минимального и максимального значений
//элементов двумерного массива,
// третья секция выполняет вычисление количества элементов массива, числовые значения
//которых кратны 3
//В каждой секции определить и выдать на экран номер исполняющей нити и результат
//выполнения вычислений.

int main() {
    int a = 6;
    int b = 8;
    int d[a][b];

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            d[i][j] = rand();
            std::cout << d[i][j] << std::endl;
        }
    }
#pragma omp parallel sections
    {
#pragma omp section
        {
            float avg = 0;
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    avg += d[i][j];
                }
            }
            avg /= a * b;

            std::cout << "Thread num is " << omp_get_thread_num << " .Avg is " << avg << "." << std::endl;
        }
#pragma omp section
        {
            int max = INT_MIN;
            int min = INT_MAX;
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    if (max < d[i][j]) {
                        max = d[i][j];
                    }
                    if (min > d[i][j]) {
                        min = d[i][j];
                    }
                }
            }
            std::cout << "Thread num is " << omp_get_thread_num << " . Min is" << min << " . Max is " << max
                      << "." << std::endl;
        }
#pragma omp section
        {
            int c = 0;
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    if (d[i][j] % 3 == 0) {
                        c += 1;
                    }
                }
            }
            std::cout << "Thread num is " << omp_get_thread_num << " . Nums is " << c << "." << std::endl;
        }
    }

    return 0;
};
