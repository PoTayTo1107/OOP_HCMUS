#include "header.h"

int main() {
	Nhansu nhansu;
	Giangvien giangvien;
	Trogiang trogiang;
	Nghiencuuvien nghiencuuvien;
	Chuyenvien chuyenvien;

	int opt;
	do {
		cout << "Chon nhan su can nhap" << endl;
		cout << "1. Nhan su" << endl;
		cout << "2. Giang vien" << endl;
		cout << "3. Tro giang" << endl;
		cout << "4. Nghien cuu vien" << endl;
		cout << "5. Chuyen vien" << endl;
		cout << "6. Tinh tong luong" << endl;
		cout << "Bat ky ky tu nao khac de thoat" << endl;

		cin >> opt;
		cin.ignore();

		switch (opt)
		{
		case 1: {
			nhansu.Input();
			nhansu.Output();
			break;
		}
		case 2: {
			giangvien.Input();
			giangvien.Output();
			break;
		}
		case 3: {
			trogiang.Input();
			trogiang.Output();
			break;
		}
		case 4: {
			nghiencuuvien.Input();
			nghiencuuvien.Output();
			break;
		}
		case 5: {
			chuyenvien.Input();
			chuyenvien.Output();
			break;
		}
		case 6: {
			float sum = giangvien.tinhLuong() + trogiang.tinhLuong() + nghiencuuvien.tinhLuong() + chuyenvien.tinhLuong();
			cout << "Tong luong can chi tra la: ";
			cout << fixed << setprecision(2) << sum << endl;
			break;
		}
		default:
			break;
		}
		cout << endl;
	} while (opt >= 1 && opt <= 6);
	


	return 0;
}