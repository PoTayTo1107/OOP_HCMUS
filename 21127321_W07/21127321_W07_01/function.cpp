#include "header.h"

Nhansu::Nhansu() {
	hoTen = "";
	ngay = 0;
	thang = 0;
	nam = 0;
	maSo = "";
}
Nhansu::Nhansu(string _hoTen, int _ngay, int _thang, int _nam, string _maSo) {
	hoTen = _hoTen;
	ngay = _ngay;
	thang = _thang;
	nam = _nam;
	maSo = _maSo;
}
Nhansu::Nhansu(const Nhansu& tmp) {
	hoTen = tmp.hoTen;
	ngay = tmp.ngay;
	thang = tmp.thang;
	nam = tmp.nam;
	maSo = tmp.maSo;
}
Nhansu::~Nhansu() {}
void Nhansu::Input()  {
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
void Nhansu::Output() {
	cout << endl;
	cout << "Ho ten la: " << hoTen << endl;
	cout << "Ngay thang nam sinh la: " << ngay<< "/" << thang << "/" << nam << endl;
	cout << "Ma so la: " << maSo << endl;
}

Giangvien::Giangvien():Nhansu() {
	hocHam = "";
	hocVi = "";
	soNam = 0;
}
Giangvien::Giangvien(string _hoTen, int _ngay, int _thang, int _nam, string _maSo, string _hocHam, string _hocVi, int _soNam, vector<string> _soMon):Nhansu(_hoTen, _ngay, _thang, _nam, _maSo) {
	hocHam = _hocHam;
	hocVi = _hocVi;
	soNam = _soNam;
	soMon = _soMon;
}
Giangvien::Giangvien(const Giangvien& tmp):Nhansu(tmp){
	hocHam = tmp.hocHam;
	hocVi = tmp.hocVi;
	soNam = tmp.soNam;
	soMon = tmp.soMon;
}
Giangvien::~Giangvien() {}
float Giangvien::tinhLuong() {
	return float(soMon.size() * soNam * 0.12) * 20000;
}
void Giangvien::Input() {
	Nhansu::Input();
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
void Giangvien::Output() {
	Nhansu::Output();
	cout << "Hoc ham la: " << hocHam << endl;
	cout << "Hoc vi la: " << hocVi << endl;
	cout << "So nam la: " << soNam << endl;
	for (int i = 0; i < soMon.size(); i++) {
		cout << "Ten mon thu " << i << " la: " << soMon[i] << endl;
	}
}

Trogiang::Trogiang():Nhansu() {
	soMon = 0;
}
Trogiang::Trogiang(string _hoTen, int _ngay, int _thang, int _nam, string _maSo, int _soMon):Nhansu(_hoTen, _ngay, _thang, _nam, _maSo) {
	soMon = _soMon;
}
Trogiang::Trogiang(const Trogiang& tmp):Nhansu(tmp) {
	soMon = tmp.soMon;
}
Trogiang::~Trogiang() {}
float Trogiang::tinhLuong() {
	return float(soMon * 0.3) * 18000;
}
void Trogiang::Input() {
	Nhansu::Input();
	cout << "Nhap so mon: " << endl;
	cin >> soMon;
	cin.ignore();
}
void Trogiang::Output() {
	Nhansu::Output();
	cout << "So mon la: " << soMon << endl;
}

Nghiencuuvien::Nghiencuuvien():Nhansu() {
	soNam = 0;
}
Nghiencuuvien::Nghiencuuvien(string _hoTen, int _ngay, int _thang, int _nam, string _maSo, vector<string> _duAn, int _soNam):Nhansu(_hoTen, _ngay, _thang, _nam, _maSo) {
	duAn = _duAn;
	soNam = _soNam;
}
Nghiencuuvien::Nghiencuuvien(const Nghiencuuvien& tmp):Nhansu(tmp) {
	duAn = tmp.duAn;
	soNam = tmp.soNam;
}
Nghiencuuvien::~Nghiencuuvien() {}
float Nghiencuuvien::tinhLuong() {
	int count = 0;
	for (int i = 0; i < duAn.size(); i++) {
		if (duAn[i][0] == 'D') count++;
	}
	return float(soNam * 2 + count) * 20000;
}
void Nghiencuuvien::Input() {
	Nhansu::Input();
	int n;
	string str;
	cout << "Nhap so du an: " << endl;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cout << "Nhap ten du an: " << endl;
		getline(cin, str);
		duAn.push_back(str);
	}
	cout << "Nhap so nam nghien cuu: " << endl;
	cin >> soNam;
	cin.ignore();
}
void Nghiencuuvien::Output() {
	Nhansu::Output();
	for (int i = 0; i < duAn.size(); i++) {
		cout << "Ten du an " << i << " la: " << duAn[i] << endl;
	}
	cout << "So nam nghien cuu la: " << soNam << endl;
}

Chuyenvien::Chuyenvien() :Nhansu() {
	soNam = 0;
}
Chuyenvien::Chuyenvien(string _hoTen, int _ngay, int _thang, int _nam, string _maSo, vector<string> _duAn, int _soNam) : Nhansu(_hoTen, _ngay, _thang, _nam, _maSo) {
	duAn = _duAn;
	soNam = _soNam;
}
Chuyenvien::Chuyenvien(const Chuyenvien& tmp):Nhansu(tmp) {
	duAn = tmp.duAn;
	soNam = tmp.soNam;
}
Chuyenvien::~Chuyenvien(){}
float Chuyenvien::tinhLuong() {
	int count = 0;
	for (int i = 0; i < duAn.size(); i++) {
		if (duAn[i][0] == 'T') count++;
	}
	return float(soNam * 4 + count) * 18000;
}
void Chuyenvien::Input() {
	Nhansu::Input();
	int n;
	string str;
	cout << "Nhap so du an: " << endl;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cout << "Nhap ten du an: " << endl;
		getline(cin, str);
		duAn.push_back(str);
	}
	cout << "Nhap so nam lam viec: " << endl;
	cin >> soNam;
	cin.ignore();
}
void Chuyenvien::Output() {
	Nhansu::Output();
	for (int i = 0; i < duAn.size(); i++) {
		cout << "Ten du an " << i << " la: " << duAn[i] << endl;
	}
	cout << "So nam lam viec la: " << soNam << endl;
}