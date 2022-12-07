#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Diem {
	int *x; //toa do X
	int *y; //toa do Y
public:
	Diem(); //Phuong thuc tao lap mac dinh
	Diem(int, int); //Phuong thuc tao lap mac dinh voi 2 tham so
	Diem& operator=(const Diem&); //Toan tu gan bang
	~Diem(); //Ham huy
	friend istream& operator>> (istream&, Diem&); // Toan tu nhap
	friend ostream& operator<< (ostream&, Diem&); // Toan tu xuat
	int getX(); // Ham lay gia tri x
	int getY(); // Ham lay gia tri y
	void setX(int); // Ham gan gia tri x
	void setY(int); // Ham gan gia tri y
};

class Quanco {
	string tenQuanco; //Ten quan co
	vector <Diem> nuocDi; //vector bieu dien nuoc di
	Diem viTri; //Vi tri hien tai cua quan co
public:
	Quanco(); //Phuong thuc tao lap mac dinh
	Quanco(string, vector<Diem>, Diem); //Phuong thuc tao lap mac dinh voi 3 tham so
	Quanco(const Quanco&); //Phuong thuc tao lap sao chep
	friend istream& operator>> (istream&, Quanco&); // Toan tu nhap
	friend ostream& operator<< (ostream&, Quanco&); // Toan tu xuat
	bool Phongcap(vector<Quanco>); // Ham phong cap
};