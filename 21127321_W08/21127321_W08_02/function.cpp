#include "header.h"

Song::Song() {
	name = "";
	lyric = "";
	artist = "";
	genre = "";
	year = 0;
	played = 0;
}
Song::Song(string _name, string _lyric, string _artist, string _genre, int _year, int _played) {
	name = _name;
	lyric = _lyric;
	artist = _artist;
	genre = _genre;
	year = _year;
	played = _played;
}
Song::Song(const Song& tmp) {
	name = tmp.name;
	lyric = tmp.lyric;
	artist = tmp.artist;
	genre = tmp.genre;
	year = tmp.year;
	played = tmp.played;
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

PubSong::PubSong() : Song() {
	price = 0;
}
PubSong::PubSong(string _name, string _lyric, string _artist, string _genre, int _year, int _played, int _price) : Song(_name, _lyric, _artist, _genre, _year, _played) {
	price = _price;
}
PubSong::PubSong(const PubSong& tmp) : Song(tmp) {
	price = tmp.price;
}
void PubSong::Input() {
	Song::Input();
}
void PubSong::Output() {
	Song::Output();
}
int PubSong::getPlayed() {
	return played;
}
string PubSong::getName() {
	return name;
}

AuthSong::AuthSong() : Song() {
	price = 0;
}
AuthSong::AuthSong(string _name, string _lyric, string _artist, string _genre, int _year, int _played, int _price) : Song(_name, _lyric, _artist, _genre, _year, _played) {
	price = _price;
}
AuthSong::AuthSong(const AuthSong& tmp) : Song(tmp) {
	price = tmp.price;
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
int AuthSong::getPlayed() {
	return played;
}
string AuthSong::getName() {
	return name;
}
