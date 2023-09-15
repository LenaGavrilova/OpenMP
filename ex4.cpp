#include <iostream>
#include <omp.h>
//Написать программу, в которой объявить и присвоить начальные значения целочисленным
//массивам a[10] и b[10], определить параллельную область, количество нитей задать равным
//2, выделить код для основной (номер 0) и нити с номером 1 Основная нить должна
//выполнять поиск min значения элементов массива a, нить с номером 1 - поиск max значения
//элементов массива b. Результат выдать на экран.

int main() {

    omp_set_num_threads(2);

    int a[10]{2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int b[10]{1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    int min = INT_MAX;
    int max = INT_MIN;

#pragma omp parallel if(omp_get_thread_num()==0)
    {
        for (int i: a) {
            if (i < min) {
                min = i;
            }
        }
    };
#pragma omp parallel if(omp_get_thread_num()==1)
    {
        for (int i: b) {
            if (i > max) {
                max = i;
            }
        }
    };

    std::cout << "Min from a: " << min << "." << std::endl;
    std::cout << "Max from b: " << max << "." << std::endl;
    return 0;
}