#include "Pdf.hpp"
#include "Metropolis.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define NITERATIONS 10000
#define BURNIN 100

using namespace std;

int main( ) {

    //test pdfs
    Gaussian gauss(1.0, 0.0, 50);
    Uniform unif(0.0, 1.0);

    ofstream gaussianDistr("Gaussian.txt");
    ofstream unifDistr("Uniform.txt");
    for (int i = 0; i < 5000; ++i)
    {
        gaussianDistr << gauss.drawValue(0.0) << endl;
        unifDistr << unif.drawValue(0.0) << endl;
    }
    gaussianDistr.close();
    unifDistr.close();
    //they work
    ifstream data("data.txt");
    Posterior target(&data, 1.0);
    data.close();

    vector<double> initialParams {1.2,11.1}; 
    Metropolis metro(initialParams, &target);

    vector<vector<double>> parameterList;
    ofstream params("params.txt");
    for (int i = 0; i < NITERATIONS; ++i) {
        
        metro.step();
        parameterList.push_back(metro.getCurrentXi());
        params << i << " " <<  parameterList[i][0] << " " << parameterList[i][1] << endl;        
    }
    params.close();

    double a_average = 0;
    double b_average = 0;

    for (int i = BURNIN; i < NITERATIONS; ++i) {
        a_average += parameterList[i][0];
        b_average += parameterList[i][1];
    }
    a_average = a_average / (double)(NITERATIONS - BURNIN);
    b_average = b_average / (double)(NITERATIONS - BURNIN);
    cout << "average a = " << a_average << endl;
    cout << "average b = " << b_average << endl;

    return 0;
}
