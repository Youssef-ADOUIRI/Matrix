#ifndef DEF_matrix
#define DEF_matrix

#include <vector>

class Matrix
{

private:
    unsigned int nCols;
    unsigned int nRows;
    std::vector<double> matrix;

public:
    Matrix(const size_t cols_num, const size_t row_num);
    Matrix(Matrix const &copy);
    //Matrix& Matrix::operator=(Matrix const& copy);
    ~Matrix();

    void Reset(const size_t cols_num, const size_t row_num);

    void print() const;
    void set(double val, unsigned int x, unsigned int y);
    double get(unsigned int x, unsigned int y);

    void init(double const &valueOfInit);

    void T();

    static Matrix add(Matrix const &m1, Matrix const &m2);

    static Matrix multiply(Matrix const &m1, Matrix const &m2);

    // static bool operator==(Matrix const& m1, Matrix const& m2);
    // static Matrix& operator+(Matrix const& m1, Matrix const& m2);

    void randomize();

    void add_by(double const &adding_Num);

    void multiply_by(double const &multiplying_Num);

    double *toArray(bool arrangement_type);
    static Matrix fromArray(const double arr[], size_t size);

    friend bool operator==(Matrix const &m1, Matrix const &m2);
};


bool operator==(Matrix const &m1, Matrix const &m2);

Matrix operator+(Matrix const &m1, Matrix const &m2);

#endif