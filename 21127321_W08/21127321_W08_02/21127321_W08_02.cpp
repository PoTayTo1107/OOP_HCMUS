#include "header.h"

bool cmp(Song* a, Song* b) {
	return a->getPlayed() > b->getPlayed();
}

int main() {
	vector <Song*> songList, playList[500];
	Song* song = new Song;
	vector <Account*> userList;
	Account* account = new Account;

	int mainOpt, opt1, addOpt, userOpt, userOpt1, menuOpt, devOpt, preOpt, songOpt = 0, mainDevOpt;

	do {
		cout << "Chon chuc nang:" << endl;
		cout << "1. Developer Mode" << endl;
		cout << "2. User Mode" << endl;
		cout << "Bat ky so nao khac de thoat" << endl;

		cin >> menuOpt;
		cin.ignore();

		if (menuOpt == 1) {
			do {
				cout << "Chon chuc nang:" << endl;
				cout << "1. Them bai hat" << endl;
				cout << "2. Xuat bai hat" << endl;
				cout << "Bat ky so nao khac de thoat" << endl;

				cin >> mainDevOpt;
				cin.ignore();

				if (mainDevOpt == 1) {
					cout << "Chon chuc nang" << endl;
					cout << "1. Them bai hat vao danh sach tat ca bai hat" << endl;
					cout << "2. Them bai hat vao playlist cua user bat ky" << endl;
					cout << "Bat ky so nao khac de thoat" << endl;

					cin >> devOpt;
					cin.ignore();

					if (devOpt == 1) {
						cout << "Chon chuc nang" << endl;
						cout << "1. Them bai hat pho thong" << endl;
						cout << "2. Them bai hat ban quyen" << endl;
						cout << "Bat ky so nao khac de thoat" << endl;

						cin >> addOpt;
						cin.ignore();

						if (addOpt == 1) {
							song = new Song;
							song->Input();
							songList.push_back(song);
						}
						else if (addOpt == 2) {
							song = new AuthSong;
							song->Input();
							songList.push_back(song);
						}
					}
					else {
						if (userList.size() == 0) {
							cout << "Danh sach user rong!\n";
						}
						else {
							int id = -1;
							cout << "Nhap STT user can chinh sua playlist\n";
							for (int i = 0; i < userList.size(); i++) {
								cout << i + 1 << ". " << userList[i]->getUsername() << endl;
							}
							cin >> id;
							cin.ignore();
							if ((id >= 1) && (id <= userList.size())) {
								cout << "Chon chuc nang" << endl;
								cout << "1. Them bai hat pho thong" << endl;
								cout << "2. Them bai hat ban quyen" << endl;
								cout << "Bat ky so nao khac de thoat" << endl;

								cin >> addOpt;
								cin.ignore();

								if (addOpt == 1) {
									song = new Song;
									song->Input();
									playList[id - 1].push_back(song);
								}
								else if (addOpt == 2) {
									song = new AuthSong;
									song->Input();
									playList[id - 1].push_back(song);
								}
							}
						}
						
					}
				}
				else if (mainDevOpt == 2) {
					cout << "Chon chuc nang" << endl;
					cout << "1. Xuat bai hat bat ky trong danh sach bai hat" << endl;
					cout << "2. Xuat bai hat bat ky trong playlist cua user bat ky" << endl;
					cout << "Bat ky so nao khac de thoat" << endl;

					cin >> devOpt;
					cin.ignore();

					if (devOpt == 1) {
						if (songList.size() == 0) cout << "Danh sach bai hat rong!\n";
						else {
							for (int i = 0; i < songList.size(); i++) {
								cout << i + 1 << ". " << songList[i]->getName() << endl;
							}
							cout << "Chon bai hat can xuat thong tin\n";

							cin >> songOpt;
							cin.ignore();
							songOpt--;
							if ((songOpt >= 0) && (songOpt < songList.size())) {
								songList[songOpt]->Output();
							}
							else {
								cout << "So thu tu bai hat khong hop le!\n";
							}
						}
					}
					else {
						if (userList.size() == 0) {
							cout << "Danh sach user rong!\n";
						}
						else {
							int id = -1;
							cout << "Nhap STT user can chinh sua playlist\n";
							for (int i = 0; i < userList.size(); i++) {
								cout << i + 1 << ". " << userList[i]->getUsername() << endl;
							}
							cin >> id;
							cin.ignore();
							if ((id >= 1) && (id <= userList.size())) {
								if (playList[id - 1].size() == 0) cout << "Danh sach bai hat rong!\n";
								else {
									for (int i = 0; i < playList[id - 1].size(); i++) {
										cout << i + 1 << ". " << playList[id - 1][i]->getName() << endl;
									}
									cout << "Chon bai hat can xuat thong tin\n";

									cin >> songOpt;
									cin.ignore();
									songOpt--;
									if ((songOpt >= 0) && (songOpt < songList.size())) {
										songList[songOpt]->Output();
									}
									else {
										cout << "So thu tu bai hat khong hop le!\n";
									}
								}
							}
						}
					}
				}
			} while ((mainDevOpt == 1) || (mainDevOpt == 2));
		}
		else if (menuOpt == 2) {
			do {
				cout << "Chon chuc nang:" << endl;
				cout << "1. Dang ky" << endl;
				cout << "2. Dang nhap" << endl;
				cout << "Bat ky so nao khac de thoat" << endl;

				cin >> userOpt;
				cin.ignore();

				if (userOpt == 1) {
					cout << "Chon loai tai khoan:" << endl;
					cout << "1. Tai khoan thuong" << endl;
					cout << "2. Tai khoan VIP" << endl;
					cout << "Bat ky so nao khac de thoat" << endl;

					cin >> userOpt1;
					cin.ignore();

					if (userOpt1 == 1) {
						account = new Account;
						account->Input();
						userList.push_back(account);
					}
					else if (userOpt1 == 2) {
						account = new PreAccount;
						account->Input();
						userList.push_back(account);
					}
				}
				else if (userOpt == 2) {
					string username, password;
					cout << "Nhap ten tai khoan:\n";
					getline(cin, username);
					cout << "Nhap mat khau:\n";
					getline(cin, password);
					
					int log = -1;
					for (int i = 0; i < userList.size(); i++) {
						if ((userList[i]->getUsername() == username) && (userList[i]->getPassword() == password)){
							log = i;
						}
					}

					if (log >= 0) {
						bool isPre = userList[log]->getPre();
						do {
							cout << "Chon chuc nang" << endl;
							cout << "1. Choi nhac trong danh sach tat ca bai hat" << endl;
							cout << "2. Playlist cua ban" << endl;
							cout << "3. Bang xep hang top 5 bai hat" << endl;
							cout << "4. Kiem tra so tien no bao gom phi ban quyen va VIP (neu co)" << endl;
							if (isPre) {
								cout << "5. Dac quyen tai khoan VIP" << endl;
							}
							cout << "Bat ky so nao khac de thoat" << endl;

							cin >> mainOpt;
							cin.ignore();

							if (mainOpt == 1) {
								if (songList.size() == 0) {
									cout << "Danh sach bai hat rong!" << endl;
								}
								else {
									cout << "Nhap STT bai hat can choi" << endl;
									for (int i = 0; i < songList.size(); i++) {
										cout << i + 1 << ". " << songList[i]->getName() << endl;
									}
									int id = -1;
									cin >> id;
									id--;
									cin.ignore();
									if (id >= 0 && id < songList.size()) {

										userList[log]->addDebt(songList[id]->getPrice());

										cout << "Dang choi " << songList[id]->getName() << "..." << endl;
										cout << "Chon chuc nang" << endl;
										cout << "1. Them/Xoa bai hat trong playlist" << endl;
										cout << "2. Hien thi loi bat hat" << endl;
										cout << "Bat ky so nao khac de thoat" << endl;

										cin >> opt1;
										cin.ignore();

										if (opt1 == 1) {
											bool found = false;
											for (int i = 0; i < playList[log].size(); i++) {
												if (playList[log][i]->getName() == songList[i]->getName()) {
													playList[log].erase(playList[log].begin() + i);
													cout << "Xoa nhac khoi playlist thanh cong" << endl;
													found = true;
												}
											}
											if (found == false) {
												playList[log].push_back(songList[id]);
												cout << "Luu tru nhac vao playlist thanh cong" << endl;
											}
										}
										else if (opt1 == 2) {
											cout << "Loi bai hat " << songList[id]->getName() << " :\n";
											cout << songList[id]->getLyric() << endl;
										}
									}
									else {
										cout << "Bai hat khong ton tai!\n";
									}
								}
							}
							else if (mainOpt == 2) {
								if (playList[log].size() == 0) {
									cout << "Playlist cua ban rong!\n";
								}
								else {
									cout << "Nhap STT bai hat can choi" << endl;
									for (int i = 0; i < playList[log].size(); i++) {
										cout << i + 1 << ". " << playList[log][i]->getName() << endl;
									}
									int id = -1;
									cin >> id;
									id--;
									cin.ignore();
									if (id >= 0 && id < playList[log].size()) {

										userList[log]->addDebt(playList[log][id]->getPrice());

										cout << "Dang choi " << playList[log][id]->getName() << "..." << endl;
										cout << "Chon chuc nang" << endl;
										cout << "1. Hien thi loi bat hat" << endl;
										cout << "Bat ky so nao khac de thoat" << endl;

										cin >> opt1;
										cin.ignore();

										if (opt1 == 1) {
											cout << "Loi bai hat " << playList[log][id]->getName() << " :\n";
											cout << playList[log][id]->getLyric() << endl;
										}
									}
									else {
										cout << "Bai hat khong ton tai!\n";
									}
								}
							}
							else if (mainOpt == 3) {
								if (songList.size() == 0) {
									cout << "Danh sach bai hat rong!\n";
								}
								else {
									vector <Song*> dup = songList;
									for (int i = 0; i < dup.size(); i++) {
										sort(dup.begin(), dup.end(), cmp);
									}
									int len = dup.size();
									if (dup.size() > 5) len = 5;
									for (int i = 0; i < len; i++) {
										cout << "Top " << i + 1 << " :\n";
										dup[i]->Output();
									}
								}
							}
							else if (mainOpt == 4) {
								cout << "Tong du no hien tai: " << userList[log]->getDebt() << endl;
							}
							else if ((mainOpt == 5) && isPre) {
								cout << "Chon chuc nang" << endl;
								cout << "1. Kiem tra thoi han VIP" << endl;
								cout << "2. Goi y bai hat co so luot nghe nhieu nhat theo the loai" << endl;
								cout << "Bat ky so nao khac de thoat" << endl;

								cin >> preOpt;
								cin.ignore();

								if (preOpt == 1) {
									if (userList[log]->getTime() == 0) {
										cout << "Tai khoan VIP cua ban da het han\n";
										userList[log]->Charge();
									}
									else {
										cout << "Thoi han su dung VIP con lai la " << userList[log]->getTime() << " thang\n";
									}		
								}
								else if (preOpt == 2) {
									int opt = 0, maxx = 0, id = -1;
									string genre;

									while (!(opt >= 1 && opt <= 3)) {
										cout << "Chon the loai nhac:\n";
										cout << "1. Nhac Viet Nam\n";
										cout << "2. Nhac Au My\n";
										cout << "3. Nhac Han Quoc\n";
										cin >> opt;
									}

									cin.ignore();

									switch (opt) {
										case 1: {
											genre = "Nhac Viet Nam";
											break;
										}
										case 2: {
											genre = "Nhac Au My";
											break;
										}
										case 3: {
											genre = "Nhac Han Quoc";
											break;
										}
									}

									for (int i = 0; i < songList.size(); i++) {
										if ((songList[i]->getPlayed() > maxx) && (songList[i]->getGenre() == genre)) {
											id = i;
										}
									}

									if (id == -1) {
										cout << "Danh sach bai hat rong!\n";
									}
									else {
										cout << "Bai hat co luot nghe nhieu nhat theo the loai nhac yeu cau la:\n";
										songList[id]->Output();
									}
								}
							}
							cout << endl;
						} while ((mainOpt == 1) || (mainOpt <= 2) || (mainOpt <= 3) || (mainOpt <= 4) || ((mainOpt == 5) && (isPre)));
					}
					else {
						cout << "Tai khoan hoac mat khau da nhap khong hop le!\n";
					}
				}
			} while ((userOpt == 1) || (userOpt == 2));
		}
	} while ((menuOpt == 1) || (menuOpt == 2));
	
	delete song;
	delete account;
	for (int i = 0; i < songList.size(); i++) {
		delete songList[i];
	}
	for (int i = 0; i < userList.size(); i++) {
		delete userList[i];
	}
	for (int i = 0; i < 500; i++) {
		for (int j = 0; i < playList[i].size(); i++) {
			delete playList[i][j];
		}
	}

	return 0;
}