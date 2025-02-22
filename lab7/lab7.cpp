#include <iostream>
#include <string>
using namespace std;

// Clase base
class CuentaBancaria {
protected:
    string titular;
    double saldo;
public:
    CuentaBancaria(string t, double s) : titular(t), saldo(s) {}

    virtual void depositar(double cantidad) {
        saldo += cantidad;
        cout << "Depositados Q" << cantidad << ". Nuevo saldo: Q" << saldo << endl;
    }

    virtual void retirar(double cantidad) {
        if (cantidad <= saldo) {
            saldo -= cantidad;
            cout << "Retirados Q" << cantidad << ". Nuevo saldo: Q" << saldo << endl;
        }
        else {
            cout << "Fondos insuficientes.\n";
        }
    }

    virtual void mostrarInformacion() const {
        cout << "Titular: " << titular << "\nSaldo: Q" << saldo << endl;
    }

    virtual ~CuentaBancaria() {}
};

// Subclase Cuenta de Ahorro
class CuentaAhorro : public CuentaBancaria {
private:
    double tasaInteres;
public:
    CuentaAhorro(string t, double s, double tasa) : CuentaBancaria(t, s), tasaInteres(tasa) {}

    void aplicarInteres() {
        double interes = saldo * tasaInteres / 100;
        saldo += interes;
        cout << "Interes aplicado: Q" << interes << ". Nuevo saldo: Q" << saldo << endl;
    }

    void mostrarInformacion() const override {
        CuentaBancaria::mostrarInformacion();
        cout << "Tasa de interes: " << tasaInteres << "%\n";
    }
};

// Subclase Cuenta Corriente
class CuentaCorriente : public CuentaBancaria {
private:
    double sobregiro;
public:
    CuentaCorriente(string t, double s, double sg) : CuentaBancaria(t, s), sobregiro(sg) {}

    void retirar(double cantidad) override {
        if (cantidad <= saldo + sobregiro) {
            saldo -= cantidad;
            cout << "Retirados Q" << cantidad << ". Nuevo saldo: Q" << saldo << endl;
        }
        else {
            cout << "Limite de sobregiro excedido.\n";
        }
    }

    void mostrarInformacion() const override {
        CuentaBancaria::mostrarInformacion();
        cout << "Limite de sobregiro: Q" << sobregiro << "\n";
    }
};

// Subclase Cuenta Plazo Fijo
class CuentaPlazoFijo : public CuentaBancaria {
private:
    int mesesRestantes;
public:
    CuentaPlazoFijo(string t, double s, int meses) : CuentaBancaria(t, s), mesesRestantes(meses) {}

    void retirar(double cantidad) override {
        if (mesesRestantes > 0) {
            cout << "No puede retirar fondos antes de " << mesesRestantes << " meses.\n";
        }
        else {
            CuentaBancaria::retirar(cantidad);
        }
    }

    void reducirMes() {
        if (mesesRestantes > 0) mesesRestantes--;
    }

    void mostrarInformacion() const override {
        CuentaBancaria::mostrarInformacion();
        cout << "Meses restantes para retiro: " << mesesRestantes << "\n";
    }
};

// Funcion principal
int main() {
    int tipoCuenta;
    string nombre;
    double saldoInicial;

    cout << "Bienvenido al sistema bancario.\n";
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);

    cout << "Ingrese saldo inicial: Q";
    cin >> saldoInicial;

    cout << "Seleccione el tipo de cuenta:\n";
    cout << "1. Cuenta de Ahorro\n";
    cout << "2. Cuenta Corriente\n";
    cout << "3. Cuenta Plazo Fijo\n";
    cout << "Opcion: ";
    cin >> tipoCuenta;

    CuentaBancaria* cuenta = nullptr;

    if (tipoCuenta == 1) {
        double tasa;
        cout << "Ingrese la tasa de interes (%): ";
        cin >> tasa;
        cuenta = new CuentaAhorro(nombre, saldoInicial, tasa);
    }
    else if (tipoCuenta == 2) {
        double sobregiro;
        cout << "Ingrese el limite de sobregiro: Q";
        cin >> sobregiro;
        cuenta = new CuentaCorriente(nombre, saldoInicial, sobregiro);
    }
    else if (tipoCuenta == 3) {
        int meses;
        cout << "Ingrese los meses de plazo: ";
        cin >> meses;
        cuenta = new CuentaPlazoFijo(nombre, saldoInicial, meses);
    }
    else {
        cout << "Opcion invalida. Saliendo...\n";
        return 0;
    }

    // Menu de operaciones
    int opcion;
    do {
        cout << "\nOperaciones disponibles:\n";
        cout << "1. Depositar dinero\n";
        cout << "2. Retirar dinero\n";
        if (tipoCuenta == 1) cout << "3. Aplicar interes (Solo Cuenta Ahorro)\n";
        if (tipoCuenta == 3) cout << "4. Reducir meses (Solo Cuenta Plazo Fijo)\n";
        cout << "5. Mostrar informacion\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        double cantidad;
        switch (opcion) {
        case 1:
            cout << "Ingrese cantidad a depositar: Q";
            cin >> cantidad;
            cuenta->depositar(cantidad);
            break;
        case 2:
            cout << "Ingrese cantidad a retirar: Q";
            cin >> cantidad;
            cuenta->retirar(cantidad);
            break;
        case 3:
            if (tipoCuenta == 1) {
                dynamic_cast<CuentaAhorro*>(cuenta)->aplicarInteres();
            }
            else {
                cout << "Opcion invalida.\n";
            }
            break;
        case 4:
            if (tipoCuenta == 3) {
                dynamic_cast<CuentaPlazoFijo*>(cuenta)->reducirMes();
                cout << "Mes reducido.\n";
            }
            else {
                cout << "Opcion invalida.\n";
            }
            break;
        case 5:
            cuenta->mostrarInformacion();
            break;
        case 6:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 6);

    delete cuenta; // Liberar memoria
    return 0;
}
