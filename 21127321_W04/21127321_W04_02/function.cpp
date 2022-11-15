#include "header.h"

Skill::Skill(){
	skillName = "undefined";
	skillLevel = 0;
}

Skill::Skill(string str, unsigned int level){
	skillName = str;
	skillLevel = level;
}

Skill::Skill(const Skill& tmp){
	skillName = tmp.skillName;
	skillLevel = tmp.skillLevel;
}

Skill::~Skill(){}

string Skill::getName(){
	return skillName;
}

unsigned int Skill::getLevel() {
	return skillLevel;
}

void Skill::setName(string name){
	skillName = name;
}

void Skill::setLevel(unsigned int level) {
	skillLevel = level;
}

void Skill::Input(){
	string name;
	unsigned int level = 0;

	cout << "Nhap ten chieu thuc:\n";
	getline(cin, name);
	while (level == 0) {
		cout << "Nhap cap can thiet de mo chieu thuc:\n";
		cin >> level;
		cin.ignore();
	}
	this->setName(name);
	this->setLevel(level);
}

void Skill::Output(){
	cout << "Ten chieu thuc: " << this->getName() << endl;
	cout << "Cap can thiet de mo chieu thuc: " << this->getLevel() << endl;
}

Hero::Hero() {
	heroName = "undefined";
	heroHealth = 0;
	heroMana = 0;
	heroLevel = 0;
	Skill *skill;
	vector<Skill*> list;
	skill = new Skill;
	list.push_back(skill);
	skillList = list;
}

Hero::Hero(string name, unsigned int health, unsigned int mana, unsigned int level, vector<Skill*> list){
	heroName = name;
	heroHealth = health;
	heroMana = mana;
	heroLevel = level;
	skillList = list;
}

Hero::Hero(const Hero& tmp){
	heroName = tmp.heroName;
	heroHealth = tmp.heroHealth;
	heroMana = tmp.heroMana;
	heroLevel = tmp.heroLevel;
	skillList = tmp.skillList;
}

Hero::~Hero(){}

string Hero::getName(){
	return heroName;
}

unsigned int Hero::getHealth(){
	return heroHealth;
}

unsigned int Hero::getMana(){
	return heroMana;
}

unsigned int Hero::getLevel(){
	return heroLevel;
}

vector<Skill*> Hero::getList(){
	return skillList;
}

void Hero::setName(string name){
	heroName = name;
}

void Hero::setHealth(unsigned int health){
	heroHealth = health;
}

void Hero::setMana(unsigned int mana){
	heroMana = mana;
}

void Hero::setLevel(unsigned int level){
	heroLevel = level;
}

void Hero::setList(vector<Skill*> list){
	skillList = list;
}

void Hero::Input(){
	string name;
	unsigned int health, mana, level;
	Skill *skill;
	skill = new Skill;

	health = mana = level = 0;

	cout << "Nhap ten vi tuong:\n";
	getline(cin, name);
	while (health == 0) {
		cout << "Nhap chi so mau:\n";
		cin >> health;
		cin.ignore();
	}
	while (mana == 0) {
		cout << "Nhap chi so nang luong:\n";
		cin >> mana;
		cin.ignore();
	}
	while (level == 0) {
		cout << "Nhap cap do vi tuong:\n";
		cin >> level;
		cin.ignore();
	}
	
	vector<Skill*> list;
	int n;
	cout << "Nhap so luong chieu thuc: " << endl;
	cin >> n;
	cin.ignore();
	list.clear();
	for (int i = 0; i < n; i++) {
		Skill* tmp = new Skill;
		tmp->Input();
		list.push_back(tmp);
	}
	for (int i = 0; i < list.size(); i++) 
		(list[i])->Output();
	
	this->setName(name);
	this->setHealth(health);
	this->setMana(mana);
	this->setLevel(level);
	this->setList(list);
}

void Hero::Output(){
	cout << "Ten anh hung: " << this->getName() << endl;
	cout << "Chi so mau: " << this->getHealth() << endl;
	cout << "Chi so nang luong: " << this->getMana() << endl;
	cout << "Cap do vi tuong: " << this->getLevel() << endl;
	cout << "Danh sach chieu thuc cua anh hung: "<< endl;
	vector<Skill*> list;
	list = this->getList();
	for (int i = 0; i < list.size(); i++) (*list[i]).Output();
}

void Hero::skillOutput(){
	vector<Skill*> list;
	list = this->getList();
	cout << "Nhung chieu thuc vi tuong co the hoc duoc la:" << endl;
	for (int i = 0; i < list.size(); i++) {
		if ((*list[i]).getLevel() <= heroLevel) (*list[i]).Output();
	} 
}

void Hero::delSkill(){
	vector<Skill*> list;
	list = this->getList();
	int n;
	cout << "Nhap so chieu thuc can xoa: " << endl;
	cin >> n;
	cin.ignore();
	if (n > list.size()) list.erase(list.begin(), list.end());
		else list.erase(list.end() - n, list.end());
	this->setList(list);
	cout << "Danh sach chieu thuc sau khi xoa:" << endl;
	for (int i = 0; i < list.size(); i++) (*list[i]).Output();
}
