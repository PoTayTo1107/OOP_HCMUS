#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <iomanip>

using namespace std;

class Tugiac {
protected:
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
public:
	Tugiac();
	Tugiac(int, int, int, int, int, int, int, int);
	Tugiac(const Tugiac&);
	void Input();
	void Output();
};

class Hinhvuong:public Tugiac {
public:
	Hinhvuong();
	Hinhvuong(int, int, int, int, int, int, int, int);
	Hinhvuong(const Hinhvuong&);
	double dienTich();
	double chuVi();
	void Input();
	void Output();
};

class Hinhchunhat:public Tugiac {
public:
	Hinhchunhat();
	Hinhchunhat(int, int, int, int, int, int, int, int);
	Hinhchunhat(const Hinhchunhat&);
	double dienTich();
	double chuVi();
	void Input();
	void Output();
};

class Sach {
	string tenSach;
	int giaTien;
public:
	Sach();
	Sach(string, int);
	Sach(const Sach&);
	void Input();
	void Output();
};

class Thuvien {
	vector <Sach> danhSach;
public:
	Thuvien();
	Thuvien(vector <Sach>);
	Thuvien(const Thuvien&);
	void Input();
	void Output();
};
