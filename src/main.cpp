#include <iostream>
#include <random>
#include <time.h>
#include "matrix.h"

using namespace std;

/*prototype*/
void f(double &x){
    x = 2.0f * ((double)rand() / RAND_MAX) - 1.0f;
}

int main()
{
    Matrix m(5 , 5);

    return 0;
}
