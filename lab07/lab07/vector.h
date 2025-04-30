#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class Vector;
class Vector {
private:
	int dim;
	double* arr;
public:
    Vector() : dim(0), arr(nullptr) {}

	Vector(int d): dim(d), arr(nullptr) {
		arr = new double[dim];
	}
	/*Vector(const Vector& c): dim(c.dim), arr(c.arr) {
		dim = c.dim;
		arr = c.arr;
	}*/
	Vector(const Vector& c): dim(c.dim) {
		arr = new double[dim];
		for (int i = 0;i < dim;i++)
			arr[i] = c.arr[i];
	}
	~Vector() {
		if (arr) {
			delete[] arr;
		}
	}

    // Print the vector
    void print(const char* str = "Vector") const {
        cout << str << "[" << dim << "] = < ";
        for (int i = 0; i < dim; i++)
            cout << arr[i] << " ";
        cout << ">\n";
    }

    // Length (magnitude) of the vector
    double length() const {
        double sum = 0.0;
        for (int i = 0; i < dim; ++i)
            sum += arr[i] * arr[i];
        return sqrt(sum);
    }

    // Dot product
    double dot(const Vector& other) const {
        if (dim != other.dim) {
            cerr << "Error: Dot product dimension mismatch!\n";
            return 0.0;
        }
        double result = 0.0;
        for (int i = 0; i < dim; ++i)
            result += arr[i] * other.arr[i];
        return result;
    }

    // Cross product (only for 3D vectors)
    Vector cross(const Vector& other) const {
        if (this ->dim != 3 || other.dim != 3) {
            cerr << "Error: Cross product requires 3D vectors!\n";
            return Vector();
        }
        Vector result(3);
        result.arr[0] = arr[1] * other.arr[2] - arr[2] * other.arr[1];
        result.arr[1] = arr[2] * other.arr[0] - arr[0] * other.arr[2];
        result.arr[2] = arr[0] * other.arr[1] - arr[1] * other.arr[0];
        return result;
    }


    double get(int idx) const {
        if (idx < 0 || idx >= dim) {
            cerr << "Error: Index out of range!\n";
            return 0.0;
        }
        return arr[idx];
    }

    //Set random values
    void setRand() {
        
        for (int i = 0;i < dim;i++)
            arr[i] = (rand() % 100)/10;
    }
};