/**
 * @author Auriane, Felix.
 * @date 07/01/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la méthode
 * checkInterval.
 */ 

#include "Dvector.h"
#include <assert.h>

int main()
{
    Dvector x(3, 2.5);
    x.checkInterval(0, 4, 0);
    x.checkInterval(0, 4, 4);
//    x.checkInterval(0, 4, -1);
    x.checkInterval(0, 4, 5);
}
