#include "Matrix.h"
#include <vector>
#include <iostream>

using namespace std;

vector<vector<float>> Mat;

Matrix::Matrix()
{

}

Matrix::Matrix(vector<vector<float>> Mat)
{
   this->Mat = Mat;
}

Matrix::Matrix(vector<float> vec)
{
   this->Mat.push_back(vec);
}

Matrix::Matrix(float scalar)
{
    vector<float> row;
    row.push_back(scalar);
   this->Mat.push_back(row);
}

Matrix::~Matrix()
{
    //cout << "Matrix has been destroyed" << endl;
}

vector<vector<float>> Matrix::getMat()
{
    return (this->Mat);
}

void Matrix::setMat(vector<vector<float>> Mat)
{
    this->Mat = Mat;
}

void Matrix::zeros(int imax, int jmax)
{
        this->Mat.clear();

        for (int i=0; i<imax; i++)
        {
            vector<float> row;
            for (int j=0; j<jmax; j++)
            {
                 row.push_back(0.0);
            }
            this->Mat.push_back(row);
        }
}

void Matrix::ones(int imax, int jmax)
{
        this->Mat.clear();

        for (int i=0; i<imax; i++)
        {
            vector<float> row;
            for (int j=0; j<jmax; j++)
            {
                 row.push_back(1.0);
            }
            this->Mat.push_back(row);
        }
}

void Matrix::fillWithNr(float nr, int imax, int jmax)
{
    this->Mat.clear();

    for (int i=0; i<imax; i++)
    {
            vector<float> row;
            for (int j=0; j<jmax; j++)
            {
                 row.push_back(nr);
            }
            this->Mat.push_back(row);
    }
}

void Matrix::fillDiagonalWithNrs(vector<float> nrs)
{
    this->Mat.clear();

    for (int i=0; i<nrs.size(); i++)
    {
            vector<float> row;
            for (int j=0; j<nrs.size(); j++)
            {
                if (i==j)
                {
                    row.push_back(nrs[j]);
                }
                else
                {
                    row.push_back(0);
                }

            }
            this->Mat.push_back(row);
    }
}

void Matrix::setCell(float value, int i, int j)
{
    this->Mat[i][j] = value;
}

void Matrix::display()
{
        for (int i=0; i<this->Mat.size(); i++)
        {
            cout << "\t";
            for (int j=0; j<this->Mat[0].size(); j++)
            {
                 cout << this->Mat[i][j] << "\t" ;
            }
            cout << endl;
        }
        cout << endl;
}

void Matrix::operator=(Matrix MatIn)
{
        for (int i=0; i<MatIn.getMat().size(); i++)
        {
            vector<float> row;
            for (int j=0; j<MatIn.getMat()[0].size(); j++)
            {
                     row.push_back(MatIn.getMat()[i][j]);
            }
            this->Mat.push_back(row);
        }
}

Matrix Matrix::operator+(Matrix MatIn)
{
    int leftHeight = this->Mat.size();
    int leftWidth = this->Mat[0].size();
    int rightHeight = MatIn.getMat().size();
    int rightWidth = MatIn.getMat()[0].size();

    if ((leftHeight == rightHeight) && ((leftWidth == rightWidth)))
    {
        vector<vector<float>> MatHelp;
        for (int i=0; i<MatIn.getMat().size(); i++)
        {
            vector<float> row;
            for (int j=0; j<MatIn.getMat()[0].size(); j++)
            {
                     row.push_back(this->Mat[i][j] + MatIn.getMat()[i][j]);
            }
            MatHelp.push_back(row);
        }
        Matrix MatOut(MatHelp);
        return MatOut;
    }
    else
    {
        throw invalid_argument( "Matrices's dimensions are not equal" );
    }
}

Matrix Matrix::operator-(Matrix MatIn)
{
    int leftHeight = this->Mat.size();
    int leftWidth = this->Mat[0].size();
    int rightHeight = MatIn.getMat().size();
    int rightWidth = MatIn.getMat()[0].size();

    if ((leftHeight == rightHeight) && ((leftWidth == rightWidth)))
    {
        vector<vector<float>> MatHelp;
        for (int i=0; i<MatIn.getMat().size(); i++)
        {
            vector<float> row;
            for (int j=0; j<MatIn.getMat()[0].size(); j++)
            {
                     row.push_back(this->Mat[i][j] - MatIn.getMat()[i][j]);
            }
            MatHelp.push_back(row);
        }
        Matrix MatOut(MatHelp);
        return MatOut;
    }
    else
    {
        throw invalid_argument( "Matrices's dimensions are not equal" );
    }
}

Matrix Matrix::operator*(Matrix MatIn)
{
    int leftHeight = this->Mat.size();
    int leftWidth = this->Mat[0].size();
    int rightHeight = MatIn.getMat().size();
    int rightWidth = MatIn.getMat()[0].size();
    float value = 0.0;

    if ((rightWidth == 1) && (rightHeight == 1))
    {
        vector<vector<float>> MatHelp;
        for (int i=0; i<leftHeight; i++)
        {
            vector<float> row;
            for (int j=0; j<leftWidth; j++)
            {
                value = this->Mat[i][j]*MatIn.getMat()[0][0];
                row.push_back(value);
            }
            MatHelp.push_back(row);
        }
        Matrix MatOut(MatHelp);
        return MatOut;
    } else if ((leftWidth == 1) && (leftHeight == 1))
    {
        vector<vector<float>> MatHelp;
        for (int i=0; i<rightHeight; i++)
        {
            vector<float> row;
            for (int j=0; j<rightWidth; j++)
            {
                value = this->Mat[0][0]*MatIn.getMat()[i][j];
                row.push_back(value);
            }
            MatHelp.push_back(row);
        }
        Matrix MatOut(MatHelp);
        return MatOut;
    }
     else if (leftWidth == rightHeight)
    {
        vector<vector<float>> MatHelp;
        for (int i=0; i<leftHeight; i++)
        {
            vector<float> row;
            for (int j=0; j<rightWidth; j++)
            {
                value = 0.0;
                for(int k=0; k<leftWidth; k++)
                {
                    value += (this->Mat[i][k]*MatIn.getMat()[k][j]);
                }
                row.push_back(value);
            }
            MatHelp.push_back(row);
        }
        Matrix MatOut(MatHelp);
        return MatOut;
    }
    else
    {
        throw invalid_argument( "Nr of columns of first matrix and nr of rows of second matrix aren't equal" );
    }
}

Matrix Matrix::operator*(float scalar)
{
    int matHeight = this->Mat.size();
    int matWidth = this->Mat[0].size();
    float value = 0;

    if ((matWidth >= 1) && (matHeight >= 1))
    {
        vector<vector<float>> MatHelp;
        for (int i=0; i<matHeight; i++)
        {
            vector<float> row;
            for (int j=0; j<matWidth; j++)
            {
                value = (this->Mat[i][j] * scalar);
                row.push_back(value);
            }
            MatHelp.push_back(row);
        }
        Matrix MatOut(MatHelp);
        return MatOut;
    }
    else
    {
        throw invalid_argument( "Nr of columns or nr of rows of matrix are negative" );
    }
}
