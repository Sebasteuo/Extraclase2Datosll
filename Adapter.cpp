#include <iostream>
#include <string>

using namespace std;


class PistolInterface{
public:
    int municiones = 0;


    virtual void disparar() = 0;
    virtual void recargar() = 0;
};

class Pistola : public PistolInterface{
public:
    Pistola(){
    }

    ///Imprime un sonido de disparo.
    void disparar() override {
        if (municiones == 0)
            cout << "La pistola no tiene municiones" << endl;
        else {
            municiones--;
            cout << "Bang Bang" << endl;
            cout << "La pistola tiene ahora " << municiones << " municiones";
        }
    }

    ///Recarga las municiones de la pistola.
    void recargar() override {
        municiones = 6;
        cout << "La pistola tiene ahora " << municiones << " municiones";
    }
};

class PistolaDeAgua{
public:
    int agua = 100;

    ///Constructor.
    PistolaDeAgua(){
    }

    ///Imprime un sonido de disparo de agua.
    void dispararAgua(){
        if (agua == 0){
            cout << "No queda agua" << endl;
        }
        else{
            agua -= 20;
            cout << "Splash Splash" << endl;
            cout << "A la pistola le quedan " << agua << " mL" << endl;

        }
    }

    ///Recarga el tanque de agua de la pistola.
    void llenarDeAgua(){
        agua = 100;
        cout << "A la pistola le quedan " << agua << " mL" << endl;
    }
};

class PistolaDeAguaAdapter : public PistolInterface{
public:
    /// Constructor.
    /// \param pistolaDeAgua Objeto al que se adapta a Pistola.
    PistolaDeAguaAdapter(PistolaDeAgua *pistolaDeAgua){
        this->pistolaDeAgua = pistolaDeAgua;
    }

    ///Imprime un sonido de disparo.
    void disparar() override {
        pistolaDeAgua->dispararAgua();
    }

    ///Recarga las municiones de la pistola.
    void recargar() override {
        pistolaDeAgua->llenarDeAgua();
    }

private:
    PistolaDeAgua *pistolaDeAgua;
};