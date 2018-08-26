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

    void disparar() override {
        if (municiones == 0)
            cout << "La pistola no tiene municiones" << endl;
        else {
            municiones--;
            cout << "Bang Bang" << endl;
            cout << "La pistola tiene ahora " << municiones << " municiones";
        }
    }

    void recargar() override {
        municiones = 6;
        cout << "La pistola tiene ahora " << municiones << " municiones";
    }
};

class PistolaDeAgua{
public:
    int agua = 100;

    PistolaDeAgua(){
    }

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

    void llenarDeAgua(){
        agua = 100;
        cout << "A la pistola le quedan " << agua << " mL" << endl;
    }
};

class PistolaDeAguaAdapter : public PistolInterface{
public:
    PistolaDeAguaAdapter(PistolaDeAgua *pistolaDeAgua){
        this->pistolaDeAgua = pistolaDeAgua;
    }

    void disparar() override {
        pistolaDeAgua->dispararAgua();
    }

    void recargar() override {
        pistolaDeAgua->llenarDeAgua();
    }

private:
    PistolaDeAgua *pistolaDeAgua;
};