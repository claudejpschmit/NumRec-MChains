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

    return 0;
}
