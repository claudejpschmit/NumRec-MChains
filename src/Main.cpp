#include "test.hpp"
#include "Metropolis.hpp"


using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main( ) {

    vector<double> xi_initial;

    for (int i = 0; i < 10 ; ++i)
        xi_initial.push_back(1);

    Metropolis metro(xi_initial);



    return 0;
		
		
}
