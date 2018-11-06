#include<iostream>
#include<sstream>
#include"Animal.h"
using namespace std;

template<class T>
class CNodo {
public:

	T datos;
	CNodo* izq;
	CNodo* der;
	CNodo* padre;
	CNodo() { izq = der = padre = 0; }  // construct.
	CNodo(T elemento) {
		this->datos = elemento;
		izq = der = padre = NULL;
	}
};

template<class T>
class CArbolBinario {
public:
	CNodo<T> * raiz;

public:
	CArbolBinario() { raiz = 0; }

	void enOrden(CNodo<T>* r/*, int*/);
	void insertarNodo(CNodo<T>* &r, T elemento, CNodo<T>* rp); // le tengo que agregar el & al nodo porque voy a estar modificando el arbol constantemente al insertar un nuevo valor													   // preguntar al profe :v
	void borrarNodo(CNodo<T>* r); //Arb-Ord 
	void borrarElemento(CNodo<T>* r, T elemento);
	void  borraMenor(CNodo<T>* r);  // 
	void reemplazar(CNodo<T>* r, CNodo<T>* rp);
	CNodo<T>* retornaMenor(CNodo<T>* r);
	bool DecidirCamino();
	bool DecidirPadre(CNodo<T>* r);
	CNodo<T>* CrearNodo(T elemento);// crear nodo devuelve un puntero
	void imprimir(CNodo<T>* r,int);
	//metodos para guardar el arbol
	void CrearArbol(CNodo<T> *);
	void Guardar(CNodo<T> *, ofstream &);
	void Cargar(CNodo<T> *, ifstream &, ifstream &);
	void Empezar(CNodo<T> *);
	CNodo<T>* unirNodo(CNodo<T> *, CNodo<T> *);
};

// metodos para guardar el arbol


template<class T>
void CArbolBinario<T>::Empezar(CNodo<T>* r) {
	if (r) {
		if (r->izq || r->der) {
			cout << r->datos << endl;
			cout << "Si o no " << endl;
			if (DecidirCamino()) {
				Empezar(r->der);
			}
			else {
				Empezar(r->izq);
			}
		}
	}
	else {
		string crt,animal;
		cout << "Ya no hay camino que seguir" << endl;
		cout << "Ud gano.........." << endl;
		cout << "Ingrese una caracteristica fundamental del animal e ingrese el animal" << endl;
		cin >> crt;
		cout << "Ingrese el animal" << endl;
		cin >> animal;
		Animal a1(crt, "0");
		Animal a2(animal, "1");
		CNodo<T> *nuevo = CrearNodo(a1);
		CNodo<T> *nuevo1 = CrearNodo(a2);
		CNodo<T> *ultimo=unirNodo(nuevo,nuevo1);
		r = ultimo;

	}
}
template<class T>
CNodo<T>* CArbolBinario<T>::unirNodo(CNodo<T>* r, CNodo<T> * rp) {
	if (r) {
		return NULL;
	}

}

template<class T>
void CArbolBinario<T>::CrearArbol(CNodo<T> *r){
	
}

template<class T>
void CArbolBinario<T>::Guardar(CNodo<T> *r, ofstream & salida) {


}

template<class T>
void CArbolBinario<T>::Cargar(CNodo<T> *r, ifstream &entra1, ifstream &entra2) {

}


// Metodos del arbol
template<class T>
CNodo<T>* CArbolBinario<T>::CrearNodo(T elemento){
	CNodo<T>* nuevo = new CNodo<T>(elemento);
	return nuevo;
}



template<class T>
bool CArbolBinario<T>::DecidirPadre(CNodo<T>* r) {// se decide el padre
	if (r) {
		if (r->padre->der->datos == r->datos)
			return true;
		else
			return false;
	}
	else 
		return false;
}




template<class T>
void CArbolBinario<T>::borrarElemento(CNodo<T>* r, T elemento) {
	if (r) {
		if (elemento < r->datos)
			borrarElemento(r->izq, elemento);
		else if (elemento > r->datos)
			borrarElemento(r->der, elemento);
		else
			borrarNodo(r);
	}
}
template<class T>
CNodo<T>* CArbolBinario<T>::retornaMenor(CNodo<T>* r) {
	if (r->izq) {
		retornaMenor(r->izq);
	}
	else {
		return r;
	}
}
// reemplazar dos nodos
template<class T>
void CArbolBinario<T>::reemplazar(CNodo<T>* r, CNodo<T>* rp){
	if (r->padre) {// se le asigna el nuevo hijo
		if (r->datos == r->padre->izq->datos) {
			r->padre->izq = rp;
		}
		else if (r->datos == r->padre->der->datos) {
			r->padre->der = rp;
		}
	}
	if (rp) {// se le asigna el nuevo padre
		rp->padre = r->padre;
	}
}
template<class T>
CNodo<T>* CrearNodo(T elemento) {
	CNodo<T>* nuevo = new CNodo<T>(elemento);
	return nuevo;
}
template<class T>
void CArbolBinario<T>::borrarNodo(CNodo<T>* r) {

	if (r->izq &&r->der) {// si el nodo tiene  los dos nodos 
		CNodo<T>* menor = retornaMenor(r->der);
		r->datos = menor->datos;
		borrarNodo(menor);
	}
	else if (r->izq) {
		reemplazar(r, r->izq);
		r->der = NULL; r->izq = NULL;
		delete r;
	}
	else if (r->der) {
		reemplazar(r, r->der);
		r->der = NULL; r->izq = NULL;
		delete r;
	}
	else {
		reemplazar(r, NULL);
		r->der = NULL; r->izq = NULL;
		delete r;
	}
}
//revisar
template<class T>
bool CArbolBinario<T>::DecidirCamino() {
	int c;
	cout << "1 o 0? (si o no)" << endl;
	cin >> c;
	if (c == 1)
		return true;
	else if (c == 0)
		return false;
}
template<class T>
void CArbolBinario<T>::insertarNodo(CNodo<T>* &root, T n, CNodo<T>* rp) {
	if (root == NULL) {// si el pinshi nodo está vacio lo inserto y ya :'v
		CNodo<T>* nuevo = new CNodo<T>(n);
		nuevo->padre = rp;
		root = nuevo;
	}
	else {// decidir camino preguntara 1 der 0 izq return true==1;

		cout << "Pregunta " << root->datos << " ";
		cout << "Datos del elemento: " << n << endl;
		if (DecidirCamino())
			insertarNodo(root->der, n, root);
		else
			insertarNodo(root->izq, n, root);
	}
}

template<class T>
void CArbolBinario<T>::imprimir(CNodo<T>* r, int cont){

	if (r) {
		
		imprimir(r->der, cont + 1);
		int i = 0;
		while (i <= cont) {
			cout << "             ";
			i++;
		}
		cout << "  " << r->datos << endl; 
		imprimir(r->izq, cont + 1);
	}

}
template<class T>
void CArbolBinario<T>::enOrden(CNodo<T>* r/*,int cont*/) {
		if (r == NULL) {
			return;
		}
		else {
			enOrden(r->izq);
			cout << r->datos << " ";
			enOrden(r->der);
		}
	
}


template<class T>
void CArbolBinario<T>::borraMenor(CNodo<T>* root) {
	if (root != NULL) {// verifico que no haya nada que borrar
		CNodo<T>*mini = retornaMenor(root);
		borrarNodo(mini);
	}
}

int main() {
	//dato, codigo
	Animal Ani1("PoneHuevos ?","0");//Pregunta
	Animal Ani2("Es un ave ?", "0");//Pregunta
	Animal Ani3("Es un mamimefero ?", "0");//Pregunta
	Animal Ani4("Es acuatico?", "0");//Pregunta 
	Animal Ani5("Es terrestre?", "0");//Pregunta
	Animal Ani6("Es un reptil?", "0");//Pregunta 
	Animal Ani7("Es un cocodrilo?", "0");//Pregunta 
	Animal Ani8("Es un Aguila?", "0");//Pregunta 
	Animal Ani9("Es una gato", "0");//Pregunta 
	Animal Ani10("Es un pez?", "0");//Pregunta 
	Animal An11("Es un tiburon?", "0");//Pregunta 
	
	cout << "Trabajando en Arbol binario " << endl;

	CArbolBinario<Animal>* Akinator = new CArbolBinario<Animal>();
	CNodo<Animal>*root = Akinator->raiz;
	
	Akinator->insertarNodo(root, Ani1, NULL);
	Akinator->insertarNodo(root, Ani2, NULL);
	Akinator->insertarNodo(root, Ani3, NULL);
	Akinator->insertarNodo(root, Ani4, NULL);
	Akinator->insertarNodo(root, Ani5, NULL);
	Akinator->insertarNodo(root, Ani6, NULL);
	cout << "Imprimiendo el arbol en Orden " << endl;
	int cont = 0;
	Akinator->enOrden(root);
	Akinator->imprimir(root,cont);
	cout << "----------------------------" << endl;
	cout << "Metodo Empezar" << endl;
	Akinator->Empezar(root);

	system("pause");
	delete Akinator;
	return 0;
}

