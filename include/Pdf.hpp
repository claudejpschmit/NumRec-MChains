#pragma once

#include <iostream>

class Pdf {
public:
    virtual ~Pdf(){}
    virtual double drawValue(double noise);
    virtual double evaluatePdf(double x);
};

class Gaussian : public Pdf {

public:
    Gaussian(double sigma, double mu, double x_range);
    double drawValue(double noise);
    double evaluatePdf(double x);

private:
    double x_range;
    double sigma, mu;
    double max_random;

};

class Uniform : public Pdf {

public:
    Uniform(double x_min, double x_max);
    double drawValue(double noise);
    double evaluatePdf(double x);

private:
    double x_min, x_max;
};

