#pragma once
#include <iostream>

using namespace std;

class MangSoNguyen
{
	int* dulieu; 
	int kichthuoc; 
public:
	MangSoNguyen();
	MangSoNguyen(int[], int);
	MangSoNguyen(const MangSoNguyen&);
	MangSoNguyen& operator=(const MangSoNguyen&);
	MangSoNguyen operator+(const MangSoNguyen&);
	MangSoNguyen& operator++();
	MangSoNguyen operator++(int);
	friend istream& operator>>(istream&, MangSoNguyen&);
	friend ostream& operator<<(ostream&, MangSoNguyen&);
};