//Matrix.h
#pragma once
#include <iostream>
#include <iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

template <typename T>
class Matrix {
private:
	int rows, cols;
	T** data;

	void allocate() {
		data = new T * [rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new T[cols];
		}
	}

	void deallocate() {
		for (int i = 0; i < rows; i++) {
			delete[] data[i];
		}
		delete[] data;
	}
public:
	Matrix(int r = 3, int c = 3) :rows(3), cols(3), data(nullptr) {
		allocate();
		}
	~Matrix() {
		deallocate();
	}

	void clone(const Matrix<T>& m) {
		if (data) {
			deallocate();
		}
		rows = m.rows;
		cols = m.cols;
		allocate();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				data[i][j] = m.data[i][j];
			}
		}
	}
	Matrix(const Matrix<T>& m) { clone(m); }
	Matrix<T>& operator =(const Matrix<T>&m){ clone(m); return *this; }

	friend ostream& operator << (ostream& os, const Matrix<T>&m) {
		for (int i = 0; i < m.rows; i++) {
			for (int j = 0; j < m.cols; j++)
				os << m.data[i][j] << "\t";
			os << endl;
		}
		return os;
	}
	friend istream& operator >>(istream& is, Matrix<T>&m) {
		for (int i = 0; i < m.rows; i++) {
			for (int j = 0; j < m.cols; j++) {
				cout << "Element [" << i << "][" << j << "] : ";
				is >> m.data[i][j];
			}
		}
		return is;
	}
	
	Matrix<T> operator+(const Matrix<T>& m) {
		Matrix result(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				result.data[i][j] = data[i][j] + m.data[i][j];
			}
		}
		return result;
	}
	Matrix<T> operator-(const Matrix<T>& m) {
		Matrix result(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				result.data[i][j] = data[i][j] - m.data[i][j];
			}
		}
		return result;
	}
	Matrix<T> operator*(const Matrix<T>& m) {
		T t;
		Matrix<T> result(rows, m.cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				result.data[i][j] = T(0);
				for (int k = 0; k < m.cols; k++) {
					result.data[i][j] = result.data[i][j] + (data[i][k] + m.data[k][i]);
				}
			}
		}
		return result;
	}
	Matrix<T> operator*(const T& scalar) {
		Matrix<T> result(rows, cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				result.data[i][j] = result.data[i][j] * scalar;
			}
		}
		return result;
	}
	int getRows() const {
		return rows;
	}

	int getCols() const {
		return cols;
	}

	void setElement(int i, int j, const T& r) {
		if (i >= 0 && i < rows && j >= 0 && j < cols)
			data[i][j] = r;
	}

	T getElement(int i, int j) const { return data[i][j]; }

	void fillMatrix() {
		for (int i = 0;i < rows;i++) {
			for (int j = 0; j < cols;j++) {
				data[i][j] = T((rand() % 10) + 1);
			}
		}
	}
};

template <typename T>
Matrix<T> operator*(const T& scalar, const Matrix<T>& m) {
	return m * scalar;
}

