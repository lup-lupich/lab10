#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

double fa(double x);
double fb(double x);

int main() {
	setlocale(LC_CTYPE, "RUS");

	double x, func1, func2;
	int user_answer;

	printf("Введите значение x: ");
	scanf("%lf", &x);
	
	func1 = fa(x);
	func2 = fb(x);

	printf("Что вычислить? (1 - функция 1, 2 - функция 2, 3 - произведение функций, 4 - разность квадратов функций, 5 - удвоенную сумму функций): %d\n", user_answer);

	switch (user_answer) {
	case(1): printf("F1(x) = %lf\n", func1);
	case(2): printf("F2(x) = %lf\n", func2);
	case(3): printf("Произведение: %lf\n", func1 * func2);
	case(4): printf("Разность квадратов: %lf\n", func1 * func1 - func2 * func2);
	case(5): printf("Удвоенная сумма: %lf\n", (func1 + func2) * 2);
	default: printf("Такой команды нет\n");

	}

	return 0;
}

//Первая функция
double fa(double x) {
	double y;

	if (x <= 3) y = x * x - 3 * x + 9;
	else y = 1 / (pow(x, 3) + 3);

	return y;
}

//Вторая функция
double fb(double x) {
	double y;

	y = x * exp(sin(x * x));

	return y;
}