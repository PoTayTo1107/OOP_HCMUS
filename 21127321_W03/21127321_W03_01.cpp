#include "header.h"

int main() {
	NhanVien nv1;
	NhanVien nv2("Khoa", 10, "10Khoa", "Nhan Vien", 1.0);
	NhanVien nv3("Anh", 365);
	NhanVien nv4(nv3);
	NhanVien nv5;
	nv4.Input();
	nv1.Output();
	nv2.Output();
	nv3.Output();
	nv4.Output();
	nv5.Output();
}