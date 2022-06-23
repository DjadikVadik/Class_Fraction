#pragma once
#ifndef FRACTION123
#define FRACTION123

#include <iostream>
#include <string>

class Fraction {

	int chislitel = 0;
	int znamenatel = 1;

public:

	Fraction() {}
	Fraction(int chislitel, int znamenatel);
	Fraction(double x);

	void set_chislitel(int chislitel); // сеттер числителя
	void set_znamtnatel(int znamenatel); // сеттер знаменателя

	int get_chislitel();  // геттер числителя
	int get_znamenatel();  //геттер знаменателя

	void show_simple_fraction(); // вывод на экран простой дроби
	void show_decimal();  // вывод на экран десятичной дроби
	double get_decimal(); // вернуть в качестве результата десятичную дробь
	void fraction_reduction(); // сокращение простой дроби

	bool operator < (const Fraction& other);  // перегрузка оператора <
	bool operator > (const Fraction& other);  // перегрузка оператора >
	bool operator == (const Fraction& other);   // перегрузка оператора ==
	bool operator != (const Fraction& other);   // перегрузка оператора !=

	Fraction& operator = (const Fraction& other);  // перегрузка оператора =
	Fraction& operator = (const double x);  // перегрузка оператора = для double

	Fraction operator + (const Fraction& other);  // перегрузка оператора +
	Fraction& operator += (const Fraction& other);  // перегрузка оператора +=

	Fraction operator - (const Fraction& other);  // перегрузка оператора -
	Fraction& operator -= (const Fraction& other);  // перегрузка оператора -=

	Fraction operator * (const Fraction& other);  // перегрузка оператора *
	Fraction& operator *= (const Fraction& other);  // перегрузка оператора *=

	Fraction operator / (const Fraction& other);  // перегрузка оператора /
	Fraction& operator /= (const Fraction& other);  // перегрузка оператора /=

	operator double(); // приведение типа к double

	friend std::ostream& operator << (std::ostream& ost, const Fraction& f); // перегрузка битового сдвига влево
	friend std::istream& operator >> (std::istream& ost, Fraction& f); // перегрузка битового сдвига вправо
};

#endif // !FRACTION123



