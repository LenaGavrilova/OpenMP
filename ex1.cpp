#include <iostream>
#include <omp.h>

//Написать программу где каждый поток печатает свой идентификатор, количество потоков
//всего и строчку «Hello World». Запустить программу с 8 потоками. Всегда ли вывод
//идентичен? Почему?
int main() {

#pragma omp parallel num_threads(8)
    {
        int id = omp_get_thread_num();
        int threads = omp_get_num_threads();

        std::cout << "Id " << id << ", all threads " << threads << ": Hello World" << std::endl;
    }

    return 0;
}
//порядок заранее неизвестен тк он определяется планировщиком операционной системы