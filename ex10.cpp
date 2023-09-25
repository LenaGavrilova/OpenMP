#include <iostream>
#include <omp.h>
//Написать программу, в которой объявить и присвоить начальные значения массиву целых
//чисел a[30], для инициализации значений использовать генератор случайных чисел.
//Используя конструкцию omp parallel for и omp atomic вычислить количество элементов
//массива, числовые значения которых кратны 9 Количество нитей задать самостоятельно.
//Результат выдать на экран.

int main() {
    int n = 30;
    int a[n];

    int threads = 5;
    omp_set_num_threads(threads);

    int count = 0;

#pragma omp parallel for
    for (int i = 0; i < n; i++) {
        a[i] = rand()%10;
//        std::cout << "a = " << a[i]<< std::endl;
        if (a[i] % 9 == 0) {
#pragma omp atomic
            count += 1;
        }
    }
    std::cout << "Count is " << count << std::endl;
    return 0;
}