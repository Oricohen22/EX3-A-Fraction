
#include "doctest.h"
#include <string>
#include "sources/Fraction.hpp"
#include <iostream>
using namespace std;
using namespace ariel;

TEST_CASE("Fraction constructors")
{
    Fraction f1_(1, 2);
    CHECK(f1_.getNumerator() == 1);
    CHECK(f1_.getDenominator() == 2);

    Fraction f2_(0.5);
    std::cout<<"this is the numerator" <<f2_.getNumerator()<<std::endl;
    std::cout<<"this is the numerator" <<f2_.getDenominator()<<std::endl;
    CHECK(f2_.getNumerator() == 1);
    CHECK(f2_.getDenominator() == 2);

    CHECK_THROWS_AS(Fraction(1, 0), std::runtime_error);
}

TEST_CASE("Fraction arithmetic operators")
{
    Fraction f1_(1, 2);
    Fraction f2_(1, 3);

    SUBCASE("addition")
    {
        Fraction result = f1_ + f2_;
        CHECK(result.getNumerator() == 5);
        CHECK(result.getDenominator() == 6);
    }

    SUBCASE("subtraction")
    {
        Fraction result = f1_ - f2_;
        CHECK(result.getNumerator() == 1);
        CHECK(result.getDenominator() == 6);
    }

    SUBCASE("multiplication")
    {
        Fraction result = f1_ * f2_;
        CHECK(result.getNumerator() == 1);
        CHECK(result.getDenominator() == 6);
    }

    SUBCASE("division")
    {
        Fraction result = f1_ / f2_;
        CHECK(result.getNumerator() == 3);
        CHECK(result.getDenominator() == 2);
    }
}

TEST_CASE("Fraction comparison operators")
{
    Fraction f1_(1, 2);
    Fraction f2_(1, 3);

    SUBCASE("equality")
    {
        CHECK(f1_ == Fraction(1, 2));
        CHECK_FALSE(f1_ == f2_);
    }

    SUBCASE("greater than")
    {
        CHECK(f1_ > f2_);
        CHECK_FALSE(f2_ > f1_);
    }

    SUBCASE("greater than or equal to")
    {
        CHECK(f1_ >= Fraction(1, 2));
        CHECK(f1_ >= f2_);
        CHECK_FALSE(f2_ >= f1_);
    }

    SUBCASE("less than")
    {
        CHECK(f2_ < f1_);
        CHECK_FALSE(f1_ < f2_);
    }

    SUBCASE("less than or equal to")
    {
        CHECK(f1_ <= Fraction(1, 2));
        CHECK(f2_ <= f1_);
        CHECK_FALSE(f1_ <= f2_);
    }
}

TEST_CASE("Fraction increment and decrement operators")
{
    Fraction f(1, 2);

    SUBCASE("postfix increment")
    {
        Fraction result = f++;
        CHECK(result.getNumerator() == 1);
        CHECK(result.getDenominator() == 2);
        CHECK(f.getNumerator() == 3);
        CHECK(f.getDenominator() == 2);
    }

    SUBCASE("prefix increment")
    {
        Fraction result = ++f;
        CHECK(result.getNumerator() == 3);
        CHECK(result.getDenominator() == 2);
        CHECK(f.getNumerator() == 3);
        CHECK(f.getDenominator() == 2);
    }
}