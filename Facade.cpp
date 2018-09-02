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
    /// Calcula la temperatura de la casa.
    /// \return La temperatura en grados Centigrados.
    int calcularTemperatura(){
        int loading = 3;
        string loadingLabel = "Calculando temperatura";

        temperatura = rand() % 35;

        //Disimula que esta calculando la temperatura.
        while(loading != 0){
            loadingLabel += ".";

            if (loading == 1){
                loadingLabel += "Listo";
                cout << loadingLabel << endl;
            }
            else{
                cout << loadingLabel << endl;
                //Congela el thread principal por 1 segundo.
                this_thread::sleep_for (chrono::seconds(1));
            }
            loading--;
        }

        cout << "La temperatura es de " << temperatura << " ºC" << endl;

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

    /// Verifica la clave ingresada.
    /// \param num La clave digitada.
    /// \return True si es la clave correcta o False si no.
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

    /// Hace las acciones apropiadas cuando el propietario sale de la casa.
    void salirDeLaCasa(){
        alarma.encenderAlarma();

        if (termometro.getTemperatura() < 20)
            calefaccion.apagarCalefaccion();
        else
            aire.apagarAire();

        luces.lucesApagadas();
        cout << endl;
    };

    /// Hace las acciones apropiadas cuando el propietario entra de la casa.
    /// \param clave La clave para ingresar a la casa.
    void entrarALaCasa(int clave){
        int temperatura = termometro.calcularTemperatura();

        if (temperatura < 20)
            calefaccion.encenderCalefaccion();
        else
            aire.encenderAire();

        ///Verifica la clave.
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

