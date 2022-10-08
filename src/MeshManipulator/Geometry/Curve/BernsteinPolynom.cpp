#include "BernsteinPolynom.hpp"
#include <glm/glm.hpp>
#include <iostream>

BernsteinPolynom::BernsteinPolynom(const unsigned int n)
{
    this->n = n;
    this->pascalTriangle();
}

BernsteinPolynom::~BernsteinPolynom()
{

}

float BernsteinPolynom::eval(const unsigned int k, const float t)
{

    unsigned int size = this->binomial_coefs.size();
    unsigned int index = k;

    if(size <= index)
        index = this->binomial_coefs.size() - 1 - (this->n%2) - index%size;

    return (float)(this->binomial_coefs[index] * pow(t, k) * pow(1-t, n-1-k));

}

void BernsteinPolynom::pascalTriangle()
{

    // Symetrie

    //1 , 1 : 1 -> [1]
    //2 , 1 : 1 1 -> [1]
    //3 , 2 : 1 2 1 -> [1, 2]
    //4 , 2 : 1 3 3 1 -> [1, 3]
    //5 , 3 : 1 4 6 4 1 -> [1, 4, 6]
    //6 , 3 : 1 5 10 10 5 1  -> [1, 5, 10]
    // unsigned int length = this->n / 2 + 1 - (this->n-1) % 2;

    // n = 1 : 1 / 2 + 1 - (1-1) % 2 = 1
    // n = 2 : 2 / 2 + 1 - (2-1) % 2 = 1
    // n = 3 : 3 / 2 + 1 - (3-1) % 2 = 2
    // n = 4 : 4 / 2 + 1 - (4-1) % 2 = 2
    // ...

    this->binomial_coefs.push_back(1);

    // Init : [1]
    for(unsigned int index = 1; index < this->n-1; ++index)
    {

        // index = 1, [1]
        // index = 2, [1, 2]
        // index = 3, [1, 3]
        // ...

        if(index%2 == 1)
        {
            auto last = this->binomial_coefs.back();
            this->binomial_coefs.push_back(last); 
        }
        
        // index = 1, [1, 1]
        // index = 2, [1, 2]
        // index = 3, [1, 3, 3]
        // ...

        for(unsigned int k = this->binomial_coefs.size()-1; 0 < k; --k)
            this->binomial_coefs[k] = this->binomial_coefs[k] + this->binomial_coefs[k-1];
        
        // index = 1, [1, 2]
        // index = 2, [1, 3]
        // index = 3, [1, 4, 6]
        // ...

    }

}

void BernsteinPolynom::print()
{
    unsigned int size = this->binomial_coefs.size();
    for(unsigned int k = 0; k < this->n; ++k)
    {
        unsigned int index = k;
        if(size <= index)
            index = this->binomial_coefs.size() - 1 - (this->n%2) - index%size;
        printf("%u ", this->binomial_coefs[index]);

    }
    printf("\n");
        
}
