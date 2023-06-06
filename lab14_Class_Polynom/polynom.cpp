#include "polynom.h"

//Constructor and destructor #########################################
Polynom::Polynom()
{
    size = 0;
    coeff = nullptr;
}

Polynom::Polynom(const Polynom &p)
{
    size = p.size;
    coeff = new double [p.size];
    for (int i = 0; i < p.size; i++)
    {
        coeff[i] = p.coeff[i];
    }
}

Polynom::Polynom(const int size, const double coeff[])
{
    this->size = size;
    this->coeff = new double [size];
    for (int i = 0; i < size; i++)
    {
        this->coeff[i] = coeff[size - i - 1];
    }
    fit(*this);
}

Polynom::~Polynom()
{
    delete [] coeff;
}

//= ##################################################################
Polynom& Polynom::operator=(const Polynom &p)
{
    if (this != &p)
    {
        double *new_coeff = new double [p.size];
        for (int i = 0; i < p.size; i++)
        {
            new_coeff[i] = p.coeff[i];
        }
        
        delete [] coeff;
        
        coeff = new_coeff;
        size = p.size;
    }
    return *this;
}

//Setter and getter ##################################################
void Polynom::setCoeff(int deg, double coeff)
{
    this->coeff[deg] = coeff;
}

double Polynom::getCoeff(int deg)
{
    return coeff[deg];
}

int Polynom::getDeg()
{
    return size - 1;
}

// == != < > <= >= ############################################
bool Polynom::operator==(const Polynom &p) const
{
    if (size != p.size)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (coeff[i] != p.coeff[i])
                return false;
        }
    }
    return true;
}

bool Polynom::operator!=(const Polynom &p) const
{
    return !(*this == p);
}

bool Polynom::operator>(const Polynom &p) const
{
    if (size > p.size)
    {
        return true;
    }
    else if (size < p.size)
    {
        return false;
    }
    else
    {
        for (int i = size - 1; i >= 0; i--)
        {
            if (coeff[i] > p.coeff[i])
                return true;
            else if (coeff[i] < p.coeff[i])
                return false;
        }
    }
    return false;
}

bool Polynom::operator<(const Polynom &p) const
{
    return p > *this;
}

bool Polynom::operator>=(const Polynom &p) const
{
    return !(*this < p);
}

bool Polynom::operator<=(const Polynom &p) const
{
    return !(*this > p);
}

//+ - * ################################################################
Polynom Polynom::operator+(const Polynom &p)
{
    Polynom temp;
    if (size >= p.size)
    {
        temp.size = size;
        temp.coeff = new double [temp.size];
        for (int i = 0; i < p.size; i++)
        {
            temp.coeff[i] = int(coeff[i] + p.coeff[i]) % 7;
        }
        for (int i = p.size; i < temp.size; i++)
        {
            temp.coeff[i] = int(coeff[i]) % 7;
        }
    }
    else
    {
        temp.size = p.size;
        temp.coeff = new double [temp.size];
        for (int i = 0; i < size; i++)
        {
            temp.coeff[i] = coeff[i] + p.coeff[i];
        }
        for (int i = size; i < temp.size; i++)
        {
            temp.coeff[i] = p.coeff[i];
        }
    }
    fit(temp);
    return temp;    
}

Polynom Polynom::operator-(const Polynom &p)
{
    Polynom temp;
    if (size >= p.size)
    {
        temp.size = size;
        temp.coeff = new double [temp.size];
        for (int i = 0; i < p.size; i++)
        {
            temp.coeff[i] = coeff[i] - p.coeff[i];
        }
        for (int i = p.size; i < temp.size; i++)
        {
            temp.coeff[i] = coeff[i];
        }
    }
    else
    {
        temp.size = p.size;
        temp.coeff = new double [temp.size];
        for (int i = 0; i < size; i++)
        {
            temp.coeff[i] = coeff[i] - p.coeff[i];
        }
        for (int i = size; i < temp.size; i++)
        {
            temp.coeff[i] = p.coeff[i];
        }
    }
    fit(temp);
    return temp; 
}

Polynom Polynom::operator*(const Polynom &p)
{
    Polynom temp;
    temp.size = size + p.size - 1;
    temp.coeff = new double [temp.size];
    
    for (int i = 0; i < temp.size; i++)
        temp.coeff[i] = 0;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < p.size; j++)
        {
            temp.coeff[i + j] = int(temp.coeff[i + j] + coeff[i] * p.coeff[j]);
        }
    }
    fit(temp);
    return temp;
}

Polynom& Polynom::operator+=(const Polynom &p)
{
    *this = *this + p;
    return *this;
}

Polynom& Polynom::operator-=(const Polynom &p)
{
    *this = *this - p;
    return *this;
}

Polynom& Polynom::operator*=(const Polynom &p)
{
    *this = *this * p;
    return *this;
}

//Pow ################################################################
Polynom Polynom::pow(int deg)
{
    double cf[] = {1};
    Polynom res(1, cf);
    for (int i = 0; i < deg; i++)
    {
        res = res * (*this);
    }
    *this = res;
    return res;
}

//iostream ###########################################################
std::istream& operator>>(std::istream &s, Polynom &p)
{
    delete [] p.coeff;
    s >> p.size;
    p.coeff = new double [p.size];
    for (int i = p.size - 1; i >= 0; i--)
    {
        s >> p.coeff[i];
    }
    
    return s;
}

std::ostream& operator<<(std::ostream &s, Polynom &p)
{
    if (p.coeff != nullptr)
    {
        for (int i = p.size - 1; i > 0; i--)
        {
            if (p.coeff[i])
                std::cout << p.coeff[i] << "*x^" << i << " + ";
        }
        std::cout << p.coeff[0];
    }
    else
    {
        std::cout << "NULL" << std::endl;
    }
    return s;
}

//####################################################################
void Polynom::fit(Polynom &p)
{
    int new_size = p.size;
    while (p.coeff[new_size - 1] == 0)
        new_size--;
    if (new_size != p.size)
    {
        Polynom tmp;
        tmp.size = new_size;
        tmp.coeff = new double [new_size];
        for (int i = 0; i < tmp.size; i++)
        {
            tmp.coeff[i] = p.coeff[i];
        }

        p = tmp;
    }
}




























