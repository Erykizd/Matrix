#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>

using namespace std;

class Matrix
{
    public:
        Matrix();
        Matrix(vector<vector<float>> Mat);
        Matrix(vector<float> vec);
        Matrix(float scalar);
        virtual ~Matrix();
        vector<vector<float>> getMat();
        void setMat(vector<vector<float>> Mat);
        void zeros(int imax, int jmax);
        void ones(int imax, int jmax);
        void fillWithNr(float nr, int imax, int jmax);
        void fillDiagonalWithNrs(vector<float> nrs);
        void setCell(float valu, int i, int j);
        void display();
        void operator=(Matrix MatIn);
        Matrix operator+(Matrix MatIn);
        Matrix operator-(Matrix MatIn);
        Matrix operator*(Matrix MatIn);
        Matrix operator*(float scalar);
    protected:

    private:
        vector<vector<float>> Mat;
};

#endif // MATRIX_H
