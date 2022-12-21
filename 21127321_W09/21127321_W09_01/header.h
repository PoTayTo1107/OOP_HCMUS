#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <iomanip>

using namespace std;

class NhanSu {
	static vector<NhanSu*> Sample;
protected:
	string hoTen;
	int ngay;
	int thang;
	int nam;
	string maSo;
public:
	NhanSu();
	NhanSu(const NhanSu&);
	virtual ~NhanSu() {};
	virtual float tinhLuong() = 0;
	void Input();
	virtual void Output();
	string getId();
	virtual NhanSu* Clone() = 0;
	virtual string getSampleName() = 0;
	static void addSample(NhanSu*);
	static NhanSu* addObjectByName(string);
	static void deleteSample();
};

class GiangVien : public NhanSu {
	string hocHam;
	string hocVi;
	int soNam;
	vector <string> soMon;
public:
	GiangVien();
	GiangVien(const GiangVien&);
	string getSampleName();
	NhanSu* Clone();
	float tinhLuong();
	void Output();
};

class TroGiang : public NhanSu {
	int soMon;
public:
	TroGiang();
	TroGiang(const TroGiang&);
	string getSampleName();
	NhanSu* Clone();
	float tinhLuong();
	void Output();
};

class NghienCuuVien : public NhanSu {
	vector <string> duAn;
	int soNam;
public:
	NghienCuuVien();
	NghienCuuVien(const NghienCuuVien&);
	string getSampleName();
	NhanSu* Clone();
	float tinhLuong();
	void Output();
};

class ChuyenVien : public NhanSu {
	vector <string> duAn;
	int soNam;
public:
	ChuyenVien();
	ChuyenVien(const ChuyenVien&);
	string getSampleName();
	NhanSu* Clone();
	float tinhLuong();
	void Output();
};

class ThucTapSinh : public NhanSu {
	vector <string> duAn;
public:
	ThucTapSinh();
	ThucTapSinh(const ThucTapSinh&);
	string getSampleName();
	NhanSu* Clone();
	float tinhLuong();
	void Output();
};

class PhongQuanLy {
	vector <NhanSu*> list;
public:
	PhongQuanLy() {};
	~PhongQuanLy();
	void addMem(NhanSu*);
	void setMem(vector<NhanSu*>);
	vector<NhanSu*> getMem();
};