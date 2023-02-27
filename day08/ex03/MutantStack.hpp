#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP 

#   include <iostream>
#   include <cstdlib.h>
#   include <stack>
#   include <dequeu>

class MutantStack {

    public:
        // Constructeur
        MutantStack(void);

        // Constructeur Copie
        MutantStack(const MutantStack &obj);

        // Destructeur
        virtual ~MutantStack();

        // Accesseur 
        int getvaleur() const;

        // Modifieur 
        void setValeur(int valeur);

        // surcharge d'asignation
        MutantStack &operator=(const MutantStack &obj);

    private:
        // [ .... ]

    protected: 
        // [ .... ]
};

// surcharge d'affichage
std::ostream &operator<<(std::ostream &cout, const MutantStack &obj);

#endif
