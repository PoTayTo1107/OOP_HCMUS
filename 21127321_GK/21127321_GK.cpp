#include "header.h"

int main() {
	Diem diem0;
	cout << "Phuong thuc tao lap mac dinh : " << endl;
	cout << diem0;

	Diem diem1(1, 1);
	cout << "Phuong thuc tao lap voi 2 tham so : " << endl;
	cout << diem1;

	Diem diem2;
	cout << "Su dung toan tu nhap va xuat" << endl;
	cin >> diem2;
	cout << diem2;
	
	cout << endl;

	Quanco quanco0;
	cout << "Phuong thuc tao lap mac dinh : " << endl;
	cout << quanco0;
	
	vector<Diem> tmp;
	Quanco quanco1("Xe", tmp, diem1);
	cout << "Phuong thuc tao lap voi 3 tham so : " << endl;
	cout << diem1;

	Quanco quanco2(quanco1);
	cout << "Phuong thuc tao lap sao chep: ";
	cout << quanco2;

	Quanco quanco3;
	cout << "Su dung toan tu nhap va xuat" << endl;
	cin >> diem2;
	cout << diem2;

	vector<Quanco> keThu;
	keThu.push_back(quanco2);
	cout << "Ham kiem tra quan co vua nhap co duoc phong cap hay khong" << endl;
	if (quanco3.Phongcap(keThu)) cout << "Da phong cap"; 
		else cout << "Khong duoc phong cap";
}
