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
public:
	Song();
	Song(string, string, string, string, int, int);
	Song(const Song&);
	virtual void Input();
	virtual void Output();
	virtual int getPlayed() = 0;
	virtual string getName() = 0;
};

class PubSong : public Song {
	int price;
public:
	PubSong();
	PubSong(string, string, string, string, int, int, int);
	PubSong(const PubSong&);
	void Input();
	void Output();
	int getPlayed();
	string getName();
};

class AuthSong : public Song {
	int price;
public:
	AuthSong();
	AuthSong(string, string, string, string, int, int, int);
	AuthSong(const AuthSong&);
	void Input();
	void Output();
	int getPlayed();
	string getName();
};

