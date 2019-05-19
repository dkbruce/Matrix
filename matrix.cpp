#include <iostream>
#include <vector>

class Matrix
{
protected:
    std::vector<std::vector<double>> data;
    short int dim_row; // Number of rows
    short int dim_col; // Number of cols

public:
    // Constructs a matrix from passed data
    Matrix(std::vector<std::vector<double>> inp)
    {
        data = inp;
        dim_row = inp.size();
        dim_col = inp[0].size();
    }

    // Constructs an n x n dimensional identity matrix
    static Matrix eye(unsigned int n)
    {
        int i, j;
        std::vector<std::vector<double>> data;
        for (i = 0; i < n; ++i)
        {
            std::vector<double> row;
            for (j = 0; j < n; ++j)
            {
                i == j ? row.push_back(1) : row.push_back(0);
            }
            data.push_back(row);
        }
        Matrix output = Matrix(data);
        return output;
    }

    void print()
    {
        int i, j;
        for (i = 0; i < dim_row; ++i)
        {
            for (j = 0; j < dim_col; ++j)
            {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix operator+(Matrix& B)
    {
        int i, j;
        std::vector<std::vector<double>> sum;
        for (i = 0; i < this->dim_row; ++i)
        {
            std::vector<double> row;
            for(j = 0; j < this->dim_col; ++j)
            {
                row.push_back(this->data[i][j] + B.data[i][j]);
            }
            sum.push_back(row);
        }
        Matrix output = Matrix(sum);
        return output;
    }

    Matrix operator*(Matrix& B)
    {
        int i, j, k;
        std::vector<std::vector<double>> prod;
        for (i = 0; i < this->dim_row; ++i)
        {
            std::vector<double> row;
            for (j = 0; j < B.dim_col; ++j)
            {
                double temp = 0;
                for (k = 0; k < this->dim_col; ++k)
                {
                    temp += this->data[i][k] * B.data[k][j];
                }
                row.push_back(temp);
            }
            prod.push_back(row);
        }
        Matrix output = Matrix(prod);
        return output;
    }
};

int main()
{
    std::cout << "Sample matrices:" << std::endl << std::endl;
    std::cout << "A =" << std::endl;
    Matrix A = Matrix({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    A.print();

    std::cout << std::endl;

    std::cout << "B =" << std::endl;
    Matrix B = Matrix::eye(3);
    B.print();

    std::cout << std::endl;

    std::cout << "A + B =" << std::endl;
    (A + B).print();

    std::cout << std::endl;


    std::cout << "A * B =" << std::endl;
    (A * B).print();

    std::cout << std::endl;

    std::cout << "A^2 =" << std::endl;
    (A * A).print();
    return 0;
}