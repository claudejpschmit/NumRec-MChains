#include "Pdf.hpp"
#include <cmath>
#define PI 3.14159265

using namespace std;

double Pdf::drawValue(double noise)
{
    (void)noise;
    return 0;
}

double Pdf::evaluatePdf(double x)
{
    (void)x;
    return 0;
}

/* ****         Gaussian        **** */

Gaussian::Gaussian(double sigma, double mu, double x_range)
    :
    sigma(sigma),
    mu(mu),
    x_range(x_range)
{
    // seed for rand()
    srand(15000);
    max_random = evaluatePdf(mu);
}

double Gaussian::drawValue(double noise)
{
    double y1, y2, random_x;
    max_random += noise;

    do 
    {
        // creates random number between 0 and 1.
        random_x = (double) rand() / (double) RAND_MAX;         
        // creates random number between 0 and x_range.
        random_x *= x_range; 

        if (((double) rand() / (double) RAND_MAX) < 0.5) {
            // creates random number between mu and mu + x_range. 
            random_x += mu;
        }
        else {
            // creates random number between mu - x_range and mu. 
            random_x = mu - random_x;
        }
        
        // evaluates the distribution at random_x
        y1 = evaluatePdf(random_x) + noise;       
        // creates random number between 0 and 1.  
        y2 = (double) rand() / (double) RAND_MAX; 
        // creates random number between 0 and max_random.
        y2 *= max_random;     }
    while (y2 >= y1);

    return random_x;

}

double Gaussian::evaluatePdf(double x)
{
    double norm = 1.0/(sigma * sqrt(2 * PI));
    double twoSigSq = 2 * sigma * sigma;
    return norm * exp(- (x - mu) * (x - mu) / twoSigSq);
}

/* ****         Uniform         **** */

Uniform::Uniform(double x_min, double x_max)
    :
    x_max(x_max),
    x_min(x_min)
{
    srand(15000);
}

double Uniform::drawValue(double noise)
{
    // creates RN between 0 and 1.
    double res = (double) rand() / ((double) RAND_MAX);

    // creates RN between x_min and x_max
    res *= (x_max - x_min);
    res += x_min;
    return res + noise;

}

double Uniform::evaluatePdf(double x)
{
    (void)x;
    return 1/(x_max - x_min);
}


