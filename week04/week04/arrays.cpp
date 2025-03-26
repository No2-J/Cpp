#include "week04.h"

double calcTax(int income) {
	const int NumSteps = 5;
	int amount[NumSteps] = { 0, 1200, 4600, 8800, 15000 };
	double tax = 0, rate[NumSteps] = { 0.06, 0.15, 0.24, 0.35, 0.38 };

	for (int i = NumSteps - 1; i > 0; i--) {
		if (income > amount[i]) {
			tax += rate[i] * (income - amount[i]);
			income = amount[i];
		}
	}
	tax += income * rate[0];
	return tax;
}


static int findMaxValue(int a[], int len) {
	int maxVal = a[0];
	for (int i = 1; i < len; i++)
		if (maxVal < a[i]) maxVal = a[i];
	return maxVal;
}
static char findMaxChar(char a[]) {
	char maxChar = a[0];
	for (unsigned int i = 1; i < strlen(a); i++)
		if (maxChar < a[i]) maxChar = a[i];
	return maxChar;
}

void findMaxArrays() {
	int arr[10] = { 3, 24, 82, 12, 34, 7, 53, 17, 26, 51 };
	char str[] = "Game Over !";
	cout << "max val  =  " << findMaxValue(arr, 10) << endl;
	cout << "max char = " << findMaxChar(str) << endl;
}

static void printArray(const int a[], int len, const char msg[] = "Array") {
	cout << msg; // printf("%s: ", msg);
	for (int i = 0; i < len; i++)
		cout << setw(3) << a[i]; //	printf("%3d", a[i]);
	cout << endl; // printf("\n");
}
static void reverseArray(const int a[], int b[], int len) {
	for (int i = 0; i < len; i++)
		b[len - i - 1] = a[i];
}
static void reverseString(const char src[], char dst[]) {
	int len = (int)strlen(src);
	for (int i = 0; i < len; i++)
		dst[len - i - 1] = src[i];
	dst[len] = '\0';
}


void reverseArrays() {
	int a[10] = { 3, 24, 82, 12, 34, 7, 53, 17, 26, 51 };
	int b[10];
	char src[] = "Game Over !", dst[40];

	reverseArray(a, b, 10);
	reverseString(src, dst);
	printArray(a, 10, "Array a");
	printArray(b, 10, "Array b");
	cout << src << endl;
	cout << dst << endl;
}

static void print2DArray(const int a[][5], int len, const char msg[] = "Image") {
	cout << msg << endl;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++)
			cout << setw(3) << a[i][j];
		cout << endl;
	}
}

static int findMaxPixel(int a[][5], int h, int w) {
	int maxVal = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (maxVal < a[i][j])
				maxVal = a[i][j];
	return maxVal;
}

void maxPixel()
{
	int img[5][5] = { { 3, 24, 82, 12, 22 },
					{ 79,  71, 65, 73, 58 },
					{ 20,  31,  19, 48, 39 },
					{ 21,  67,  9, 99, 26 },
					{ 50,  37,  59, 47, 33 } };
	print2DArray(img, 5, "Image");
	cout << "Max pixel = " << findMaxPixel(img, 3, 5) << endl;

}

static void printScoreTable(const int a[], int len, const char msg[] = "Array") {
	cout << msg;
	for (int i = 0; i < len; i++)
		cout << setw(3) << a[i];

	cout << endl;
}
static void addDescending(int a[], int len, int val) {
	if (val > a[len - 1]) {
		a[len - 1] = val;
		for (int i = len - 1; i > 0; i--) {
			if (val < a[i - 1]) return;
			a[i] = a[i - 1];
			a[i - 1] = val;
		}
	}
}
void runAddDescending() {
	int score[5] = { 0,0,0,0,0 };
	cout << setfill(' ');
	for (int i = 0; i < 10; i++) {
		int newScore = rand() % 100;
		addDescending(score, 5, newScore);
		cout << setw(2) << "[" << newScore << "]  ";
		printScoreTable(score, 5, "Score Table");
	}
}