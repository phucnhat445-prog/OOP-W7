#pragma once
#include <iostream>
class Fraction {
private:
    int numerator, denominator;
public:
    Fraction(int n = 0, int d = 1);

    bool operator>(const Fraction& other) const;
    bool operator<(const Fraction& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
};