
#include "matrix.h"

//specify the dimensions for the matrix via template arguments.

int main()
{
    Matrix<2, 2> matrix1{};
    Matrix<2, 1> matrix2{};
    matrix1.fillUp();               //fill up values for instantiated matrices. Doesn't need to be a member function as it doesn't interoporate well
    matrix2.fillUp();               //with the row echelon calculator for example because of the limitation of picking pivots, but it's fine as it's seperate program.          
    Matrix<2,1>& result = performMultiplication(matrix1, matrix2);
    std::cout << '\n';                          
    result.print();
}
    
    

