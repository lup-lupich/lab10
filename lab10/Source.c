#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

void task1();
double fa(double x);
double fb(double x);
void task2();
double sin_n(double x, int N);
double sin_eps(double x, double eps);

int main() {
	int selected_task;
	int stop;

	setlocale(LC_CTYPE, "RUS");
	do {
		printf("Выберите задание (1 или 2): ");
		scanf("%d", &selected_task);
		printf("\n");
		printf("Задание %d\n\n", selected_task);

		if (selected_task == 1) task1();
		else task2();

		printf("Продолжить? (да - любое число, 0 - нет): ");
		scanf("%d", &stop);
		printf("\n");
	} 
	while (stop != 0);
	return 0;
}


//1 задание
void task1() {

	double x, func1, func2;
	int user_answer;

	printf("Введите значение x: ");
	scanf("%lf", &x);

	func1 = fa(x);
	func2 = fb(x);

	printf("Что вычислить? (1 - функция 1, 2 - функция 2, 3 - произведение функций, 4 - разность квадратов функций, 5 - удвоенную сумму функций): ");
	scanf("%d", &user_answer);

	switch (user_answer) {
	case(1): printf("F1(x) = %lf\n", func1); break;
	case(2): printf("F2(x) = %lf\n", func2); break;
	case(3): printf("Произведение: %lf\n", func1 * func2); break;
	case(4): printf("Разность квадратов: %lf\n", func1 * func1 - func2 * func2); break;
	case(5): printf("Удвоенная сумма: %lf\n", (func1 + func2) * 2); break;
	default: printf("Такой команды нет\n"); break;
	}
}

//Первая функция (задание 1)
double fa(double x) {
	double y;

	if (x <= 3) y = x * x - 3 * x + 9;
	else y = 1 / (pow(x, 3) + 3);

	return y;
}

//Вторая функция (задание 1)
double fb(double x) {
	double y;

	y = x * exp(sin(x * x));

	return y;
}


//2 задание
void task2() {
	double x;
	int N;
	double eps;

	printf("Введите x в радианах: ");
	scanf("%lf", &x);
	printf("\n");
	printf("Введите число членов ряда: ");
	scanf("%d", &N);
	printf("\n");
	printf("Введите точность вычисления: ");
	scanf("%lf", &eps);

	//1
	printf("Первый способ: %lf\n\n", sin(x));

	//2
	printf("Второй способ: %lf\n", sin_n(x, N));
	printf("Отклонение: %e\n\n", sin(x) - sin_n(x, N));

	//3
	printf("Третий способ: %lf\n", sin_eps(x, eps));
	printf("Отклонение: %e\n\n", sin(x) - sin_eps(x, eps));
}

//Второй способ (задание 2)
double sin_n(double x, int N) {
	double y = 0;

	for (int k = 1; k <= N; k++) {
		double fact = 1;
		for (int temp = 2; temp <= (2 * k - 1); temp++) {	
			fact *= temp;
		}
		y += ((int)pow(-1, k - 1)) * (pow(x, 2 * k - 1) / (fact));
	}

	return y;
}

//Третий способ (задание 2)
double sin_eps(double x, double eps) {
	double y = 0;
	double term = x;
	int k = 1;

	while (fabs(term) > eps) {
		double fact = 1;

		for (int temp = 2; temp <= (2 * k - 1); temp++) {
			fact *= temp;
		}

		term = ((int)pow(-1, k - 1)) * (pow(x, 2 * k - 1) / (fact));
		y += term;

		k++;
	}
	
	return y;
}