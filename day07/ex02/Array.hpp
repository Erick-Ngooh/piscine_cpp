#ifndef ARRAY_HPP
# define ARRAY_HPP 

#   include <iostream>
#   include <exception>

template<typename T>
class Array {

    public:

        // exception   
        class Overflow : public std::exception {
            public:
                virtual const char *what(void) const throw() {
                    return "Error: buffer overflow";
                };
        };

        // Constructeur
        Array(void) : _array(NULL), _size(0) {}

        Array(unsigned int n) {
            if (n >= 1) {
                _array = new T[n];
                _size = n;
            }
            else {
                _array = NULL;
                _size = 0;
            }
        }

        // Constructeur Copie
        Array(const Array &obj) {
            *this = obj;
        }


        // Destructeur
        ~Array(void) {
            if (_array)
                delete _array;
        }

        //getter 
        unsigned int size(void) {
            return _size;
        }

        // surcharge d'asignation
        Array &operator=(const Array &obj) {
            if (_array)
                delete _array;
  
            _size = obj._size;
            if (_size > 0) {
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = obj._array[i];
            }
            else {
                _array = NULL;
                _size = 0;
            } 
            return *this;
        }
        
        T &operator[](const unsigned int n) {
            if (_size < 1 || n >= _size)
                throw(Overflow());
            return _array[n];
        }


    private:
        T           *_array;
        unsigned int _size;
        // [ .... ]

    protected: 
        // [ .... ]
};

// surcharge d'affichage
template<typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &obj);

#endif
