#include <iostream>
#include <random>
#include <time.h>
#include "matrix.h"

using namespace std;

int main()
{
    srand(time(0));
    Matrix m1(5, 1);
    m1.randomize();
    m1.add_by(2);
    m1.print();
    m1.init(8);
    m1.set(5, 0, 1);
    m1.multiply_by(2);
    cout << "\n";
    m1.print();
    m1.T();
    m1.print();

    Matrix m2(5, 1);
    m2.init(2);
    m2.print();
    cout << "\n";

    Matrix m3 = Matrix::multiply(m1, m2);
    m3.print();

    double *array = m3.toArray(true);
    for (int i = 0; i < 25; i++)
    {
        cout << array[i] << " ";
    }
    delete[] array;

    m3.kill();
    m2.kill();
    m1.kill();

    return 0;
}
