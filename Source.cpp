#include <iostream>
using namespace std;
int playgame();

int main() {
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
	answer = min + rand() % (max-min);
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