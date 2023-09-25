#include <iostream>
#include <omp.h>
//Написать параллельную программу возведения числа 210 в квадрат без операции
//умножения.
//Пояснение: Квадрат натурального числа N равен сумме первых N нечетных чисел. Например,
//32 = 9 это 1+3+5=9; 52 = 25 это 1+3+5+7+9=25;

int main() {
    int num = 210;
    int res = 0;

    int threads = 5;
    omp_set_num_threads(threads);
#pragma omp parallel for reduction(+:res)
    for (int i = 0; i < num; i++) {
        res += 2 * i + 1;
    }
    std::cout << "Result is  " << res << std::endl;
    return 0;
}