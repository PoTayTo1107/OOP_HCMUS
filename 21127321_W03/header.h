#pragma once
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

class NhanVien {
	string name;
	int date;
	string id;
	string job;
	float salary;

public:
	NhanVien();
	NhanVien(string, int, string, string, float);
	NhanVien(string, int);
	NhanVien(const NhanVien& temp);
	~NhanVien();

	string getName();
	int getDate();
	string getId();
	string getJob();
	float getSalary();
	void setName(string Name);
	void setDate(int Date);
	void setId(string Id);
	void setJob(string Job);
	void setSalary(float Salary);
	void Input();
	void Output();
};