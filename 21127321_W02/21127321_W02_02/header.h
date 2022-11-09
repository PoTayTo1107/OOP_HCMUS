#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Hocsinh {
	string Hoten, Sdt;
	float Dtb;

public:
	void InputC();
	void Input();
	void Output();
	string getHoten();
	float getDtb();
};

class Lophoc {
	vector <Hocsinh> Danhsach;

public:
	void Add();
	void Remove();
	void Sort();
	void Output();
	void Input();
};