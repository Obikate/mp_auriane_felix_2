/**
 * @author Auriane, Felix.
 * @date 07/02/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la surcharge
 * d'opérateur.
 */ 

#include "Dvector.hpp"
#include <assert.h>
#include <sstream>

int main()
{
    Dvector y(2);
    std::cout<<"Rentrez: \n2\n2\n";
    std::cin>>y;
    assert(y[0] == 2);
    assert(y[1] == 2);
    std::cout<<"OK"<<std::endl;
}
