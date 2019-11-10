#include "Model1.h"
#include <iomanip>

double Task1()
{
	double eps = 0.01, result = 0, temp_result = 0;
	int i = 0;
	do
	{
		temp_result = 0;
		for (int j = 0; j <= i; j++)
		{
			temp_result += (pow(-2, i) / fact(i));
		}
		result += temp_result;
		i++;
	} while (abs(temp_result) > eps);

	return result;
}

int fact(int i)
{
	int fact_i = 1;
	if (i == 0) return 1;
	else
	{
		for (int j = 1; j <= i; j++)
		{
			fact_i *= j;
		}
		return fact_i;
	}
}


void Task2(int m, int n)
{
	srand(time(NULL));

	Triengle* tr = new Triengle[n];

	for (int i = 0; i < n; i++)
	{
		tr[i].x1 = rand() % (2 * m) - m;
		tr[i].y1 = rand() % (2 * m) - m;
		tr[i].x2 = rand() % (2 * m) - m;
		tr[i].y2 = rand() % (2 * m) - m;
		tr[i].x3 = rand() % (2 * m) - m;
		tr[i].y3 = rand() % (2 * m) - m;
	}

	for (int i = 0; i < n; i++)
	{
		if (sqrt(tr[i].x3 * tr[i].x3 + tr[i].y3 * tr[i].y3) * sqrt(tr[i].x3 * tr[i].x3 + tr[i].y3 * tr[i].y3) == sqrt(tr[i].x1 * tr[i].x1 + tr[i].y1 * tr[i].y1) * sqrt(tr[i].x1 * tr[i].x1 + tr[i].y1 * tr[i].y1) + sqrt(tr[i].x2 * tr[i].x2 + tr[i].y2 * tr[i].y2) * sqrt(tr[i].x2 * tr[i].x2 + tr[i].y2 * tr[i].y2))
		{
			cout << "Triengl is right, with dots: " << " - X1 & Y1 - " << tr[i].x1 << " " << tr[i].y1 << " - X2 & Y2 - " << tr[i].x2 << " " << tr[i].y2 << " - X3 & Y3 - " << tr[i].x3 << " " << tr[i].y3 << endl;
		}
	}
}

int Task3(char* S, char* T, int length, int length_S)
{
	srand(time(NULL));
	length--;
	int i = rand() % length;
	for (int j = 0; j < length_S; j++)
	{
		if (S[j] == T[i])
			return j + 1;
	}
	return -1;
}

bool isPolind(char* str, int length)
{
	for (int i = 0, j = length - 1; i < length / 2; i++, j--)
	{
		if (str[i] != str[j]) return false;
	}

	return true;
}

void creatPolid(char* str, int length)
{
	int p = 0, count = 0;
	for (int j = length / 2 - 1, q = length - 1; j != -1; j--)
	{
		str[q++] = str[j];
		count = q;
		if (isPolind(str, count)) break;
	}
	for (int i = 0; i < count + 1 + length; i++)
	{
		cout << str[i];
		if (str[i] == str[count]) break;
	}
	cout << endl;
}

void Task4(char* str, int length)
{
	--length;
	int k = 0;
	if (length % 2 == 0)  k = 1;
	else  k = 2;

	if (isPolind(str, length))
	{
		cout << "Str is Polid" << endl;
		return;
	}
	int i = 0, count = 0;
	while (!isPolind(str, length))
	{
		bool f = true;
		for (int j = length / 2, q = length - 1, p = length - 2; ; j--, q++)
		{
			if (f)
			{
				f = false;
				if (str[j - 1] == str[j + 1])
				{
					if (k == 2 && !isPolind(str, length + 1)) continue;
					creatPolid(str, length);
					return;
				}
			}
			else
			{
				str[q] = str[p--];
				count++;
				if (q == (length - 1) * 2) break;
			}
		}

		for (int i = 0; i < count + length; i++) cout << str[i];

		return;
	}
}

void Task5(int** a, int m, int n)
{
	int* ckar = new int[m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) cout << setw(4) << a[i][j] << ' ';
		cout << endl;
	}

	cout << endl << endl;

	for (int j = 0; j < m; j++)
	{
		int p = 0;

		for (int i = 0; i < n; i++)
		{
			if (a[i][j] < 0 && abs(a[i][j]) % 2 != 0)
				p += abs(a[i][j]);
		}
		ckar[j] = p;
	}

	
	for (int j = 0; j < m; j++) cout << setw(4) << ckar[j] << ' ';

	cout << endl << endl;

	for (int j = 0; j < n - 1; j++)
	{
		for (int q = j; q < m; q++)
		{
			if (ckar[j] > ckar[q])
			{
				for (int i = 0; i < n; i++)
				{
					int temp = a[i][j];
					a[i][j] = a[i][q];
					a[i][q] = temp;
				}

				int tmp = ckar[j];
				ckar[j] = ckar[q];
				ckar[q] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) cout << setw(4) << a[i][j] << ' ';
		cout << endl;
	}

	cout << endl;

	for (int j = 0; j < m; j++) cout << setw(4) << ckar[j] << ' ';

	cout << endl << endl;
}