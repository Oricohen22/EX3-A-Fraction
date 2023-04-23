
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <numeric>
#include <math.h>
#include "Fraction.hpp"
using namespace std;

Fraction::Fraction(int a, int b)
{
    if (b == 0)
    {
        throw std::runtime_error("can't divide by 0");
    }
    (this)->Numerator = a;
    (this)->Denominator = b;
    reduce();
}

Fraction::Fraction(float number)
{
    this->Numerator = number * 1000;
    this->Denominator = 1000;
    this->reduce();
}

int Fraction::getNumerator()
{
    return this->Numerator;
}

int Fraction::getDenominator()
{
    return this->Denominator;
}

void Fraction::setNumerator(int Numerator)
{
    this->Numerator = Numerator;
}

void Fraction::setDenominator(int denominator)
{
    if (denominator == 0)
    {
        throw std ::invalid_argument("Invalid Denominator argument");
    }
    this->Denominator = denominator;
}
// operator '+' defination
Fraction operator+(float, const Fraction &other)
{
    return Fraction(1, 1);
}
Fraction Fraction::operator+(const Fraction &other)
{
    return (*this);
}

// operator '-' defination
Fraction Fraction::operator-(const Fraction &)
{
    return (*this);
}

Fraction operator-(const float, const Fraction &)
{
    return Fraction(1, 1);
}
// operator '*' defination
Fraction Fraction::operator*(const Fraction &)
{
    return (*this);
}

Fraction operator*(const float, const Fraction &)
{
    return Fraction(1, 1);
}
// operator '/' defination
Fraction Fraction::operator/(const Fraction &)
{
    return (*this);
}

Fraction operator/(const float, const Fraction &)
{
    return Fraction(1, 1);
}

bool Fraction::operator==(const Fraction &)
{
    return true;
}

bool operator==(const float, const Fraction &)
{
    return true;
}

bool Fraction::operator>(const Fraction &)
{
    return true;
}
bool operator>(const float, const Fraction &)
{
    return true;
}

bool Fraction::operator<(const Fraction &)
{
    return true;
}
bool operator<(const float, const Fraction &)
{
    return true;
}

bool Fraction::operator>=(const Fraction &other)
{
    return true;
}
bool operator>=(const float, const Fraction &)
{
    return true;
}

bool Fraction::operator<=(const Fraction &other)
{
    return true;
}

bool operator<=(const float, const Fraction &)
{
    return true;
}

Fraction Fraction::operator++(const int)
{
    return Fraction(1, 1);
}
Fraction Fraction::operator--(const int)
{
    return Fraction(1, 1);
}

Fraction &Fraction::operator++()
{
    return (*this);
}
Fraction &Fraction::operator--()
{
    return (*this);
}

// input and output operators
ostream &operator<<(std::ostream &os, const Fraction &frac)
{
    return (os << frac.Numerator << '/' << frac.Denominator);
}

ostream &operator>>(std::ostream &os, Fraction &frac)
{
    return (os >> frac);
}

int Fraction::gcd(const Fraction &otherFraction)
{
    int a = this->Denominator;
    int b = otherFraction.Denominator;
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// to reduce the fraction as much as possible
void Fraction::reduce()
{
    int minNumber = min(this->Numerator, this->Denominator);

    for (int i = minNumber; i > 1; i--)
    {
        if ((this->Numerator % i == 0) && (this->Denominator % i == 0))
        {
            this->Numerator = Numerator / i;
            this->Denominator = Denominator / i;
            break;
        }
    }
}
