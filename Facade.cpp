#include <iostream>
#include <string>
#include <thread>
#include <chrono>

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

class AireAcondicionado{
public:
    void encenderAire(){
        cout << "Se encendio el aire acondicionado" << endl;
    }

    void apagarAire(){
        cout << "Se apago el aire acondicionado" << endl;
    }
};

class Termometro{
public:
    int calcularTemperatura(){
        int loading = 3;
        string loadingLabel = "Calculando temperatura";

        temperatura = rand() % 35;
        while(loading != 0){
            loadingLabel += ".";

            if (loading == 1){
                loadingLabel += "Listo";
                cout << loadingLabel << endl;
            }
            else{
                cout << loadingLabel << endl;
                this_thread::sleep_for (chrono::seconds(1));
            }
            loading--;
        }

        cout << "La temperatura es de " << temperatura << endl;
        return temperatura;
    }

    int getTemperatura(){
        return temperatura;
    }

private:
    int temperatura = 0;
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

        if (termometro.getTemperatura() < 20)
            calefaccion.apagarCalefaccion();
        else
            aire.apagarAire();

        luces.lucesApagadas();
        cout << endl;
    };

    void entrarALaCasa(int clave){
        int temperatura = termometro.calcularTemperatura();

        if (temperatura < 20)
            calefaccion.encenderCalefaccion();
        else
            aire.encenderAire();

        if (verificador.verificarClave(clave)){
            alarma.apagarAlarma();

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
    AireAcondicionado aire;
    Termometro termometro;
    Luces luces;
};

