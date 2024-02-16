#include <iostream>
using namespace std;

struct point {
	double m_x;
	double m_y; // не используется см. ниже исправления
	point(double x, double y) {
		m_x = x;
		m_y = y; // было y = y скорее всего "опечатка"
	}
}; //после закрытия структуры нужна " ; "

void print_point(const point& point_object) {
	std::cout << "x:" << point_object.m_x << ", y: "
		<< point_object.m_y << std::endl; // используется переменная структуры, которая ранее не инициализировалась.
}


int main() // "Main" вместо " main "
{
	int i;
	for (i = 0; i < 5; i++) { // Было for (i = 0; i < 5; i++); { точка с запятой закрывала функцию цыкла
		point my_point(i, 2 * i);
		print_point(my_point);
	}
	return 0;
}
/*
void print_point(const point& point_object) {
	std::cout << "x:" << point_object.m_x << ", y: "
		<< point_object.m_y << std::endl;
}
Данный кусок кода лишний, кроме того что он вне и после функции " main ", он также реализован уже до нее 
*/