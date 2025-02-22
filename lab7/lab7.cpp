#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Profesor
{
private:
	string cursos;
	string titulo;
public:
	Profesor(string cursos, string titulo) {
		this->cursos = cursos;
		this->titulo = titulo;

	}
	void mostrardatos() {
		cout << "Cursos: " << cursos << endl;
		cout << "Titulo: " << titulo << endl;
	};
	void getcurso(string cursos) {
		this->cursos = cursos;
	};
	void gettitulo(string titulo) {
		this->titulo = titulo;
	};
};
class catedratico : private Profesor
{
private:
	string nombre;
	string apellido;

public:
	catedratico(string nombre, string apellido, string cursos, string titulo) : Profesor(cursos, titulo) {
		this->nombre = nombre;
		this->apellido = apellido;
	}
	void mostrardatos1() {
		cout << "Nombre: " << nombre << endl;
		cout << "Apellido: " << apellido << endl;
		Profesor::mostrardatos();
	};



};
class aniosclase : public catedratico
{
private:
	int anios;
	string clase;
public:
	aniosclase(int anios, string clase, string nombre, string apellido, string cursos, string titulo) : catedratico(nombre, apellido, cursos, titulo) {
		this->anios = anios;
		this->clase = clase;
	}

	void mostrardatos2() {
		system("cls");
		cout << "Anios dando clase: " << anios << endl;
		cout << "Clase que daba: " << clase << endl;
		catedratico::mostrardatos1();
	};

};
class estudiantesacarg :public aniosclase
{
private:
	string estudiantegrado;
	int cantidad;
public:
	estudiantesacarg(string estudiantegrado, int cantidad, int anios, string clase, string nombre, string apellido, string cursos, string titulo) : aniosclase(anios, clase, nombre, apellido, cursos, titulo) {
		this->estudiantegrado = estudiantegrado;
		this->cantidad = cantidad;
	}
	void mostrardatos3() {
		system("cls");
		cout << "Estudiantes a cargo: " << estudiantegrado << endl;
		cout << "Cantidad de estudiantes: " << cantidad << endl;
		aniosclase::mostrardatos2();
	};


};

int main() {
	string nombre, apellido, curso, titulo, clase, estudiantesacar;
	int anios, cantidad;

	cout << "Ingrese el nombre del catedratico: ";
	getline(cin, nombre);

	cout << "Ingrese el apellido del catedratico: ";
	getline(cin, apellido);

	cout << "Ingrese los cursos que imparte (separados por comas): ";
	getline(cin, curso);

	cout << "Ingrese el titulo del profesor: ";
	getline(cin, titulo);
	cout << "ingrese anios dando clase: ";
	cin >> anios;
	cout << "ingrese la clase que daba: ";
	cin >> clase;
	cout << "ingrese estudiantes a cargo: ";
	getline(cin, estudiantesacar);
	cout << "ingrese cantidad de estudiantes: ";
	cin >> cantidad;
	estudiantesacarg catedratico1(estudiantesacar, cantidad, anios, clase, nombre, apellido, curso, titulo);
	catedratico1.mostrardatos3();

	return 0;
}