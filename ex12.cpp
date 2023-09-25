#include <iostream>
#include <omp.h>

//Модифицируйте задачу 1 так, что бы потоки распечатывали свои идентификаторы в
//обратном порядке. Существует как минимум 5 способов решения. Постарайтесь найти как
//можно больше.

int main() {

#pragma omp parallel num_threads(8)
    {
        for (int i = 8; i > 0; i--) {
            int id = omp_get_thread_num();
            int threads = omp_get_num_threads();
#pragma omp barrier
            if (i == id) {
                std::cout << "Id " << id << ", all threads " << threads << ": Hello World" << std::endl;
            }
        }
    }
    return 0;
}
