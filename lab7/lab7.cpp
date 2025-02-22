#include <iostream>
#include <string>
using namespace std;

// Superclase Carro
class Carro {
protected:
    string marca;
    string modelo;
private:
    int anio;  // Cambiado 'año' por 'anio' para evitar problemas de codificación
public:
    Carro(string m, string mod, int a) : marca(m), modelo(mod), anio(a) {}
    virtual void mostrarInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Anio: " << anio << endl;
    }
    virtual ~Carro() {}
};

// Clase derivada CarroDeportivo
class CarroDeportivo : public Carro {
private:
    int velocidadMaxima;
public:
    CarroDeportivo(string m, string mod, int a, int v) : Carro(m, mod, a), velocidadMaxima(v) {}
    void mostrarInfo() override {
        Carro::mostrarInfo();
        cout << "Velocidad Maxima: " << velocidadMaxima << " km/h" << endl;
    }
};

// Clase derivada CarroDeLujo
class CarroDeLujo : public Carro {
private:
    string tipoInterior;
public:
    CarroDeLujo(string m, string mod, int a, string t) : Carro(m, mod, a), tipoInterior(t) {}
    void mostrarInfo() override {
        Carro::mostrarInfo();
        cout << "Tipo de Interior: " << tipoInterior << endl;
    }
};

// Clase derivada CarroEconomico
class CarroEconomico : public Carro {  // Cambiado 'CarroEconómico' por 'CarroEconomico'
private:
    float consumoCombustible;
public:
    CarroEconomico(string m, string mod, int a, float c) : Carro(m, mod, a), consumoCombustible(c) {}
    void mostrarInfo() override {
        Carro::mostrarInfo();
        cout << "Consumo de Combustible: " << consumoCombustible << " L/100km" << endl;
    }
};

int main() {
    // Crear objetos de cada tipo de carro
    CarroDeportivo deportivo("Ferrari", "488 GTB", 2021, 340);
    CarroDeLujo lujo("Mercedes", "S-Class", 2023, "Cuero y madera");
    CarroEconomico economico("Toyota", "Corolla", 2022, 6.5);

    // Mostrar información de cada carro
    cout << "Carro Deportivo:" << endl;
    deportivo.mostrarInfo();
    cout << endl;

    cout << "Carro de Lujo:" << endl;
    lujo.mostrarInfo();
    cout << endl;

    cout << "Carro Economico:" << endl;
    economico.mostrarInfo();
    cout << endl;

    return 0;
}