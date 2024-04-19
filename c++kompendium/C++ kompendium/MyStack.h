//
// Created by User on 26.05.2022.
//

#ifndef UNTITLED25_MYSTACJ_H
#define UNTITLED25_MYSTACJ_H

#include <iostream>
using std::cout;
using std::endl;

//Szablony klas muszą w całości być zaimplementowane w pliku nagłówkowym
template<typename E>// template obowiązuje od tego momentu
class MyStack // klasa MyStack
{
public:
    //Klasa wewnętrzna
    class Node // klasa lokalna wewnątrz klasy MyStack
        {
        public: // elementy klasy Node sa dostępne publicznie przez Klasy MyStack
            E data; // odwołanie do zmiennej z template
            Node* next;
        };
    //pole prywatne
    Node* head = nullptr;// pierwszy element inicjowany pzy zworzeniu stosu, head jest nullptr (to istotne, bez tegonie będziemożnawykryćgdzie kończy się klasa)

    void push(const E& d) // umieszczanie kolejnych elementów w stosie,   podana niezmienna zmienna const E& d - stanowiąca
    {
        head = new Node(d, head); // head zastępowana jest nową head zawierającą podaną daną i referencje head
    }
    E pop() // pop zwraca zmienna z template
    {
        E data = head->data;// pobranie poszukiwaneo elementu
        Node *temp = head->next;// poranie wskaźnika do kolejneo elementu
        delete head;// zwolninie niepotzebneo framentu pamięci
        head = temp; // zastąpienie miejsca w pamięci
        return data; // zwrucenie zmiennej
    }

    bool empty()
    {
        return head == nullptr; // sprawdza czy head=nullptr izwracawynik logiczny
    }

    virtual ~MyStack();// destruktor jak i wszystkie inne funkcje można zadeklarowąć przed ich inicjalizacją
    //virtual oznacza funkcje które mają być nadpisane w funkcjach dziedziczących
};

template<typename E>// po zadeklarowaniu wewnatrz
MyStack<E>::~MyStack() // odwołanie do funkcji z klasy pzez nazwe klasy
{
    cout << "Usuwanie Stack" << endl;
    while (head != nullptr) // while kończącesię dopiero kiedy napotka head=nullptr - dlatego ustawienie pierwszego heada na nullptrbyło tak istotne
    {
        Node *node = head;
        head = head->next;
        cout << " usuwanie wezla" << node->data << endl;
        delete node;
    }
}



#endif //UNTITLED25_MYSTACJ_H
