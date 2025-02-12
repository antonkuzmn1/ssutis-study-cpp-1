#include <iostream>
#include <random>
#include <vector>

using namespace std;

constexpr int SIZE = 5;

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

void printCenterSpiral(int **matrix) {
    constexpr int centerRow = SIZE / 2;
    constexpr int centerCol = SIZE / 2;

    const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int step = 1;
    int dirIndex = 0;
    int row = centerRow, col = centerCol;

    cout << matrix[row][col] << " ";

    while (step < max(SIZE, SIZE)) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < step; ++j) {
                row += directions[dirIndex].first;
                col += directions[dirIndex].second;
                if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
                    cout << matrix[row][col] << " ";
                }
            }
            dirIndex = (dirIndex + 1) % 4;
        }
        step++;
    }

    cout << endl;
}

void printSpiral(int** matrix) {
    int top = 0, bottom = SIZE - 1, left = 0, right = SIZE - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
}

void part2() {
    int rows;
    std::cout << "Введите количество строк: ";
    std::cin >> rows;

    std::vector<std::vector<int>> arr(rows);

    for (int i = 0; i < rows; ++i) {
        int cols;
        std::cout << "Введите количество элементов в строке " << i + 1 << ": ";
        std::cin >> cols;

        arr[i].resize(cols);

        std::cout << "Введите элементы для строки " << i + 1 << ": ";
        for (int j = 0; j < cols; ++j) {
            std::cin >> arr[i][j];
        }
    }

    std::cout << "Массив:\n";
    for (int i = 0; i < rows; ++i) {
        for (const int j : arr[i]) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    const auto matrix = new int *[SIZE];
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

    std::cout << "\nc) по спирали, начиная с центрального элемента" << endl;
    printCenterSpiral(matrix);

    std::cout << "\nd) по спирали, начиная с левого верхнего элемента" << endl;
    printSpiral(matrix);

    part2();

    for (int i = 0; i < SIZE; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
