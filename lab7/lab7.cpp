#include <iostream>
#include <vector>
#include <string>

using namespace std;

class estudiante
{
private:
	string nombre;
	int edad;
	int carnet;
public:
	estudiante(string _nombre, int _edad, int _carnet)
	{
		this->nombre = _nombre;
		this->edad = _edad;
		this->carnet = _carnet;
	}
	void mostrar()
	{
		cout << "Nombre: " << nombre << endl;
		cout << "Edad: " << edad << endl;
		cout << "Carnet: " << carnet << endl;
	}
};

class curso : public estudiante
{
private:
	string nombre_curso;
	int codigo_curso;
public:
	curso(string _nombre_curso, int _codigo_curso, string _nombre, int _edad, int _carnet) : estudiante(_nombre, _edad, _carnet)
	{
		this->nombre_curso = _nombre_curso;
		this->codigo_curso = _codigo_curso;
	}
	void mostrarcurso()
	{
		mostrar();
		cout << "Nombre del curso: " << nombre_curso << endl;
		cout << "Codigo del curso: " << codigo_curso << endl;
	}
};

class promedio : public curso
{
private:
	float promedio_estudiante;
public:
	promedio(string _nombre_curso, int _codigo_curso, string _nombre, int _edad, int _carnet, float _prom) : curso(_nombre_curso, _codigo_curso, _nombre, _edad, _carnet)
	{
		this->promedio_estudiante = _prom;
	}
	void mostrarpromedio()
	{
		mostrarcurso();

		cout << "El promedio del estudiante es: " << promedio_estudiante << endl;
	}
};

class asistencia : public promedio
{
private:
	float porcentaje_asistencia;
public:
	asistencia(string _nombre_curso, int _codigo_curso, string _nombre, int _edad, int _carnet, float _prom, float _porcentaje_asistencia) : promedio(_nombre_curso, _codigo_curso, _nombre, _edad, _carnet, _prom)
	{
		this->porcentaje_asistencia = _porcentaje_asistencia;
	}
	void mostrarasistencia()
	{
		mostrarpromedio();
		cout << "El porcentaje de asistencia del estudiante es: " << porcentaje_asistencia << "%" << endl;
	}

};

int main() {
	string nom_estudiante, nombrecurso;
	int carnet, edad, codigocurso;
	float porcentaje_asistencia, promedioestu;

	cout << "Ingrese el nombre del estudiante: ";
	getline(cin, nom_estudiante);
	cout << "Ingrese la edad del estudiante: ";
	cin >> edad;
	cout << "Ingrese el carnet del estudiante: ";
	cin >> carnet;
	cout << "Ingrese el porcentaje de asistencia del estudiante: ";
	cin >> porcentaje_asistencia;
	cout << "Ingrese el codigo del curso: ";
	cin >> codigocurso;
	cout << "Ingrese el promedio del estudiante: ";
	cin >> promedioestu;
	cin.ignore();
	cout << "Ingrese el nombre del curso: ";
	getline(cin, nombrecurso);

	asistencia est1(nombrecurso, codigocurso, nom_estudiante, edad, carnet, promedioestu, porcentaje_asistencia);
	est1.mostrarasistencia();

	return 0;
}