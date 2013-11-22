#include "Metropolis.hpp"
#include <cmath>

#define PI 3.1415

Metropolis::Metropolis(vector<double> xi_initial)
{
    srand(15000);
    xi_values = xi_initial;
}

Metropolis::~Metropolis()
{

}

std::vector<double> Metropolis::step(vector<double> initial_xi)
{
    double random01 = ((double) rand() / (RAND_MAX));
    vector<double> temp = xi_values;
    for (int i = 0; i < initial_xi.size(); ++i)
    {
        xi_values[i] += res[i];
        double ratio = target_p(xi_values[i]) / target_p(temp[i]);

    }
    return 0;
}

double Metropolis::target_p(double x)
{
    return 0;
}
double Metropolis::trial_distr_q(double x, double sigma)
{
    double result;
    double norm = 1.0/(sigma * 2 * sqrt(PI)); 
    double twoSigSq = 1.0/(2 * sigma * sigma);
    return norm * exp(- twoSigSq * x * x);
}
