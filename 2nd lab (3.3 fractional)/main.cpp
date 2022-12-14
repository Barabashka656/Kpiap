#include <iostream>
#include <exception>
#include <numeric>
#include <algorithm>
#include <sstream>

using namespace std;

int gcd(const int a, const int b)
{
    if (b == 0)return a;
    else return gcd(b, a % b);
}


int lcm(const int a, const int b)
{
    return a * b / gcd(a, b);
}

class Fractional{
public:

    Fractional(const int num = 0, const int den = 1)
    {
        if (den == 0)
        {
            cout << "denominator can't be zero";
            exit(-1);
            
        }

        numerator = num;
        denominator = den;

        if (((denominator < 0) && (numerator > 0)) || ((denominator < 0) && (numerator < 0)))
        {
            denominator *= -1;
            numerator *= -1;
        }
        if (numerator == 0)
        {
            denominator = 1;
        }
        else if (gcd(abs(numerator), abs(denominator)) != 1)
        {
            int dop = gcd(abs(numerator), abs(denominator));
            numerator /= dop;
            denominator /= dop;
        }

    
    }
    int Numerator() const 
    {
        return numerator;
    }

    int Denominator() const 
    {
        return denominator;
    }
   
    Fractional operator+(const Fractional& r2); 
    Fractional operator+(const float& float_r1);
    Fractional operator-(const Fractional& r2);
    Fractional operator-(const float& float_r1);
   
    int& operator[](const int index);
    
    Fractional& operator ++();
    
    Fractional& operator ++(int);
    
    Fractional& operator --(); //dosent friend because "this" 
    
    Fractional& operator --(int);


    operator float() const
    {
        return float(this->numerator) / this->denominator; 
    }

    friend ostream& operator << (ostream& stream, const Fractional& r);

    friend Fractional operator+(const float& float_r1, const Fractional& r2);

    friend Fractional operator-(const float& float_r1, const Fractional& r2);


    friend bool operator==(const float& float_r1, const  Fractional& r2);
    friend bool operator==(const Fractional& r2, const float& float_r1);

    friend bool operator>(const float& float_r1, const  Fractional& r2);
    friend bool operator>(const Fractional& r2, const float& float_r1);

    friend bool operator<(const float& float_r1, const  Fractional& r2);
    friend bool operator<(const Fractional& r2, const float& float_r1);


    
private:
    int numerator;
    int denominator;

};



Fractional Fractional::operator+(const Fractional& r2)
{

    if (this->Denominator() == r2.Denominator())
    {
        return Fractional{ this->Numerator() + r2.Numerator(), this->Denominator() };
    }
    else
    {
        int NOK = lcm(this->Denominator(), r2.Denominator());
        int newDen1 = NOK, newDen2 = NOK, newNum1, newNum2;
        newNum1 = NOK / this->Denominator() * this->Numerator();
        newNum2 = NOK / r2.Denominator() * r2.Numerator();

        return Fractional{ newNum1 + newNum2 ,NOK };
    }
}

Fractional Fractional::operator+(const float& float_r2)
{
    float float_r1;
    float_r1 = float(*this);

    float sum = float_r1 + float_r2;
    int denominator = 1;
    while (sum != int(sum))
    {
        sum *= 10;
        denominator *= 10;
    }
    int numerator = sum;
    return Fractional{ numerator , denominator };
}

Fractional operator+(const float& float_r1, const Fractional& r2)
{
    float float_r2;
    float_r2 = float(r2);
    float sum = float_r1 + float_r2;
    int denominator = 1;
    while (sum != int(sum))
    {
        sum *= 10;
        denominator *= 10;
    }
    int numerator = sum;
    return Fractional{ numerator , denominator };
}

Fractional Fractional::operator-(const Fractional& r2)
{
    if (this->Denominator() == r2.Denominator())
    {
        return Fractional{ this->Numerator() - r2.Numerator(), this->Denominator() };
    }
    else
    {
        int NOK = lcm(this->Denominator(), r2.Denominator());
        int newDen1 = NOK, newDen2 = NOK, newNum1, newNum2;
        newNum1 = NOK / this->Denominator() * this->Numerator();
        newNum2 = NOK / r2.Denominator() * r2.Numerator();

        return Fractional{ newNum1 - newNum2 ,NOK };
    }
}

Fractional Fractional::operator-(const float& float_r2)
{
    float float_r1;
    float_r1 = float(*this);

    float dif = float_r1 - float_r2;
    int denominator = 1;
    while (dif != int(dif))
    {
        dif *= 10;
        denominator *= 10;
    }
    int numerator = dif;
    return Fractional{ numerator , denominator };
}

Fractional operator-(const float& float_r1, const Fractional& r2)
{
    float float_r2;
    float_r2 = float(r2);
    float dif = float_r1 - float_r2;
    int denominator = 1;
    while (dif != int(dif))
    {
        dif *= 10;
        denominator *= 10;
    }
    int numerator = dif;
    return Fractional{ numerator , denominator };
}


Fractional& Fractional::operator ++()
{
    this->numerator += this->denominator;
    return *this;
}

Fractional& Fractional::operator ++(int)
{
    Fractional temp(*this);
    this->numerator += this->denominator;
    return temp;
}

Fractional& Fractional::operator --() //can't be friend because "this" 
{
    this->numerator -= this->denominator;
    return *this;
}

Fractional& Fractional::operator --(int)
{
    Fractional temp(*this);
    this->numerator -= this->denominator;
    return temp;
}


int& Fractional::operator[](const int index)
{
    if (index == 0)
        return numerator;
    if (index == 1)
        return denominator;
    else
        cout << "Array index out of bounds (index: " << index << ") is missing";
    exit(-2);
}


bool operator==(const Fractional& r1, const  Fractional& r2)
{
    return ((r1.Numerator() == r2.Numerator()) && (r1.Denominator() == r2.Denominator()));
}

bool operator==(const float& float_r1, const  Fractional& r2)
{
    float float_r2;
    float_r2 = float(r2);
    return (float_r1 == float_r2);
}

bool operator==(const Fractional& r2, const float& float_r1)
{
    float float_r2;
    float_r2 = float(r2);
    return (float_r1 == float_r2);
}


bool operator>(const Fractional& r1, const  Fractional& r2)
{

    if ((r1.Numerator() == r2.Numerator()) && (r1.Denominator() > r2.Denominator()))
        return false;
    if ((r1.Numerator() == r2.Numerator()) && (r1.Denominator() < r2.Denominator()))
        return true;
    if ((r1.Numerator() > r2.Numerator()) && (r1.Denominator() == r2.Denominator()))
        return true;
    if ((r1.Numerator() < r2.Numerator()) && (r1.Denominator() == r2.Denominator()))
        return false;
    int OurLcm = lcm(r1.Denominator(), r2.Denominator());
    int newNominator1= OurLcm/r2.Denominator() * r1.Numerator(), newNumerator2 = OurLcm / r1.Denominator() * r2.Numerator();

    return (newNominator1 > newNumerator2);
}

bool operator>(const float& float_r1, const  Fractional& r2)
{
    float float_r2;
    float_r2 = float(r2);
    return (float_r1 > float_r2);
}

bool operator>(const Fractional& r2, const float& float_r1)
{
    float float_r2;
    float_r2 = float(r2);
    return (float_r1 < float_r2);
}


bool operator<(const Fractional& r1, const  Fractional& r2)
{

    if ((r1.Numerator() == r2.Numerator()) && (r1.Denominator() > r2.Denominator()))
        return true;
    if ((r1.Numerator() == r2.Numerator()) && (r1.Denominator() < r2.Denominator()))
        return false;
    if ((r1.Numerator() > r2.Numerator()) && (r1.Denominator() == r2.Denominator()))
        return false;
    if ((r1.Numerator() < r2.Numerator()) && (r1.Denominator() == r2.Denominator()))
        return true;
    int OurLcm = lcm(r1.Denominator(), r2.Denominator());
    int newNominator1 = OurLcm / r2.Denominator() * r1.Numerator(), newNumerator2 = OurLcm / r1.Denominator() * r2.Numerator();

    return (newNominator1 < newNumerator2);
}

bool operator<(const float& float_r1, const  Fractional& r2)
{
    float float_r2;
    float_r2 = float(r2);
    return (float_r1 < float_r2);
}

bool operator<(const Fractional& r2, const float& float_r1)
{
    float float_r2;
    float_r2 = float(r2);
    return (float_r1 > float_r2);
}





ostream& operator << (ostream& stream, const Fractional& r)
{
    stream << r.Numerator() << '/' << r.Denominator();
    return stream;
}





int main()
{
    Fractional a;
    Fractional b(1, 4);
    Fractional c(-1, 2);
    Fractional a1;

 
    cout << "Fractional a = " << a << endl;
    cout << "Fractional b = " << b << endl << endl << endl;


    cout << "///// operator '[]' /////" << endl << endl;

    cout << "Fractional c = " << c << " // c[0] (numerator) = " << c[0]
        << " // c[1] (denominator) = " << c[1] << endl << endl << endl;


    cout << "///// prefix increment '++a' /////" << endl<<endl; 

    cout << "Fractional a = " << a 
        << " // ++a (+1/1) = " << ++a << " //  after operating a = " << a << endl << endl << endl;


    cout << "///// postfix increment 'a++' /////" << endl << endl;

    cout << "Fractional a = " << a;
    cout << " // a++ (+1/1) = " << a++ <<  " //  after operating a = " << a << endl<<endl << endl;


    cout << "///// operator '+' (operands of the same type) /////" << endl << endl;

    cout << "Fractional c = " << c << endl;
    cout << "Fractional b = " << b << endl;
    cout << " c + b = " << c + b << endl << endl << endl;


    cout << "///// operator '-' (operands of the same type) /////" << endl << endl;

    cout << "Fractional c = " << c << endl;
    cout << "Fractional b = " << b << endl;
    cout << " c - b = " << c - b << endl << endl << endl;


    cout << "///// operator '>' (operands of the same type) /////" << endl << endl;

    cout << "Fractional c = " << c << endl;
    cout << "Fractional b = " << b << endl;
    cout << " c > b ? - " << (c > b) << endl;
    cout << " b > c ? - " << (b > c) << endl;
    cout << " b > b ? - " << (b > b) << endl << endl << endl;


    cout << "///// operator '<' (operands of the same type) /////" << endl << endl;

    cout << "Fractional c = " << c << endl;
    cout << "Fractional b = " << b << endl;
    cout << " c < b ? - " << (c < b) << endl;
    cout << " b < c ? - " << (b < c) << endl;
    cout << " b < b ? - " << (b < b) << endl << endl << endl;


    cout << "///// operator '==' (operands of the same type) /////" << endl << endl;

    cout << "Fractional c = " << c << endl;
    cout << "Fractional b = " << b << endl;
    cout << " c == b ? - " << (c == b) << endl;
    cout << " b == c ? - " << (b == c) << endl;
    cout << " b == b ? - " << (b == b) << endl << endl << endl;


    cout << "///// prefix decrement '--a' /////" << endl << endl;

    cout << "Fractional a = " << a;
    cout << " // --a (-1/1) = " << --a << " //  after operating a = " << a << endl << endl << endl;


    cout << "///// postfix decrement 'a--' /////" << endl << endl;

    cout << "Fractional a = " << a;
    cout << " // a-- (-1/1) = " << a-- << " //  after operating a = " << a << endl << endl << endl;

    float f = 2.3;

    cout << "///// operator '+' (operands of different types) /////" << endl << endl;

    cout << "Fractional c = " << c << endl;
    cout << "     float f = " << f << endl;
    cout << " c + f = " << c + f << endl;
    cout << " f + c = " << f + c << endl << endl << endl;


    cout << "///// operator '-' (operands of different types) /////" << endl << endl;

    cout << "Fractional c = " << c << endl;
    cout << "     float f = " << f << endl;
    cout << " c - f = " << c - f << endl;
    cout << " f - c = " << f - c << endl << endl << endl;

    
    cout << "///// operator '>' (operands of different types) /////" << endl << endl;

    cout << "Fractional c = " << c << endl;
    cout << "     float f = " << f << endl;
    cout << " c > f ? - " << (c > f) << endl;
    cout << " f > c ? - " << (f > c) << endl << endl << endl;


    cout << "///// operator '<' (operands of different types) /////" << endl << endl;

    cout << "Fractional c = " << c << endl;
    cout << "     float f = " << f << endl;
    cout << " c < f ? - " << (c < f) << endl;
    cout << " f < c ? - " << (f < c) << endl << endl << endl;
    

    

    cout << "///// operator '==' (operands of different types) /////" << endl << endl;
    f = -0.5;
    float f2 = 0.5;
    cout << "Fractional c  = " << c << endl;
    cout << "     float f  = " << f << endl;
    cout << "     float f2 = " << f2 << endl;
    cout << " c == f  ? - " << (c == f) << endl;
    cout << " f == c  ? - " << (f == c) << endl;
    cout << " f == f2 ? - " << (f == f2) << endl << endl << endl;


    

    cout << "///// cast 'float()' /////" << endl << endl;

    cout << "Fractional c = " << c << endl; 
    cout << "    float(c) = " << float(c) << endl << endl;
    
}
