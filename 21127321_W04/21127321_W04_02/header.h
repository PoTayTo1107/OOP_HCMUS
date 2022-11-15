#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

class Skill
{
	string skillName;
	unsigned int skillLevel;
public:
	Skill();
	Skill(string, unsigned int);
	Skill(const Skill&);
	~Skill();
	string getName();
	unsigned int getLevel();
	void setName(string);
	void setLevel(unsigned int);
	void Input();
	void Output();
};
class Hero
{
	string heroName;
	unsigned int heroHealth;
	unsigned int heroMana;
	unsigned int heroLevel;
	vector<Skill*> skillList;
public:
	Hero();
	Hero(string, unsigned int, unsigned int, unsigned int, vector<Skill*>);
	Hero(const Hero&);
	~Hero();
	string getName();
	unsigned int getHealth();
	unsigned int getMana();
	unsigned int getLevel();
	vector<Skill*> getList();
	void setName(string);
	void setHealth(unsigned int);
	void setMana(unsigned int);
	void setLevel(unsigned int);
	void setList(vector<Skill*>);
	void Input();
	void Output();
	void skillOutput();
	void delSkill();
};