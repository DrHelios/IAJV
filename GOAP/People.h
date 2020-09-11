#pragma once
#include <string>
class People {
	std::string m_name;
	int pocket;
public:
	People() : m_name("Romulus"), pocket(0){}
	People(std::string name, int bag) : m_name(name), pocket(bag) {}
	std::string Name() const { return m_name; }
	int Pocket() const { return pocket; }
	void setPocket(int obj) { pocket += obj; }
};
