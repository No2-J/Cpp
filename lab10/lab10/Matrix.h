//Matrix.h
#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "Rational.h"
using namespace std;

class Matrix {
private:
	Rational** data;
	int rows, cols;
	void deallocate() {
		for (int i = 0;i < rows; i++)
			delete[] data[i];
		delete[] data;
	}
public:
	Matrix(int r = 3, int c = 3) :rows(r), cols(c), data(nullptr) {
		data = new Rational * [rows];
		for (int i = 0;i < rows; i++)
			data[i] = new Rational[cols];
	}
	~Matrix() {
		deallocate();
	}

	void clone(const Matrix& m) {
		if (data) {
			deallocate();
		}
		rows = m.rows;
		cols = m.cols;
		data = new Rational * [rows];
		for (int i = 0;i < rows;i++) {
			data[i] = new Rational[cols];
			for (int j = 0; j < cols;j++) {
				data[i][j] = m.data[i][j];
			}
		}
	}
	Matrix(const Matrix& m) {
		clone(m);
	}

	Matrix& operator=(const Matrix& m){
		//if (this == &m) return *this;
		clone(m);
		return *this;
	}

	void fillMatrix() {
		for (int i = 0;i < rows;i++) {
			for (int j = 0; j < cols;j++) {
				data[i][j] = Rational((rand()%10)+1, (rand()%10)+1);
			}
		}
	}

	int getRows() const {
		return rows;
	}

	int getCols() const {
		return cols;
	}

	void setElement(int i, int j, const Rational& r) {
		if (i >= 0 && i < rows && j >= 0 && j < cols)
			data[i][j] = r;
	}

	Rational getElement(int i, int j) const {
		if (i >= 0 && i < rows && j >= 0 && j < cols)
			return data[i][j];
		return Rational(); // 범위 벗어난 경우 기본 Rational 반환
	}

	friend ostream& operator <<(ostream & os, const Matrix & m) {
		for (int i = 0;i < m.rows;i++) {
			for (int j = 0; j < m.cols;j++) {
				os << m.data[i][j] << "\t";
			}
			cout << endl;
		}
		return os;
	}
	friend istream& operator >>(istream & is, Matrix & m) {
		for (int i = 0;i < m.rows;i++) {
			for (int j = 0; j < m.cols;j++) {
				cout << "Element " << "[" << i << "]" << "[" << j << "] : ";
				is >> m.data[i][j];
			}
		}
		return is;
	}
	Matrix operator+(const Matrix& other) const {
		Matrix result(rows, cols);
		for (int i = 0;i < rows;i++)
			for (int j = 0;j < cols; ++j)
				result.data[i][j] = data[i][j] + other.data[i][j];
		return result;

	}
	Matrix operator-(const Matrix& other) const {
		Matrix result(rows, cols);
		for (int i = 0;i < rows;i++)
			for (int j = 0;j < cols; ++j)
				result.data[i][j] = data[i][j] - other.data[i][j];
		return result;

	}
	Matrix operator*(const Matrix& other) const {
		if (cols != other.rows) {
			cerr << "Error : Matrix size mismatch for mul\n";
			return Matrix(0, 0);
		}
		Matrix result(rows, cols);
		for (int i = 0;i < rows;i++)
			for (int j = 0;j < cols; ++j) {
				result.data[i][j] = Rational();
				for (int k = 0;k < cols;k++) {
					result.data[i][j] = result.data[i][j] + (data[i][k] * other.data[k][j]);
				}
			}
		return result;

	}

	Matrix operator*(const Rational& scalar) const {
		Matrix result(rows, cols);
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				result.data[i][j] = data[i][j] * scalar;
		return result;
	}
};

