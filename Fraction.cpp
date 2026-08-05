#include "Fraction.h"

Fraction::Fraction(int n, int d) : tuso(n), mauso(d) {}

bool Fraction::operator>(const Fraction& other) const {
    return tuso * other.mauso > other.tuso * mauso;
}

bool Fraction::operator<(const Fraction& other) const {
    return tuso * other.mauso < other.tuso * mauso;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << f.tuso << "/" << f.mauso;
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& f) {
    is >> f.tuso >> f.mauso;
    return is;
}