#include "header.h"

NhanVien::NhanVien() {
	name = "name";
	date = 0;
	id = "id";
	job = "job";
	salary = 0;
}

NhanVien::NhanVien(string Name, int Date, string Id, string Job, float Salary) {
	name = Name;
	date = Date;
	id = Id;
	job = Job;
	salary = Salary;
}

NhanVien::NhanVien(string Name, int Date) {
	name = Name;
	date = Date;

	id = to_string(Date) + name;

	if (date >= 0 && date < 365) {
		job = "Nhan Vien";
		salary = 1.0;
	}
	else if (date >= 365 && date < 730) {
		job = "Quan ly";
		salary = 1.5;
	}
	else if (date >= 730 && date < 1460) {
		job = "Truong phong";
		salary = 2.25;
	}
	else if (date >= 1460) {
		job = "Truong ban quan ly";
		salary = 4.0;
	}
}

NhanVien::NhanVien(const NhanVien& temp) {
	job = temp.job;
	date = temp.date;
	salary = temp.salary;
	name = "name";
	id = "id";
}

NhanVien::~NhanVien(){}

string NhanVien::getName() {
	return name;
}

int NhanVien::getDate() {
	return date;
}

string NhanVien::getId() {
	return id;
}

string NhanVien::getJob() {
	return job;
}

float NhanVien::getSalary() {
	return salary;
}

void NhanVien::setName(string Name) {
	name = Name;
}

void NhanVien::setDate(int Date) {
	date = Date;
}

void NhanVien::setId(string Id) {
	id = Id;
}

void NhanVien::setJob(string Job) {
	job = Job;
}

void NhanVien::setSalary(float Salary) {
	salary = Salary;
}

void NhanVien::Input() {
	cout << "Nhap ho va ten: \n";
	getline(cin, name);
	cout << "Nhap so ngay lam viec: \n";
	cin >> date;
	cout << "Nhap ma so nhan vien: \n";
	cin.ignore();
	getline(cin, id);
	cout << "Nhap chuc danh nhan vien: \n";
	getline(cin, job);
	cout << "Nhap he so luong: \n";
	cin >> salary;

}

void NhanVien::Output() {
	cout << "Ho va ten: " << name << '\n';
	cout << "So ngay lam viec: " << date << '\n';
	cout << "Ma so nhan vien: " << id << '\n';
	cout << "Chuc danh nhan vien: " << job << '\n';
	cout << "He so luong: " << salary << '\n' << '\n';
}