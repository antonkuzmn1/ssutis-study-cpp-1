#include <iostream>
#include <random>
#include <vector>

using namespace std;

const int SIZE = 5;

int generateRandomNumber(const int min, const int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void fillMatrix(int **matrix) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matrix[i][j] = generateRandomNumber(10, 99);
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

void printRightDiagonals(int **matrix) {
    vector<int> result;
    for (int start = 0; start < SIZE; ++start) {
        int row = 0, col = start;
        while (row < SIZE && col < SIZE) {
            result.push_back(matrix[row][col]);
            ++row;
            ++col;
        }
    }

    for (const int i: result) cout << i << " ";

    cout << endl;
}

void printLeftDiagonals(int **matrix) {
    vector<int> result;
    for (int start = SIZE - 1; start >= 0; --start) {
        int row = 0, col = start;
        while (row < SIZE && col >= 0) {
            result.push_back(matrix[row][col]);
            ++row;
            --col;
        }
    }

    for (const int i: result) cout << i << " ";

    cout << endl;
}

int main() {
    int **matrix = new int *[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        matrix[i] = new int[SIZE];
    }

    fillMatrix(matrix);

    std::cout << "\nматрица" << endl;
    printMatrix(matrix);

    std::cout << "\na) по правым диагоналям, начиная с правого верхнего элемента" << endl;
    printRightDiagonals(matrix);

    std::cout << "\nb) по левым диагоналям, начиная с левого верхнего элемента" << endl;
    printLeftDiagonals(matrix);

    for (int i = 0; i < SIZE; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
