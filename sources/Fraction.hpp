#pragma once

#include <iostream>
using namespace std;
namespace ariel{}

class Fraction
{
private:
    int Numerator;
    int Denominator;
    void reduce();

public:
    // constructors
    // Fraction();
    Fraction(float);
    // Fraction(const Fraction& other); // copy constructor
    Fraction(int, int);
   
    // Fraction(const Fraction &Fother);

    int getNumerator();
    int getDenominator();
    void setNumerator(int );
    void setDenominator(int );

    // Fraction operators

    //+operators;
    Fraction operator+(const Fraction &);
    friend Fraction operator+(float, const Fraction &);

    // -operators
    Fraction operator-(const Fraction &);
    friend Fraction operator-(float, const Fraction &);

    // '/'operator
    Fraction operator/(const Fraction &);
    friend Fraction operator/(float, const Fraction &);

    //* operator
    Fraction operator*(const Fraction &);
    friend Fraction operator*(float, const Fraction &);

    // ***copersions operator***
    bool operator==(const Fraction &);
    friend bool operator==(float, const Fraction &);

    bool operator>(const Fraction &);
    friend bool operator>(float, const Fraction &);

    bool operator<(const Fraction &);
    friend bool operator<(float, const Fraction &);

    bool operator>=(const Fraction &);
    friend bool operator>=(float, const Fraction &);

    bool operator<=(const Fraction &);
    friend bool operator<=(float, const Fraction &);

    Fraction operator++(int);
    Fraction operator--(int);
    Fraction &operator++();
    Fraction &operator--();

    friend std::ostream &operator<<(std::ostream &stream, const Fraction &other); // output stream operator
    friend std::istream &operator>>(std::istream &stream, Fraction &other);           // input stream operator
    

    int gcd(const Fraction &);

    // float to_float() const;

    // float short_the_float(float f);

    // std::string to_string() const;
};
