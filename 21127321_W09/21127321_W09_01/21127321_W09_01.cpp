#include "header.h"

vector<NhanSu*> NhanSu::Sample;
int main() {
	NhanSu::addSample(new GiangVien);
	NhanSu::addSample(new TroGiang);
	NhanSu::addSample(new NghienCuuVien);
	NhanSu::addSample(new ChuyenVien);
	NhanSu::addSample(new ThucTapSinh);

	PhongQuanLy pql;
	int opt;
	do {
		cout << "1. Them nhan su theo ten bo phan" << endl;
		cout << "2. Xoa nhan su bang ma so" << endl;
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
			pql.addMem(ns);
			break;
		}
		case 2: {
			vector<NhanSu*> tmp = pql.getMem();
			int pos = -1;
			string id;

			cout << "Nhap ma so nhan su can xoa:" << endl;
			cin >> id;
			cin.ignore();
			
			for (int i = 0; i < tmp.size(); i++) {
				if (id == tmp[i]->getId()) pos = i;
			}

			if (pos != -1) {
				tmp.erase(tmp.begin() + pos);
				pql.setMem(tmp);
				cout << "Xoa nhan su thanh cong!" << endl;
			}
			else {
				cout << "Khong tim thay ma so!" << endl;
			}
			break;
		}
		case 3: {
			float tongLuong = 0;
			vector<NhanSu*> tmp = pql.getMem();
			for (int i = 0; i < tmp.size(); i++) {
				tongLuong += tmp[i]->tinhLuong();
			}
			cout << "Tong luong can chi tra la: ";
			cout << fixed << setprecision(2) << tongLuong << endl;
			break;
		}
		case 4: {
			vector<NhanSu*> tmp = pql.getMem();
			if (tmp.size() == 0) {
				cout << "Danh sach nhan su rong!" << endl;
			}
			else {
				for (int i = 0; i < tmp.size(); i++) {
					cout << "Nhan su thu " << i + 1 << " :";
					tmp[i]->Output();
				}
			}
			break;
		}
		case 5: {
			float maxx = 0;
			vector<NhanSu*> tmp = pql.getMem();
			for (int i = 0; i < tmp.size(); i++) {
				if (tmp[i]->tinhLuong() > maxx) maxx = tmp[i]->tinhLuong();
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
	
	return 0;
}