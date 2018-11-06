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
//template<class T>// metodo insert iterativo, me resulta mas sencillo.
//void CArbolBinario<T>::insert(T elemento) { 
//	CNodo<T>* nuevo = new CNodo<T>(elemento);
//	CNodo<T>* root = raiz;
//	CNodo<T>* padre = NULL;// root pass 
//	if (raiz == NULL) {
//		raiz = nuevo;
//	}
//	else {
//		while (root != NULL) {
//			padre = root;
//			cout << "Datos del padre: "<<padre->datos << endl;
//			cout << "Datos del elemento: " << elemento << endl;
//			cout << "Se va a insertar a la : " << endl;
//			if (DecidirCamino())
//				root = root->der;
//			else
//				root = root->izq;
//		}
//		if (DecidirPadre(root))
//			padre->izq = nuevo;
//		else
//			padre->der = nuevo;
//	}
//
//}

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


//template<class T>
//string CArbolBinario<T>::imprimeNivel(CNodo<T>* r, int niv) {
//
//	if (r) {
//		string iz, der;
//		stringstream ss;
//		if (niv == 1) {
//			ss << r->datos << " ";
//			return ss.str();
//		}
//		else {
//			niv -= 1;
//			iz = imprimeNivel(r->izq, niv);
//			der = imprimeNivel(r->der, niv);
//		}
//		ss << iz << " " << der;
//		return ss.str();
//	}
//	else {
//		return " ";
//	}
//}
//template<class T>
//int  CArbolBinario<T>::altura(CNodo<T>* r) {
//	int a, b;
//	if (r) {
//		if (r->izq == NULL && r->der == NULL) {
//			return 1;
//
//		}
//		else {
//			a = altura(r->izq);
//			b = altura(r->der);
//		}
//
//		if (a < b) {
//			return b + 1;
//		}
//		else {
//			return  a + 1;
//		}
//	}
//	else
//		return 0;
//
//}
//template<class T>
//int CArbolBinario<T>::cuentaNodos(CNodo<T>* r) {
//	int a, b;
//	if (r) {
//		if (r->izq == NULL&&r->der == NULL) {
//			return 1;
//		}
//		else {
//			a = cuentaNodos(r->izq);
//			b = cuentaNodos(r->der);
//		}
//		return a + b + 1;
//	}
//	else
//		return 0;
//}

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
// metodo del profe
//template<class T>
//void CArbolBinario<T>::insertarOrden(T elemento) {
//	CNodo<T>* nuevo = new CNodo<T>(elemento);
//	CNodo<T>* root = raiz;
//	CNodo<T>* padre = NULL;// root pass 
//	if (raiz == NULL) {
//		raiz = nuevo;
//	}
//	else {
//		while (root != NULL) {
//			padre = root;
//			if (elemento < root->datos)
//				root = root->izq;
//			else
//				root = root->der;
//		}
//
//		if (padre->datos > elemento)
//			padre->izq = nuevo;
//		else
//			padre->der = nuevo;
//	}
//} // metodo hecho por Caama
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

//}
// se puede utilizar el root pass para entender por donde anda el root ..... que es lo mismo que si el nodo tuviera un padre o no ?
// metodo del profe
//template<class T>
//void CArbolBinario<T>::poda(CNodo<T>* r, CNodo<T>* rp) {// root pass le sigue al root osea se necesitan dos punteros para recorrer el arbol 
//	if (r != NULL) {// hay algo que se puede borrar
//		if (r->izq == NULL && r->der == NULL) {
//			CNodo<T>* borrado; // nodo para borrar elemento
//			if (rp != NULL) {// estoy dentro del arbol... no se está en la raiz
//				if (r == rp->izq) {
//					borrado = rp->izq;
//					rp->izq = NULL;
//				}
//				else {
//					borrado = rp->der;
//					rp->der = NULL;
//				}
//			}
//			else {// hay que borrar a la raiz
//				borrado = raiz;
//				raiz = NULL;
//			}
//			delete borrado;
//		}
//		else {
//			poda(r->der, r);
//			poda(r->izq, r);
//		}
//	}
//}

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

//Akinator->insert(Ani1);
	//Akinator->insert(Ani2);
	//Akinator->insert(Ani3);
	//Akinator->insert(Ani4);
	//Akinator->insert(Ani5);
	//Akinator->insert(Ani6);

/*CArbolBinario<int>* arbol = new CArbolBinario<int>();

cout << "Ingresando valores" << endl;
arbol->insertarOrden(8);
arbol->insertarOrden(6);
arbol->insertarOrden(10);
arbol->insertarOrden(12);
arbol->insertarOrden(9);
arbol->insertarOrden(85);
arbol->insertarOrden(45);
arbol->insertarOrden(5);
arbol->insertarOrden(13);
arbol->insertarOrden(16);
CNodo<int>* root = arbol->raiz;*/

//cout << "Imprimiendo el arbol en Orden " << endl;
//arbol->enOrden(root);
//cout << "----------------------------" << endl;

//cout << "Imprimiendo el arbol podado " << endl;
//arbol->poda(arbol->raiz, NULL);
//cout << "Imprimiendo el arbol en Orden " << endl;
//arbol->enOrden(arbol->raiz);

/*arbol->borraMenor(root,NULL);
arbol1->insertarNodo(arbol1->raiz, 10, NULL);
arbol1->insertarNodo(arbol1->raiz, 8, NULL);
cout << "Imprimiendo el arbol1 en Orden " << endl;
CNodo<int>* root1 = arbol1->raiz;
arbol1->enOrden(root1);
cout << endl;
cout << "----------------------------" << endl;
cout << "Imprimiendo la altura del arbol " << endl;
cout << "altura: " << arbol1->altura(root1) << endl;
cout << "----------------------------" << endl;

cout << "Imprimiendo el arbol1 en Orden " << endl;
arbol1->enOrden(root1);
cout << endl;
cout << "----------------------------" << endl;

cout << "Imprimiendo los nodos del arbol " << endl;
cout << "Cantidad: " << arbol1->cuentaNodos(root1);
cout << endl;
cout << "----------------------------" << endl;


cout << "Imprimiendo los nodos del nivel 3 " << endl;
cout << arbol1->imprimeNivel(root1, 3);
cout << endl;
cout << "----------------------------" << endl;


cout << "borrando el nodo menor " << endl;
CNodo<int>* menor = arbol1->retornaMenor(arbol1->raiz);
cout << menor->datos << endl;
arbol1->borraMenor(root1);

delete arbol1;




*/
