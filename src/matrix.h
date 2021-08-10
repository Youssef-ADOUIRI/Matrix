#ifndef DEF_matrix
#define DEF_matrix


class Matrix
{

private:
    unsigned int nCols;
    unsigned int nRows;
    double **matrix;

public:
    Matrix(unsigned int cols_num, unsigned int row_num);
    ~Matrix();

    void kill();

    void print() const;
    void set(double val ,unsigned int x , unsigned int y);
    double get(unsigned int x , unsigned int y);
    
    void init(double valueOfInit);

    void T();

    static Matrix add(Matrix m1, Matrix m2);

    static Matrix multiply(Matrix m1, Matrix m2);

    void randomize();

    void add_by(double adding_Num);

    void multiply_by(double multiplying_Num);

    double *toArray(bool arrangement_type);
    

};

#endif