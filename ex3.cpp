#include <iostream>
#include <omp.h>
//Написать программу, в которой объявить и присвоить начальные значения целочисленным
//переменным: a и b, определить две параллельные области, первая – с числом нитей 2,
//вторая – с числом нитей 4 Для первой области переменные a и b объявить защищенными, с
//режимом доступа private и firstprivate соответственно, внутри области определить номер
//нити и выполнить увеличение значения переменных на это величину. Выдать на экран
//значения переменных до входа в параллельную область, внутри параллельной области и
//после выхода из параллельной области. Для второй области переменную a объявить
//общей, переменную b объявить защищенной, с режимом доступа private, определить номер
//нити и выполнить уменьшение значения переменных на это величину. Выдать на экран
//значения переменных до входа в параллельную область, внутри параллельной области и
//после выхода из параллельной области.

int main() {
    int a = 20;
    int b = 30;

    std::cout << "Before 1 parallel a = " << a << " , b = " << b << std::endl;
#pragma omp parallel num_threads(2) private(a) firstprivate(b)
    {
        int thread = omp_get_thread_num();
        a += thread;
        b += thread;

        std::cout << "This is  1 parallel: a = " << a << " , b = " << b << " .Thread number is " << thread << std::endl;
    }
    std::cout << "After 1 parallel a = " << a << " , b = " << b << std::endl;

    std::cout << "Before 2 parallel a = " << a << " , b = " << b << std::endl;
#pragma omp parallel num_threads(4) shared(a) private(b)
    {
        int thread = omp_get_thread_num();
        a -= thread;
        b -= thread;


        std::cout << "This is  2 parallel a = " << a << " , b = " << b << " .Thread number is " << thread << std::endl;
    }
    std::cout << "After 2 parallel a = " << a << " , b = " << b << std::endl;
    return 0;
};