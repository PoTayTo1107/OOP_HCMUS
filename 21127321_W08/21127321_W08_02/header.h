#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

class Song {
protected:
	string name;
	string lyric;
	string artist;
	string genre;
	int year;
	int played;
	int price;
public:
	Song();
	Song(string, string, string, string, int, int, int);
	Song(const Song&);
	~Song() {};
	virtual void Input();
	virtual void Output();
	int getPlayed();
	string getName();
	string getLyric();
	string getGenre();
	virtual int getPrice();
};

class AuthSong : public Song {
public:
	void Input();
	void Output();
	int getPrice();
};

class Account {
protected:
	string username;
	string password;
	int debt;
	bool isPre;
public:
	Account();
	Account(string, string, int, bool);
	Account(const Account&);
	~Account() {};
	virtual void Input();
	string getUsername();
	string getPassword();
	bool getPre();
	int getDebt();
	virtual void Charge() {};
	virtual int getTime() { return 0; };
	virtual void addDebt(int);
};

class PreAccount : public Account {
	int time;
public:
	PreAccount();
	PreAccount(string, string, int, bool, int);
	PreAccount(const PreAccount&);
	~PreAccount() {};
	void Input();
	void Charge();
	int getTime();
	void addDebt(int);
};