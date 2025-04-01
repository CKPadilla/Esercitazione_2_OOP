/*
Nome, cognome e matricola: Cael Kyler Padilla | 307931
Esercitazione_1_IO complex_number

Nota dello studente: sono consapevole del fatto che il codice è commentato passo per passo e potrebbe risultare troppo;
per scopi didattici, preferisco spiegarmi ogni passaggio che faccio
anche per aiutarmi ad ottimizzare il codice in una forma più corta ed efficiente.
*/

#pragma once

#include <iostream>
#include <cmath>
#include <concepts>   //Per poter vincolare il type ad essere come richiesto


using namespace std;

template <typename T>
requires floating_point<T>   // vincoliamo ai soli floating point il type T (quindi double, long double e float)
class complex_number {
    T real;
    T imaginary;

public:
    
    // Dato che devo avere un costruttore di default, imposto che parte reale e immaginaria siano di default nulli
    complex_number ()
        : real(0) , imaginary(0)
    {}

    // Inserisco un costruttore user-defined per l'inizializzazione di parte reale e immaginaria da parte dello user
    complex_number (T re, T im)
        : real(re) , imaginary(im)
    {}

    // Creo un metodo give_real che restituisce la parte reale del complesso
    T give_real() const{
        return real;
    }

    // Creo un metodo give_imaginary che restituisce la parte immaginaria
    T give_imaginary() const {
        return imaginary;
    }

    // Creo un metodo con che restituisce il coniugato di un complesso
    complex_number coniugato() const {
        return complex_number(real, -imaginary);
    }

    // Overload +=
    complex_number& operator+=(const complex_number& w) {   // w è il secondo numero complesso
        real += w.real;
        imaginary += w.imaginary;
        return *this;   // returna real e imaginary dopo averci sommato w
    }

    // Overload +
    complex_number operator+(const complex_number& w) const {
        return complex_number(real+w.real , imaginary+w.imaginary);
    }

    // Overload *=
    complex_number& operator*=(const complex_number& w) {   
        T re = real* w.real - imaginary* w.imaginary;
        T im = real*w.imaginary + imaginary*w.real;
        real = re;
        imaginary = im;
        return *this;
    }

    // Overload *
    complex_number operator*(const complex_number& w) const{   
        return complex_number(real*w.real - imaginary*w.imaginary , real*w.imaginary + imaginary*w.real);
    }
};


/* 
Per stampare un numero complesso nel formato che voglio, sovracarico l'operatore <<. 
Devo stare attento quando la parte immaginaria è negativa e non-nagativa 
*/
template<typename T>
ostream& operator<<(ostream& os, const complex_number<T>& z) {
    os << z.give_real();
    if (z.give_imaginary() >=0) os << "+";
    os << z.give_imaginary() << "i";
    return os;
}


// Verifico il mio codice con un esempio

int main() {

    //Creo due numeri complessi e li visualizzo
    complex_number<float> z(3.0, -5.0);  
    complex_number<float> w(2.0, 6.0);

    cout << "Numero complesso z : " << z << "\n";   // stampo z
    cout << "Numero complesso w : " << w << "\n";   // stampo w

    // Visualizzo le loro parti reale e immaginaria
    cout << "La parte reale Re(z) è " << z.give_real() << endl ;
    cout << "e la sua parte immaginaria Im(z) è " << z.give_imaginary() << "\n";
    cout << "La parte reale Re(w) è " << w.give_real() << endl;
    cout << "e la sua parte immaginaria Im(w) è " << w.give_imaginary() << "\n";

    // Visualizzo il coniugato di z e w
    cout << "Il coniugato di z è " << z.coniugato() << "\n";
    cout << "Il coniugato di w è " << w.coniugato() << "\n";

    // Faccio la somma e visualizzo
    complex_number<float> s = z+w;
    cout << "La somma tra z e w è " << s << "\n";

    // Faccio la somma += e visualizzo
    z += w;
    cout << "z dopo l'operazione += : " << z << "\n";

    // Faccio il prodotto e visualizzo

    complex_number<float> p = z * w;
    cout << "Il prodotto tra z e w è " << p << "\n";

    // Faccio il prodotto *= e visualizzo
    z *= w;   // Attenzione che qui prende la z dopo l'operazione +=
    cout << "z dopo l'operazione *= : " << z << "\n";

    return 0;
}
    
