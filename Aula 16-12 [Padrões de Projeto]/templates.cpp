#include <iostream>
#include <array>
#include <stdexcept>
#include <iomanip>

template <typename T, size_t Rows, size_t Cols>
class Matrix {
    std::array<std::array<T, Cols>, Rows> data;
public:
    Matrix() {
        for (auto& row : data)
            row.fill(T());
    }

    T& operator()(size_t row, size_t col) {
        if (row >= Rows || col >= Cols)
            throw std::out_of_range("Index out of range");
        return data[row][col];
    }

    const T& operator()(size_t row, size_t col) const {
        if (row >= Rows || col >= Cols)
            throw std::out_of_range("Index out of range");
        return data[row][col];
    }

    Matrix<T, Rows, Cols> operator+(const Matrix<T, Rows, Cols>& other) const {
        Matrix<T, Rows, Cols> result;
        for (size_t i = 0; i < Rows; ++i) {
            for (size_t j = 0; j < Cols; ++j) {
                result(i, j) = (*this)(i, j) + other(i, j);
            }
        }
        return result;
    }

    template <size_t OtherCols>
    Matrix<T, Rows, OtherCols> operator*(const Matrix<T, Cols, OtherCols>& other) const {
        Matrix<T, Rows, OtherCols> result;
        for (size_t i = 0; i < Rows; ++i) {
            for (size_t j = 0; j < OtherCols; ++j) {
                for (size_t k = 0; k < Cols; ++k) {
                    result(i, j) += (*this)(i, k) * other(k, j);
                }
            }
        }
        return result;
    }

    void display() const {
        for (const auto& row : data) {
            for (const auto& elem : row) {
                std::cout << std::setw(8) << elem << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix<int, 2, 2> mat1;
    Matrix<int, 2, 2> mat2;

    mat1(0, 0) = 1; mat1(0, 1) = 2;
    mat1(1, 0) = 3; mat1(1, 1) = 4;

    mat2(0, 0) = 5; mat2(0, 1) = 6;
    mat2(1, 0) = 7; mat2(1, 1) = 8;

    std::cout << "Matrix 1:" << std::endl;
    mat1.display();

    std::cout << "\nMatrix 2:" << std::endl;
    mat2.display();

    auto sum = mat1 + mat2;
    std::cout << "\nSum of Matrix 1 and Matrix 2:" << std::endl;
    sum.display();

    auto product = mat1 * mat2;
    std::cout << "\nProduct of Matrix 1 and Matrix 2:" << std::endl;
    product.display();

    return 0;
}
