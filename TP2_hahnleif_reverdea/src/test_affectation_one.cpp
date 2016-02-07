/**
 * @author Auriane, Felix.
 * @date 07/01/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la surcharge
 *  d'affectation.
 */ 

#include "Dvector.h"
#include <assert.h>

int main()
{
    Dvector x(3, 2.5);
    x = x;
    x.display(std::cout);
}
