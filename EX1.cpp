/*
 * main.cpp
 *
 *  Created on: 23 oct. 2026
 *      Author: hP
 */

#include <iostream>
#include <string>
using namespace std; // @suppress("Symbol is not resolved")

class Livre {
private:
    string titre;
    string auteur;
    int annee;
    static int nbLivres;   // attribut statique (partagé par tous les livres)

public:
    // Constructeur : initialise les attributs et incrémente le compteur
    Livre(string t, string a, int an) {
        titre = t;
        auteur = a;
        annee = an;
        nbLivres++;
    }

    void afficher() {
        cout << titre << " - " << auteur << " (" << annee << ")" << endl;
    }

    // Méthode statique : appelable sans objet
    static void afficherTotal() {
        cout << "Nombre total de livres : " << nbLivres << endl;
    }
};

// Initialisation de l'attribut statique (obligatoire, en dehors de la classe)
int Livre::nbLivres = 0;

int main() {
    // Appel sans instanciation : doit afficher 0
    Livre::afficherTotal();

    Livre l1("1984", "George Orwell", 1949);
    Livre l2("Le Petit Prince", "Antoine de Saint-Exupéry", 1943);
    Livre l3("L'Étranger", "Albert Camus", 1942);

    l1.afficher();
    l2.afficher();
    l3.afficher();

    Livre::afficherTotal(); // Affiche 3
    return 0;
}

