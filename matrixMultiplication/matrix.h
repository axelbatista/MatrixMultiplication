#pragma once
#include <array>
#include <iostream>

template <int row, int col>
class Matrix {                                                  //container is non-immutable so we went with std::array
    std::array<std::array<double, col>, row> matrix;
public:
    void print() const;
    void fillUp();
    std::array<double, col>& operator[](int i){ return matrix[i];}              //defined in class so that it can be inlined properly
    constexpr int getColumn() const{ return col; }
    constexpr int getRow() const{ return row; }
};

template <int row, int col>
void Matrix<row, col>::fillUp() {
    std::cout << "Please enter the values for the matrix\n";
    for (int j = 0; j < row; j++) {
        for (int i = 0; i < col; i++) {
            std::cin >> matrix[j][i];
        }
    }
    std::cout << '\n';
}

template <int row, int col>
void Matrix<row, col>::print() const {
    for (int j = 0; j < row; j++) {
        for (int i = 0; i < col; i++) {
            std::cout << matrix[j][i] << ' ';
        }
        std::cout << '\n';
    }
}

template <int row1, int col1, int row2, int col2>
Matrix<row1, col2>& performMultiplication(Matrix<row1, col1>& m1,Matrix<row2, col2>& m2) {
    static Matrix<row1, col2> res;
    int yPositionInFirstM{};
    constexpr int rowLastPlace = res.getRow() - 1;
    constexpr int colLastPlace = res.getColumn() - 1;
    const int secondMatrixLength = m2.getColumn();
    const int firstMatrixLength = m1.getColumn();
    while (res[rowLastPlace][colLastPlace] == 0) {
        for (int j = yPositionInFirstM, columnsInSecondM{}; columnsInSecondM < secondMatrixLength;columnsInSecondM++) {
            for (int i = 0; i < firstMatrixLength; i++) {
                res[yPositionInFirstM][columnsInSecondM] += m1[j][i] * m2[i][columnsInSecondM];
            }
        }
        yPositionInFirstM++;
    }
    return res;
}

//all this does is just automates the exact procedure you would do if you were to do this on paper, in case you wanted to know of the algorithm.