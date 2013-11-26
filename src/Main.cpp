#include "Pdf.hpp"
#include "Metropolis.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
    ////////////////////////////////
    //  TEST
    ////////////////////////////////

    //cout << target.evaluatePdf(initialParams) << endl;




    /////////////////////////////////
    

    
    //metro.step();
    ofstream params("params.txt");
    for (int i = 0; i < 50; ++i) {
        
        metro.step();
        vector<double> current = metro.getCurrentXi();
        cout << i << " " <<  current[0] << " " << current[1] << endl;        
        params << i << " " <<  current[0] << " " << current[1] << endl;        
    }
    params.close();
    return 0;
}
