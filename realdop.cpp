
#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

void task219()
{
	int massiv[100], a = 0, k = 0, n = 0, n1 = 0, n2 = 0;
	for (int i = 0; i < 25; ++i)
	{
		a++;
		massiv[i] = rand() % 35 - 5;
		cout << " " << a << ")" << massiv[i] << " ";
	}
	for (int i = 0; i < 25; ++i)
	{
		if (massiv[i] < 0)
		{
			for (int j = i; j < 25; ++j)
				massiv[j] = massiv[j + 1];
			++k;
			massiv[25 - 1] = 0;
			--i;
		}
	}
	cout << "\n\n";
	a = 0;
	for (int i = 0; i < 25 - k; ++i)
	{
		a++;
		cout << " " << a << ")" << massiv[i] << " ";
	}
	a = 0;
	cout << "\nВведите число n: ";
	cin >> n;
	for (int i = 0; i < 25 - k; ++i)
	{
		if (massiv[i] > n)
		{
			for (int j = i; j < 25; ++j)
				massiv[j] = massiv[j + 1];
			++k;
			massiv[25 - 1] = 0;
			--i;
		}
	}
	for (int i = 0; i < 25 - k; ++i)
	{
		a++;
		cout << " " << a << ")" << massiv[i] << " ";
	}
	cout << "\nВведите число n1: ";
	cin >> n1;
	cout << "\nВведите число n2, помните, что n1 <= n2 : ";
	cin >> n2;
	for (int i = 0; i < 25 - k; ++i)
	{
		if (i > n1 - 2 && i <= n2)
		{
			massiv[i] = massiv[n2++];
			k++;
		}


	}


	a = 0;
	for (int i = 0; i < 25 - k - 2; ++i)
	{
		a++;
		cout << " " << a << ")" << massiv[i] << " ";
	}
}
int GCD(int a, int b)
{
	while (a - b != 0)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}
int comp1(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
void task230()
{
	const int;
	int A[10], g[10], M, k;
	cout << "Введите 10 значений знаменателей:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < 10; i++)
	{
		g[i] = rand() % 10 + 1;
	}
	M = A[0];
	for (int i = 1; i < 10; i++)
	{
		M = (M * A[i]) / GCD(M, A[i]);
	}
	cout << "НОК = " << M << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << g[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}
	for (int i = 0; i < 10; i++)
	{
		k = M / A[i];
		g[i] = g[i] * k;
		A[i] = M;
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << g[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << "   ";
	}
	cout << endl<< endl;
	qsort(g, 10, sizeof(int), comp1);
	for (int i = 0; i < 10; i++)
	{
		cout << g[i]<< "/" << A[i]<< " ";
	}
	
}
void task231()
{
	int a[1000], n = 0;
	cout << "input n:";
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 30;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n\n";
	qsort(a, n, sizeof(int), comp1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<< " ";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	//task219();
	//task230();
	task231();
}
/*
* 230.	Даны дроби   (рi, qi — натуральные). Составить программу, которая приводит эти дроби к общему знаменателю и упорядочивает их в порядке возрастания.
219.	Удалить из массива:
а) все отрицательные элементы;
б) все элементы, большие данного числа n;
в) все элементы, начиная с n1-го по n2-й (n1 ≤ n2).

231
	Упорядочить массив а1, а2, ..., an по неубыванию с помощью алгоритма
сортировки слиянием фон Неймана, когда каждая пара соседних элементов сливается
в одну группу из двух элементов(последняя группа может состоять из одного элемента),
каждая пара соседних двухэлементных групп сливается в одну четырехэлементную группу
и т.д.При каждом слиянии новая укрупненная группа упорядочивается.
*/
