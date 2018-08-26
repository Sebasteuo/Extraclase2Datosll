#include <iostream>
#include <string>

using namespace std;

class Luces{
public:
    void lucesEncendidas(){
        cout << "Las luces se encendieron" << endl;
    }

    void lucesApagadas(){
        cout << "Las luces se apagaron" << endl;
    }
};

class Calefaccion{
public:
    void encenderCalefaccion(){
        cout << "La calefaccion esta encendida" << endl;
    }

    void apagarCalefaccion(){
        cout << "La calefaccion esta apagada" << endl;
    }
};

class AlarmaDeSeguridad{
public:
    void encenderAlarma(){
        cout << "La alarma de seguridad esta activada" << endl;
    }

    void apagarAlarma(){
        cout << "La alarma de seguridad esta apagada" << endl;
    }
};

class VerificadorDeClave{
private:
    int clave = 1234;

public:
    int getClave(){
        return clave;
    }

    bool verificarClave(int num){
        if (num == getClave()){
            return true;
        }
        else{
            return false;
        }
    }
};

class SmartHouseFacade{
public:
    SmartHouseFacade(){
    }

    void salirDeLaCasa(){
        alarma.encenderAlarma();
        calefaccion.apagarCalefaccion();
        luces.lucesApagadas();
        cout << endl;
    };

    void entrarALaCasa(int clave){
        if (verificador.verificarClave(clave)){
            alarma.apagarAlarma();
            calefaccion.encenderCalefaccion();
            luces.lucesEncendidas();
            cout << endl;

        } else {
            cout << "Clave incorrecta \n" << endl;
        }
    }

private:
    VerificadorDeClave verificador;
    AlarmaDeSeguridad alarma;
    Calefaccion calefaccion;
    Luces luces;
};

