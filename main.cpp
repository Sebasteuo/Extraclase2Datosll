/**
 * Instituto Tecnológico de Costa Rica
 * Profesor: Isaac Ramírez
 * Estudiantes: Sebastián Alba, Isaac Benavidez y Gabriel Brenes
 * Ingeniería en computadores
 * Patrones de diseño en C++

 * Bibliografía y Webgrafía:
 * 1.C++ Programming: Code patterns design - Wikibooks, open books for an open world. (2018).
 * Retrieved from https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns
 * 2.Design Patterns (C++): Introduction - 2018. (2018). Retrieved from http://www.bogotobogo.com/
 * DesignPatterns/introduction.php
 */
#include <string>
#include <iostream>
#include <memory>
#include "Adapter.cpp"
#include "Facade.cpp"
#include "Observer.cpp"


/** PATRON BUILDER
 * El patrón Builder se usa para separar la construcción de un objeto complejo de su representación para que el mismo proceso
 * de construcción pueda crear diferentes representaciones de objetos.Ejemplo, cuando queremos construir un objeto complejo,
 * sin embargo no queremos tener un constructor complejo o uno que necesitaría muchos argumentos.Lo que se hace es definir
 * un objeto intermedio con funciones que definen la parte del objeto deseado por pieza antes de que el objeto esté disponible
 * para el cliente. El patrón Builder nos permite separar la construcción del objeto hasta que se hayan especificado todas las
 * opciones de creación.
 */
using namespace std;

// "Producto"
class Sandwich
{
public:
    void ponerPan(const string& pan)
    {
        m_pan = pan;
    }
    void ponerSalsa(const string& salsa)
    {
        m_salsa = salsa;
    }
    void ponerVegetales(const string& vegetales)
    {
        m_vegetales = vegetales;
    }
    void abrir() const
    {
        cout << "Sandwich con " << "pan " << m_pan << ", "  << "salsa "<< m_salsa  << ", "
              << "y con los vegetales " << m_vegetales   << ".¡Mae qué rico! "<< endl;
    }
private:
    string m_pan;
    string m_salsa;
    string m_vegetales;
};

// "Abstract Builder"
class SandwichBuilder
{
public:
    virtual ~SandwichBuilder() {};

    Sandwich* getSandwich()
    {
        return m_sandwich.release();
    }
    void crearNuevoProductoSandwich()
    {
        m_sandwich =  make_unique<Sandwich>();
    }
    virtual void hacerPan() = 0;
    virtual void hacerSalsa() = 0;
    virtual void hacerVegetales() = 0;
protected:
    unique_ptr<Sandwich> m_sandwich;
};

//----------------------------------------------------------------

class VegetarianoSandwichBuilder : public SandwichBuilder
{
public:
    virtual ~VegetarianoSandwichBuilder() {};

    virtual void hacerPan()
    {
        m_sandwich->ponerPan("de Avena");
    }
    virtual void hacerSalsa()
    {
        m_sandwich->ponerSalsa(" Verde");
    }
    virtual void hacerVegetales()
    {
        m_sandwich->ponerVegetales("manzana y zanahoria");
    }
};

class FitnessSandwichBuilder : public SandwichBuilder
{
public:
    virtual ~FitnessSandwichBuilder() {};

    virtual void hacerPan()
    {
        m_sandwich->ponerPan("integral");
    }
    virtual void hacerSalsa()
    {
        m_sandwich->ponerSalsa("Mostaza Miel");
    }
    virtual void hacerVegetales()
    {
        m_sandwich->ponerVegetales("Lechuga y Pepinillos");
    }
};

//----------------------------------------------------------------

class Cocinar
{
public:
    void abrirSandwich()
    {
        m_SandwichBuilder->getSandwich()->abrir();
    }
    void hacerSandwich(SandwichBuilder* pb)
    {
        m_SandwichBuilder = pb;
        m_SandwichBuilder->crearNuevoProductoSandwich();
        m_SandwichBuilder->hacerPan();
        m_SandwichBuilder->hacerSalsa();
        m_SandwichBuilder->hacerVegetales();
    }
private:
    SandwichBuilder* m_SandwichBuilder;
};
/**
 * ABSTRACT FACTORY
     * Abstract Factory: Crea una instancia de varias familias de clases.Es útil en una situación que requiere la creación de
     * muchos tipos diferentes de objetos, todos derivados de un tipo base común.El método Factory define un método para crear
     * los objetos, que las subclases pueden reemplazar para especificar el tipo derivado que se creará.
     *
     * Solución: definir una interfaz para crear un objeto, pero dejando que las subclases decidan qué clase se creará.
     * El método Factory permite que una clase demore la creación de instancias a subclases.En el ejemplo siguiente,
     * se utiliza un método Factory para crear objetos de ordenador portátil o de escritorio en tiempo de ejecución.
     */

class Pizza {
public:
    virtual int getPrice() const = 0;
    virtual ~Pizza() {};  /*Sin esto,  no se llamará al destructor para las pizzas derivadas */
};

class SupremaPizza : public Pizza {
public:
    virtual int getPrice() const { return 850; };
    virtual ~SupremaPizza() {};
};

class MantequillaPizza : public Pizza {
public:
    virtual int getPrice() const { return 1050; };
    virtual ~MantequillaPizza() {};
};

class HawaianaPizza : public Pizza {
public:
    virtual int getPrice() const { return 1150; };
    virtual ~HawaianaPizza() {};
};

class PizzaFactory {
public:
    enum TipodePizza {
        Suprema,
        Mantequilla,
        Hawaiana
    };

    static unique_ptr<Pizza> createPizza(TipodePizza TipodePizza) {
        switch (TipodePizza) {
            case Suprema: return make_unique<SupremaPizza>();
            case Mantequilla:      return make_unique<MantequillaPizza>();
            case Hawaiana:    return make_unique<HawaianaPizza>();
        }
        throw "Tipo de pizza inválido.";
    }
};

/*
* Crear todas las pizzas e imprimir sus precios
*/
void pizza_information(PizzaFactory::TipodePizza TipodePizza)
{
    unique_ptr<Pizza> pizza = PizzaFactory::createPizza(TipodePizza);
    cout << "El precio de la pizza " << TipodePizza << " es " << pizza->getPrice()  << " colónes. " << std::endl;
}


int main()
{
    /*
     * Builder
     */
    cout << "Builder" << endl;

    Cocinar Cocinar;
    VegetarianoSandwichBuilder VegetarianoSandwichBuilder;
    FitnessSandwichBuilder    FitnessSandwichBuilder;

    Cocinar.hacerSandwich(&VegetarianoSandwichBuilder);
    Cocinar.abrirSandwich();

    Cocinar.hacerSandwich(&FitnessSandwichBuilder);
    Cocinar.abrirSandwich();

    /*
     * Adapter
     */
    cout << "\n\nAdapter \n" << endl;

    PistolaDeAgua *nerf = new PistolaDeAgua();
    PistolInterface *pistolaDeAgua = new PistolaDeAguaAdapter(nerf);

    //Con adapter
    pistolaDeAgua->disparar();
    pistolaDeAgua->recargar();

    //Sin Adapter
    nerf->dispararAgua();
    nerf->llenarDeAgua();

    delete nerf, pistolaDeAgua;
    nerf = nullptr;
    pistolaDeAgua = nullptr;

    /*
     * Facade
     */
    cout << "\n\nFacade \n" << endl;

    SmartHouseFacade smartHouse;

    smartHouse.entrarALaCasa(1234);
    smartHouse.salirDeLaCasa();
    smartHouse.entrarALaCasa(1234);

    /*
     * Observer
     */
    cout << "\n\nObserver \n" << endl;


    Subway *subway = new Subway;
    Cliente *cliente1 = new Cliente;
    Cliente *cliente2 = new Cliente;

    subway->addObserver(cliente1);
    subway->addObserver(cliente2);

    subway->notifyObserver();

    delete cliente1, cliente2, subway;


    /**
     * Factory
     */
    cout << "\n\nAbstract Factory \n" << endl;
    pizza_information(PizzaFactory::Suprema);
    pizza_information(PizzaFactory::Mantequilla);
    pizza_information(PizzaFactory::Hawaiana);
};