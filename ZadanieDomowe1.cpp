#include <iostream>
#include <cmath>
#include <time.h>
#include <iomanip>

using namespace std;


double szukajMinArgumentowFunkcji(double a, double b, double c, double xp, double xk, int maxLiczbaIteracji,int kryteriumZbiezności, double& xmin)
{
	double x = 1;
	double x_min = xp;
	double y_min = a * pow(x_min, 2) + b * x_min + c;
	int zbieznosc = 0;

	if (a <= 0)
	{
		cout << "Podano Zly wspolczynnik a ";
	}
	else
	{
		for (int i = 0; i < maxLiczbaIteracji && zbieznosc < kryteriumZbiezności; i++)
		{
			double x = xp + (1.0 * rand() / RAND_MAX) * (xk - xp);
			double y = a * pow(x, 2) + b * x + c;
			if (y < y_min)
			{
				y_min = y;
				x_min = x;
				zbieznosc = 0;
			}
			else
			{
				zbieznosc++;
			}
		}
		xmin = x_min;
		return y_min;
	}
}

int main()
{
	srand(time(0));

	int maxIteracji,zbieznosc;
	double a, b, c, xp, xk, ymin, xmin;

	cout << "Podaj wspolczynnik a: "; 
	cin >> a;

	cout << "Podaj wspolczynnikb: "; 
	cin >> b;

	cout << "Podaj wspolczynnikc: "; 
	cin >> c;

	cout << "Podaj wartosc poczatku przedzialu: "; 
	cin >> xp;

	cout << "Podaj wartosc koncowa przedzialu: "; 
	cin >> xk;

	cout << "Podaj limit iteracji: "; 
	cin >> maxIteracji;

	cout << "Podaj kryterium zbieżności: ";
	cin >> zbieznosc;

	ymin = szukajMinArgumentowFunkcji(a, b, c, xp, xk, maxIteracji, zbieznosc ,xmin);

	cout << fixed << setprecision(1) << "x_min: " << xmin << endl;
	cout << fixed << setprecision(1) << "y_min: " << ymin;
	
}

