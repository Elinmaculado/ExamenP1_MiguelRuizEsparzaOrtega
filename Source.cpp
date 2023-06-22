#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

void instructions();
char PlayerSymbol(string question);
char Opponent(char a);
char winner(const vector<char>& board);
void displayBoard(vector <char>& board);
int playerMove(vector <char>& board);

void ejercicio1();
void ejercicio2();

const int NUM_SQUARES = 9;
const char EMPTY = '.';

const char X = 'X';
const char O = 'O';
const char NO_ONE = 'N';
const char TIE = 'T';

int main()
{
	int ejercicio;
	cout << "elija si quiere ver el ejercicio 1 o 2" << endl;
	cin >> ejercicio;
	if (ejercicio == 1)
	{
		ejercicio1();
	}
	if (ejercicio == 2)
	{
		ejercicio2();
	}
	else
	{
		cout << "opcion invalida, mataste el programa" << endl;
	}
}

void ejercicio1()
{
	vector<char> board(NUM_SQUARES, EMPTY);
	int move = 0;
	char player = X;
	char ai = O;
	char turn = player;
	instructions();
	displayBoard(board);
	cout << endl;
	player = PlayerSymbol("deseas ir primero? ");
	cout << "jugador " << player << endl;
	ai = Opponent(player);
	cout << "oponente " << ai << endl;
}

void ejercicio2()
{
	int sumaNum = 0;
	int sumaPos = 0;
	int resta;

	int matriz[3][4] = { { 2, 3, 1, 4 },
						{9, 8, 7, 9},
						{3, 2, 1, 5} };

	//for para imprimir matriz
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << matriz[i][j];
		}
		cout << endl;
	}

	cout << "numeros pares y su suma" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (matriz[i][j] % 2 == 0)
			{
				cout << matriz[i][j] << " + ";
				sumaNum += matriz[i][j];
			}
		}
	}
	cout << " = " << sumaNum << endl;

	cout << "suma de posiciones" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (matriz[i][j] % 2 == 0)
			{
				cout << i << j << " + ";
				sumaPos += ((i * 10) + j);
			}
		}
	}
	cout << " = " << sumaPos << endl;

	cout << "resta final" << endl;

	resta = sumaNum - sumaPos;

	cout << sumaNum << " - " << sumaPos << " = " << resta;
}

int playerMove(vector <char>& board)
{
	int choice;
	do {
		cin >> choice;
	} while (board[choice] == '.');
	return choice;
}

void displayBoard(vector <char>& board)
{
	cout << "Bienvenido a tic tac toe, elije una posicion entre el 0 y el 8" << endl;

	cout << board[0] << " " << board[1] << " " << board[2] << endl;
	cout << board[3] << " " << board[4] << " " << board[5] << endl;
	cout << board[6] << " " << board[7] << " " << board[8] << endl;
}

void instructions()
{
	char boardoptions[3][3] = { {'0', '1', '2'},
										 {'3', '4', '5'},
										 {'6', '7', '8'} };

	cout << "Bienvenido a un nuevo TicTacToe" << endl;
	cout << "En este juego te enfrentaras a una IA basica" << endl;
	cout << "El tablero siguiente representa tus controles, recuerdalos bien" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << boardoptions[i][j];
		}
		cout << endl;
	}
}

char PlayerSymbol(string question)
{
	string choice;
	unsigned int answer;
	//se obtiene numero aleatorio entre el 1 y el 6 para el dado
	srand(static_cast<unsigned int>(time(0)));
	answer = 1 + rand() % (6 - 1);
	cout << "desea numero par o numero impar?" << endl;
	cout << "numero: " << answer << endl;
	cin >> choice;

	if (choice == "par")
	{
		if (answer % 2 == 0)
		{
			return X;
		}
		else
		{
			return O;
		}
	}
	else if (choice == "impar")
	{
		if (answer % 2 == 0)
		{
			return O;
		}
		else
		{
			return X;
		}
	}

	
}

char Opponent(char a)
{
	char opponent;

	if (a == X)
	{
		opponent = O;
	}
	else
	{
		opponent = X;
	}

	return opponent;
}

char winner(const vector<char>& board)
{

	//This are the posibilities to win
	const int WINNING_POS[8][3] = { {0, 1, 2}, //Horizontal
									{3, 4, 5}, //Horizontal
									{6, 7, 8}, //Horizontal
									{0, 3, 6}, //Vertical
									{1, 4, 7}, //Vertical
									{2, 5, 8}, //Vertical
									{2, 4, 6}, //Horizontal
									{0, 4, 8} }; //Horizontal
	const int TOTAL_ROWS = 8;

	//Return the winner
	for (int row = 0; row < TOTAL_ROWS; row++)
	{
		if ((board[WINNING_POS[row][0]] != EMPTY) &&
			(board[WINNING_POS[row][0]] == board[WINNING_POS[row][1]]) &&
			(board[WINNING_POS[row][1]] == board[WINNING_POS[row][2]]))
		{
			return board[WINNING_POS[row][0]];
		}
	}

	//Return a Tie
	if (count(board.begin(), board.end(), EMPTY) == 0) {
		return TIE;
	}

	//Return that no one is the winner yet
	return NO_ONE;
}


/*#include <iostream>
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
*/