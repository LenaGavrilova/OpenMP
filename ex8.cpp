#include <iostream>
#include <omp.h>
#include <windows.h>
#include <chrono>
//Используя возможности OpenMP, написать программу умножения матрицы на вектор.
//Сравнить время выполнения последовательной и параллельных программ.

int main() {

    int const rows = 100;
    int const columns = 150;

    int static matrix[rows][columns];
    int static vector[columns];
    int static res[rows];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = i + j;
        }
    }

    for (int i = 0; i < columns; i++) {
        vector[i] = i;
    }
    //последовательное перемножение
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < rows; i++) {
        res[i] = 0;
        for (int j = 0; j < columns; j++) {
            res[i] += matrix[i][j] * vector[j];
        }
    }
    auto end = std::chrono::high_resolution_clock::now();

    float duration = std::chrono::duration_cast<std::chrono::duration<float>>(end - start).count();
    std::cout << "Duration " << duration << std::endl;

//умножение при помощи распараллеливания
start = std::chrono::high_resolution_clock::now();
#pragma omp parallel for
    for (int i = 0; i < rows; i++) {
        res[i] = 0;
        for (int j = 0; j < columns; j++) {
            res[i] += matrix[i][j] * vector[j];
        }
    }
    end = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::duration<float>>(end - start).count();
    std::cout << "Duration " << duration << std::endl;
}