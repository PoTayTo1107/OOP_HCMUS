#include "header.h"

int main(){
	Skill skill0;
	Hero hero0;

	Skill skill1("Mediate", 1);
	vector<Skill*> list;
	list.push_back(&skill1);
	Hero hero1("Yi",1000,500,1,list);

	Skill skill2(skill1);
	Hero hero2(hero1);

	Skill skill3;
	Hero hero3;

	skill3.Input();
	hero3.Input();

	cout << "\n";
	cout << "Skill0 (mac dinh):\n";
	skill0.Output();
	cout << "\n";
	cout << "Hero0 (mac dinh):\n";
	hero0.Output();
	cout << "\n";
	cout << "Skill1 (co tham so):\n";
	skill1.Output();
	cout << "\n";
	cout << "Hero1 (co tham so):\n";
	hero1.Output();
	cout << "\n";
	cout << "Skill2 (sao chep):\n";
	skill2.Output();
	cout << "\n";
	cout << "Hero2 (sao chep):\n";
	hero2.Output();
	cout << "\n";
	cout << "Hero3 (tu nhap):\n";
	skill3.Output();
	cout << "\n";
	cout << "Hero3 (tu nhap):\n";
	hero3.Output();
	hero3.skillOutput();
	hero3.delSkill();
}
