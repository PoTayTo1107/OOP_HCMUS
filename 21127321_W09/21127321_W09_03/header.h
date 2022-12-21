#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <iomanip>
#include <queue>

using namespace std;

class Component {
protected:
	string name;
	float size;
public:
	Component(string _name) {
		name = _name;
	}
	virtual string getName() = 0;
	virtual float getSize() = 0;
	virtual void AddComponent(Component*) {}
	virtual void RemoveComponent(Component*) {}
	virtual void DeleteComponent() {}
	virtual void Output(int) {}
	virtual ~Component() {}
};
class Composite : public Component {	
	vector<Component*> components;
public:
	Composite(string _name) : Component(_name) {};
	string getName() {
		return name;
	}
	float getSize() {
		float totalSize = 0;
		for (int i = 0; i < components.size(); i++)
			totalSize += components[i]->getSize(); 
		return totalSize;
	}
	void AddComponent(Component* iComp) {
		components.push_back(iComp);
	}
	void RemoveComponent(Component* iComp) {
		for (int i = 0; i < components.size(); i++) {
			if (components[i] == iComp) {
				components.erase(components.begin() + i);
				break;
			}
		}
	}
	void DeleteComponent() {
		for (int i = 0; i < components.size(); i++) {
			components[i]->DeleteComponent();
			delete components[i];
		}
	}
	void Output(int layer) {
		layer++;
		for (int i = 0; i < components.size(); i++) {
			for (int j = 0; j < layer; j++) cout << "     ";
			cout << components[i]->getName() << endl;
			components[i]->Output(layer);
		}
	}
	~Composite() {
		DeleteComponent();
	}
};

class Leaf : public Component {
public:
	Leaf(string _name, float _size) : Component(_name) {
		size = _size;
	};
	string getName() {
		return name;
	}
	float getSize() {
		return size;
	}
	~Leaf() {}
};