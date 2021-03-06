/**
 * @author Auriane, Felix.
 * @date 08/02/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la méthode
 * resize.
 * Il y a un comportement invalide dans ce test, utilisation d'une dimension
 * négative, ainsi il y aura une perte de mémoire.
 */ 

#include "Dvector.hpp"
#include <assert.h>

int main()
{
    Dvector x(3, 2.5);
    x.resize(-3, 0);
    std::cout<<"OK"<<std::endl;
}
