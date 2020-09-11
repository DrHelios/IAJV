#include "People.h"
People::People() : m_name("Romulus"), quantityInPocket(0) {}
People::People(std::string name, int bag) : m_name(name), quantityInPocket(bag) {}
std::string People::Name() const { return m_name; }
int People::Pocket() const { return quantityInPocket; }
void People::setPocket(int obj) { quantityInPocket += obj; }