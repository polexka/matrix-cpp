#include "complex.h"

TComplex::TComplex() : re(0.0), im(0.0) {}

TComplex::TComplex(double r, double i) : re(r), im(i) {}


TComplex TComplex::operator + (const TComplex & c)
{
    return TComplex(re + c.re, im + c.im);
}

TComplex TComplex::operator - (const TComplex & c)
{
    return TComplex(re - c.re, im - c.im);
}

TComplex TComplex::operator * (const TComplex & c)
{
    return TComplex(re * c.re - im * c.im, re * c.im + im * c.re);
}

TComplex TComplex::operator / (const TComplex & c)
{
    double denominator = c.re * c.re + c.im * c.im;
    return TComplex((re * c.re + im * c.im) / denominator,
                    (im * c.re - re * c.im) / denominator);
}

TComplex & TComplex::operator = (const TComplex& c)
{
    re = c.re;
    im = c.im;
    return *this;
}

TComplex & TComplex::operator = (int c)
{
    this->re = this->re + c;
    return *this;
}

bool TComplex::operator == (const TComplex & c)
{
    return (re == c.re && im == c.im);
}
bool TComplex::operator != (const TComplex & c)
{
    return (re != c.re || im != c.im);
}

istream& operator >> (istream & in, TComplex & c)
{
    in >> c.re >> c.im;
    return in;
}

ostream& operator << (ostream & os, const TComplex & c)
{
    os << c.re << "+" << c.im << "i";
    return os;
}
