#include "header.h"

vector<NhanSu*> NhanSu::Sample;
vector<NhanSu*> PhongQuanLy::list;
int main() {
	NhanSu::addSample(new GiangVien);
	NhanSu::addSample(new TroGiang);
	NhanSu::addSample(new NghienCuuVien);
	NhanSu::addSample(new ChuyenVien);
	NhanSu::addSample(new ThucTapSinh);

	int opt;
	do {
		cout << "1. Them nhan su theo ten bo phan" << endl;
		cout << "2. Xoa nhan su theo ma so" << endl;
		cout << "3. Tinh tong luong" << endl;
		cout << "4. Xuat danh sach nhan su" << endl;
		cout << "5. Luong cua nhan su co luong cao nhat" << endl;
		cout << "Bat ky ky tu nao khac de thoat" << endl;

		cin >> opt;
		cin.ignore();

		switch (opt) {
		case 1: {
			cout << "Nhap ten nhan su can them" << endl;
			cout << "- GiangVien" << endl;
			cout << "- TroGiang" << endl;
			cout << "- NghienCuuVien" << endl;
			cout << "- ChuyenVien" << endl;
			cout << "- ThucTapSinh" << endl;
			string tmp;
			cin >> tmp;
			cin.ignore();
			NhanSu* ns = NhanSu::addObjectByName(tmp);
			if (ns != NULL ) PhongQuanLy::addInstance(ns);
			break;
		}
		case 2: {
			cout << "Nhap ma so nhan su can xoa:" << endl;
			string tmp;
			cin >> tmp;
			cin.ignore();
			PhongQuanLy::deleteID(tmp);
			break;
		}
		case 3: {
			float tongLuong = 0;
			vector<NhanSu*> list = PhongQuanLy::getInstance();
			for (int i = 0; i < list.size(); i++) {
				tongLuong += list[i]->tinhLuong();
			}
			cout << "Tong luong can chi tra la: ";
			cout << fixed << setprecision(2) << tongLuong << endl;
			break;
		}
		case 4: {
			vector<NhanSu*> list = PhongQuanLy::getInstance();
			if (list.size() == 0) cout << "Danh sach nhan su rong!" << endl;
			else {
				for (int i = 0; i < list.size(); i++) {
					cout << "Nhan su thu " << i + 1 << " :";
					list[i]->Output();
				}
			}
			break;
		}
		case 5: {
			float maxx = 0;
			vector<NhanSu*> list = PhongQuanLy::getInstance();
			for (int i = 0; i < list.size(); i++) {
				if (list[i]->tinhLuong() > maxx) 
					maxx = list[i]->tinhLuong();
			}
			cout << "Luong cua nhan su co luong cao nhat la:  ";
			cout << fixed << setprecision(2) << maxx << endl;
			break;
		}
		default:
			break;
		}
		cout << endl;
	} while (opt >= 1 && opt <= 5);
	
	NhanSu::deleteSample();
	PhongQuanLy::deleteInstance();

	return 0;
}