#include "header.h"

int main() {
	Component* tree = new Composite("C");
	Component* branch1 = new Composite("OOP");
	Component* branch2 = new Composite("HTMT");
	Component* leaf_1 = new Leaf("W1",20);
	Component* leaf_2 = new Leaf("W2",30);
	Component* leaf_3 = new Leaf("W3",40);

	branch1->AddComponent(leaf_1);
	branch1->AddComponent(leaf_2);
	branch1->RemoveComponent(leaf_2);
	branch2->AddComponent(leaf_3);
	tree->AddComponent(branch1);
	tree->AddComponent(branch2);
	
	int opt;
	do {
		cout << "1. Liet ke tat ca cac thu muc va tep tin" << endl;
		cout << "2. Tong dung luong cua o dia" << endl;
		cout << "Bat ky ky tu nao khac de thoat" << endl;

		cin >> opt;
		cin.ignore();

		switch (opt) {
		case 1: {
			cout << tree->getName() << endl;
			tree->Output(0);
			break;
		}
		case 2: {
			cout << "Tong dung luong cua o dia la: ";
			cout << fixed << setprecision(2) << tree->getSize() << endl;
			break;
		}
		default:
			break;
		}
		cout << endl;
	} while (opt == 1 || opt == 2);
	
	return 0;
}