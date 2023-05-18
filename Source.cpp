#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int playgame();
int parcial1();
void parcial2();


int main()
{
	int choice;
	cout << "elija que examen quiere ver:" << endl << "1. Parcial 1" << endl << "2. Parcial 2" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		parcial1();
		break;
	case 2:
		parcial2();
	}
}

int parcial1() {
	string play;
	string exit;

	do {																//menu para elegir si jugar o salir del juego
		system("cls");
		cout << "elija que quiere hacer play/exit" << endl;
		cin >> play;
		if (play == "play") {
			playgame();
		}
		else if (play == "exit") {
			cout << "estas seguro que deseas salir? si/no" << endl;
			cin >> exit;
			if (exit == "si") {
				cout << "vuelva pronto";
				return 0;
			}
			else {
				play = "play";
			}
		}
	} while (play != "exit");
	return 0;
}

int playgame() {
	srand(static_cast<unsigned int>(time(0)));
	int min;
	int max;
	int answer;
	int randnumber = rand();
	int guess;
	int tries = 0;
	int close;
	string playing = "si";

	//do while del juego completo
	do {
		system("cls");

		//se ingresan los rangos y se comprueba que el minimo sea menor que el maximo
		do {
			cout << "asegurese de que el numero minimo es mas pequeño que el numero maximo" << endl;
			cout << "ingrese el numero minimo del rango" << endl;
			cin >> min;

			cout << "ingrese el numero maximo del rango" << endl;
			cin >> max;
		} while (min > max);

		//se obtiene el numero aleatorio dentro del rango
		answer = min + rand() % (max - min);
		cout << answer << endl;

		//se ingresa la respuesta del usuario
		do {
			cout << "ingrese su respuesta: ";
			cin >> guess;

			//se confirma si la respuesta esta a 5 numeros de distancia de la respuesta correcta y se da un mensaje
			close = answer - guess;

			if (close < 5 && close > -5 && close != 0) {
				cout << "estas muy cerca" << endl;
				if (guess > answer) {
					cout << "muy alto" << endl;
				}
				if (guess < answer) {
					cout << "muy bajo" << endl;
				}
			}
			//se le suma 1 a los intentos y si no averiguo el numero, vuelve a introducir una nueva respuesta
			tries++;
		} while (guess != answer);

		//Se le da el mensaje con los intentos que le tomo ganar y se sale del juego
		if (tries <= 5) {
			cout << "felicidades, lo averiguaste en solo " << tries << " intentos" << endl;
		}
		else {
			cout << "lo lograste en " << tries << " intentos" << endl;
		}

		//se le pregunta si desea volver a jugar o salir al menu
		cout << "desea volver a jugar? si/ no ";
		tries = 0;
		cin >> playing;
	} while (playing == "si");
	return 0;
}

void parcial2()
{
	int a = 1; //variable para asegurar el ciclo
	int b = 5; //espacios gratuitos dentro del vector
	int coins = 25;
	int choice;
	int replace;
	string object;

	//definir inventario. 10 espacios, solo 5 gratuitos
	vector<string> inventory(b);

	//llena los espacios gratis del inventario
	for (int i = 0; i < b; i++)
	{

		cout << "que item desas agregar a tu inventario?" << endl;
		cin >> inventory[i];

		cout << "tu inventario: " << endl;
		for (int j = 0; j <= i; j++)
		{
			cout << inventory[j] << endl;
		}

	}
	do {
		//pregunta por un nuevo objeto y al hacerlo presentará el menú con las tres opciones
		cout << "que item desas agregar a tu inventario?" << endl;
		cin >> object;

		cout << "tal parece que te haz quedado sin espacio, tu inventario es:" << endl;
		cout << "tu inventario: " << endl;
		for (int j = 0; j <= b; j++)
		{
			cout << inventory[j] << endl;
		}


		cout << "tienes las siguientes opciones, elije el numero de la opcion que quieras: " << endl
			<< "1. tirar un objeto del inventario para agregar el que acabas de tomar" << endl
			<< "2. continuar sin el objeto" << endl
			<< "3. comprar mas espacio por 5 monedas, tienes " << coins << " monedas" << endl
			<< "4. salir del programa" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "elija el numero del objeto que desea reemplazar" << endl;
			for (int j = 0; j < b; j++)
			{
				cout << (j + 1) << inventory[j] << endl;
			}
			cin >> replace;
			if (replace > b)
			{
				cout << "no elegiste una opcion valida" << endl;
				break;
			}
			else {
				inventory[replace - 1] = object;
			}
			cout << "tu nuevo inventario es: " << endl;
			for (int j = 0; j < b; j++)
			{
				cout << (j + 1) << inventory[j] << endl;
			}

			break;
		case 2:
			cout << "decides continuar sin " << object << endl;
			cout << "tu inventario es: " << endl;
			for (int j = 0; j < b; j++)
			{
				cout << (j + 1) << " " << inventory[j] << endl;
			}

			break;
		case 3:
			coins -= 5;
			b++;
			inventory.push_back(object);
			cout << "ahora tienes " << coins << " monedas, tu nuevo inventario es: " << endl;
			for (int j = 0; j < b; j++)
			{
				cout << (j + 1) << " " << inventory[j] << endl;
			}
			break;
		case 4:
			b = 10;
			break;
		default:
			cout << "por favor elija una opcion valida";
		}

	} while (b < 10);
	cout << "hasta la proxima";
}