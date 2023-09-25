#include <iostream>
#include <omp.h>
#include <math.h>

//Написать программу, в которой, используя возможности OpenMP найти все простые числа в
//заданном
//с
//клавиатуры
//диапазоне.
//Количество
//потоков
//определить
//самостоятельно.
//Результат выдать на экран.

int is_prime(int n) {
    int limit = sqrt(n) + 1;
    for (int i = 2; i <= limit; i++) {
        if (n % i == 0) {
            return 0;
        } else {
            return 1;
        }
    }
}

int count_prime_numbers(int a, int b) {
    int count = 0;
    if (a <= 2) {
        count = 1;
    }
    if (b <= 2) {
        count += 1;
    }
    if (a % 2 == 0) {
        a++;
    }
#pragma omp parallel num_threads(8)
    {
#pragma omp for
        for (int i = a; i <= b + 1; i += 2) {
            if (is_prime(i))
#pragma omp atomic
                count++;
        }

    }
    return count;
}

int main() {

    int a;
    int b;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    if (a > b or a < 0 or b <= 0) {
        std::cout << "Incorrect numbers  " << std::endl;
    } else {

        int res = count_prime_numbers(a, b);

        std::cout << "Result is  " << res << std::endl;
    }
}


