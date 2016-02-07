#include "Dvector.h"
#include <iomanip>

/**
 * @brief Fonction auxiliaire vérifiant si l'argument d'entrée se trouve
 * dans l'intervalle voulu. Elle lève une exception si ce n'est pas 
 * le cas.
 * @param inf : Si l'argument est strictement inférieur, alors on lève
 * une exception.
 * @param max : Si l'argument est strictement supérieur, alors on lève
 * une exception.
 */
void Dvector::checkInterval(int inf, int max, int arg)
{
    std::string msg = "L'argument d'entrée n'est pas dans l'intervalle voulu!";
    if(arg < inf || arg > max)
        throw std::out_of_range(msg);
}

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
    {
        pCor[i] = init;
    }
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
    {
        pCor[i] = d.pCor[i];
    }
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
Dvector operator + (const Dvector & dvec, const double & d)
{
    Dvector res(dvec.size());
    for(int i = 0; i<res.size(); i++)
    {
        res.pCor[i] = dvec.pCor[i] + d;
    }
    return res;
}

Dvector operator + (const double & d, const Dvector & dvec)
{
    return dvec+d;
}

/**
 * @brief Surcharge externe de l'opérateur '-' avec un double.
 */
Dvector operator - (const Dvector & dvec, const double & d)
{
    return dvec+(-d);
}

Dvector operator - (const double & d, const Dvector & dvec)
{
    for(int i=0; i<dvec.size(); i++)
        dvec.pCor[i] *= -1;
    return dvec+d;
}

/**
 * @brief Surcharge externe de l'opérateur '*' avec un double.
 */
Dvector operator * (const Dvector & dvec, const double & d)
{
    Dvector res(dvec.size());
    for(int i = 0; i<res.size(); i++)
    {
        res.pCor[i] = dvec.pCor[i]*d;
    }
    return res;
}

Dvector operator * (const double & d, const Dvector & dvec)
{
    return dvec*d;
}

/**
 * @brief Surcharge externe de l'opérateur '/' avec un double.
 */
Dvector operator / (const Dvector & dvec, const double & d)
{
    if(d == 0)
        throw std::overflow_error("Division par zero!");
    return dvec*(1/d);
}

/**
 * @brief Surcharge interne de l'opérateur d'affectation '='.
 */
Dvector & Dvector::operator=(const Dvector &d)
{
    dim = d.size();
    if(pCor == d.pCor)
        return *this;
    pCor = new double[dim];
    std::memcpy(pCor, d.pCor, dim*sizeof(double));

    return *this;
};

/**
 * @brief Surcharge externe de l'opérateur '+' avec un autre Dvector.
 */
Dvector operator + (const Dvector & dvec1, const Dvector & dvec2)
{
    if(dvec1.size() != dvec2.size())
        exit(-1);
    Dvector res(dvec1.size());
    for(int i = 0; i<res.size(); i++)
    {
        res.pCor[i] = dvec1.pCor[i] + dvec2.pCor[i];
    }
    return res;
}

/**
 * @brief Surcharge externe de l'opérateur '-' avec un autre Dvector.
 */
Dvector operator - (const Dvector & dvec1, const Dvector & dvec2)
{
    //on évite le cas x = x-x
    if(dvec1.pCor == dvec2.pCor && dvec1.size() == dvec2.size())
        return dvec1*0;
    for(int i=0; i<dvec2.size(); i++)
        dvec2.pCor[i] *= -1;
    return dvec1+dvec2;
}

//implémentation de l'accesseur pour le TP2 question 2
/**
 * @brief La fonction accesseur pour les coordonnées du vecteur.
 * @param i: indice de la coordonnée à récupérer.
 * @return Un double.
 */

double & Dvector::operator ()(int i)
{
    /* TODO 
     * Pq dans les slides pour surcharge avec () on renvoie val[i+1] et non val[i-1] ?
     */
    checkInterval(1, size(), i);
    return pCor[i-1]; 
}

double & Dvector::operator [](int i)
{
    checkInterval(0, size() - 1, i);
    return pCor[i]; 
}
