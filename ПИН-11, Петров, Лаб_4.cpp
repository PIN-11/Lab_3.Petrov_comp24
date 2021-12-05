///////Лабораторная работа №4///////

/////////////Задание 1/////////////

#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

void init(int** args, int lines, int posts) {
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < posts; j++)
			args[i][j] = rand() % 60;
}

int f(int** massive, int lines, int posts, int* answer)
{
	int size = 0;
	int count = 0;
	for (int i = 0; i < posts; i++)
	{
		int min = massive[0][i];
		for (int j = 0; j < lines; j++) {
			if (min > massive[j][i]) {
				min = massive[j][i];
			}
		}
		answer[count] = min;
		count++;
	}
	size = sizeof(answer);
	return size * count;
}

int main() {
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int n, m;
	cout << "Введите количество строк для массива: " << endl;
	cin >> n;
	cout << "Постойте, ещё раз, чему равно количество строк?" << endl;
	cin >> m;
	cout << "Понятно, принято. Тогда держите матрицу: " << endl;
	int* answer = new int[m];
	int** A = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		A[i] = (int*)calloc(m, sizeof(int));
	}
	init(A, n, m);
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << A[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
	int size = f(A, n, m, answer);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "Вау, это действительно поражает." << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	cout << "Размер ответа: " << size << " bytes" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	for (int j = 0; j < m; j++)
		cout << answer[j] << "\t";
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	return 0;
}

/////////////Задание 2/////////////

#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
using namespace std;

void init(int** args, int lines, int posts) {
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < posts; j++)
			args[i][j] = rand() % 7 - 2;
}

int f(int** massive, int lines, int posts, int* answer)
{
	int ans = 0;
	int kol = 0;
	for (int k = 0; k < posts; k++)
	{
		for (int i = k; i < (posts - k); i++)
		{
			if (massive[k][i] == 0)
			{
				kol++;
			}
			answer[ans] = kol;
		}
	}
	return kol;
}

int f1(int** massive1, int lines, int posts, int* answer1)
{
	int ans1 = 0;
	int kol1 = 0;
	for (int k = (posts / 2); k < posts; k++)
	{
		for (int i = k; i > (posts - k - 2); i--)
		{
			if (massive1[k][i] > 0)
			{
				kol1++;
			}
			answer1[ans1] = kol1;
		}
	}
	return kol1;
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int n, m;
	cout << "Введите количество строк для массива: " << endl;
	cin >> n;
	cout << "Постойте, ещё раз, чему равно количество строк?" << endl;
	cin >> m;
	cout << "Понятно, принято. Тогда держите матрицу: " << endl;
	int* answer = new int[n];
	int* answer1 = new int[n];
	int** A = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		A[i] = (int*)calloc(m, sizeof(int));
	}
	init(A, n, m);
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << setw(3) << A[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
	int size = f(A, n, m, answer);
	int size1 = f1(A, n, m, answer1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "Вау, это действительно поражает." << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	cout << "Размер ответа: " << size << " bytes" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	int j = 0;
	cout << answer[j] << "\t";
	cout << endl;
	cout << answer1[j] << "\t";
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	return 0;
}