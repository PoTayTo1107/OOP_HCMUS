#include "header.h"

Diem::Diem() {
	x = new int;
	y = new int;
	*x = 0;
	*y = 0;
}

Diem::Diem(int _x, int _y) {
	x = new int;
	y = new int;
	*x = _x;
	*y = _y;
}

Diem::~Diem(){
	delete x;
	delete y;
}

int Diem::getX() {
	return *x;
}

int Diem::getY() {
	return *y;
}

void Diem::setX(int _x) {
	*x = _x;
}

void Diem::setY(int _y) {
	*y = _y;
}

Diem& Diem::operator=(const Diem& tmp) {
	x = new int;
	y = new int;
	*this->x = *tmp.x;
	*this->y = *tmp.y;
	return *this;
}

istream& operator>> (istream& is, Diem& tmp) {
	tmp.x = new int;
	tmp.y = new int;
	cout << "Nhap toa do x: ";
	is >> *tmp.x;
	cout << "Nhap toa do y: ";
	is >> *tmp.y;
	return is;
}

ostream& operator<< (ostream& os, Diem& tmp) {
	os << "Toa do x: " << *tmp.x << endl;
	os << "Toa do y: " << *tmp.y << endl;
	return os;
}

Quanco::Quanco() {
	tenQuanco = "";
	Diem tmp(0, 0);
	viTri = tmp;
}

Quanco::Quanco(string _tenQuanco, vector<Diem> _nuocDi, Diem _viTri) {
	tenQuanco = _tenQuanco;
	nuocDi = _nuocDi;
	viTri.setX(_viTri.getX());
	viTri.setY(_viTri.getY());
}

Quanco::Quanco(const Quanco& tmp) {
	tenQuanco = tmp.tenQuanco;
	nuocDi = tmp.nuocDi;
	viTri = tmp.viTri;
}

istream& operator>> (istream& is, Quanco& tmp) {
	int n;
	cout << "Nhap ten quan co: ";
	is >> tmp.tenQuanco;
	cout << "Nhap vi tri quan co: " << endl;
	cin >> tmp.viTri;
	cout << "Nhap so diem bieu dien buoc di: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp.nuocDi[i] ;
	}
	return is;
}

ostream& operator<< (ostream& os, Quanco& tmp) {
	os << "Ten quan co: " << tmp.tenQuanco << endl;
	os << "Vi tri quan co: " << endl;
	os << tmp.viTri;
	return os;
}

bool Quanco::Phongcap(vector<Quanco> doiThu) {
	int minn = 99999999, num = 99999999;
	if (this->viTri.getY() == 7 && this->viTri.getX() >= 0 && this->viTri.getX() <= 7) {
		for (int i = 0; i < doiThu.size(); i++) {
			// Tinh khoang cach theo cong thuc Euclidean
			int khoangCach = sqrt(
				(this->viTri.getX() - doiThu[i].viTri.getX()) * (this->viTri.getX() - doiThu[i].viTri.getX())
				+ (this->viTri.getY() - doiThu[i].viTri.getY()) * (this->viTri.getY() - doiThu[i].viTri.getY()));
			if (khoangCach < minn) {
				minn = khoangCach;
				num = i;
			}
		}
		this->nuocDi = doiThu[num].nuocDi;
		return true;
	}
	else return false;
}