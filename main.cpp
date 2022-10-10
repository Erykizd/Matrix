#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include  "Matrix.h"

using namespace std;

void display(Matrix M);

int main()
{
    Matrix A({{1,0,2},{-1,3,1}});
    Matrix B({{3,1},{2,1},{1,0}});
    Matrix C;
    Matrix D(2);

    C=A*B;

    display(B*10);

    return 0;
}

void display(Matrix M)
{
    M.display();
}
