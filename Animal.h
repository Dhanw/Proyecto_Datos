#pragma once
#include<iostream>
#include<sstream>

using namespace std;
class Animal{// razpn de ser 

public:
	Animal(string,string);
	Animal();
	~Animal() {};
	virtual bool operator==(const Animal&) const;
	virtual bool operator<(const Animal&) const;
	virtual string toString() const;
	friend ostream & operator +(ostream &,const Animal&);
	string getDato();
	string getCod();
private:
	string dato;
	string cod;
};
istream & operator>> (istream &, const Animal&);
ostream&  operator <<(ostream&, const Animal&);


//friend istream & operator>> (istream &, Animal&);
//friend ostream & operator<< (ostream &, Animal&);
//friend ostream & operator +(ostream &, Animal&);