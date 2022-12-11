#include "header.h"


bool cmp(Song* a, Song* b) {
	return a->getPlayed() > b->getPlayed();
}

int main() {
	vector <Song*> danhSach;
	Song* song;

	int mainOpt, opt1, opt2;
	do {
		cout << "Chon chuc nang" << endl;
		cout << "1. Choi nhac" << endl;
		cout << "2. Them bai hat" << endl;
		cout << "3. Xuat danh sach tat ca bai hat" << endl;
		cout << "4. Bang xep hang top 5 bai hat" << endl;
		cout << "5. Tinh tong luong" << endl;
		cout << "6. Xuat danh sach nhan su" << endl;
		cout << "7. Luong cua nhan su co luong cao nhat" << endl;
		cout << "Bat ky ky tu nao khac de thoat" << endl;

		cin >> mainOpt;
		cin.ignore();

		switch (mainOpt) {
		case 1: {
			cout << "Nhap STT bai hat can choi" << endl;
			for (int i = 0; i < danhSach.size(); i++) {
				cout << i + 1 << ". " << danhSach[i]->getName() << endl;
			}
			int id;
			cin >> id;
			id--;
			cin.ignore();
			if (id >= 0 && id < danhSach.size()) {
				cout << "Dang choi " << danhSach[id]->getName() << endl;

				// FUNCTION


			}
			else {
				cout << "Bai hat khong ton tai!\n";
			}
			break;
		}
		case 2: {
			cout << "Chon chuc nang" << endl;
			cout << "1. Them bai hat pho thong" << endl;
			cout << "2. Them bai hat ban quyen" << endl;

			cin >> opt2;
			cin.ignore();

			switch (opt2) {
				case 1: {
					song = new PubSong;
					song->Input();
					danhSach.push_back(song);
					break;
				}
				case 2: {
					song = new AuthSong;
					song->Input();
					danhSach.push_back(song);
					break;
				}
				default:
					break;
			}
		}
		case 3: {
			for (int i = 0; i < danhSach.size(); i++) {
				cout << "Bai nhac thu " << i + 1 << " :\n";
				danhSach[i]->Output();
			}
			break;
		}
		case 4: {
			vector <Song*> dup = danhSach;
			for (int i = 0; i < dup.size(); i++) {
				sort(dup.begin(), dup.end(), cmp);
			}
			int len = dup.size();
			if (dup.size() > 5) len = 5;
			for (int i = 0; i < len; i++) {
				dup[i]->Output();
			}
			break;
		}
		case 5: {
			break;
		}
		case 6: {
			break;
		}
		case 7: {
			break;
		}
		default:
			break;
		}
		cout << endl;
	} while (mainOpt >= 1 && mainOpt <= 7);

	return 0;
}