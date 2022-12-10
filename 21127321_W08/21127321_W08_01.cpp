#include "header.h"

int main() {
	vector <NhanSu*> danhSach;
	NhanSu* ns;

	int opt;
	do {
		cout << "Chon nhan su can nhap" << endl;
		cout << "1. Giang vien" << endl;
		cout << "2. Tro giang" << endl;
		cout << "3. Nghien cuu vien" << endl;
		cout << "4. Chuyen vien" << endl;
		cout << "5. Tinh tong luong" << endl;
		cout << "6. Xuat danh sach nhan su" << endl;
		cout << "7. Luong cua nhan su co luong cao nhat" << endl;
		cout << "Bat ky ky tu nao khac de thoat" << endl;

		cin >> opt;
		cin.ignore();

		switch (opt)
		{
		case 1: {
			ns = new GiangVien;
			ns->Input();
			ns->Output();
			danhSach.push_back(ns);
			break;
		}
		case 2: {
			ns = new TroGiang;
			ns->Input();
			ns->Output();
			danhSach.push_back(ns);
			break;
		}
		case 3: {
			ns = new NghienCuuVien;
			ns->Input();
			ns->Output();
			danhSach.push_back(ns);
			break;
		}
		case 4: {
			ns = new ChuyenVien;
			ns->Input();
			ns->Output();
			danhSach.push_back(ns);
			break;
		}
		case 5: {
			float tongLuong = 0;
			for (int i = 0; i < danhSach.size(); i++) {
				tongLuong += danhSach[i]->tinhLuong();
			}
			cout << "Tong luong can chi tra la: ";
			cout << fixed << setprecision(2) << tongLuong << endl;
			break;
		}
		case 6: {
			for (int i = 0; i < danhSach.size(); i++) {
				cout << "Nhan su thu " << i + 1 << " :";
				danhSach[i]->Output();
			}
			break;
		}
		case 7: {
			float maxx = 0;
			for (int i = 0; i < danhSach.size(); i++) {
				if (danhSach[i]->tinhLuong() > maxx) maxx = danhSach[i]->tinhLuong();
			}
			cout << "Luong cua nhan su co luong cao nhat la:  ";
			cout << fixed << setprecision(2) << maxx << endl;
			break;
		}
		default:
			break;
		}
		cout << endl;
	} while (opt >= 1 && opt <= 7);
	
	return 0;
}