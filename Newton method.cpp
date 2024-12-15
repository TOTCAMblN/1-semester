#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
const float e = 2.718;
const double E = 0.000001;
//f(x) = e^x - e^-x - 2
//f'(x) = e^x + e^-x
//f''(x) = e^x - e^-x
//�������, ���������� ������: [0;1]
//������ ��������: 0,8814
int main()
{
	//setlocale(LC_ALL, "Russian"); 
	float a = 0;
	float b = 1;
	float x;
	// ���������, ����� �� �� ������� x0=0 ��� x0=1
	// f(0)*f''(0) = 0
	// f(1)*f''(1) > 0
	x = b;
	float xPrev = 0;
	while (abs(x - xPrev) > E)
	{
		xPrev = x;
		x = xPrev - ((pow(e, xPrev) - pow(e, (xPrev * (-1))) - 2) / (pow(e, x) + (pow(e, (xPrev * (-1))))));
	}
	cout << x << " - ������";
	return 0;
}