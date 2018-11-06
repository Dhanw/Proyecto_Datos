#include"Animal.h"


Animal::Animal(string ap1,string ap2) :dato(ap1),cod(ap2){}

bool Animal::operator==(const Animal& p) const {
	if (this->dato == p.dato && this->cod == p.cod) {
		return true;
	}
	else
		return false;
}
Animal::Animal() {}
bool Animal::operator<(const Animal& p) const {
	/*if (this->cod < p.cod)
			return true;
		else
			return false;*/
	// forma de una sola linea;

	return this->cod < p.cod;

}
string Animal::toString() const {
	stringstream ss;
	ss << dato << " " /*<< cod << " "*/ << endl;
	return ss.str();
}

string Animal::getDato() { return dato; }
string Animal::getCod() { return cod; }

ostream& operator<<(ostream& salida, const Animal& p) {

	salida << p.toString();
	return salida;
}

//istream & operator>> (istream & Lee, const Animal& p) {
//	cout << "\n\nIngrese nombre de la Persona:";
//	// ingresar el dato principal
//	Lee >> p.getDato;
//	cout << "\n\nIngrese anio de nacimiento:";
//	// ingresar el cod que parece quw usare más tarde;
//	Lee >> p.getCod;
//	return Lee;
//}

//ostream & operator +(ostream &escribe, Animal& p) {
//	escribe << p.getDato << " " << p.getCod << endl;
//	return escribe;
//
//}

//Animal::Animal() {}
//bool Animal::operator<(const Animal& p) const {
//	/*if (this->dato < p.dato)
//	return true;
//	else*/ if (this->cod < p.cod)
//		return true;
//	else
//		return false;
//}