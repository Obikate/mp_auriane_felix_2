/**
 * @author Auriane, Felix.
 * @date 07/02/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la surchage
 * d'opérateur +=.
 */ 

#include "Dvector.hpp"
#include <assert.h>

int main()
{
    Dvector x(3, 2.5);
    Dvector y(3, 3);
    x += y;
    assert(x.pCor[0] == 5.5);
    assert(x.pCor[1] == 5.5);
    assert(x.pCor[2] == 5.5);
    std::cout<<"x.pCor[0] : "<<x.pCor[0]<<std::endl;
    std::cout<<"x.pCor[1] : "<<x.pCor[1]<<std::endl;
    std::cout<<"x.pCor[2] : "<<x.pCor[2]<<std::endl;
    //x += -x;
    //ATTENTION ICI LE X EST MODIFIE EN -X => LE RESULTAT 
    //DEVRAIT ETRE 0 MAIS C'EST EN FAIT -11.
    x += (-1*x);
    assert(x.pCor[0] == 0);
    assert(x.pCor[1] == 0);
    assert(x.pCor[2] == 0);
    std::cout<<"OK"<<std::endl;
}
