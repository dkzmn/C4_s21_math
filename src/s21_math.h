#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <float.h>
#include <stdio.h>
#include <unistd.h>

#define S21_PI 3.141592653589793238462643383279502884197169399375105820974944592
#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0
#define EPSILON 1e-100
#define NCOUNT 10000

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

long double s21_pow_int(double base, int exp);

#endif  // SRC_S21_MATH_H_
