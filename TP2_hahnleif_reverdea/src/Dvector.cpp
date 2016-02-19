#include "Dvector.hpp"
#include <iomanip>

//implémentation des constructeurs et méthodes pour la question 1
/**
 * @brief Le constructeur par défaut.
 * @param d: entier spécifiant la dimension du vecteur.
 * @param inti: double spécifiant la valeur par défaut des coordonnées.
 */
Dvector::Dvector(int d, double init)
{
    std::cout<<"Appel au constructeur normal"<<std::endl;
    dim = d;
    //si le constructeur est vide, alors on simule le constructeur
    //"par défaut" en initialisant ses champs à 0 et NULL.
    if(dim==0)
    { 
        pCor = NULL;
        return ;
    }
    pCor = new double[dim];
    for(int i=0; i<dim; i++)
        pCor[i] = init;
}

/**
 * @brief Le destructeur. On désalloue seulement pCor si il a été
 * initialisé.
 */
Dvector::~Dvector()
{
    std::cout<<"Appel au destructeur"<<std::endl;
    if(pCor != NULL)
    {
        delete [] pCor;
        pCor = NULL;
    }
}

/**
 * @brief Fonction auxiliaire de la fonction "display".
 * @return renvoie le nombre de chiffres décimaux du double d'entrée.
 */
int doubleLength(double x)
{
    int length = 1;
    //on veut afficher au moins 2 chiffres décimaux
    if(x >= 10)
        return 3;
    //on s'intéresse uniquement à la partie fractionnaire
    x -= int(x);
    while(x != 0)
    {
        length++;
        x *= 10;
        x -= int(x);
    }
    return length;
}

/**
 * @brief La fonction d'affichage.
 * @param str: Le flux utilisé pour l'affichage, de type std::ostream&.
 * Il s'agit d'une référence.
 */
void Dvector::display(std::ostream& str)
{
    //on veut afficher au moins deux chiffres décimaux, il nous faut
    //alors la "longueur" du nombre courant.
    for(int i=0; i<dim; i++)
    {
        if(doubleLength(pCor[i]) < 2)
            str<<std::setprecision(1)<<std::fixed<<pCor[i]<<"\n";
        else
            str<<pCor[i]<<"\n";
    }
}

//implémentation des constructeurs et méthodes pour la question 2
/**
 * @brief La fonction accesseur pour la dimension du vecteur.
 * @return Un entier constant.
 */
int Dvector::size(int catchError) const
{
    return dim;
}

/**
 * @brief La fonction remplit remplit les coordonnées du vecteur selon
 * une loi uniforme sur [0, 1] en utilisant la fonction random() de la
 * bibliothèque "stdlib.h"
 */
void Dvector::fillRandomly(int catchError)
{
    //pour que la méthode renvoie "vraiment" des nouvelles valeurs à 
    //chaque fois qu'on appelle la fonction, il faut initialiser le
    //générateur de nombres aléatoires en semant une graine.
    for(int i=0; i<dim; i++)
        pCor[i] = (double)random()/(double)RAND_MAX;
}

/**
 * @brief Le constructeur par copie appelé automatiquement.
 */
Dvector::Dvector(const Dvector & d)
{
    //on accède à la valeur d'un champ privé
    std::cout<<"Appel au constructeur par recopie"<<std::endl;
    dim = d.size();
    if(dim == 0)
        return ;
    pCor = new double[dim];
    for(int i=0; i<dim; i++)
        pCor[i] = d[i];
}

//implémentation des constructeurs et méthodes pour la question 3
/**
 * @brief Le constructeur "par fichier". Recopie de tous les doubles se
 * trouvant dans le fichier dans le tableau de l'objet à créer.
 * @param str: une chaîne de caractères décrivant le chemin relatif du 
 * fichier.
 */
Dvector::Dvector(std::string str)
{
    std::cout<<"Appel au constructeur par fichier"<<std::endl;
    //on recupère d'abord la taille du vecteur à créer
    std::fstream file(str.c_str());
    dim = 0;
    //on vérifie si le fichier existe
    if(!file.good())
    {
        dim = 0;
        return ;
    }
    else {
        //on parcourt le fichier pour trouver le nombre d'éléments du fichier
        file.seekg(0, std::ios::beg);
        double tmp;
        while(file>>tmp)
            dim++;
        //on est à la fin du fichier
        file.clear();
        file.seekg(0, std::ios::beg);
    }
    //on vérifie s'il s'agit d'un fichier vide
    if(dim == 0)
    {
        pCor = NULL;
        return ;
    }
    //recopie des valeurs
    pCor = new double[dim];
    for(int i=0; i<dim; i++)
    {
        file>>pCor[i];
    }
    file.close();
}

/**
 * @brief Surcharge externe de l'opérateur '+' avec un double.
 */
Dvector operator + (const Dvector & dVec, const double & d)
{
    Dvector res(dVec.size());
    for(int i = 0; i<res.size(); i++)
    {
        res[i] = dVec[i] + d;
    }

    return res;
}

Dvector operator + (const double & d, const Dvector & dVec)
{
    return dVec+d;
}

/**
 * @brief Surcharge externe de l'opérateur '-' avec un double.
 */
Dvector operator - (const Dvector & dVec, const double & d)
{
    return dVec+(-d);
}

Dvector operator - (const double & d, const Dvector & dVec)
{
    return (-1*dVec)+d;
}

/**
 * @brief Surcharge externe de l'opérateur '*' avec un double.
 */
Dvector operator * (const Dvector & dVec, const double & d)
{
    Dvector res(dVec.size());
    for(int i = 0; i<res.size(); i++)
        res[i] = dVec[i]*d;
    return res;
}

Dvector operator * (const double & d, const Dvector & dVec)
{
    return dVec*d;
}

/**
 * @brief Surcharge externe de l'opérateur '/' avec un double.
 */
Dvector operator / (const Dvector & dVec, const double & d)
{
    if(d == 0)
        throw std::overflow_error("Division par zero!");
    return dVec*(1/d);
}

/**
 * @brief Surcharge interne de l'opérateur d'affectation '='.
 * Version 1.
 */
Dvector & Dvector::operator=(const Dvector &dVec)
{
    dim = dVec.size();
    if(pCor == dVec.pCor)
        return *this;
    delete [] pCor;
    pCor = new double[dim];
    std::memcpy(pCor, dVec.pCor, dim*sizeof(double));

    return *this;
};

/**
 * @brief Surcharge interne de l'opérateur d'affectation '='.
 * Version 2.
 */
//Dvector & Dvector::operator=(const Dvector &dVec)
//{
//    dim = dVec.size();
//    if(pCor == dVec.pCor)
//        return *this;
//    delete [] pCor;
//    pCor = new double[dim];
//    for(int i=0; i<dim; i++)
//        pCor[i] = dVec[i];
//    return *this;
//};



/**
 * @brief Surcharge interne de l'opérateur unaire '-'.
 */
Dvector operator-(const Dvector & dVec)
{
    Dvector res = -1*dVec;
    return res;
};



/**
 * @brief Surcharge externe de l'opérateur '+' avec un autre Dvector.
 */
Dvector operator + (const Dvector & dVec1, const Dvector & dVec2)
//Dvector operator + (Dvector dVec1, Dvector dVec2)
{
    if(dVec1.size() != dVec2.size())
        exit(-1);
    Dvector res(dVec1.size());
    for(int i = 0; i<res.size(); i++)
    {
        res[i] = dVec1[i] + dVec2[i];
    }
    return res;
}

/**
 * @brief Surcharge externe de l'opérateur '-' avec un autre Dvector.
 */
Dvector operator - (const Dvector & dVec1, const Dvector & dVec2)
{
    //on évite le cas x = x-x
    if(dVec1.pCor == dVec2.pCor && dVec1.size() == dVec2.size())
        return dVec1*0;
    return dVec1+(-1*dVec2);
}

//implémentation de l'accesseur pour le TP2 question 2
/**
 * @brief La fonction accesseur pour les coordonnées du vecteur.
 * @param i: indice de la coordonnée à récupérer.
 * @return Un double.
 */

double & Dvector::operator ()(int i)
{
    return (*this)[i]; 
}

/**
 * @brief Même fonction que la fonction précédente, juste pour
 * des valeurs de retour constantes.
 */
double & Dvector::operator()(int i) const
{
    return (*this)[i]; 
}


double & Dvector::operator [](int i)
{
    assert(i >= 0 && i < size());
    return pCor[i]; 
}

/**
 * @brief Même fonction que la fonction précédente, juste pour
 * des valeurs de retour constantes.
 */
double & Dvector::operator[](int i) const
{
    assert(i >= 0 && i < size());
    return pCor[i]; 
}

/**
 * @brief Surcharge externe du outputstream.
 */
std::ostream & operator <<(std::ostream & out, const Dvector & dVec)
{
    out<<"Dvector: ";
    for(int i=0; i<dVec.size(); i++)
        out<<dVec[i]<<" ";
    out<<std::endl;
    return out;
}

/**
 * @brief Surcharge externe du inputstream.
 */
std::istream & operator >>(std::istream & in, const Dvector & dVec)
{
    double tmp;
    for(int i=0; i<dVec.size(); i++)
    {
        in>>tmp;
        dVec[i] = tmp;
    }
    return in;
}

/**
 * @brief Surcharge interne de l'opérateur d'affectation '+='.
 */
Dvector & Dvector::operator+=(const Dvector &dVec)
{
   if (dim != dVec.size()) 
       exit(-1);
   for (int i = 0; i < dim; i++)
       (*this)[i] += dVec[i];
   return *this;
}

/**
 * @brief Surcharge interne de l'opérateur d'affectation '+=' avec un réel.
 */
Dvector & Dvector::operator+=(const double & d)
{
   for (int i = 0; i < dim; i++)
       (*this)[i] += d;
   return *this;
}

/**
 * @brief Surcharge interne de l'opérateur d'affectation '-='.
 */
Dvector & Dvector::operator-=(const Dvector &dVec)
{
   return *this+=-dVec;//(-1*dVec);
}

/**
 * @brief Surcharge interne de l'opérateur d'affectation '-=' avec un réel.
 */
Dvector & Dvector::operator-=(const double & d)
{
   return *this+=(-d);
}


/**
 * @brief Surcharge interne de l'opérateur d'affectation '*='.
 */
Dvector & Dvector::operator*=(const double & d)
{
   for (int i = 0; i < dim; i++)
       (*this)[i] *= d;
   return *this;
}

/**
 * @brief Surcharge interne de l'opérateur d'affectation '/='.
 */
Dvector & Dvector::operator/=(const double & d)
{
   if (d == 0)
        throw std::overflow_error("Division par zero!");
   return *this*=(1/d);
}

/**
 * @brief Surcharge interne de l'opérateur d'égalité '=='.
 */
bool Dvector::operator==(const Dvector & dVec)
{
    if(size() != dVec.size())
        return false;
    for(int i=0; i<size(); i++)
    {
        if(this->pCor[i] != dVec[i])
            return false;
    }
    return true;
}

/**
 * @brief Surcharge interne de l'opérateur d'inégalité '!='.
 */
bool Dvector::operator!=(const Dvector & dVec)
{
    return !(*this == dVec);
}

/**
 * @brief La méthode resize permet de redimensionner le vecteur en
 * définissant directement les nouvelles valeurs éventuellement
 * ajoutées.
 */
void Dvector::resize(int newDim, double newVal)
{
    assert(newDim >= 0 && newDim <= INT_MAX);
    if(newDim <= dim)
        dim = newDim;
    else
    {
        //on fait une réallocation de mémoire
        double tmpTab[newDim];
        memcpy(tmpTab, pCor, dim*sizeof(double));
        delete [] pCor;
        pCor = new double[newDim];
        //recopie des valeurs
        memcpy(pCor, tmpTab, dim*sizeof(double));
        for(int i=dim; i<newDim; i++)
            pCor[i] = newVal;
        dim=newDim;
    }
}
