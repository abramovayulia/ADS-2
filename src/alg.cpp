// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <iostream>
using namespace std;

double pown(double value, uint16_t n) {
	if (n == 0) {
		return 1;
	}
	else {
		return value * pown(value, n-1);
	}
}

uint64_t fact(uint16_t n) {
	if ((n == 1) || (n == 0)) {
		return 1;
	} else {
		return n * fact(n - 1);
	}
}

double calcItem(double x, uint16_t n) {
	return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
	double sum = 1.0;
	for (count; count > 0; count--) {
		sum += calcItem(x,count);
	}
	return sum;
}

double sinn(double x, uint16_t count) {
	double sum = 0;
	for (count; count > 0; count--) {
		sum += pown(-1, count-1) * calcItem(x, 2*count-1);
	}
	return sum;
}

ddouble cosn(double x, uint16_t count) {
	double sum = 0;
	for (count; count > 0; count--) {
		sum += pown(-1, count-1) * calcItem(x, 2*count-2);
	}
	return sum;
}


int main() {
	setlocale(LC_ALL, "RU");
	double value;
	uint16_t n = 0;
	cin >> value >> n;
	cout << "Степень числа " << value << " = " << pown(value, n) << endl;
	cout << "Факториал " << n << " = " << fact(n) << endl;
	cout << "Экспонента " << " = " << expn(value, n) << endl;
	cout << "Синус " << " = " << sinn(value, n) << endl;
	cout << "Косинус " << " = " << cosn(value, n) << endl;
}
