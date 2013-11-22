#include "Metropolis.hpp"
#include <cmath>

Metropolis::Metropolis(vector<double> initial_xi, Pdf *targetPdf)
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
        dx[i] = gaussian->drawValue(0.0);
        temp_xi[i] = current_xi[i] + dx[i];
        ratio = targetPdf->evaluatePdf(temp_xi[i]) / 
                        targetPdf->evaluatePdf(current_xi[i]);
        
        if (ratio >= uniform->drawValue(0.0))
            current_xi[i] = temp_xi[i];
    }
}

vector<double> Metropolis::getCurrentXi()
{
    return current_xi;
}
