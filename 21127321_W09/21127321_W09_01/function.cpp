#include "header.h"

NhanSu::NhanSu() {
	hoTen = "";
	ngay = 0;
	thang = 0;
	nam = 0;
	maSo = "";
}
NhanSu::NhanSu(const NhanSu& tmp) {
	hoTen = tmp.hoTen;
	ngay = tmp.ngay;
	thang = tmp.thang;
	nam = tmp.nam;
	maSo = tmp.maSo;
}
void NhanSu::Input()  {
	cout << "Nhap ho ten: ";
	getline(cin, hoTen);
	cout << "Nhap ngay sinh: ";
	cin >> ngay;
	cout << "Nhap thang sinh: ";
	cin >> thang;
	cout << "Nhap nam sinh: ";
	cin >> nam;
	cin.ignore();
	cout << "Nhap ma so: ";
	getline(cin, maSo);
}
string NhanSu::getId() {
	return maSo;
}
void NhanSu::Output() {
	cout << endl;
	cout << "Ho ten la: " << hoTen << endl;
	cout << "Ngay thang nam sinh la: " << ngay<< "/" << thang << "/" << nam << endl;
	cout << "Ma so la: " << maSo << endl;
}
void NhanSu::addSample(NhanSu* ns) {
	if (ns == NULL) return;
	int pos = -1;
	for (int i = 0; i < Sample.size(); i++) {
		if (Sample[i]->getSampleName() == ns->getSampleName())
			pos = i;
	}
	if (pos == -1) Sample.push_back(ns);
}
NhanSu* NhanSu::addObjectByName(string name) {
	for (int i = 0; i < Sample.size(); i++) {
		if (Sample[i]->getSampleName() == name)
			return Sample[i]->Clone();
	}
	cout << "Khong co ten doi tuong hop le\n";
	return NULL;
}
void NhanSu::deleteSample() {
	for (int i = 0; i < Sample.size(); i++) {
		delete Sample[i];
	}
}

GiangVien::GiangVien():NhanSu() {
	hocHam = "";
	hocVi = "";
	soNam = 0;
}
GiangVien::GiangVien(const GiangVien& tmp){
	NhanSu::Input();
	cout << "Nhap hoc ham: " << endl;
	getline(cin, hocHam);
	cout << "Nhap hoc vi: " << endl;
	getline(cin, hocVi);
	cout << "Nhap so nam: " << endl;
	cin >> soNam;
	int n;
	string str;
	cout << "Nhap so so mon: " << endl;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cout << "Nhap ten mon: " << endl;
		getline(cin, str);
		soMon.push_back(str);
	}
}
float GiangVien::tinhLuong() {
	return float(soMon.size() * soNam * 0.12) * 20000;
}
NhanSu* GiangVien::Clone() {
	return new GiangVien(*this);
}
string GiangVien::getSampleName() {
	return "GiangVien";
}
void GiangVien::Output() {
	NhanSu::Output();
	cout << "Hoc ham la: " << hocHam << endl;
	cout << "Hoc vi la: " << hocVi << endl;
	cout << "So nam la: " << soNam << endl;
	for (int i = 0; i < soMon.size(); i++) {
		cout << "Ten mon thu " << i + 1 << " la: " << soMon[i] << endl;
	}
}

TroGiang::TroGiang():NhanSu() {
	soMon = 0;
}
TroGiang::TroGiang(const TroGiang& tmp):NhanSu(tmp) {
	NhanSu::Input();
	cout << "Nhap so mon: " << endl;
	cin >> soMon;
	cin.ignore();
}
string TroGiang::getSampleName() {
	return "TroGiang";
}
NhanSu* TroGiang::Clone() {
	return new TroGiang(*this);
}
float TroGiang::tinhLuong() {
	return float(soMon * 0.3) * 18000;
}
void TroGiang::Output() {
	NhanSu::Output();
	cout << "So mon la: " << soMon << endl;
}

NghienCuuVien::NghienCuuVien():NhanSu() {
	soNam = 0;
}
NghienCuuVien::NghienCuuVien(const NghienCuuVien& tmp) : NhanSu(tmp) {
	NhanSu::Input();
	int n;
	string str;
	cout << "Nhap so du an: " << endl;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		do {
			cout << "Nhap ma du an: " << endl;
			getline(cin, str);
		} while ((str.size() != 3) || (!isalpha(str[0])) || (!isdigit(str[1])) || (!isdigit(str[2])));
		duAn.push_back(str);
	}
	cout << "Nhap so nam nghien cuu: " << endl;
	cin >> soNam;
	cin.ignore();
}
string NghienCuuVien::getSampleName() {
	return "NghienCuuVien";
}
NhanSu* NghienCuuVien::Clone() {
	return new NghienCuuVien(*this);
}
float NghienCuuVien::tinhLuong() {
	int count = 0;
	for (int i = 0; i < duAn.size(); i++) {
		if (duAn[i][0] == 'D') count++;
	}
	return float(soNam * 2 + count) * 20000;
}
void NghienCuuVien::Output() {
	NhanSu::Output();
	for (int i = 0; i < duAn.size(); i++) {
		cout << "Ma du an " << i + 1 << " la: " << duAn[i] << endl;
	}
	cout << "So nam nghien cuu la: " << soNam << endl;
}

ChuyenVien::ChuyenVien() :NhanSu() {
	soNam = 0;
}
ChuyenVien::ChuyenVien(const ChuyenVien& tmp):NhanSu(tmp) {
	NhanSu::Input();
	int n;
	string str;
	cout << "Nhap so du an: " << endl;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		do {
			cout << "Nhap ma du an: " << endl;
			getline(cin, str);
		} while ((str.length() != 3) || (!isalpha(str[0])) || (!isdigit(str[1])) || (!isdigit(str[2])));
		duAn.push_back(str);
	}
	cout << "Nhap so nam lam viec: " << endl;
	cin >> soNam;
	cin.ignore();
}
string ChuyenVien::getSampleName() {
	return "ChuyenVien";
}
NhanSu* ChuyenVien::Clone() {
	return new ChuyenVien(*this);
}
float ChuyenVien::tinhLuong() {
	int count = 0;
	for (int i = 0; i < duAn.size(); i++) {
		if (duAn[i][0] == 'T') count++;
	}
	return float(soNam * 4 + count) * 18000;
}
void ChuyenVien::Output() {
	NhanSu::Output();
	for (int i = 0; i < duAn.size(); i++) {
		cout << "Ma du an " << i + 1 << " la: " << duAn[i] << endl;
	}
	cout << "So nam lam viec la: " << soNam << endl;
}

ThucTapSinh::ThucTapSinh() : NhanSu() {
}
ThucTapSinh::ThucTapSinh(const ThucTapSinh& tmp) : NhanSu(tmp) {
	NhanSu::Input();
	int n;
	string str;
	cout << "Nhap so du an: " << endl;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		do {
			cout << "Nhap ma du an: " << endl;
			getline(cin, str);
		} while ((str.length() != 3) || (!isalpha(str[0])) || (!isdigit(str[1])) || (!isdigit(str[2])));
		duAn.push_back(str);
	}
}
string ThucTapSinh::getSampleName() {
	return "ThucTapSinh";
}
NhanSu* ThucTapSinh::Clone() {
	return new ThucTapSinh(*this);
}
float ThucTapSinh::tinhLuong() {
	int count = 0;
	for (int i = 0; i < duAn.size(); i++) {
		if (duAn[i][0] == 'R') count++;
	}
	return float(count * 10000 * 0.1);
}
void ThucTapSinh::Output() {
	NhanSu::Output();
	for (int i = 0; i < duAn.size(); i++) {
		cout << "Ma du an " << i + 1 << " la: " << duAn[i] << endl;
	}
}

PhongQuanLy::~PhongQuanLy() {
	for (int i = 0; i < list.size(); i++) {
		delete list[i];
	}
}
void PhongQuanLy::addMem(NhanSu* tmp) {
	list.push_back(tmp);
}
void PhongQuanLy::setMem(vector<NhanSu*> tmp) {
	list = tmp;
}
vector<NhanSu*> PhongQuanLy::getMem() {
	return list;
}