#ifndef HEADER_H_
#define HEADER_H_

double I1(double x);
double I2(double x);
double I3(double x);
double I4(double x);
double I5(double x);
double Trapez(double l, double r, int n, double (*fun)(double));
double Dreptunghi(double l, double r, int n, double (*fun)(double));
double Simpson(double l, double r, int n, double (*fun)(double));

#endif
