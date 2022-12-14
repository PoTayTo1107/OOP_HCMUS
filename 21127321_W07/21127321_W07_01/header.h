#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <iomanip>

using namespace std;

class Nhansu {
	string hoTen;
	int ngay;
	int thang;
	int nam;
	string maSo;
public:
	Nhansu();
	Nhansu(string, int, int, int, string);
	Nhansu(const Nhansu&);
	~Nhansu();
	void Input();
	void Output();
};

class Giangvien : public Nhansu {
	string hocHam;
	string hocVi;
	int soNam;
	vector <string> soMon;
public:
	Giangvien();
	Giangvien(string, int, int, int, string, string, string, int, vector<string>);
	Giangvien(const Giangvien&);
	~Giangvien();
	float tinhLuong();
	void Input();
	void Output();
};

class Trogiang : public Nhansu {
	int soMon;
public:
	Trogiang();
	Trogiang(string, int, int, int, string, int);
	Trogiang(const Trogiang&);
	~Trogiang();
	float tinhLuong();
	void Input();
	void Output();
};

class Nghiencuuvien : public Nhansu {
	vector <string> duAn;
	int soNam;
public:
	Nghiencuuvien();
	Nghiencuuvien(string, int, int, int, string, vector<string>, int);
	Nghiencuuvien(const Nghiencuuvien&);
	~Nghiencuuvien();
	float tinhLuong();
	void Input();
	void Output();
};

class Chuyenvien : public Nhansu {
	vector <string> duAn;
	int soNam;
public:
	Chuyenvien();
	Chuyenvien(string, int, int, int, string, vector<string>, int);
	Chuyenvien(const Chuyenvien&);
	~Chuyenvien();
	float tinhLuong();
	void Input();
	void Output();
};