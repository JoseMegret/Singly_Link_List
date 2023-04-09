//
// Codificar una lista ADT 
// Implementar utilizando un Singly linked list (lista enlasada,
// cadena de eslabones (nodos)

/*
    Agenda
        1. Definir e implementar una clase de tipo Node (eslabon)
        2. Definir una clase base de listas NO ordenadas
            - Utilizando la clase de los nodos 
            - Implementar operaciones
                - Buscar
                - Insertar
                - Remover
        3. Definir una clase derivada de la clase base de listas ordenadas
            - Hereda de la clase base
            - Redefining u overriding de 
                - Buscar  
                - Insertar
                - Remover
        4. Un cliente para nuestras clases.

*/

// Definir e implementar la clase nodo.
// Include guard

#include <iostream>
using namespace std;

#ifndef NODE_H
#define NODE_H

class Node{

    public: // Acceso a las clase base y derivada
    
        // Data members

        int info ; // dato o informacion
        Node * link ; // self-referential

        // Constructor del nodo (dos parametros)
        //  1. el dato (int)
        //  2. el puntero (puntero a nodo)

        Node (int data, Node* ptr = nullptr) : info(data), link(ptr) {
        }    

};
#endif

typedef Node* Nodeptr ;

// Definir la clase base de listas NO ordenadas que utiliza la clase Node
//Definir e implementar clase nodo.
//Include guard

#ifndef UNLLIST_H
#define UNLLIST_H

class UNLList{

    protected: //para dar acceso a la clase derivada
    Nodeptr head;

    private:
    //Funcion copy para usar el copy constructor y OAO
    void copy(const UNLList& originalList);

    public:
    //constructor: inicializa head a nullptr
    UNLList();

    //Destruir la lista(utilizar para clear la lista y el destructor)
    void destroyList();

    //Copy Constructor
    UNLList(const UNLList& original);

    //Getters
    //Cotejar lista vacia
    bool IsEmpty() const;

    //Cotejar la cantidad de items (nodes) en la lista 
    int length() const;

    //Buscar si un item esta en la lista
    bool search(int item) const;

    //Desplegar la lista
    void print() const;

    //Setters
    //insertar un item o nodo a la lista
    void insert(int item);

    //remover un nodo de la lista
    void remove(int item);

};
#endif

// Implementation de la clase UNLIST
UNLList::UNLList() : head(nullptr) { }

// Funcion copy para CC y OAO

// void UNLList:: copy (const UNLList& originallist) ;

// Copy constructor

//  UNLList::UNLList(const UNLList& original) ;

// Destruir la lista
// Utilizar para clear y en el destructor
void UNLList::destroyList() {

    Nodeptr temp ;
    while ( head != nullptr) {
        temp = head ;   // temp apunta a head
        head = head -> link ; // head apunta al siguiente nodo
        delete temp ;   // devolvemos a memoria el nodo al que apunta temp
    } // End while
}   // End function

// Destructor

UNLList::~UNLList() {
    destroyList() ;
}

// Getters (observers)
// Cotejar lista vacia
bool UNLList:: IsEmpty() const {
    return head == nullptr ; 
}
// Cotejar la cantidad de items (nodos) en la lista 
int UNLList::length() const {

    int countNodes = 0 ;
    Nodeptr current = head ; // cree puntero copia de head
    while(current != nullptr){
        countNodes++ ; // incremente el contador
        current = current->link ;   // el puntero al siguiente nodo 
    }
    return countNodes ;
}

// Buscar si un item esta en la lista
// bool search(int item) const ;

// Desplegar la lista
void UNLList::print() const {
    if(IsEmpty()) {
        cout << "List is empty, cannot display. \n" ;
    }
    else {  // La lista no esta vacia
        Nodeptr temp = head ;   // Node* temp = head
        while (temp != nullptr) {
            cout << temp->info << endl ;    // Desplegar el campo info
            temp = temp->link ; 
        }
    }
}