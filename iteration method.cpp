#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
const float e = 2.718;
const double E = 0.000001;
//f(x) = e^x - e^-x - 2
//f'(x) = e^x + e^-x
// ф(x) = x + λ(e^x-e^(-x))-2
//Отрезок, содержащий корень: [0;1]
//Точное значение: 0,8814
int main()
{
	setlocale(LC_ALL, "Russian");
	//f'(0) = 2
	//f'(1) = 3.089
	//следовательно r = 3.089
	//т.к. f'(x) > 0, то -1/r < λ < 0ы
	//возьмём λ = -1/5 = -0.2
	float lambda = -0.2;
	float x;
	cout << "Введите значение X0 от 0 до 1: ";
	cin >> x;
	if (x < 0 or x>1)
		cout << "Ошибка: X0 вне промежутка от 0 до 1";
	else
	{
		float xPrev = -1;
		while (abs(x - xPrev) > E)
		{
			xPrev = x;
			x = lambda * (pow(e, xPrev) - pow(e, (-1) * xPrev) - 2) + xPrev;
		}
		cout << "Корень: " << x;
	}
	return 0;
}