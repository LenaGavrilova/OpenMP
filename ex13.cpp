#include <iostream>
#include <omp.h>
#include <cmath>
//На нулевом процессе задан массив целых чисел, который является двоичным представлением
//десятичного числа. Написать параллельную программу вычисления десятичного числа из
//заданного двоичного представления.
//int a[30] = {1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1};
//Число x может быть представлено в системе с основанием p, как x=an*pn+an-1*pn-1+
//a1*p1+a0*p0, где an ... a0 - цифры в представлении данного числа.

int main() {
    int a[30] = {1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1};

    int res = 0;

    int threads = 5;
    omp_set_num_threads(threads);

#pragma omp parallel for reduction(+:res)
    for (int i = 0; i < 30; i++) {
        if (a[i] == 1) {
            res += pow(2, 30 - i - 1);
        }
    }
    std::cout << "Result is  " << res << std::endl;
    return 0;
}