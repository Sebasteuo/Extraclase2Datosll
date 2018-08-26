#include <iostream>
#include <string>
#include "LinkedList.cpp"

class Cliente{
public:
    Cliente(){
    }

    void update(string sub){
        cout << "El sub del dia es " << sub << endl;
    }
};

class Subway{
public:
    void addObserver(Cliente *cliente){
        list->add(cliente);
    }

    void notifyObserver(){
        const string subsDelDia[] = {"Pollo al Grill", "Atun", "Italiano B.M.T", "Pizza Sub",
                               "Mariscos y Cangrejo", "Jamon", "Italiano Picante"};

        time_t rawtime;
        tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        int today = timeinfo->tm_wday;

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