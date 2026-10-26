/*
 * EX2.cpp
 *
 *  Created on: 23 oct. 2026
 *      Author: hP
 */

#include <iostream>
#include <string>
using namespace std;

class Universite {
private:
    string nom;

public:
    Universite(string n) {
        nom = n;
    }

    void afficherNom() {
        cout << nom;
    }
};

class Etudiant {
private:
    string nom;
    int age;
    Universite* universite;     // pointeur vers l'université
    static int nbEtudiants;     // compteur partagé

public:
    Etudiant(string n, int a, Universite* u) {
        nom = n;
        age = a;
        universite = u;
        nbEtudiants++;
    }

    void afficher() {
        cout << "Nom : " << nom << ", Age : " << age << ", Université : ";
        universite->afficherNom();
        cout << endl;
    }

    static void afficherTotal() {
        cout << "Nombre total d'étudiants : " << nbEtudiants << endl;
    }
};

int Etudiant::nbEtudiants = 0;

int Main() {
    Universite u("Université de Casablanca");
    Etudiant e1("Amine", 20, &u);
    Etudiant e2("Sara", 21, &u);

    e1.afficher();
    e2.afficher();

    Etudiant::afficherTotal(); // Affiche 2
    return 0;
}


