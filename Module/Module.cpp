// Module.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Model1.h"

int main()
{
	srand(time(NULL));

	cout << Task1() << endl << endl;

	Task2(5, 10); cout << endl;

	char S1[10] = "reqwrt";
	char T[3] = "qw";
	cout << Task3(S1, T, 3, 7) << endl;

	char S[10] = "abcb";
	Task4(S, 5);

	int** a = new int* [10];
	for (int i = 0; i < 10; i++)
		a[i] = new int[10];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			a[i][j] = rand() % 5 - 3;

	Task5(a, 10, 10);

	return 0;
}

