// file: matrix.cpp
// author: Alex Varga
// version: 1.1
// date: 28th november 2020
#include "matrix.h"

//assigns matrixM, to a dynamically allocated array of m
//double-pointer, where each pointer points to a dynamically
//allocated array of n doubles.
//Assigns sum_rowsM to a dynamically allocated array of m doubles
//Assigns sum_colsM to a dynamically allocated array of n doubles
//initializes rowsM and colsM with the values of m and n
Matrix::Matrix(int r, int c):rowsM(r), colsM(c)
{
    matrixM = new double* [rowsM];
    assert(matrixM != NULL);
    
    for(int i=0; i < rowsM; i++){
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }
    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);
    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);
}
//Destructor - calls helper function destroy
Matrix::~Matrix()
{
    destroy();
}
//Copy ctor - makes this matrix a copy of source
Matrix::Matrix(const Matrix& source)
{
    copy(source);
}
//Assignment operator
Matrix& Matrix::operator= (const Matrix& rhs)
{
    if(&rhs != this){
        destroy();
        copy(rhs);
    }
    return *this;
}
//returns sum of the values in the i_th row
double Matrix::get_sum_col(int i) const
{
    assert(i >= 0 && i < colsM);
    return sum_colsM[i];
}
//returns sum of the values in the i_th row
double Matrix::get_sum_row(int i) const
{
    assert(i >= 0 && i < rowsM);
    return sum_rowsM[i];
}
//calculate sum of values in each row of the matrix, storing them
//into the elements of sum_rowsM array, already created by the ctor
void Matrix::sum_of_rows()const
{
   double sum;
   for(int i = 0; i < rowsM; i++)
   {
	   sum = 0;
	   for(int j = 0; j < colsM; j++)
	   {
		   sum += this->matrixM[i][j];
	   }
	   sum_rowsM[i] = sum;
   }
}
//calculate sum of values in each column of the matrix, storing
//them into the elements of the sum_colsM array, already create by a ctor
void Matrix::sum_of_cols()const
{
	double sum;
    for(int i = 0; i < colsM; i++)
   {
	   sum = 0;
	   for(int j = 0; j < rowsM; j++)
	   {
		   sum += this->matrixM[j][i];
	   }
	   sum_colsM[i] = sum;
   }
    
}
//Copy function for copy ctor
void Matrix::copy(const Matrix& source)
{
    // THIS FUNCITON IS DEFECTIVE AND DOSEN'T PROPERLY MAKE THE COPY OF SROUCE
    if(source.matrixM == NULL){
        matrixM = NULL;
        sum_rowsM = NULL;
        sum_colsM = NULL;
        rowsM = 0;
        colsM = 0;
        return;
    }
    rowsM = source.rowsM;
    colsM = source.colsM;
    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);
    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);
    
    matrixM = new double*[rowsM];
    assert(matrixM !=NULL);
    for(int i =0; i < rowsM; i++){
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }
	for(int i = 0; i < rowsM; i++)
	{
		for(int j = 0; j < colsM; j++)
		{
			matrixM[i][j] = source.matrixM[i][j];
			sum_rowsM[i] = source.sum_rowsM[i];
			sum_colsM[j] = source.sum_colsM[j];
		}
	}
}

//deallocats memory which is dynamically allocated
//for each pointer in each element matrixM.
//Then deallocates memory which is dynamiclaly allocated for
//matrixM. Also deallocates memories allocated for arrays
//sum_colsM, and sum_rowsM.
void Matrix::destroy()
{
    delete [] sum_colsM;
	delete [] sum_rowsM;
	for(int i = 0; i < rowsM; i++)
	{
		delete [] matrixM[i];
	}
	delete[] matrixM;
}