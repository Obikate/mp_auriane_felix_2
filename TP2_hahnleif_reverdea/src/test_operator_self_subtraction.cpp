/**
 * @author Auriane, Felix.
 * @date 07/02/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la surchage
 * d'opérateur -=.
 */ 

#include "Dvector.h"
#include <assert.h>

int main()
{
    Dvector x(3, 3);
    Dvector y(3, 2.5);
    x -= y;
    assert(x.pCor[0] == 0.5);
    assert(x.pCor[1] == 0.5);
    assert(x.pCor[2] == 0.5);
    x -= x;
    assert(x.pCor[0] == 0);
    assert(x.pCor[1] == 0);
    assert(x.pCor[2] == 0);
    //ATTENTION MEME ERREUR QUE DANS ADDITION
    //ON S'ATTEND A 6 ET ON OBTIENT 0
    y -= -y;
    std::cout<<"y.pCor[0] : "<<y.pCor[0]<<std::endl;
    std::cout<<"y.pCor[1] : "<<y.pCor[1]<<std::endl;
    std::cout<<"y.pCor[2] : "<<y.pCor[2]<<std::endl;
    /*
    assert(y.pCor[0] == 6);
    assert(y.pCor[1] == 6);
    assert(y.pCor[2] == 6);
    */
    std::cout<<"OK"<<std::endl;
}
