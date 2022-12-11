#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <iomanip>

using namespace std;

class NhanSu {
	string hoTen;
	int ngay;
	int thang;
	int nam;
	string maSo;
public:
	NhanSu();
	NhanSu(string, int, int, int, string);
	NhanSu(const NhanSu&);
	virtual ~NhanSu() = 0;
	virtual float tinhLuong() = 0;
	virtual void Input();
	virtual void Output();
};

class GiangVien : public NhanSu {
	string hocHam;
	string hocVi;
	int soNam;
	vector <string> soMon;
public:
	GiangVien();
	GiangVien(string, int, int, int, string, string, string, int, vector<string>);
	GiangVien(const GiangVien&);
	~GiangVien();
	float tinhLuong();
	void Input();
	void Output();
};

class TroGiang : public NhanSu {
	int soMon;
public:
	TroGiang();
	TroGiang(string, int, int, int, string, int);
	TroGiang(const TroGiang&);
	~TroGiang();
	float tinhLuong();
	void Input();
	void Output();
};

class NghienCuuVien : public NhanSu {
	vector <string> duAn;
	int soNam;
public:
	NghienCuuVien();
	NghienCuuVien(string, int, int, int, string, vector<string>, int);
	NghienCuuVien(const NghienCuuVien&);
	~NghienCuuVien();
	float tinhLuong();
	void Input();
	void Output();
};

class ChuyenVien : public NhanSu {
	vector <string> duAn;
	int soNam;
public:
	ChuyenVien();
	ChuyenVien(string, int, int, int, string, vector<string>, int);
	ChuyenVien(const ChuyenVien&);
	~ChuyenVien();
	float tinhLuong();
	void Input();
	void Output();
};

class ThucTapSinh : public NhanSu {
	vector <string> duAn;
public:
	ThucTapSinh();
	ThucTapSinh(string, int, int, int, string, vector<string>);
	ThucTapSinh(const ThucTapSinh&);
	~ThucTapSinh();
	float tinhLuong();
	void Input();
	void Output();
};