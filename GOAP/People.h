#pragma once
#include <string>
class People {
private:
	std::string m_name;
	int quantityInPocket;
public:
	People();
	People(std::string name, int bag);
	std::string Name() const;
	int Pocket() const;
	void setPocket(int obj);
};
