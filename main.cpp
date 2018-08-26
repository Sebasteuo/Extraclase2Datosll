#include <string>
#include <iostream>
#include <memory>
#include "Adapter.cpp"
#include "Facade.cpp"

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
        m_sandwich = make_unique<Sandwich>();
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

int main()
{
    /*
     * Builder
     */
    cout << "Builder\n" << endl;

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
    nerf = NULL;
    pistolaDeAgua = NULL;

    /*
     * Facade
     */
    cout << "\n\nFacade \n" << endl;

    SmartHouseFacade smartHouse;

    smartHouse.salirDeLaCasa();
    smartHouse.entrarALaCasa(4321);
    smartHouse.entrarALaCasa(1234);
}