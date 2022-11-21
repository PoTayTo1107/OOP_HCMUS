#include "header.h"

MangSoNguyen::MangSoNguyen() {
	dulieu = NULL;
	kichthuoc = 0;
}

MangSoNguyen::MangSoNguyen(int a[], int n) {
	dulieu = new int [n];
	kichthuoc = n;
	for (int i = 0; i < n; i++) {
		dulieu[i] = a[i];
	}
}

MangSoNguyen::MangSoNguyen(const MangSoNguyen& tmp) {
	dulieu = new int[tmp.kichthuoc];
	kichthuoc = tmp.kichthuoc;
	for (int i = 0; i < kichthuoc; i++) {
		dulieu[i] = tmp.dulieu[i];
	}
}

MangSoNguyen& MangSoNguyen::operator=(const MangSoNguyen& a) {
	this->dulieu = new int[kichthuoc];
	for (int i = 0; i <= a.kichthuoc; i++) {
		this->dulieu[i] = a.dulieu[i];
	}
	this->kichthuoc = a.kichthuoc;
	return *this;
}

MangSoNguyen MangSoNguyen::operator+(const MangSoNguyen& tmp) {
	MangSoNguyen res;
	res.kichthuoc = min(kichthuoc, tmp.kichthuoc);
	res.dulieu = new int[res.kichthuoc];
	for (int i = 0; i <= res.kichthuoc; i++) {
		res.dulieu[i] = this->dulieu[i] + tmp.dulieu[i];
	}
	return res;
}

MangSoNguyen& MangSoNguyen::operator++() {
	for (int i = 0; i < kichthuoc; i++)
		dulieu[i]++;
	return *this;
}

MangSoNguyen MangSoNguyen::operator++(int x) {
	MangSoNguyen res(*this);
	for (int i = 0; i < kichthuoc; i++)
		dulieu[i]++;
	return res;
}
istream& operator>>(istream& is, MangSoNguyen& tmp) {
	cout << "Nhap kich thuoc: ";
	is >> tmp.kichthuoc;
	for (int i = 0; i < tmp.kichthuoc; i++) {
		cout << "Nhap gia tri: ";
		is >> tmp.dulieu[i];
	}
	return is;
}
ostream& operator<<(ostream& os, MangSoNguyen& tmp) {
	os << endl;
	os << "Kich thuoc la: " << tmp.kichthuoc << endl;
	os << "Du lieu la: " << endl;
	for (int i = 0; i < tmp.kichthuoc; i++) os << tmp.dulieu[i] << endl;
	os << endl;
	return os;
}