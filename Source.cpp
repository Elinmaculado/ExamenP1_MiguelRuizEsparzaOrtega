#include <iostream>
#include <vector>
#include "Critter.h"

using namespace std;

void Ejercicio1();
void Ejercicio2();

int ReadNumbers(vector<int> number);

int main()
{
	int choice;
	cout << "elige que ejercicio quieres revisar, 1 o 2: " << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		system("cls");
		Ejercicio1();
		break;
	case 2:
		system("cls");
		Ejercicio2();
	default:
		cout << "opcion invalida";
	}
}

void Ejercicio2()
{
	Critter crit;
	crit.Talk();
	int choice;
	do
	{
		cout << "\n Mascotas Virtuales\n\n";
		cout << "0 - Salir.\n";
		cout << "1 - Escucha a tu mascota.\n";
		cout << "2 - Alimentar.\n";
		cout << "3 - Jugar con tu mascota.\n";
		cout << "4 - Darle de beber a tu mascota.\n";
		cout << "5 - Ver el estado de tu mascota.\n";
		cout << "Elige una opción: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "Vuelve pronto!.\n";
			break;
		case 1:
			crit.Talk();
			break;
		case 2:
			crit.Eat();
			break;
		case 3:
			crit.Play();
			break;
		case 4:
			crit.Drink();
			break;
		case 5:
			crit.DisplayStatus();
			break;
		default:
			cout << "\n Tu elección es inválida. \n";
		}
		
	} while (choice != 0);
}

void Ejercicio1()
{
	int position;
	int* pointer;
	vector <int> numbers = { 1010,2020, 1239, 5839, 1011 ,4444, 4025, 2221 }; //Respuesta [7]
	position = ReadNumbers(numbers);
	pointer = &numbers[position];

	cout << "Posicion de memoria: " << pointer << endl;
	cout << "Valor del numero: " << * pointer << endl;
}

int ReadNumbers(vector<int> number)
{
	int masalto = 0;
	int temp;
	int contador = 0;
	int numero;
	int respuesta;
	for (int i = 0; i < 8; i++)
	{
		temp = 0;
		numero = number[i];
		for (int y = 0; y <= 4; y++)
		{
			temp = numero % 10;
			if ((temp % 2 == 0) && (temp != 0))
			{
				contador++;
			}
			if (contador > masalto)
			{
				masalto = contador;
				respuesta = i;
			}
			numero /= 10;
		}
		/*while (numero > 0)
		{
			temp = numero % 10;
			if (temp % 2 == 0)
			{
				contador++;
			}
			numero /= 10;
			if (contador > masalto)
			{
				masalto = contador;
			}
		}
		*/
		contador = 0;
	}
	cout << "posicion del vector: " << respuesta << endl;
	return respuesta;
}

