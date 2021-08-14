#include <iostream>
#include <random>
#include <time.h>
#include "matrix.h"

using namespace std;

int main()
{
    srand(time(0));

    Matrix m1(5, 3);

    m1.init(2);

    //m1.set(0 ,1 ,0);

    m1.print();

    m1.T();
    cout << "trans is : " << endl;
    m1.print();

    Matrix m2(3, 5);
    m2.init(2);
    //m2.set(-5.1 , 0, 1);
    
    m2.print();


    cout << "add\n";

    Matrix result = m1 + m2;
    result.print();

    return 0;
}
