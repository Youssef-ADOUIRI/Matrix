

#include <iostream>
#include <math.h>

using namespace std;

class Matrix
{

public:
    unsigned int nCols;
    unsigned int nRows;
    double **matrix;

    Matrix(unsigned int cols_num, unsigned int row_num)
    {
        nCols = cols_num;
        nRows = row_num;
        /* allocate desired memory size */
        // alocate the array of columns //matrix = (double **)malloc(sizeof(double*) * nRows);
        matrix = new double *[nRows];
        //allocate the matrix
        for (int i = 0; i < nRows; i++)
        {
            //matrix[i] = (double *)malloc(sizeof(double) * nCols);
            matrix[i] = new double[nCols];
        }
    }

    void kill()
    {
        /*
        for (int i = 0; i < nRows; i++)
        {
            free(matrix[i]);
        }
        free(matrix);
        */
        for (int i = 0; i < nRows; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void print()
    {
        for (int i = 0; i < nRows; i++)
        {
            cout << "[ ";
            for (int j = 0; j < nCols; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "]\n";
        }
    }
    void init(double valueOfInit = 0)
    {
        for (int i = 0; i < nRows; i++)
        {
            for (int j = 0; j < nCols; j++)
            {
                matrix[i][j] = valueOfInit;
            }
        }
    }

    void T()
    {
        for (int i = 0; i < nRows; i++)
        {
            for (int j = 0; j < nCols; j++)
            {
                
            }
        }
    }

    static Matrix add(Matrix m1, Matrix m2)
    {
        unsigned int row_num = 0, col_num = 0;
        if (m1.nRows != m2.nRows)
        {
            cout << "Both matrix's rows number don't match";
            return m1;
        }
        else if (m1.nCols != m2.nCols)
        {
            cout << "Both matrix's columns number don't match";
            return m2;
        }
        else
        {
            row_num = m1.nRows;
            col_num = m1.nCols;
        }
        Matrix result(col_num, row_num);
        for (int i = 0; i < row_num; i++)
        {
            for (int j = 0; j < col_num; j++)
            {
                result.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
            }
        }
        return result;
    }
    static Matrix multiply(Matrix m1, Matrix m2)
    {
        unsigned int row_num = m1.nRows, col_num = m2.nCols;
        if (m1.nCols != m2.nRows)
        {
            cout << "Both matrix's don't match";
            Matrix result(col_num, row_num);
            return result;
        }
        else
        {
            row_num = m1.nRows;
            col_num = m1.nCols;
        }
        Matrix result(col_num, row_num);
        for (int i = 0; i < row_num; i++)
        {
            for (int j = 0; j < col_num; j++)
            {
                result.matrix[i][j] = 0;
                for (int k = 0; k < m1.nCols; k++)
                    result.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
            }
        }
        return result;
    }
};

int main()
{

    Matrix m1(2, 2);
    m1.init(1);
    m1.print();
    cout << "\n";

    Matrix m2(2, 2);
    m2.init(2);
    m2.print();
    cout << "\n";

    Matrix m3 = Matrix::add(m1, m2);
    m3.print();

    m3.kill();
    m2.kill();
    m1.kill();

    return 0;
}
