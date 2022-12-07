#include "header.h"

Tugiac::Tugiac(){
	x1 = x2 = x3 = x4 = 0;
	y1 = y2 = y3 = y4 = 0;
}
Tugiac::Tugiac(int _x1, int _x2, int _x3, int _x4, int _y1, int _y2, int _y3, int _y4) {
	x1 = x2 = x3 = x4 = 0;
	y1 = y2 = y3 = y4 = 0;
}
Tugiac::Tugiac(const Tugiac& tmp) {
	x1 = tmp.x1;
	x2 = tmp.x2;
	x3 = tmp.x3;
	x4 = tmp.x4;
	y1 = tmp.y1;
	y2 = tmp.y2;
	y3 = tmp.y3;
	y4 = tmp.y4;
}
void Tugiac::Input() {
	cout << "Nhap x1: "; cin >> x1;
	cout << "Nhap y1: "; cin >> y1;
	cout << "Nhap x2: "; cin >> x2;
	cout << "Nhap y2: "; cin >> y2;
	cout << "Nhap x3: "; cin >> x3;
	cout << "Nhap y3: "; cin >> y3;
	cout << "Nhap x4: "; cin >> x4;	
	cout << "Nhap y4: "; cin >> y4;
	cin.ignore();
}
void Tugiac::Output() {
	cout << "Diem 1: " << x1 << "," << y1 << endl;
	cout << "Diem 2: " << x2 << "," << y2 << endl;
	cout << "Diem 3: " << x3 << "," << y3 << endl;
	cout << "Diem 4: " << x4 << "," << y4 << endl;
}

Hinhvuong::Hinhvuong():Tugiac() {
}
Hinhvuong::Hinhvuong(int _x1, int _x2, int _x3, int _x4, int _y1, int _y2, int _y3, int _y4):Tugiac(_x1, _x2, _x3, _x4, _y1, _y2, _y3, _y4) {
}
Hinhvuong::Hinhvuong(const Hinhvuong& tmp):Tugiac(tmp) {
}
double Hinhvuong::dienTich() {
	double canh = double(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
	return canh * canh;
}
double Hinhvuong::chuVi() {
	double canh = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	return canh * 4;
}
void Hinhvuong::Input() {
	Tugiac::Input();
}
void Hinhvuong::Output() {
	Tugiac::Output();
	cout << "Chu vi la: " << fixed << setprecision(2) << this->chuVi() << endl;
	cout << "Dien tich la: " << fixed << setprecision(2) << this->dienTich() << endl;
}

Hinhchunhat::Hinhchunhat():Tugiac() {
}
Hinhchunhat::Hinhchunhat(int _x1, int _x2, int _x3, int _x4, int _y1, int _y2, int _y3, int _y4) : Tugiac(_x1, _x2, _x3, _x4, _y1, _y2, _y3, _y4) {
}
Hinhchunhat::Hinhchunhat(const Hinhchunhat& tmp):Tugiac(tmp) {
}
double Hinhchunhat::dienTich() {
	double canh1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	double canh2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	return canh1 * canh2;
}
double Hinhchunhat::chuVi() {
	double canh1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	double canh2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	return (canh1 + canh2) * 2;
}
void Hinhchunhat::Input() {
	Tugiac::Input();
}
void Hinhchunhat::Output() {
	Tugiac::Output();
	cout << "Chu vi la: " << fixed << setprecision(2) << this->chuVi() << endl;
	cout << "Dien tich la: " << fixed << setprecision(2) << this->dienTich() << endl;
}

Sach::Sach() {
	tenSach = "";
	giaTien = 0;
}
Sach::Sach(string _tenSach, int _giaTien) {
	tenSach = _tenSach;
	giaTien = _giaTien;
}
Sach::Sach(const Sach& tmp) {
	tenSach = tmp.tenSach;
	giaTien = tmp.giaTien;
}
void Sach::Input() {
	cout << "Nhap ten sach: " << endl;
	getline(cin, tenSach);
	cout << "Nhap gia tien: " << endl;
	cin >> giaTien;
	cin.ignore();
}
void Sach::Output() {
	cout << "Ten sach la: " << tenSach << endl;
	cout << "Gia tien sach la: " << giaTien << endl;
}

Thuvien::Thuvien(){
}
Thuvien::Thuvien(vector <Sach> _danhSach) {
	danhSach = _danhSach;
}
Thuvien::Thuvien(const Thuvien& tmp) {
	danhSach = tmp.danhSach;
}
void Thuvien::Input() {
	int n;
	cout << "Nhap so luong sach: " << endl;
	cin >> n;
	cin.ignore();
	Sach sach;
	for (int i = 0; i < n; i++) {
		sach.Input();
		danhSach.push_back(sach);
	}
}
void Thuvien::Output() {
	for (int i = 0; i < danhSach.size(); i++) {
		danhSach[i].Output();
	}
}