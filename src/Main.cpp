#include "test.hpp"

using namespace std;
#include <iostream>
#include <fstream>
#include <string>

#include <cmath>
//#include "TRoot.h"
//#include <TCanvas.h>
//#include <TGraph.h>
//#include <TFrame.h>
//#include <TAxis.h>
//#include <TEllipse.h>
//#include <TPaveLabel.h>
//#include <TH1F.h>
//#include <RooEllipse.h>

#include <vector>
#include <stdlib.h>
#include <sstream>
#include <iomanip>

#include <fftw3.h>


typedef unsigned int uint ;
#define round(x) ((x)>=0?(double)((x)+0.5):(double)((x)-0.5))

#define INPUTFORM (1.0 + cos((period/N)*ii)  + cos((3*period/N)*ii)  )
//#define INPUTFORM (1.0 + cos((period/N)*ii)   )




//===================================================================
int main( ) {

		
		int N=100 ;
		fftw_complex *in, *out;
		fftw_plan p;

		double twopi = 2.0*3.14159265 ;
		double period = twopi;
	// this was: double period = twopi * 4.0;
	    //....	

	// open a stream and output file

	filebuf txtIn;
	txtIn.open ("fftinput.txt",ios::out);
	ostream ins(&txtIn);
	ins << fixed ;
	ins << setprecision(1) ;
	
	
	filebuf txtOut;
	txtOut.open ("fftresults.txt",ios::out);
	ostream os(&txtOut);
	os << fixed ;
	os << setprecision(1) ;
	
	
	
		in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
		out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
		p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
		
		for(int ii=0; ii < N ; ++ii) { 
			in[ii][0]=1000*INPUTFORM ; 
			in[ii][1]=0.;
			ins << ii+1 << " "  << in[ii][0]/1000. << endl ;
		}
		//...
		
		fftw_execute(p); /* repeat as needed */
		
		//...
		cout << " Results of fftw run " << endl ;
		for(int ii=0; ii < N ; ++ii) { 
			cout << fixed ;
			cout << setprecision(1) ;
			cout << out[ii][0]/1000.   <<  "   "  << out[ii][1]/1000.  << endl ;
			os << ii+1 << " "  << out[ii][0]/1000. << endl ;
		}
		
		fftw_destroy_plan(p);
		fftw_free(in); fftw_free(out);
		
	
	
	// close the output
	txtIn.close();
	txtOut.close();
	

}
