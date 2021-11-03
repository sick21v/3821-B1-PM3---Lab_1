#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <malloc.h>


int main() {

	setlocale(LC_ALL, "Rus");

	int n = 0;
	int i = 0, j = 0;
	double min = 0.0;
	double max = 0.0;
	double sum = 0.0;
	double* a;
	double fr = 0.0;
	double integer = 0.0;
	int* frmas;

	printf("Введите n (кол-во случайных чисел): \t"); //кол-во чисел
	scanf_s("%d", &n);
	if (n <= 0)
	{
		printf("Ошибка! Значение n должно быть больше нуля.\n");
		return 0;
	}

	printf("Введите min (мин. значение диапазона): \t"); //минимальное значение
	scanf_s("%lf", &min);

	printf("Введите max (макс. значение диапазона): \t"); //максимальное значение
	scanf_s("%lf", &max);
	if (max < min)
	{
		printf("Ошибка! min должно быть больше max.\n");
		return 0;
	}

	a = (double*)malloc(n * sizeof(double));//массив для рандомных чисел
	if (a == 0)
	{
		printf("Ошибка 1!\n");
		return 0;
	}

	for (i = 0; i < n; i++)
	{
		a[i] = (((double)rand()) / RAND_MAX) * (max - min) + min;//забиваю массив
	}

	frmas = (int*)malloc(n * sizeof(int)); //создаю массив для дробных частей

	for (i = 0; i < n; i++)
	{
		frmas[i] = (fr = modf(a[i], &integer) * 1000000); //отделяю дробную часть,
								  //ограниченную до 6 знаков после запятой																			
		if (frmas[i] < 0)//проверяю дробную часть на знак
			frmas[i] *= -1;
		while (frmas[i] % 10 == 0) // отбрасываю ненужные нули
		{
			frmas[i] /= 10;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == frmas[j])  //проверяю порядковый номер
			{                   //на равенство дробной части
				sum = sum - a[i];
				a[i] = 0.0; //зануляю вычитаемый элемент в массиве рандомных чисел
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		sum = sum + a[i];
	}

	printf("Сумма равна %lf", sum);
	
	free(a);
	free(frmas);
	return 0;
}
