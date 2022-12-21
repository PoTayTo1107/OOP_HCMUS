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
	static void addSample(NhanSu* ns);
	static NhanSu* addObjectByName(string name);
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
	static vector<NhanSu*> list;
	PhongQuanLy(){}
public:
	static vector<NhanSu*> getInstance() {
		return list;
	}
	static void addInstance(NhanSu* ns) {
		list.push_back(ns);
	}
	static void deleteInstance() {
		for (int i = 0; i < list.size(); i++) {
			delete list[i];
		}
	}
	static void deleteID(string id) {
		int pos = -1;
		for (int i = 0; i < list.size(); i++) {
			if (list[i]->getId() == id) pos = i;
		}
		if (pos == -1) {
			cout << "Khong tim thay ma so!" << endl;
		}
		else {
			list.erase(list.begin() + pos);
			cout << "Xoa thanh cong!" << endl;
		}
	}
	~PhongQuanLy(){}
};