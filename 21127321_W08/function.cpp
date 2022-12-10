#include "header.h"

NhanSu::NhanSu() {
	hoTen = "";
	ngay = 0;
	thang = 0;
	nam = 0;
	maSo = "";
}
NhanSu::NhanSu(string _hoTen, int _ngay, int _thang, int _nam, string _maSo) {
	hoTen = _hoTen;
	ngay = _ngay;
	thang = _thang;
	nam = _nam;
	maSo = _maSo;
}
NhanSu::NhanSu(const NhanSu& tmp) {
	hoTen = tmp.hoTen;
	ngay = tmp.ngay;
	thang = tmp.thang;
	nam = tmp.nam;
	maSo = tmp.maSo;
}
NhanSu::~NhanSu() {}
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
void NhanSu::Output() {
	cout << endl;
	cout << "Ho ten la: " << hoTen << endl;
	cout << "Ngay thang nam sinh la: " << ngay<< "/" << thang << "/" << nam << endl;
	cout << "Ma so la: " << maSo << endl;
}

GiangVien::GiangVien():NhanSu() {
	hocHam = "";
	hocVi = "";
	soNam = 0;
}
GiangVien::GiangVien(string _hoTen, int _ngay, int _thang, int _nam, string _maSo, string _hocHam, string _hocVi, int _soNam, vector<string> _soMon):NhanSu(_hoTen, _ngay, _thang, _nam, _maSo) {
	hocHam = _hocHam;
	hocVi = _hocVi;
	soNam = _soNam;
	soMon = _soMon;
}
GiangVien::GiangVien(const GiangVien& tmp):NhanSu(tmp){
	hocHam = tmp.hocHam;
	hocVi = tmp.hocVi;
	soNam = tmp.soNam;
	soMon = tmp.soMon;
}
GiangVien::~GiangVien() {}
float GiangVien::tinhLuong() {
	return float(soMon.size() * soNam * 0.12) * 20000;
}
void GiangVien::Input() {
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
TroGiang::TroGiang(string _hoTen, int _ngay, int _thang, int _nam, string _maSo, int _soMon):NhanSu(_hoTen, _ngay, _thang, _nam, _maSo) {
	soMon = _soMon;
}
TroGiang::TroGiang(const TroGiang& tmp):NhanSu(tmp) {
	soMon = tmp.soMon;
}
TroGiang::~TroGiang() {}
float TroGiang::tinhLuong() {
	return float(soMon * 0.3) * 18000;
}
void TroGiang::Input() {
	NhanSu::Input();
	cout << "Nhap so mon: " << endl;
	cin >> soMon;
	cin.ignore();
}
void TroGiang::Output() {
	NhanSu::Output();
	cout << "So mon la: " << soMon << endl;
}

NghienCuuVien::NghienCuuVien():NhanSu() {
	soNam = 0;
}
NghienCuuVien::NghienCuuVien(string _hoTen, int _ngay, int _thang, int _nam, string _maSo, vector<string> _duAn, int _soNam):NhanSu(_hoTen, _ngay, _thang, _nam, _maSo) {
	duAn = _duAn;
	soNam = _soNam;
}
NghienCuuVien::NghienCuuVien(const NghienCuuVien& tmp):NhanSu(tmp) {
	duAn = tmp.duAn;
	soNam = tmp.soNam;
}
NghienCuuVien::~NghienCuuVien() {}
float NghienCuuVien::tinhLuong() {
	int count = 0;
	for (int i = 0; i < duAn.size(); i++) {
		if (duAn[i][0] == 'D') count++;
	}
	return float(soNam * 2 + count) * 20000;
}
void NghienCuuVien::Input() {
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
ChuyenVien::ChuyenVien(string _hoTen, int _ngay, int _thang, int _nam, string _maSo, vector<string> _duAn, int _soNam) : NhanSu(_hoTen, _ngay, _thang, _nam, _maSo) {
	duAn = _duAn;
	soNam = _soNam;
}
ChuyenVien::ChuyenVien(const ChuyenVien& tmp):NhanSu(tmp) {
	duAn = tmp.duAn;
	soNam = tmp.soNam;
}
ChuyenVien::~ChuyenVien(){}
float ChuyenVien::tinhLuong() {
	int count = 0;
	for (int i = 0; i < duAn.size(); i++) {
		if (duAn[i][0] == 'T') count++;
	}
	return float(soNam * 4 + count) * 18000;
}
void ChuyenVien::Input() {
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
		} while ( (str.length() != 3) || (!isalpha(str[0])) || (!isdigit(str[1])) || (!isdigit(str[2])) );
		duAn.push_back(str);
	}
	cout << "Nhap so nam lam viec: " << endl;
	cin >> soNam;
	cin.ignore();
}
void ChuyenVien::Output() {
	NhanSu::Output();
	for (int i = 0; i < duAn.size(); i++) {
		cout << "Ma du an " << i + 1 << " la: " << duAn[i] << endl;
	}
	cout << "So nam lam viec la: " << soNam << endl;
}

ThucTapSinh::ThucTapSinh() :NhanSu() {
}
ThucTapSinh::ThucTapSinh(string _hoTen, int _ngay, int _thang, int _nam, string _maSo, vector<string> _duAn) : NhanSu(_hoTen, _ngay, _thang, _nam, _maSo) {
	duAn = _duAn;
}
ThucTapSinh::ThucTapSinh(const ThucTapSinh& tmp) : NhanSu(tmp) {
	duAn = tmp.duAn;
}
ThucTapSinh::~ThucTapSinh() {}
float ThucTapSinh::tinhLuong() {
	int count = 0;
	for (int i = 0; i < duAn.size(); i++) {
		if (duAn[i][0] == 'R') count++;
	}
	return float(count * 10000 * 0.1);
}
void ThucTapSinh::Input() {
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
void ThucTapSinh::Output() {
	NhanSu::Output();
	for (int i = 0; i < duAn.size(); i++) {
		cout << "Ma du an " << i + 1 << " la: " << duAn[i] << endl;
	}
}