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

	void set_chislitel(int chislitel); // ������ ���������
	void set_znamtnatel(int znamenatel); // ������ �����������

	int get_chislitel();  // ������ ���������
	int get_znamenatel();  //������ �����������

	void show_simple_fraction(); // ����� �� ����� ������� �����
	void show_decimal();  // ����� �� ����� ���������� �����
	double get_decimal(); // ������� � �������� ���������� ���������� �����
	void fraction_reduction(); // ���������� ������� �����

	bool operator < (const Fraction& other);  // ���������� ��������� <
	bool operator > (const Fraction& other);  // ���������� ��������� >
	bool operator == (const Fraction& other);   // ���������� ��������� ==
	bool operator != (const Fraction& other);   // ���������� ��������� !=

	Fraction& operator = (const Fraction& other);  // ���������� ��������� =
	Fraction& operator = (const double x);  // ���������� ��������� = ��� double

	Fraction operator + (const Fraction& other);  // ���������� ��������� +
	Fraction& operator += (const Fraction& other);  // ���������� ��������� +=

	Fraction operator - (const Fraction& other);  // ���������� ��������� -
	Fraction& operator -= (const Fraction& other);  // ���������� ��������� -=

	Fraction operator * (const Fraction& other);  // ���������� ��������� *
	Fraction& operator *= (const Fraction& other);  // ���������� ��������� *=

	Fraction operator / (const Fraction& other);  // ���������� ��������� /
	Fraction& operator /= (const Fraction& other);  // ���������� ��������� /=

	operator double(); // ���������� ���� � double

	friend std::ostream& operator << (std::ostream& ost, const Fraction& f); // ���������� �������� ������ �����
	friend std::istream& operator >> (std::istream& ost, const Fraction& f); // ���������� �������� ������ ������
};

#endif // !FRACTION123



