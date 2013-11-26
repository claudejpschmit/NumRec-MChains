#include "Metropolis.hpp"
#include <cmath>

Metropolis::Metropolis(vector<double> initial_xi, Posterior *targetPdf)
{
    this->targetPdf = targetPdf;
    gaussian = new Gaussian(1.0, 0.0, 50.0);
    uniform = new Uniform(0.0, 1.0);
    current_xi = initial_xi;
    nParams = initial_xi.size(); 
}

Metropolis::~Metropolis()
{

}

void Metropolis::step()
{

    vector<double> dx, temp_xi;
    double ratio;
    for (int i = 0; i < nParams; ++i) {
        dx.push_back(gaussian->drawValue(0.0));
        temp_xi.push_back(current_xi[i] + dx[i]);
    }

    //cout << "p(new) = " << targetPdf->evaluatePdfLog(temp_xi)<<endl;
    //cout << "p(old) = " << targetPdf->evaluatePdfLog(current_xi)<<endl;
    ratio = exp(targetPdf->evaluatePdfLog(temp_xi) - targetPdf->evaluatePdfLog(current_xi));
       //cout << ratio << endl; 
    if (ratio >= uniform->drawValue(0.0))
        current_xi = temp_xi;
}

vector<double> Metropolis::getCurrentXi()
{
    return current_xi;
}
