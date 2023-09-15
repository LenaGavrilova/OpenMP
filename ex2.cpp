#include <iostream>
#include <omp.h>
//Написать программу, в которой определить две параллельные области, выполнение которых
//зависит от условного оператора #pragma omp parallel if(…), если заданное значение числа
//нитей больше 1, параллельная область выполняется, иначе не выполняется. Число нитей
//перед первой областью задать равным 3, перед второй – равным 1 Внутри параллельных
//областей определить количество нитей и номер каждой нити, результат выдать на экран.
//Убедиться в правильности работы программы.


int main() {

    int threads = 3;

    omp_set_num_threads(threads);

#pragma omp parallel if(omp_get_max_threads() > 1)
    {

        int thread_num = omp_get_thread_num();
        int all_threads = omp_get_num_threads();


        std::cout << "If threads more than 1. Thread " << thread_num << " of " << all_threads << std::endl;
    };
    threads = 1;
#pragma omp parallel if(omp_get_max_threads() > 1)
    {
        int thread_num = omp_get_thread_num();
        int all_threads = omp_get_num_threads();
        std::cout << "If threads less than 1. Thread " << thread_num << " of " << all_threads << std::endl;
    }
    return 0;
}