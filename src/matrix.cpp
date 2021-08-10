#include <iostream>
#include <random>
#include "matrix.h"

using namespace std;

#define default_Row 1
#define default_Col 1

Matrix::Matrix(unsigned int cols_num = default_Col, unsigned int row_num = default_Row) : nCols(cols_num), nRows(row_num)
{

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

void Matrix::kill()
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

void Matrix::print() const
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
void Matrix::init(double valueOfInit = 0)
{
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            matrix[i][j] = valueOfInit;
        }
    }
}

Matrix::~Matrix()
{
    //(*this).kill();
}

void Matrix::T()
{
    Matrix newM(nRows, nCols);

    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            newM.matrix[j][i] = matrix[i][j];
        }
    }

    this->kill();

    *this = newM;
}

void Matrix:: set(double val ,unsigned int x , unsigned int y){
    matrix[x][y] = val;
}
double Matrix:: get(unsigned int x , unsigned int y){
    return matrix[x][y];
}

Matrix Matrix::add(Matrix m1, Matrix m2)
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

Matrix Matrix::multiply(Matrix m1, Matrix m2)
{
    unsigned int row_num = m1.nRows, col_num = m2.nCols;
    if (m1.nCols != m2.nRows)
    {
        cout << "Both matrix's don't match";
        Matrix result(col_num, row_num);
        return result;
    }
    Matrix result(col_num, row_num);
    for (int i = 0; i < row_num; i++)
    {
        for (int j = 0; j < col_num; j++)
        {
            result.matrix[i][j] = 0;
            for (int k = 0; k < m1.nCols; k++)
                result.matrix[i][j] += (m1.matrix[i][k]) * (m2.matrix[k][j]);
        }
    }
    return result;
}

void Matrix::randomize()
{ //generate numbers randomly between -1 and 1
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            matrix[i][j] = 2.0f * ((double)rand() / RAND_MAX) - 1.0f;
        }
    }
}

void Matrix::add_by(double adding_Num)
{
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            matrix[i][j] += adding_Num;
        }
    }
}

void Matrix::multiply_by(double multiplying_Num)
{
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            matrix[i][j] *= multiplying_Num;
        }
    }
}

double *Matrix::toArray(bool arrangement_type = true)
{
    double *arr_ptr = NULL;
    arr_ptr = new double[nCols * nRows];
    if (arrangement_type)
    {
        // horizental
        for (int i = 0; i < nRows; i++)
        {
            for (int j = 0; j < nCols; j++)
            {
                arr_ptr[i*nCols + j] =  matrix[i][j];
            }
        }
        return arr_ptr;
    }
    else{
        // vertical
        for (int i = 0; i < nCols; i++)
        {
            for (int j = 0; j <  nRows; j++)
            {
                arr_ptr[i*nRows + j] =  matrix[j][i];
            }
        }
        return arr_ptr;
    }
}
