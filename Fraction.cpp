#include "Fraction.h"

Fraction::Fraction(int chislitel, int znamenatel) {

	if (znamenatel == 0) throw std::exception("знаменатель не должен быть равен нулю!!!");

	this->chislitel = chislitel;
	this->znamenatel = znamenatel;
}

Fraction::Fraction(double x)
{
	std::string str = std::to_string(x);
	std::string str1; // строка для хранения значения числителя
	int y = 1; // знаменатель
	bool val = false; // проверка на наличие точки

	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0 && str[i] == '0') continue;
		else if (str[i] == '.')
		{
			val = true;
			continue;
		}
		else str1 += str[i];
		if (val) y *= 10;
	}

	this->chislitel = std::stoi(str1);
	this->znamenatel = y;
	this->fraction_reduction();
}

void Fraction::set_chislitel(int chislitel)
{
	this->chislitel = chislitel;
}

void Fraction::set_znamtnatel(int znamenatel)
{
	if (znamenatel == 0) throw std::exception("знаменатель не должен быть равен нулю!!!"); 
	this->znamenatel = znamenatel;
}

int Fraction::get_chislitel()
{
	return chislitel;
}

int Fraction::get_znamenatel()
{
	return znamenatel;
}

void Fraction::show_simple_fraction()
{
	if (this->chislitel < this->znamenatel) std::cout << "(" << this->chislitel << "/" << this->znamenatel << ")\n";
	else if (this->chislitel == this->znamenatel) std::cout << "1\n";
	else
	{
		int x = this->chislitel / this->znamenatel;
		if (this->chislitel % this->znamenatel == 0)
			std::cout << x << "\n";
		else
		{
			int y = this->chislitel - (x * this->znamenatel);
			std::cout << x << "(" << y << "/" << this->znamenatel << ")\n";
		}
	}
}

void Fraction::show_decimal()
{
	std::cout << (double)this->chislitel / this->znamenatel << "\n";
}

double Fraction::get_decimal()
{
	return (double)this->chislitel / this->znamenatel;
}

void Fraction::fraction_reduction()
{
	bool enable;

	do
	{

		enable = false;

		for (int i = 2; i <= this->znamenatel; i++)
			if (this->chislitel % i == 0 && this->znamenatel % i == 0)
			{
				this->chislitel /= i;
				this->znamenatel /= i;
				enable = true;
			}

	} while (enable);
}

bool Fraction::operator < (const Fraction& other)
{
	int x = this->chislitel * other.znamenatel;
	int y = other.chislitel * this->znamenatel;

	return (x < y);
}

bool Fraction::operator > (const Fraction& other)
{
	int x = this->chislitel * other.znamenatel;
	int y = other.chislitel * this->znamenatel;

	return (x > y);
}

bool Fraction::operator == (const Fraction& other)
{
	int x = this->chislitel * other.znamenatel;
	int y = other.chislitel * this->znamenatel;

	return x == y;
}

bool Fraction::operator!=(const Fraction& other)
{
	int x = this->chislitel * other.znamenatel;
	int y = other.chislitel * this->znamenatel;

	return x != y;
}

Fraction& Fraction::operator=(const Fraction& other)
{
	this->chislitel = other.chislitel;
	this->znamenatel = other.znamenatel;
	return *this;
}

Fraction& Fraction::operator=(const double x)
{
	std::string str = std::to_string(x);
	std::string str1; // строка для хранения значения числителя
	int y = 1; // знаменатель
	bool val = false; // проверка на наличие точки

	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0 && str[i] == '0') continue;
		else if (str[i] == '.')
		{
			val = true;
			continue;
		}
		else str1 += str[i];
		if (val) y *= 10;
	}

	this->chislitel = std::stoi(str1);
	this->znamenatel = y;
	this->fraction_reduction();

	return *this;
}

Fraction Fraction::operator + (const Fraction& other)
{
	Fraction f;

	if (this->znamenatel == other.znamenatel)
	{
		f.chislitel = this->chislitel + other.chislitel;
		f.znamenatel = this->znamenatel;
		f.fraction_reduction();
		return f;
	}

	else
	{
		f.chislitel = this->chislitel * other.znamenatel + other.chislitel * this->znamenatel;
		f.znamenatel = this->znamenatel * other.znamenatel;
		f.fraction_reduction();
		return f;
	}
}

Fraction& Fraction::operator+=(const Fraction& other)
{
	if (this->znamenatel == other.znamenatel)
	{
		this->chislitel += other.chislitel;
		this->fraction_reduction();
		return *this;
	}

	else
	{
		this->chislitel = this->chislitel * other.znamenatel + other.chislitel * this->znamenatel;
		this->znamenatel *= other.znamenatel;
		this->fraction_reduction();
		return *this;
	}
}

Fraction Fraction::operator - (const Fraction& other)
{
	Fraction f;

	if (this->znamenatel == other.znamenatel)
	{
		f.chislitel = this->chislitel - other.chislitel;
		f.znamenatel = this->znamenatel;
		f.fraction_reduction();
		return f;
	}

	else
	{
		f.chislitel = this->chislitel * other.znamenatel - other.chislitel * this->znamenatel;
		f.znamenatel = this->znamenatel * other.znamenatel;
		f.fraction_reduction();
		return f;
	}
}

Fraction& Fraction::operator-=(const Fraction& other)
{
	if (this->znamenatel == other.znamenatel)
	{
		this->chislitel -= other.chislitel;
		this->fraction_reduction();
		return *this;
	}

	else
	{
		this->chislitel = this->chislitel * other.znamenatel - other.chislitel * this->znamenatel;
		this->znamenatel *= other.znamenatel;
		this->fraction_reduction();
		return *this;
	}
}

Fraction Fraction::operator * (const Fraction& other)
{
	Fraction f;

	f.chislitel = this->chislitel * other.chislitel;
	f.znamenatel = this->znamenatel * other.znamenatel;
	f.fraction_reduction();
	return f;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
	this->chislitel *= other.chislitel;
	this->znamenatel *= other.znamenatel;
	this->fraction_reduction();
	return *this;
}

Fraction Fraction::operator / (const Fraction& other)
{
	Fraction f;

	f.chislitel = this->chislitel * other.znamenatel;
	f.znamenatel = this->znamenatel * other.chislitel;
	f.fraction_reduction();
	return f;
}

Fraction& Fraction::operator/=(const Fraction& other)
{
	this->chislitel *= other.znamenatel;
	this->znamenatel *= other.chislitel;
	this->fraction_reduction();
	return *this;
}

Fraction::operator double()
{
	return static_cast<double>(chislitel) / znamenatel;
}

std::ostream& operator<<(std::ostream& ost, const Fraction& f)
{
	ost << static_cast<double>(f.chislitel) / f.znamenatel;
	return ost;
}

std::istream& operator>>(std::istream& ist, Fraction& f)
{
	int x, y;
	ist >> x >> y;
	f.set_chislitel(x);
	f.set_znamtnatel(y);
	return ist;
}