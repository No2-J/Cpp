#include "week04.h"

struct Complex {
	double	real;
	double	imag;
};
static void printComplex(Complex c, const char* msg = "Complex Number : ") {
	cout << setprecision(2);
	cout << msg << c.real << " + " << c.imag << "i" << endl;
	//printf("  %s %4.2f + %4.2fi\n", msg, c.real, c.imag);
}
static Complex readComplex(const char* msg = "Enter Complex Number :") {
	Complex c;
	cout << msg;
	cin >> c.real >> c.imag;
	//printf("  %s ", msg);
	//scanf_s("%lf%lf", &c.real, &c.imag);
	return c;
}
static Complex addComplex(Complex a, Complex b) {
	Complex c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;
}
static void resetComplex(Complex a) {
	a.real = a.imag = 0.0;
}

void useComlex()
{
	Complex a, b, c;
	a = readComplex("a(real imag) = ");
	b = readComplex("b(real imag) = ");
	c = addComplex(a, b);
	printComplex(a, "    a   =");
	printComplex(b, "    b   =");
	printComplex(c, "   a+b  =");
	resetComplex(c);
	printComplex(c, "reset(c)=");	// ???

}


void structExamples() {
	struct Point2D {
		double x = 0.0;
		double y = 0.0;
	};
	struct Point3D {
		double x = 0.0;
		double y = 0.0;
		double z = 0.0;
	};

	struct Person
	{
		char name[50];
		int age;
		float salary;
	};
	Point2D p1;
	Point2D p2 = { 1.1,2.2 };
	cout << fixed << setprecision(1);
	cout << "p1 : default x = " << p1.x << ", default y = " << p1.y << endl;
	cout << "p2 : x = " << p2.x << ", y = " << p2.y << endl;
	p1.x = 3.4;
	p1.y = 5.5;
	cout << "p1 : modified x = " << p1.x << ", modified y = " << p1.y << endl;
	p2.x = 13.4;
	p2.y = 15.5;
	cout << "p2 : x = " << p2.x << ", y = " << p2.y << endl;

	Point3D p11;
	Point3D p12 = { 1.1,2.2 ,3.3 };
	cout << "p1 : default x = " << p11.x << ", default y = " << p11.y << ", default z = " << p11.z << endl;
	cout << "p2 : x = " << p12.x << ", y = " << p12.y << ", z = " << p12.z << endl;
	p11.x = 3.4;
	p11.y = 5.5;
	p11.z = 6.5;
	cout << "p11 : modified x = " << p11.x << ", modified y = " << p11.y << ", modified z = " << p12.y << endl;
	p12.x = 13.4;
	p12.y = 15.5;
	p12.y = 25.5;
	cout << "p12 : x = " << p2.x << ", y = " << p12.y << ", z = " << p12.z << endl;

	Person p31 = { "abc", 45, 2000.5 };
	cout << "\nDisplaying Information." << endl;
	cout << "Name: " << p31.name << endl;
	cout << "Age: " << p31.age << endl;
	cout << "Salary: " << p31.salary;
}

