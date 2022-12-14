#include "header.h"

Song::Song() {
	name = "";
	lyric = "";
	artist = "";
	genre = "";
	year = 0;
	played = 0;
	price = 0;
}
Song::Song(string _name, string _lyric, string _artist, string _genre, int _year, int _played, int _price) {
	name = _name;
	lyric = _lyric;
	artist = _artist;
	genre = _genre;
	year = _year;
	played = _played;
	price = _price;
}
Song::Song(const Song& tmp) {
	name = tmp.name;
	lyric = tmp.lyric;
	artist = tmp.artist;
	genre = tmp.genre;
	year = tmp.year;
	played = tmp.played;
	price = tmp.price;
}
void Song::Input() {
	cout << "Nhap ten bai hat:\n";
	getline(cin, name);
	cout << "Nhap loi bai hat:\n";
	getline(cin, lyric);
	cout << "Nhap ten ca si:\n";
	getline(cin, artist);
	int opt = 0;
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
	cout << "Nhap nam phat hanh:\n";
	cin >> year;
	cin.ignore();
	cout << "Nhap luot nghe hien tai:\n";
	cin >> played;
	cin.ignore();
}
void Song::Output() {
	cout << "Ten bai hat: " << name << endl;
	cout << "Loi bai hat: " << lyric << endl;
	cout << "Ten ca si: " << artist << endl;
	cout << "The loai nhac: " << genre << endl;
	cout << "Nam phat hanh: " << year << endl;
	cout << "So luot nghe hien tai: " << played << endl;
}

int Song::getPlayed() {
	return played;
}
string Song::getName() {
	return name;
}
string Song::getLyric() {
	return lyric;
}
string Song::getGenre() {
	return genre;
}
int Song::getPrice() {
	return 0;
}

void AuthSong::Input() {
	Song::Input();
	cout << "Nhap gia tri ban quyen:\n";
	cin >> price;
	cin.ignore();
}
void AuthSong::Output() {
	Song::Output();
	cout << "Gia tri ban quyen: " << price << endl;
}
int AuthSong::getPrice() {
	return price;
}

Account::Account() {
	username = "";
	password = "";
	debt = 0;
	isPre = false;
}
Account::Account(string _username, string _password, int _debt, bool _isPre) {
	username = _username;
	password = _password;
	debt = _debt;
	isPre = _isPre;
}
Account::Account(const Account& tmp) {
	username = tmp.username;
	password = tmp.password;
	debt = tmp.debt;
	isPre = tmp.isPre;
}
void Account::Input() {
	do {
		cout << "Nhap ten tai khoan:\n";
		getline(cin, username);
	} while (username.find(' ') != string::npos);
	do {
		cout << "Nhap mat khau:\n";
		getline(cin, password);
	} while ((password.find(' ') != string::npos) || (password.size() < 8)) ;
}
string Account::getUsername() {
	return username;
}
string Account::getPassword() {
	return password;
}
bool Account::getPre() {
	return isPre;
}
int Account::getDebt() {
	return debt;
}
void Account::addDebt(int price) {
	debt += price;
}

PreAccount::PreAccount():Account() {
	username = "";
	password = "";
	debt = 0;
	isPre = true;
	time = 0;
}
PreAccount::PreAccount(string _username, string _password, int _debt, bool _isPre, int _time) : Account(_username, _password, _debt, _isPre) {
	time = _time;
}
PreAccount::PreAccount(const PreAccount& tmp) : Account(tmp) {
	time = tmp.time;
}
void PreAccount::Charge() {
	int opt = 0;
	do {
		cout << "Chon thoi gian dang ky VIP:\n";
		cout << "1. 1 thang gia 50k\n";
		cout << "2. 3 thang gia 140k\n";
		cout << "3. 6 thang gia 270k\n";

		cin >> opt;
		cin.ignore();

		switch (opt) {
		case 1: {
			debt += 50;
			time += 1;
			break;
		}
		case 2: {
			debt += 140;
			time += 3;
			break;
		}
		case 3: {
			debt += 270;
			time += 6;
			break;
		}
		default:
			break;
		}
	} while (!((opt >= 1) && (opt <= 3)));
}
void PreAccount::Input() {
	Account::Input();
	Charge();
}
void PreAccount::addDebt(int price) {
	if (time > 0) {
		debt += price / 2;
	}
	else {
		debt += price;
	}
}
int PreAccount::getTime() {
	return time;
}
