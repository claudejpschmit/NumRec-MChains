#pragma once

#include "Pdf.hpp"
#include <iostream>
#include <vector>


using namespace std;

class Metropolis {
public:
    Metropolis(vector<double> initial_xi, Pdf *targetPdf);
    ~Metropolis();

    void step();
    vector<double> getCurrentXi();

private:
    vector<double> current_xi;
    int nParams;
    Pdf *targetPdf;
    Gaussian *gaussian;
    Uniform *uniform;
   
};
