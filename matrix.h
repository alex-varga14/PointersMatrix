// file: matrix.h
// author: Alex Varga
// version: 1.0
// date: 28th november 2020
#ifndef MATRIX_H
#define MATRIX_H
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

//Matrix class for pointers of pointers
class Matrix{
	public:
		Matrix(int m, int n);
		// Default ctor
		Matrix():matrixM(NULL), sum_rowsM(NULL), sum_colsM(NULL), rowsM(0), colsM(0){}
		~Matrix();
		Matrix& operator=(const Matrix& rhs);
		Matrix(const Matrix& source);
		//Simple getetrs
		int get_rows() const {return rowsM;}
		int get_cols() const {return colsM;}
		//returns the value in the r_th row and c_th column of matrixM
		double& at(int r, int c) {return matrixM[r][c];}
		//returns the value in the r_th row and c_th column of matrixM
		const double& at(int r, int c)const {return matrixM[r][c];}
		double get_sum_col(int i) const;
		double get_sum_row(int i) const;
		void sum_of_rows()const;
		void sum_of_cols()const;
	private:
		double ** matrixM;   // points to an array of double-pointers on the heap
		double* sum_rowsM;   // points to an array of doubles on the heap
		double* sum_colsM;   // points to an array of doubles on the heap
		int rowsM;           // number of rows of matrix
		int colsM;           // number of columns of matrix
		
		void copy(const Matrix& souce);
		void destroy();
};
#endif 
