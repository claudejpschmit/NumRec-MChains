#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Metropolis {
public:
    Metropolis(vector<double> xi_initial);
    ~Metropolis();

    vector<double> step(int nsteps);
private:
    vector<double> target_p();
    vector<double> trial_distr_q(double sigma);
    vector<double> xi_values;
};
