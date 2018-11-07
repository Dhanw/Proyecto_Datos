#include"Animal.h"


Animal::Animal(string ap1,int cd) :dato(ap1),code(cd) {}

bool Animal::operator==(const Animal& p) const {
	return this->dato == p.dato && this->code==p.code;
}
Animal::Animal() {}
bool Animal::operator<(const Animal& p) const {
	return this->code < p.code;
}

bool Animal::operator>(const Animal& p) const {
	return this->code > p.code;
}
string Animal::toString() const {
	stringstream ss;
	ss << dato << endl;
	return ss.str();
}

string Animal::getDato() { return dato; }
int Animal::getCode() { return code; }

ostream& operator<<(ostream& salida, const Animal& p) {

	salida << p.toString();
	return salida;
}
