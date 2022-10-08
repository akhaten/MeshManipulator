#ifndef BERNSTEIN_POLYNOM_HPP
#define BERNSTEIN_POLYNOM_HPP

#include <vector>

class BernsteinPolynom
{

public:
    BernsteinPolynom(const unsigned int n);
    ~BernsteinPolynom();
    float eval(const unsigned int k, const float t);;
    void print();

private:
    unsigned int n;
    std::vector<unsigned int> binomial_coefs;
    void pascalTriangle();

};

#endif // BERNSTEIN_POLYNOM_HPP