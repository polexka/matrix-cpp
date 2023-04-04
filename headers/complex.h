#include<iostream>

#ifndef COMPLEX_H
#define COMPLEX_H

using namespace std;

class TComplex
{
public:
    TComplex();
    TComplex(double r, double i);
    TComplex(int i);

    double re;
    double im;

    TComplex operator+ (const TComplex& c);
    TComplex operator- (const TComplex& c);
    TComplex operator* (const TComplex& c);
    TComplex operator/ (const TComplex& c);

    TComplex& operator = (const TComplex& c);
    // TComplex& operator = (int c);

    bool operator== (const TComplex& c);
    bool operator!= (const TComplex& c);


    friend istream& operator >> (istream & in, TComplex & c);
    friend ostream& operator << (ostream & os, const TComplex & c);

protected:

private:
};

#endif // COMPLEX_H
