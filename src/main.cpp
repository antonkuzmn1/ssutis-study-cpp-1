#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int SIZE = 5;

void fillMatrix(int **matrix) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void printMatrix(int **matrix) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));

    int **matrix = new int *[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        matrix[i] = new int[SIZE];
    }

    printMatrix(matrix);

    fillMatrix(matrix);

    printMatrix(matrix);

    // std::cout << "Hello, CMake!" << std::endl;
    return 0;
}
