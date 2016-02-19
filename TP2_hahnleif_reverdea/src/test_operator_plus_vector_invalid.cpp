/**
 * @author Auriane, Felix.
 * @date 07/02/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la surchage
 * d'opérateur.
 * Le test effectue une opération invalide, l'addition entre deux vecteurs
 * de tailles différentes. Le programme va alors être interrompu en mi-chemin
 * et la mémoire ne va pas être complètement libérée.
 */ 

#include "Dvector.hpp"
#include <assert.h>

int main()
{
    Dvector x(3, 2.5);
    Dvector y;
    x = x + y;
    std::cout<<"OK"<<std::endl;
}
