#pragma once

#include "Pdf.hpp"
#include "Posterior.hpp"
#include <iostream>
#include <vector>


using namespace std;

class Metropolis {
public:
    Metropolis(vector<double> initial_xi, Posterior *targetPdf);
    ~Metropolis();

    void step();
    vector<double> getCurrentXi();

private:
    vector<double> current_xi;
    int nParams;
    Posterior *targetPdf;
    Gaussian *gaussian;
    Uniform *uniform;
   
};
