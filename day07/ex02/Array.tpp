#ifndef ARRAY_HPP
# define ARRAY_HPP 

#  include <iostream>

template<typename T>
class Array {

    public:
        // Constructeur
        Array(void);

        // Constructeur Copie
        Array(const Array &obj);

        // Destructeur
        ~Array();

        // Accesseur 
        int getvaleur() const;

        // Modifieur 
        void setValeur(int valeur);

        // surcharge d'asignation
        Array &operator=(const Array &obj);

    private:
        T *_array;
        // [ .... ]

    protected: 
        // [ .... ]
};

// surcharge d'affichage
std::ostream &operator<<(std::ostream &cout, const Array &obj);

#endif
