////Лабораторная работа №3/////////

//////////Задание 1////////////////

#include <iostream>
#include<clocale>
#include<time.h>
#include<iomanip>
#define N1 10
#define N2 20
using namespace std;
int sum(int array[], int k)
{
    int res = 0;
    for (int i = 0; i < k; i++)
        res += array[i];
    return res;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int mas1[N1], mas2[N2];
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int sum4 = 0;
    for (int i = 0; i < N1; i++)
        mas1[i] = rand() % 9;
    for (int i = 0; i < N2; i++)
        mas2[i] = rand() % 9;
    cout << "Массив 1: \n" << endl;
    cout << "============================================================================" << endl;
    for (int i = 0; i < N1; i++)
        cout << mas1[i] << '\t';
    cout << '\n' << "============================================================================" << endl;
    cout << "Массив 2: \n" << endl;
    cout << "============================================================================================================================================================" << endl;
    for (int i = 0; i < N2; i++)
        cout << mas2[i] << '\t';
    cout << '\n' << "============================================================================================================================================================" << endl;
    int i = 0;
    while (mas1[i] != 0)
    {
        sum1 += mas1[i];
        i++;
    }
    cout << "1) " << sum1 << '\t';
    int j = N1 - 1;
    while (mas1[j] != 0)
    {
        sum2 += mas1[j];
        j--;
    }
    cout << "2) " << sum2 << '\t';
    int m = 0;
    while (mas2[m] != 0)
    {
        sum3 += mas2[m];
        m++;
    }
    cout << "3) " << sum3 << '\t';
    int n = N2 - 1;
    while (mas2[n] != 0)
    {
        sum4 += mas2[n];
        n--;
    }
    cout << "4) " << sum4 << '\t';
}

//////////Задание 2////////////////


#include <iostream>
#include <time.h>

const int N = 6, M = 10;

int function(int args[N][M], int w)
{
    int k = 0;
    double Sum = 0;
    if (w <= (M / 2))
    {
        for (int i = 0; i < (N / 2); i++)
        {
            std::cout << args[i][w - 1] << '\n';
            if (args[i][w - 1] > 0)
            {
                Sum += args[i][w - 1];
                k++;
            }
        }
        return Sum / k;
    }
    else std::cout << "Интересно." << '\n';
    if ((w >= (M / 2)) && (w <= M))
    {
        for (int i = N - 1; i > ((N / 2) - 1); i--)
        {
            std::cout << args[i][w - 1] << '\n';
            if (args[i][w - 1] > 0)
            {
                Sum += args[i][w - 1];
                k++;
            }
        }
        return Sum / k;
    }
    else std::cout << "Так, стоп. Тут ошибка. Ты переходишь границы!" << '\n';
}

int main()
{
    srand(time(0));

    int Q[N][M];
    int w, e;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            Q[i][j] = rand() % 50;
            std::cout << Q[i][j] << "\t";

        }std::cout << "\n";
    }
    std::cout << "Введите номер столба\n>>";
    std::cin >> w;
    e = function(Q, w);
    std::cout << "Среднее арифметическое число = " << e;
}