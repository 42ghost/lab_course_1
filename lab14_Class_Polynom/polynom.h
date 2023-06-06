#ifndef _POLYNOM_H_
#define _POLYNOM_H_

#include <iostream>

class Polynom
{
    private:
        double* coeff;
        int size;

        void fit(Polynom &);
    public:
        Polynom();
        Polynom(const Polynom &);
        Polynom(const int size, const double clist[]);        
        ~Polynom();

        void setCoeff(int deg, double coeff);
        double getCoeff(int deg); 
        int getDeg();

        bool operator==(const Polynom &) const;
        bool operator!=(const Polynom &) const;
        bool operator>(const Polynom &) const;
        bool operator<(const Polynom &) const;
        bool operator>=(const Polynom &) const;
        bool operator<=(const Polynom &) const;

        Polynom operator+(const Polynom &);
        Polynom operator-(const Polynom &);
        Polynom operator*(const Polynom &);
        Polynom& operator+=(const Polynom &);
        Polynom& operator-=(const Polynom &);
        Polynom& operator*=(const Polynom &);
        
        Polynom pow(int deg);

        Polynom& operator=(const Polynom &);

        friend std::istream& operator >>(std::istream &s, Polynom &);
        friend std::ostream& operator <<(std::ostream &s, Polynom &);
};

#endif
