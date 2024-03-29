#include <iostream>
#include <omp.h>
//Написать программу, в которой определить две параллельные области, каждая из которых
//содержит итерационную конструкцию for выполняющую инициализацию элементов
//одномерных массивов целых чисел a[12], b[12] и c[12]. Число нитей перед первой областью
//задать равным 3, перед второй – равным 4 Первая параллельная область выполняет
//инициализацию элементов массивов a и b с использованием статического распределения
//итераций, размер порции итераций выбрать самостоятельно, вторая параллельная область
//выполняет инициализацию элементов массива c по следующему правилу c[i] = a[i] + b[i], с
//использованием динамического распределения итераций, размер порции итераций выбрать
//самостоятельно. В каждой области определить и выдать на экран количество нитей, номер
//нити и результат выполнения цикла. Убедиться в правильности работы программы.

int main() {
    int a[12];
    int b[12];
    int c[12];

    int threads = 3;

    omp_set_num_threads(threads);
#pragma omp parallel
    {
#pragma omp for schedule(static)
        for (int i = 0; i < 12; i++) {
            a[i] = i + 1;
            b[i] = i + 2;
            std::cout << "1.All threads = " << omp_get_num_threads() << " , thread number is " << omp_get_thread_num
                      << " , a = " << a[i] << " , b = " << b[i] << std::endl;
        }
    }
    threads = 4;

    omp_set_num_threads(threads);
#pragma omp parallel
    {
#pragma omp for schedule(static)
        for (int i = 0; i < 12; i++) {
            c[i] = a[i] + b[i];
            std::cout << "2.All threads = " << omp_get_num_threads() << " , thread number is " << omp_get_thread_num
                      << " , c = "
                      << c[i] << std::endl;
        }
    }
    return 0;
}



