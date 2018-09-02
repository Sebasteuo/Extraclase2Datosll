#include <iostream>
#include <string>
#include "LinkedList.cpp"

/*
 * Patron Observer
 */
class Cliente{
public:
    Cliente(){
    }

    //Actualiza a los observadores el estado
    void update(string sub){
        cout << "El sub del dia es " << sub << endl;
    }
};

class Subway{
public:
    //Adiciona un observer a la lista
    void addObserver(Cliente *cliente){
        list->add(cliente);
    }

    //Notifica a los subcritores
    void notifyObserver(){
        const string subsDelDia[] = {"Pollo al Grill", "Atun", "Italiano B.M.T", "Pizza Sub",
                               "Mariscos y Cangrejo", "Jamon", "Italiano Picante"};

        //Obtiene el dia
        time_t rawtime;
        tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        int today = timeinfo->tm_wday;

        //Actualiza a los subcriptores
        for (int i = 0; i < list->length(); ++i) {
            list->get(i)->update(subsDelDia[today]);
        }
    }

    ~Subway(){
        list = nullptr;
    }

private:
    LinkedList<Cliente *> *list = new LinkedList<Cliente *>();
};