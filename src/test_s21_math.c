#include <check.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_math.h"

#define BUFF_SIZE 30
#define SPRINTF_SPEC "%.16Le"
#define SPRINTF_SPEC_FLOAT "%Lf"
#define TEST_EPS 1e-12

START_TEST(s21_abs_test_1) {
  int x = 0;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(s21_abs_test_2) {
  int x = -123;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(s21_abs_test_3) {
  int x = 123;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(s21_abs_test_4) {
  int x = INT_MAX;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(s21_abs_test_5) {
  int x = INT_MIN;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(s21_fabs_test_1) {
  long double x = 0;
  ck_assert_ldouble_eq(s21_fabs(x), fabsl(x));
}

START_TEST(s21_fabs_test_2) {
  long double x = 0.00000000000000000000000000000000000000000000000000000000001;
  ck_assert_ldouble_eq(s21_fabs(x), fabsl(x));
}

START_TEST(s21_fabs_test_3) {
  long double x = -0.0000000000000000000000000000000000000000000000000000000001;
  ck_assert_ldouble_eq(s21_fabs(x), fabsl(x));
}

START_TEST(s21_fabs_test_4) {
  long double x = 999999999999999999999999999999.999999999999999999999999999999;
  ck_assert_ldouble_eq(s21_fabs(x), fabsl(x));
}

START_TEST(s21_fabs_test_5) {
  long double x = -999999999999999999999999999999.99999999999999999999999999999;
  ck_assert_ldouble_eq(s21_fabs(x), fabsl(x));
}

START_TEST(s21_ceil_test_1) {
  long double x = 0;
  ck_assert_ldouble_eq(s21_ceil(x), ceill(x));
}
END_TEST

START_TEST(s21_ceil_test_2) {
  long double x = 1.123456789;
  ck_assert_ldouble_eq(s21_ceil(x), ceill(x));
}
END_TEST

START_TEST(s21_ceil_test_3) {
  long double x = -1.123456789;
  ck_assert_ldouble_eq(s21_ceil(x), ceill(x));
}
END_TEST

START_TEST(s21_ceil_test_4) {
  long double x = 0.00000000000000000000000000000000000000000000000000000000001;
  ck_assert_ldouble_eq(s21_ceil(x), ceill(x));
}
END_TEST

START_TEST(s21_ceil_test_5) {
  long double x = -0.0000000000000000000000000000000000000000000000000000000001;
  ck_assert_ldouble_eq(s21_ceil(x), ceill(x));
}
END_TEST

START_TEST(s21_ceil_test_6) {
  long double x = 999999999.999999999;
  ck_assert_ldouble_eq(s21_ceil(x), ceill(x));
}
END_TEST

START_TEST(s21_ceil_test_7) {
  long double x = -999999999.999999999;
  ck_assert_ldouble_eq(s21_ceil(x), ceill(x));
}
END_TEST

START_TEST(s21_ceil_test_8) {
  long double x = 999.17654321;
  ck_assert_ldouble_eq(s21_ceil(x), ceill(x));
}
END_TEST

START_TEST(s21_ceil_test_9) {
  long double x = -999.17654321;
  ck_assert_ldouble_eq(s21_ceil(x), ceill(x));
}
END_TEST

START_TEST(s21_ceil_test_10) {
  long double x = S21_INF;
  ck_assert_ldouble_eq(s21_ceil(x), ceill(x));
}
END_TEST

START_TEST(s21_ceil_test_11) {
  long double x = -S21_INF;
  ck_assert_ldouble_eq(s21_ceil(x), ceill(x));
}
END_TEST

START_TEST(s21_ceil_test_12) {
  long double x = S21_NAN;
  ck_assert_ldouble_nan(s21_ceil(x));
  ck_assert_ldouble_nan(ceill(x));
}
END_TEST

START_TEST(s21_ceil_test_13) {
  double x = DBL_MAX;
  ck_assert_ldouble_eq(s21_ceil(x), ceill(x));
}
END_TEST

START_TEST(s21_ceil_test_14) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq(s21_ceil(x), ceill(x));
}
END_TEST

START_TEST(s21_floor_test_1) {
  long double x = 0;
  ck_assert_ldouble_eq(s21_floor(x), floorl(x));
}
END_TEST

START_TEST(s21_floor_test_2) {
  long double x = 1.123456789;
  ck_assert_ldouble_eq(s21_floor(x), floorl(x));
}
END_TEST

START_TEST(s21_floor_test_3) {
  long double x = -1.123456789;
  ck_assert_ldouble_eq(s21_floor(x), floorl(x));
}
END_TEST

START_TEST(s21_floor_test_4) {
  long double x = 0.00000000000000000000000000000000000000000000000000000000001;
  ck_assert_ldouble_eq(s21_floor(x), floorl(x));
}
END_TEST

START_TEST(s21_floor_test_5) {
  long double x = -0.0000000000000000000000000000000000000000000000000000000001;
  ck_assert_ldouble_eq(s21_floor(x), floorl(x));
}
END_TEST

START_TEST(s21_floor_test_6) {
  long double x = 999999999.999999999;
  ck_assert_ldouble_eq(s21_floor(x), floorl(x));
}
END_TEST

START_TEST(s21_floor_test_7) {
  long double x = -999999999.999999999;
  ck_assert_ldouble_eq(s21_floor(x), floorl(x));
}
END_TEST

START_TEST(s21_floor_test_8) {
  long double x = 999.17654321;
  ck_assert_ldouble_eq(s21_floor(x), floorl(x));
}
END_TEST

START_TEST(s21_floor_test_9) {
  long double x = -999.17654321;
  ck_assert_ldouble_eq(s21_floor(x), floorl(x));
}
END_TEST

START_TEST(s21_floor_test_10) {
  long double x = S21_INF;
  ck_assert_ldouble_eq(s21_floor(x), floorl(x));
}
END_TEST

START_TEST(s21_floor_test_11) {
  long double x = -S21_INF;
  ck_assert_ldouble_eq(s21_floor(x), floorl(x));
}
END_TEST

START_TEST(s21_floor_test_12) {
  long double x = S21_NAN;
  ck_assert_ldouble_nan(s21_floor(x));
  ck_assert_ldouble_nan(floorl(x));
}
END_TEST

START_TEST(s21_floor_test_13) {
  double x = DBL_MAX;
  ck_assert_ldouble_eq(s21_floor(x), floorl(x));
}
END_TEST

START_TEST(s21_floor_test_14) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq(s21_floor(x), floorl(x));
}
END_TEST

START_TEST(s21_pow_int_test_1) {
  long double x = 0, y = 0;
  ck_assert_ldouble_eq(s21_pow_int(x, y), powl(x, y));
}
END_TEST

START_TEST(s21_pow_int_test_2) {
  long double x = 12, y = 0;
  ck_assert_ldouble_eq(s21_pow_int(x, y), powl(x, y));
}
END_TEST

START_TEST(s21_pow_int_test_3) {
  long double x = 0, y = 12;
  ck_assert_ldouble_eq(s21_pow_int(x, y), powl(x, y));
}
END_TEST

START_TEST(s21_pow_int_test_4) {
  long double x = -55, y = 3;
  ck_assert_ldouble_eq(s21_pow_int(x, y), powl(x, y));
}
END_TEST

START_TEST(s21_pow_int_test_5) {
  long double x = 55, y = -5;
  char str_x[BUFF_SIZE], str_y[BUFF_SIZE];
  sprintf(str_x, SPRINTF_SPEC, s21_pow_int(x, y));
  sprintf(str_y, SPRINTF_SPEC, powl(x, y));
  ck_assert_pstr_eq(str_x, str_y);
}
END_TEST

START_TEST(s21_pow_int_test_6) {
  long double x = -123, y = -2;
  char str_x[BUFF_SIZE], str_y[BUFF_SIZE];
  sprintf(str_x, SPRINTF_SPEC, s21_pow_int(x, y));
  sprintf(str_y, SPRINTF_SPEC, powl(x, y));
  ck_assert_pstr_eq(str_x, str_y);
}
END_TEST

START_TEST(s21_pow_int_test_7) {
  long double x = 555, y = -55;
  char str_x[BUFF_SIZE], str_y[BUFF_SIZE];
  sprintf(str_x, SPRINTF_SPEC, s21_pow_int(x, y));
  sprintf(str_y, SPRINTF_SPEC, powl(x, y));
  ck_assert_pstr_eq(str_x, str_y);
}
END_TEST

START_TEST(s21_pow_int_test_8) {
  long double x = 555, y = 55;
  char str_x[BUFF_SIZE], str_y[BUFF_SIZE];
  sprintf(str_x, SPRINTF_SPEC, s21_pow_int(x, y));
  sprintf(str_y, SPRINTF_SPEC, powl(x, y));
  ck_assert_pstr_eq(str_x, str_y);
}
END_TEST

START_TEST(s21_exp_test_1) {
  long double x = 0, res_s21, res_orig, floatpart1, floatpart2, intpart;
  char str_s21[BUFF_SIZE], str_orig[BUFF_SIZE];
  char str_s21_float[BUFF_SIZE], str_orig_float[BUFF_SIZE];
  res_s21 = s21_exp(x);
  res_orig = expl(x);
  floatpart1 = modfl(res_s21, &intpart);
  floatpart2 = modfl(res_orig, &intpart);
  sprintf(str_s21, SPRINTF_SPEC, res_s21);
  sprintf(str_orig, SPRINTF_SPEC, res_orig);
  sprintf(str_s21_float, SPRINTF_SPEC_FLOAT, floatpart1);
  sprintf(str_orig_float, SPRINTF_SPEC_FLOAT, floatpart2);
  ck_assert_pstr_eq(str_s21, str_orig);
  ck_assert_pstr_eq(str_s21_float, str_orig_float);
}
END_TEST

START_TEST(s21_exp_test_2) {
  long double x = 1, res_s21, res_orig, floatpart1, floatpart2, intpart;
  char str_s21[BUFF_SIZE], str_orig[BUFF_SIZE];
  char str_s21_float[BUFF_SIZE], str_orig_float[BUFF_SIZE];
  res_s21 = s21_exp(x);
  res_orig = expl(x);
  floatpart1 = modfl(res_s21, &intpart);
  floatpart2 = modfl(res_orig, &intpart);
  sprintf(str_s21, SPRINTF_SPEC, res_s21);
  sprintf(str_orig, SPRINTF_SPEC, res_orig);
  sprintf(str_s21_float, SPRINTF_SPEC_FLOAT, floatpart1);
  sprintf(str_orig_float, SPRINTF_SPEC_FLOAT, floatpart2);
  ck_assert_pstr_eq(str_s21, str_orig);
  ck_assert_pstr_eq(str_s21_float, str_orig_float);
}
END_TEST

START_TEST(s21_exp_test_3) {
  long double x = -1, res_s21, res_orig, floatpart1, floatpart2, intpart;
  char str_s21[BUFF_SIZE], str_orig[BUFF_SIZE];
  char str_s21_float[BUFF_SIZE], str_orig_float[BUFF_SIZE];
  res_s21 = s21_exp(x);
  res_orig = expl(x);
  floatpart1 = modfl(res_s21, &intpart);
  floatpart2 = modfl(res_orig, &intpart);
  sprintf(str_s21, SPRINTF_SPEC, res_s21);
  sprintf(str_orig, SPRINTF_SPEC, res_orig);
  sprintf(str_s21_float, SPRINTF_SPEC_FLOAT, floatpart1);
  sprintf(str_orig_float, SPRINTF_SPEC_FLOAT, floatpart2);
  ck_assert_pstr_eq(str_s21, str_orig);
  ck_assert_pstr_eq(str_s21_float, str_orig_float);
}
END_TEST

START_TEST(s21_exp_test_4) {
  long double x = 0.000001, res_s21, res_orig, floatpart1, floatpart2, intpart;
  char str_s21[BUFF_SIZE], str_orig[BUFF_SIZE];
  char str_s21_float[BUFF_SIZE], str_orig_float[BUFF_SIZE];
  res_s21 = s21_exp(x);
  res_orig = expl(x);
  floatpart1 = modfl(res_s21, &intpart);
  floatpart2 = modfl(res_orig, &intpart);
  sprintf(str_s21, SPRINTF_SPEC, res_s21);
  sprintf(str_orig, SPRINTF_SPEC, res_orig);
  sprintf(str_s21_float, SPRINTF_SPEC_FLOAT, floatpart1);
  sprintf(str_orig_float, SPRINTF_SPEC_FLOAT, floatpart2);
  ck_assert_pstr_eq(str_s21, str_orig);
  ck_assert_pstr_eq(str_s21_float, str_orig_float);
}
END_TEST

START_TEST(s21_exp_test_5) {
  long double x = -0.000001, res_s21, res_orig, floatpart1, floatpart2, intpart;
  char str_s21[BUFF_SIZE], str_orig[BUFF_SIZE];
  char str_s21_float[BUFF_SIZE], str_orig_float[BUFF_SIZE];
  res_s21 = s21_exp(x);
  res_orig = expl(x);
  floatpart1 = modfl(res_s21, &intpart);
  floatpart2 = modfl(res_orig, &intpart);
  sprintf(str_s21, SPRINTF_SPEC, res_s21);
  sprintf(str_orig, SPRINTF_SPEC, res_orig);
  sprintf(str_s21_float, SPRINTF_SPEC_FLOAT, floatpart1);
  sprintf(str_orig_float, SPRINTF_SPEC_FLOAT, floatpart2);
  ck_assert_pstr_eq(str_s21, str_orig);
  ck_assert_pstr_eq(str_s21_float, str_orig_float);
}
END_TEST

START_TEST(s21_exp_test_6) {
  long double x = 98.765432, res_s21, res_orig, floatpart1, floatpart2, intpart;
  char str_s21[BUFF_SIZE], str_orig[BUFF_SIZE];
  char str_s21_float[BUFF_SIZE], str_orig_float[BUFF_SIZE];
  res_s21 = s21_exp(x);
  res_orig = expl(x);
  floatpart1 = modfl(res_s21, &intpart);
  floatpart2 = modfl(res_orig, &intpart);
  sprintf(str_s21, SPRINTF_SPEC, res_s21);
  sprintf(str_orig, SPRINTF_SPEC, res_orig);
  sprintf(str_s21_float, SPRINTF_SPEC_FLOAT, floatpart1);
  sprintf(str_orig_float, SPRINTF_SPEC_FLOAT, floatpart2);
  ck_assert_pstr_eq(str_s21, str_orig);
  ck_assert_pstr_eq(str_s21_float, str_orig_float);
}
END_TEST

START_TEST(s21_exp_test_7) {
  long double x = 0.1234567, res_s21, res_orig, floatpart1, floatpart2, intpart;
  char str_s21[BUFF_SIZE], str_orig[BUFF_SIZE];
  char str_s21_float[BUFF_SIZE], str_orig_float[BUFF_SIZE];
  res_s21 = s21_exp(x);
  res_orig = expl(x);
  floatpart1 = modfl(res_s21, &intpart);
  floatpart2 = modfl(res_orig, &intpart);
  sprintf(str_s21, SPRINTF_SPEC, res_s21);
  sprintf(str_orig, SPRINTF_SPEC, res_orig);
  sprintf(str_s21_float, SPRINTF_SPEC_FLOAT, floatpart1);
  sprintf(str_orig_float, SPRINTF_SPEC_FLOAT, floatpart2);
  ck_assert_pstr_eq(str_s21, str_orig);
  ck_assert_pstr_eq(str_s21_float, str_orig_float);
}
END_TEST

START_TEST(s21_exp_test_8) {
  long double x = 11355, res_s21 = 0, res_orig, floatpart1, floatpart2, intpart;
  char str_s21[BUFF_SIZE], str_orig[BUFF_SIZE];
  char str_s21_float[BUFF_SIZE], str_orig_float[BUFF_SIZE];
  res_s21 = s21_exp(x);
  res_orig = expl(x);
  floatpart1 = modfl(res_s21, &intpart);
  floatpart2 = modfl(res_orig, &intpart);
  sprintf(str_s21, SPRINTF_SPEC, res_s21);
  sprintf(str_orig, SPRINTF_SPEC, res_orig);
  sprintf(str_s21_float, SPRINTF_SPEC_FLOAT, floatpart1);
  sprintf(str_orig_float, SPRINTF_SPEC_FLOAT, floatpart2);
  ck_assert_pstr_eq(str_s21, str_orig);
  ck_assert_pstr_eq(str_s21_float, str_orig_float);
}
END_TEST

START_TEST(s21_exp_test_9) {
  long double x = -10000, res_s21, res_orig, floatpart1, floatpart2, intpart;
  char str_s21[BUFF_SIZE], str_orig[BUFF_SIZE];
  char str_s21_float[BUFF_SIZE], str_orig_float[BUFF_SIZE];
  res_s21 = s21_exp(x);
  res_orig = expl(x);
  floatpart1 = modfl(res_s21, &intpart);
  floatpart2 = modfl(res_orig, &intpart);
  sprintf(str_s21, SPRINTF_SPEC, res_s21);
  sprintf(str_orig, SPRINTF_SPEC, res_orig);
  sprintf(str_s21_float, SPRINTF_SPEC_FLOAT, floatpart1);
  sprintf(str_orig_float, SPRINTF_SPEC_FLOAT, floatpart2);
  ck_assert_pstr_eq(str_s21, str_orig);
  ck_assert_pstr_eq(str_s21_float, str_orig_float);
}
END_TEST

START_TEST(s21_exp_test_10) {
  long double x = S21_NAN, res_s21, res_orig;
  res_s21 = s21_exp(x);
  res_orig = expl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_exp_test_11) {
  long double x = S21_INF, res_s21, res_orig;
  res_s21 = s21_exp(x);
  res_orig = expl(x);
  ck_assert_ldouble_infinite(res_s21);
  ck_assert_ldouble_infinite(res_orig);
}
END_TEST

START_TEST(s21_exp_test_12) {
  long double x = 20000, res_s21, res_orig;
  res_s21 = s21_exp(x);
  res_orig = expl(x);
  ck_assert_ldouble_infinite(res_s21);
  ck_assert_ldouble_infinite(res_orig);
}
END_TEST

START_TEST(s21_exp_test_13) {
  long double x = -20000, res_s21, res_orig;
  res_s21 = s21_exp(x);
  res_orig = expl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_sin_test_1) {
  long double x = 0, res_s21, res_orig;
  res_s21 = s21_sin(x);
  res_orig = sinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_sin_test_2) {
  long double x = 1, res_s21, res_orig;
  res_s21 = s21_sin(x);
  res_orig = sinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_sin_test_3) {
  long double x = -1, res_s21, res_orig;
  res_s21 = s21_sin(x);
  res_orig = sinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_sin_test_4) {
  long double x = 10, res_s21, res_orig;
  res_s21 = s21_sin(x);
  res_orig = sinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_sin_test_5) {
  long double x = -10, res_s21, res_orig;
  res_s21 = s21_sin(x);
  res_orig = sinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_sin_test_6) {
  long double x = 100, res_s21, res_orig;
  res_s21 = s21_sin(x);
  res_orig = sinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_sin_test_7) {
  long double x = -100, res_s21, res_orig;
  res_s21 = s21_sin(x);
  res_orig = sinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_sin_test_8) {
  long double x = S21_PI / 2, res_s21, res_orig;
  res_s21 = s21_sin(x);
  res_orig = sinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_sin_test_9) {
  long double x = -S21_PI / 2, res_s21, res_orig;
  res_s21 = s21_sin(x);
  res_orig = sinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_sin_test_10) {
  long double x = S21_NAN, res_s21, res_orig;
  res_s21 = s21_sin(x);
  res_orig = sinl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_sin_test_11) {
  long double x = S21_INF, res_s21, res_orig;
  res_s21 = s21_sin(x);
  res_orig = sinl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_sin_test_12) {
  long double x = -S21_INF, res_s21, res_orig;
  res_s21 = s21_sin(x);
  res_orig = sinl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_sin_test_13) {
  long double x = 5.123456789123, res_s21, res_orig;
  res_s21 = s21_sin(x);
  res_orig = sinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_cos_test_1) {
  long double x = 0, res_s21, res_orig;
  res_s21 = s21_cos(x);
  res_orig = cosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_cos_test_2) {
  long double x = 1, res_s21, res_orig;
  res_s21 = s21_cos(x);
  res_orig = cosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_cos_test_3) {
  long double x = -1, res_s21, res_orig;
  res_s21 = s21_cos(x);
  res_orig = cosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_cos_test_4) {
  long double x = 10, res_s21, res_orig;
  res_s21 = s21_cos(x);
  res_orig = cosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_cos_test_5) {
  long double x = -10, res_s21, res_orig;
  res_s21 = s21_cos(x);
  res_orig = cosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_cos_test_6) {
  long double x = 100, res_s21, res_orig;
  res_s21 = s21_cos(x);
  res_orig = cosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_cos_test_7) {
  long double x = -100, res_s21, res_orig;
  res_s21 = s21_cos(x);
  res_orig = cosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_cos_test_8) {
  long double x = S21_PI, res_s21, res_orig;
  res_s21 = s21_cos(x);
  res_orig = cosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_cos_test_9) {
  long double x = -S21_PI, res_s21, res_orig;
  res_s21 = s21_cos(x);
  res_orig = cosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_cos_test_10) {
  long double x = S21_NAN, res_s21, res_orig;
  res_s21 = s21_cos(x);
  res_orig = cosl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_cos_test_11) {
  long double x = S21_INF, res_s21, res_orig;
  res_s21 = s21_cos(x);
  res_orig = cosl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_cos_test_12) {
  long double x = -S21_INF, res_s21, res_orig;
  res_s21 = s21_cos(x);
  res_orig = cosl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_tan_test_1) {
  long double x = 0, res_s21, res_orig;
  res_s21 = s21_tan(x);
  res_orig = tanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_tan_test_2) {
  long double x = 1, res_s21, res_orig;
  res_s21 = s21_tan(x);
  res_orig = tanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_tan_test_3) {
  long double x = -1, res_s21, res_orig;
  res_s21 = s21_tan(x);
  res_orig = tanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_tan_test_4) {
  long double x = 10, res_s21, res_orig;
  res_s21 = s21_tan(x);
  res_orig = tanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_tan_test_5) {
  long double x = -10, res_s21, res_orig;
  res_s21 = s21_tan(x);
  res_orig = tanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_tan_test_6) {
  long double x = 100, res_s21, res_orig;
  res_s21 = s21_tan(x);
  res_orig = tanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_tan_test_7) {
  long double x = -100, res_s21, res_orig;
  res_s21 = s21_tan(x);
  res_orig = tanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_tan_test_8) {
  long double x = S21_PI, res_s21, res_orig;
  res_s21 = s21_tan(x);
  res_orig = tanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_tan_test_9) {
  long double x = -S21_PI, res_s21, res_orig;
  res_s21 = s21_tan(x);
  res_orig = tanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_tan_test_10) {
  long double x = S21_PI / 2 - 0.001, res_s21, res_orig;
  res_s21 = s21_tan(x);
  res_orig = tanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_tan_test_11) {
  long double x = -S21_PI / 2 + 0.001, res_s21, res_orig;
  res_s21 = s21_tan(x);
  res_orig = tanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_tan_test_12) {
  long double x = S21_NAN, res_s21, res_orig;
  res_s21 = s21_tan(x);
  res_orig = tanl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_tan_test_13) {
  long double x = S21_INF, res_s21, res_orig;
  res_s21 = s21_tan(x);
  res_orig = tanl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_tan_test_14) {
  long double x = -S21_INF, res_s21, res_orig;
  res_s21 = s21_tan(x);
  res_orig = tanl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_log_test_1) {
  long double x = 1, res_s21, res_orig;
  res_s21 = s21_log(x);
  res_orig = logl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_log_test_2) {
  long double x = 0, res_s21, res_orig;
  res_s21 = s21_log(x);
  res_orig = logl(x);
  ck_assert_ldouble_infinite(res_s21);
  ck_assert_ldouble_infinite(res_orig);
}
END_TEST

START_TEST(s21_log_test_3) {
  long double x = -1, res_s21, res_orig;
  res_s21 = s21_log(x);
  res_orig = logl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_log_test_4) {
  long double x = 0.01, res_s21, res_orig;
  res_s21 = s21_log(x);
  res_orig = logl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_log_test_5) {
  long double x = 1.1, res_s21, res_orig;
  res_s21 = s21_log(x);
  res_orig = logl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_log_test_6) {
  long double x = 9.87654321, res_s21, res_orig;
  res_s21 = s21_log(x);
  res_orig = logl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_log_test_7) {
  long double x = 9999.9999, res_s21, res_orig;
  res_s21 = s21_log(x);
  res_orig = logl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_log_test_8) {
  long double x = S21_INF, res_s21, res_orig;
  res_s21 = s21_log(x);
  res_orig = logl(x);
  ck_assert_ldouble_infinite(res_s21);
  ck_assert_ldouble_infinite(res_orig);
}
END_TEST

START_TEST(s21_log_test_9) {
  long double x = S21_NAN, res_s21, res_orig;
  res_s21 = s21_log(x);
  res_orig = logl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_log_test_10) {
  long double x = 11.2233, res_s21, res_orig;
  res_s21 = s21_log(x);
  res_orig = logl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_sqrt_test_1) {
  long double x = 1, res_s21, res_orig;
  res_s21 = s21_sqrt(x);
  res_orig = sqrtl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_sqrt_test_2) {
  long double x = 0, res_s21, res_orig;
  res_s21 = s21_sqrt(x);
  res_orig = sqrtl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_sqrt_test_3) {
  long double x = -1, res_s21, res_orig;
  res_s21 = s21_sqrt(x);
  res_orig = sqrtl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_sqrt_test_4) {
  long double x = 0.01, res_s21, res_orig;
  res_s21 = s21_sqrt(x);
  res_orig = sqrtl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_sqrt_test_5) {
  long double x = 1.1, res_s21, res_orig;
  res_s21 = s21_sqrt(x);
  res_orig = sqrtl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_sqrt_test_6) {
  long double x = 9.87654321, res_s21, res_orig;
  res_s21 = s21_sqrt(x);
  res_orig = sqrtl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_sqrt_test_7) {
  long double x = 1000000, res_s21, res_orig;
  res_s21 = s21_sqrt(x);
  res_orig = sqrtl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_sqrt_test_8) {
  long double x = S21_INF, res_s21, res_orig;
  res_s21 = s21_sqrt(x);
  res_orig = sqrtl(x);
  ck_assert_ldouble_infinite(res_s21);
  ck_assert_ldouble_infinite(res_orig);
}
END_TEST

START_TEST(s21_sqrt_test_9) {
  long double x = S21_NAN, res_s21, res_orig;
  res_s21 = s21_sqrt(x);
  res_orig = sqrtl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_asin_test_1) {
  long double x = 0, res_s21, res_orig;
  res_s21 = s21_asin(x);
  res_orig = asinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_asin_test_2) {
  long double x = 0.99999999, res_s21, res_orig;
  res_s21 = s21_asin(x);
  res_orig = asinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_asin_test_3) {
  long double x = -0.99999999, res_s21, res_orig;
  res_s21 = s21_asin(x);
  res_orig = asinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_asin_test_4) {
  long double x = 1, res_s21, res_orig;
  res_s21 = s21_asin(x);
  res_orig = asinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_asin_test_5) {
  long double x = -1, res_s21, res_orig;
  res_s21 = s21_asin(x);
  res_orig = asinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_asin_test_6) {
  long double x = 0.5, res_s21, res_orig;
  res_s21 = s21_asin(x);
  res_orig = asinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_asin_test_7) {
  long double x = -0.5, res_s21, res_orig;
  res_s21 = s21_asin(x);
  res_orig = asinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_asin_test_8) {
  long double x = 0.00000000001, res_s21, res_orig;
  res_s21 = s21_asin(x);
  res_orig = asinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_asin_test_9) {
  long double x = -0.00000000001, res_s21, res_orig;
  res_s21 = s21_asin(x);
  res_orig = asinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_asin_test_10) {
  long double x = 0.666666666666666666666666666666666, res_s21, res_orig;
  res_s21 = s21_asin(x);
  res_orig = asinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_asin_test_11) {
  long double x = -0.666666666666666666666666666666666, res_s21, res_orig;
  res_s21 = s21_asin(x);
  res_orig = asinl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_asin_test_12) {
  long double x = S21_NAN, res_s21, res_orig;
  res_s21 = s21_asin(x);
  res_orig = asinl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_asin_test_13) {
  long double x = S21_INF, res_s21, res_orig;
  res_s21 = s21_asin(x);
  res_orig = asinl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_asin_test_14) {
  long double x = 1.1, res_s21, res_orig;
  res_s21 = s21_asin(x);
  res_orig = asinl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_asin_test_15) {
  long double x = -1.1, res_s21, res_orig;
  res_s21 = s21_asin(x);
  res_orig = asinl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_acos_test_1) {
  long double x = 0, res_s21, res_orig;
  res_s21 = s21_acos(x);
  res_orig = acosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_acos_test_2) {
  long double x = 0.9999, res_s21, res_orig;
  res_s21 = s21_acos(x);
  res_orig = acosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_acos_test_3) {
  long double x = -0.9999, res_s21, res_orig;
  res_s21 = s21_acos(x);
  res_orig = acosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_acos_test_4) {
  long double x = 1, res_s21, res_orig;
  res_s21 = s21_acos(x);
  res_orig = acosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_acos_test_5) {
  long double x = -1, res_s21, res_orig;
  res_s21 = s21_acos(x);
  res_orig = acosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_acos_test_6) {
  long double x = 0.5, res_s21, res_orig;
  res_s21 = s21_acos(x);
  res_orig = acosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_acos_test_7) {
  long double x = -0.5, res_s21, res_orig;
  res_s21 = s21_acos(x);
  res_orig = acosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_acos_test_8) {
  long double x = 0.00000000001, res_s21, res_orig;
  res_s21 = s21_acos(x);
  res_orig = acosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_acos_test_9) {
  long double x = -0.00000000001, res_s21, res_orig;
  res_s21 = s21_acos(x);
  res_orig = acosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_acos_test_10) {
  long double x = 0.666666666666666666666666666666666, res_s21, res_orig;
  res_s21 = s21_acos(x);
  res_orig = acosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_acos_test_11) {
  long double x = -0.666666666666666666666666666666666, res_s21, res_orig;
  res_s21 = s21_acos(x);
  res_orig = acosl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_acos_test_12) {
  long double x = S21_NAN, res_s21, res_orig;
  res_s21 = s21_acos(x);
  res_orig = acosl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_acos_test_13) {
  long double x = S21_INF, res_s21, res_orig;
  res_s21 = s21_acos(x);
  res_orig = acosl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_acos_test_14) {
  long double x = 1.001, res_s21, res_orig;
  res_s21 = s21_acos(x);
  res_orig = acosl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_acos_test_15) {
  long double x = -1.001, res_s21, res_orig;
  res_s21 = s21_acos(x);
  res_orig = acosl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_atan_test_1) {
  long double x = 0, res_s21, res_orig;
  res_s21 = s21_atan(x);
  res_orig = atanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_atan_test_2) {
  long double x = 9.87654321, res_s21, res_orig;
  res_s21 = s21_atan(x);
  res_orig = atanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_atan_test_3) {
  long double x = -9.87654321, res_s21, res_orig;
  res_s21 = s21_atan(x);
  res_orig = atanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_atan_test_4) {
  long double x = 1, res_s21, res_orig;
  res_s21 = s21_atan(x);
  res_orig = atanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_atan_test_5) {
  long double x = -1, res_s21, res_orig;
  res_s21 = s21_atan(x);
  res_orig = atanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_atan_test_6) {
  long double x = 0.5, res_s21, res_orig;
  res_s21 = s21_atan(x);
  res_orig = atanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_atan_test_7) {
  long double x = -0.5, res_s21, res_orig;
  res_s21 = s21_atan(x);
  res_orig = atanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_atan_test_8) {
  long double x = 0.00000000001, res_s21, res_orig;
  res_s21 = s21_atan(x);
  res_orig = atanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_atan_test_9) {
  long double x = -0.00000000001, res_s21, res_orig;
  res_s21 = s21_atan(x);
  res_orig = atanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_atan_test_10) {
  long double x = 0.666666666666666666666666666666666, res_s21, res_orig;
  res_s21 = s21_atan(x);
  res_orig = atanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_atan_test_11) {
  long double x = -0.666666666666666666666666666666666, res_s21, res_orig;
  res_s21 = s21_atan(x);
  res_orig = atanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_atan_test_12) {
  long double x = S21_NAN, res_s21, res_orig;
  res_s21 = s21_atan(x);
  res_orig = atanl(x);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_atan_test_13) {
  long double x = S21_INF, res_s21, res_orig;
  res_s21 = s21_atan(x);
  res_orig = atanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_atan_test_14) {
  long double x = -S21_INF, res_s21, res_orig;
  res_s21 = s21_atan(x);
  res_orig = atanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_atan_test_15) {
  long double x = 101, res_s21, res_orig;
  res_s21 = s21_atan(x);
  res_orig = atanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_atan_test_16) {
  long double x = -101, res_s21, res_orig;
  res_s21 = s21_atan(x);
  res_orig = atanl(x);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_pow_test_1) {
  long double base = 1.1, exp = 2.2, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_pow_test_2) {
  long double base = -1.1, exp = 2.2, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_pow_test_3) {
  long double base = 1.1, exp = -2.2, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_pow_test_4) {
  long double base = 9.87654321, exp = 1.23456789, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_pow_test_5) {
  long double base = 1.23456789, exp = 9.87654321, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_pow_test_6) {
  long double base = 10.23456789, exp = -9.87654321, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_pow_test_7) {
  long double base = 12345, exp = 321, res_s21, res_orig;
  long double floatpart1, floatpart2, intpart;
  char str_s21[BUFF_SIZE], str_orig[BUFF_SIZE];
  char str_s21_float[BUFF_SIZE], str_orig_float[BUFF_SIZE];
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  floatpart1 = modfl(res_s21, &intpart);
  floatpart2 = modfl(res_orig, &intpart);
  sprintf(str_s21, SPRINTF_SPEC, res_s21);
  sprintf(str_orig, SPRINTF_SPEC, res_orig);
  sprintf(str_s21_float, SPRINTF_SPEC_FLOAT, floatpart1);
  sprintf(str_orig_float, SPRINTF_SPEC_FLOAT, floatpart2);
  ck_assert_pstr_eq(str_s21, str_orig);
  ck_assert_pstr_eq(str_s21_float, str_orig_float);
}
END_TEST

START_TEST(s21_pow_test_8) {
  long double base = 123.456, exp = -6.54321, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_pow_test_9) {
  long double base = S21_NAN, exp = -6.54321, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_pow_test_10) {
  long double base = 6.54321, exp = S21_NAN, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_pow_test_11) {
  long double base = 6.54321, exp = S21_INF, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_infinite(res_s21);
  ck_assert_ldouble_infinite(res_orig);
}
END_TEST

START_TEST(s21_pow_test_12) {
  long double base = S21_INF, exp = 6.54321, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_infinite(res_s21);
  ck_assert_ldouble_infinite(res_orig);
}
END_TEST

START_TEST(s21_pow_test_13) {
  long double base = S21_INF, exp = -6.54321, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_pow_test_14) {
  long double base = 0, exp = -2.3456, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_infinite(res_s21);
  ck_assert_ldouble_infinite(res_orig);
}
END_TEST

START_TEST(s21_pow_test_15) {
  long double base = -S21_INF, exp = S21_INF, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_infinite(res_s21);
  ck_assert_ldouble_infinite(res_orig);
}
END_TEST

START_TEST(s21_pow_test_16) {
  long double base = 0.9999, exp = S21_INF, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_pow_test_17) {
  long double base = 1, exp = S21_INF, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_pow_test_18) {
  long double base = 1, exp = -S21_INF, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_pow_test_19) {
  long double base = 0.9999, exp = -S21_INF, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_infinite(res_s21);
  ck_assert_ldouble_infinite(res_orig);
}
END_TEST

START_TEST(s21_pow_test_20) {
  long double base = S21_INF, exp = 0, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_pow_test_21) {
  long double base = -S21_INF, exp = 0, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_pow_test_22) {
  long double base = -S21_INF, exp = S21_INF, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_infinite(res_s21);
  ck_assert_ldouble_infinite(res_orig);
}
END_TEST

START_TEST(s21_pow_test_23) {
  long double base = S21_INF, exp = S21_NAN, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_pow_test_24) {
  long double base = S21_NAN, exp = S21_INF, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_pow_test_25) {
  long double base = -S21_INF, exp = 2.4, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_infinite(res_s21);
  ck_assert_ldouble_infinite(res_orig);
}
END_TEST

START_TEST(s21_pow_test_26) {
  long double base = -34.56, exp = 0, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_pow_test_27) {
  long double base = -34.56, exp = 2, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_pow_test_28) {
  long double base = -34.56, exp = -2, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_pow_test_29) {
  long double base = -34.56, exp = -2.4, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_pow_test_30) {
  long double base = S21_NAN, exp = 0, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_pow_test_31) {
  long double base = 1, exp = S21_NAN, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_pow_test_32) {
  long double base = 1.0001, exp = -S21_INF, res_s21, res_orig;
  res_s21 = s21_pow(base, exp);
  res_orig = powl(base, exp);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_fmod_test_1) {
  long double x = 8.8888, y = 2.2, res_s21, res_orig;
  res_s21 = s21_fmod(x, y);
  res_orig = fmodl(x, y);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_fmod_test_2) {
  long double x = -10.1, y = 2.2, res_s21, res_orig;
  res_s21 = s21_fmod(x, y);
  res_orig = fmodl(x, y);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_fmod_test_3) {
  long double x = 1.1, y = -2.2, res_s21, res_orig;
  res_s21 = s21_fmod(x, y);
  res_orig = fmodl(x, y);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_fmod_test_4) {
  long double x = 9.87654321, y = 1.23456789, res_s21, res_orig;
  res_s21 = s21_fmod(x, y);
  res_orig = fmodl(x, y);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_fmod_test_5) {
  long double x = 1.23456789, y = 9.87654321, res_s21, res_orig;
  res_s21 = s21_fmod(x, y);
  res_orig = fmodl(x, y);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_fmod_test_6) {
  long double x = 10.23456789, y = -9.87654321, res_s21, res_orig;
  res_s21 = s21_fmod(x, y);
  res_orig = fmodl(x, y);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_fmod_test_7) {
  long double x = 123456, y = 3, res_s21, res_orig;
  res_s21 = s21_fmod(x, y);
  res_orig = fmodl(x, y);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_fmod_test_8) {
  long double x = 123.456, y = -6.54321, res_s21, res_orig;
  res_s21 = s21_fmod(x, y);
  res_orig = fmodl(x, y);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_fmod_test_9) {
  long double x = S21_NAN, y = -6.54321, res_s21, res_orig;
  res_s21 = s21_fmod(x, y);
  res_orig = fmodl(x, y);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_fmod_test_10) {
  long double x = 6.54321, y = S21_NAN, res_s21, res_orig;
  res_s21 = s21_fmod(x, y);
  res_orig = fmodl(x, y);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_fmod_test_11) {
  long double x = 6.54321, y = S21_INF, res_s21, res_orig;
  res_s21 = s21_fmod(x, y);
  res_orig = fmodl(x, y);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

START_TEST(s21_fmod_test_12) {
  long double x = S21_INF, y = 6.54321, res_s21, res_orig;
  res_s21 = s21_fmod(x, y);
  res_orig = fmodl(x, y);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_fmod_test_13) {
  long double x = -S21_INF, y = S21_INF, res_s21, res_orig;
  res_s21 = s21_fmod(x, y);
  res_orig = fmodl(x, y);
  ck_assert_ldouble_nan(res_s21);
  ck_assert_ldouble_nan(res_orig);
}
END_TEST

START_TEST(s21_fmod_test_14) {
  long double x = 2.4, y = -S21_INF, res_s21, res_orig;
  res_s21 = s21_fmod(x, y);
  res_orig = fmodl(x, y);
  ck_assert_ldouble_eq_tol(res_s21, res_orig, TEST_EPS);
}
END_TEST

Suite *s21_math_suite(void) {
  Suite *suite = suite_create("s21_math");
  TCase *tcase_core_abs = tcase_create("abs");
  tcase_add_test(tcase_core_abs, s21_abs_test_1);
  tcase_add_test(tcase_core_abs, s21_abs_test_2);
  tcase_add_test(tcase_core_abs, s21_abs_test_3);
  tcase_add_test(tcase_core_abs, s21_abs_test_4);
  tcase_add_test(tcase_core_abs, s21_abs_test_5);
  suite_add_tcase(suite, tcase_core_abs);

  TCase *tcase_core_fabs = tcase_create("fabs");
  tcase_add_test(tcase_core_fabs, s21_fabs_test_1);
  tcase_add_test(tcase_core_fabs, s21_fabs_test_2);
  tcase_add_test(tcase_core_fabs, s21_fabs_test_3);
  tcase_add_test(tcase_core_fabs, s21_fabs_test_4);
  tcase_add_test(tcase_core_fabs, s21_fabs_test_5);
  suite_add_tcase(suite, tcase_core_fabs);

  TCase *tcase_core_ceil = tcase_create("ceil");
  tcase_add_test(tcase_core_ceil, s21_ceil_test_1);
  tcase_add_test(tcase_core_ceil, s21_ceil_test_2);
  tcase_add_test(tcase_core_ceil, s21_ceil_test_3);
  tcase_add_test(tcase_core_ceil, s21_ceil_test_4);
  tcase_add_test(tcase_core_ceil, s21_ceil_test_5);
  tcase_add_test(tcase_core_ceil, s21_ceil_test_6);
  tcase_add_test(tcase_core_ceil, s21_ceil_test_7);
  tcase_add_test(tcase_core_ceil, s21_ceil_test_8);
  tcase_add_test(tcase_core_ceil, s21_ceil_test_9);
  tcase_add_test(tcase_core_ceil, s21_ceil_test_10);
  tcase_add_test(tcase_core_ceil, s21_ceil_test_11);
  tcase_add_test(tcase_core_ceil, s21_ceil_test_12);
  tcase_add_test(tcase_core_ceil, s21_ceil_test_13);
  tcase_add_test(tcase_core_ceil, s21_ceil_test_14);
  suite_add_tcase(suite, tcase_core_ceil);

  TCase *tcase_core_floor = tcase_create("floor");
  tcase_add_test(tcase_core_floor, s21_floor_test_1);
  tcase_add_test(tcase_core_floor, s21_floor_test_2);
  tcase_add_test(tcase_core_floor, s21_floor_test_3);
  tcase_add_test(tcase_core_floor, s21_floor_test_4);
  tcase_add_test(tcase_core_floor, s21_floor_test_5);
  tcase_add_test(tcase_core_floor, s21_floor_test_6);
  tcase_add_test(tcase_core_floor, s21_floor_test_7);
  tcase_add_test(tcase_core_floor, s21_floor_test_8);
  tcase_add_test(tcase_core_floor, s21_floor_test_9);
  tcase_add_test(tcase_core_floor, s21_floor_test_10);
  tcase_add_test(tcase_core_floor, s21_floor_test_11);
  tcase_add_test(tcase_core_floor, s21_floor_test_12);
  tcase_add_test(tcase_core_floor, s21_floor_test_13);
  tcase_add_test(tcase_core_floor, s21_floor_test_14);
  suite_add_tcase(suite, tcase_core_floor);

  TCase *tcase_core_pow_int = tcase_create("pow_int");
  tcase_add_test(tcase_core_pow_int, s21_pow_int_test_1);
  tcase_add_test(tcase_core_pow_int, s21_pow_int_test_2);
  tcase_add_test(tcase_core_pow_int, s21_pow_int_test_3);
  tcase_add_test(tcase_core_pow_int, s21_pow_int_test_4);
  tcase_add_test(tcase_core_pow_int, s21_pow_int_test_5);
  tcase_add_test(tcase_core_pow_int, s21_pow_int_test_6);
  tcase_add_test(tcase_core_pow_int, s21_pow_int_test_7);
  tcase_add_test(tcase_core_pow_int, s21_pow_int_test_8);
  suite_add_tcase(suite, tcase_core_pow_int);

  TCase *tcase_core_exp = tcase_create("exp");
  tcase_add_test(tcase_core_exp, s21_exp_test_1);
  tcase_add_test(tcase_core_exp, s21_exp_test_2);
  tcase_add_test(tcase_core_exp, s21_exp_test_3);
  tcase_add_test(tcase_core_exp, s21_exp_test_4);
  tcase_add_test(tcase_core_exp, s21_exp_test_5);
  tcase_add_test(tcase_core_exp, s21_exp_test_6);
  tcase_add_test(tcase_core_exp, s21_exp_test_7);
  tcase_add_test(tcase_core_exp, s21_exp_test_8);
  tcase_add_test(tcase_core_exp, s21_exp_test_9);
  tcase_add_test(tcase_core_exp, s21_exp_test_10);
  tcase_add_test(tcase_core_exp, s21_exp_test_11);
  tcase_add_test(tcase_core_exp, s21_exp_test_12);
  tcase_add_test(tcase_core_exp, s21_exp_test_13);
  suite_add_tcase(suite, tcase_core_exp);

  TCase *tcase_core_sin = tcase_create("sin");
  tcase_add_test(tcase_core_sin, s21_sin_test_1);
  tcase_add_test(tcase_core_sin, s21_sin_test_2);
  tcase_add_test(tcase_core_sin, s21_sin_test_3);
  tcase_add_test(tcase_core_sin, s21_sin_test_4);
  tcase_add_test(tcase_core_sin, s21_sin_test_5);
  tcase_add_test(tcase_core_sin, s21_sin_test_6);
  tcase_add_test(tcase_core_sin, s21_sin_test_7);
  tcase_add_test(tcase_core_sin, s21_sin_test_8);
  tcase_add_test(tcase_core_sin, s21_sin_test_9);
  tcase_add_test(tcase_core_sin, s21_sin_test_10);
  tcase_add_test(tcase_core_sin, s21_sin_test_11);
  tcase_add_test(tcase_core_sin, s21_sin_test_12);
  tcase_add_test(tcase_core_sin, s21_sin_test_13);
  suite_add_tcase(suite, tcase_core_sin);

  TCase *tcase_core_cos = tcase_create("cos");
  tcase_add_test(tcase_core_cos, s21_cos_test_1);
  tcase_add_test(tcase_core_cos, s21_cos_test_2);
  tcase_add_test(tcase_core_cos, s21_cos_test_3);
  tcase_add_test(tcase_core_cos, s21_cos_test_4);
  tcase_add_test(tcase_core_cos, s21_cos_test_5);
  tcase_add_test(tcase_core_cos, s21_cos_test_6);
  tcase_add_test(tcase_core_cos, s21_cos_test_7);
  tcase_add_test(tcase_core_cos, s21_cos_test_8);
  tcase_add_test(tcase_core_cos, s21_cos_test_9);
  tcase_add_test(tcase_core_cos, s21_cos_test_10);
  tcase_add_test(tcase_core_cos, s21_cos_test_11);
  tcase_add_test(tcase_core_cos, s21_cos_test_12);
  suite_add_tcase(suite, tcase_core_cos);

  TCase *tcase_core_tan = tcase_create("tan");
  tcase_add_test(tcase_core_tan, s21_tan_test_1);
  tcase_add_test(tcase_core_tan, s21_tan_test_2);
  tcase_add_test(tcase_core_tan, s21_tan_test_3);
  tcase_add_test(tcase_core_tan, s21_tan_test_4);
  tcase_add_test(tcase_core_tan, s21_tan_test_5);
  tcase_add_test(tcase_core_tan, s21_tan_test_6);
  tcase_add_test(tcase_core_tan, s21_tan_test_7);
  tcase_add_test(tcase_core_tan, s21_tan_test_8);
  tcase_add_test(tcase_core_tan, s21_tan_test_9);
  tcase_add_test(tcase_core_tan, s21_tan_test_10);
  tcase_add_test(tcase_core_tan, s21_tan_test_11);
  tcase_add_test(tcase_core_tan, s21_tan_test_12);
  tcase_add_test(tcase_core_tan, s21_tan_test_13);
  tcase_add_test(tcase_core_tan, s21_tan_test_14);
  suite_add_tcase(suite, tcase_core_tan);

  TCase *tcase_core_log = tcase_create("log");
  tcase_add_test(tcase_core_log, s21_log_test_1);
  tcase_add_test(tcase_core_log, s21_log_test_2);
  tcase_add_test(tcase_core_log, s21_log_test_3);
  tcase_add_test(tcase_core_log, s21_log_test_4);
  tcase_add_test(tcase_core_log, s21_log_test_5);
  tcase_add_test(tcase_core_log, s21_log_test_6);
  tcase_add_test(tcase_core_log, s21_log_test_7);
  tcase_add_test(tcase_core_log, s21_log_test_8);
  tcase_add_test(tcase_core_log, s21_log_test_9);
  tcase_add_test(tcase_core_log, s21_log_test_10);
  suite_add_tcase(suite, tcase_core_log);

  TCase *tcase_core_sqrt = tcase_create("sqrt");
  tcase_add_test(tcase_core_sqrt, s21_sqrt_test_1);
  tcase_add_test(tcase_core_sqrt, s21_sqrt_test_2);
  tcase_add_test(tcase_core_sqrt, s21_sqrt_test_3);
  tcase_add_test(tcase_core_sqrt, s21_sqrt_test_4);
  tcase_add_test(tcase_core_sqrt, s21_sqrt_test_5);
  tcase_add_test(tcase_core_sqrt, s21_sqrt_test_6);
  tcase_add_test(tcase_core_sqrt, s21_sqrt_test_7);
  tcase_add_test(tcase_core_sqrt, s21_sqrt_test_8);
  tcase_add_test(tcase_core_sqrt, s21_sqrt_test_9);
  suite_add_tcase(suite, tcase_core_sqrt);

  TCase *tcase_core_asin = tcase_create("asin");
  tcase_add_test(tcase_core_asin, s21_asin_test_1);
  tcase_add_test(tcase_core_asin, s21_asin_test_2);
  tcase_add_test(tcase_core_asin, s21_asin_test_3);
  tcase_add_test(tcase_core_asin, s21_asin_test_4);
  tcase_add_test(tcase_core_asin, s21_asin_test_5);
  tcase_add_test(tcase_core_asin, s21_asin_test_6);
  tcase_add_test(tcase_core_asin, s21_asin_test_7);
  tcase_add_test(tcase_core_asin, s21_asin_test_8);
  tcase_add_test(tcase_core_asin, s21_asin_test_9);
  tcase_add_test(tcase_core_asin, s21_asin_test_10);
  tcase_add_test(tcase_core_asin, s21_asin_test_11);
  tcase_add_test(tcase_core_asin, s21_asin_test_12);
  tcase_add_test(tcase_core_asin, s21_asin_test_13);
  tcase_add_test(tcase_core_asin, s21_asin_test_14);
  tcase_add_test(tcase_core_asin, s21_asin_test_15);
  suite_add_tcase(suite, tcase_core_asin);

  TCase *tcase_core_acos = tcase_create("acos");
  tcase_add_test(tcase_core_acos, s21_acos_test_1);
  tcase_add_test(tcase_core_acos, s21_acos_test_2);
  tcase_add_test(tcase_core_acos, s21_acos_test_3);
  tcase_add_test(tcase_core_acos, s21_acos_test_4);
  tcase_add_test(tcase_core_acos, s21_acos_test_5);
  tcase_add_test(tcase_core_acos, s21_acos_test_6);
  tcase_add_test(tcase_core_acos, s21_acos_test_7);
  tcase_add_test(tcase_core_acos, s21_acos_test_8);
  tcase_add_test(tcase_core_acos, s21_acos_test_9);
  tcase_add_test(tcase_core_acos, s21_acos_test_10);
  tcase_add_test(tcase_core_acos, s21_acos_test_11);
  tcase_add_test(tcase_core_acos, s21_acos_test_12);
  tcase_add_test(tcase_core_acos, s21_acos_test_13);
  tcase_add_test(tcase_core_acos, s21_acos_test_14);
  tcase_add_test(tcase_core_acos, s21_acos_test_15);
  suite_add_tcase(suite, tcase_core_acos);

  TCase *tcase_core_atan = tcase_create("atan");
  tcase_add_test(tcase_core_atan, s21_atan_test_1);
  tcase_add_test(tcase_core_atan, s21_atan_test_2);
  tcase_add_test(tcase_core_atan, s21_atan_test_3);
  tcase_add_test(tcase_core_atan, s21_atan_test_4);
  tcase_add_test(tcase_core_atan, s21_atan_test_5);
  tcase_add_test(tcase_core_atan, s21_atan_test_6);
  tcase_add_test(tcase_core_atan, s21_atan_test_7);
  tcase_add_test(tcase_core_atan, s21_atan_test_8);
  tcase_add_test(tcase_core_atan, s21_atan_test_9);
  tcase_add_test(tcase_core_atan, s21_atan_test_10);
  tcase_add_test(tcase_core_atan, s21_atan_test_11);
  tcase_add_test(tcase_core_atan, s21_atan_test_12);
  tcase_add_test(tcase_core_atan, s21_atan_test_13);
  tcase_add_test(tcase_core_atan, s21_atan_test_14);
  tcase_add_test(tcase_core_atan, s21_atan_test_15);
  tcase_add_test(tcase_core_atan, s21_atan_test_16);
  suite_add_tcase(suite, tcase_core_atan);

  TCase *tcase_core_pow = tcase_create("pow");
  tcase_add_test(tcase_core_pow, s21_pow_test_1);
  tcase_add_test(tcase_core_pow, s21_pow_test_2);
  tcase_add_test(tcase_core_pow, s21_pow_test_3);
  tcase_add_test(tcase_core_pow, s21_pow_test_4);
  tcase_add_test(tcase_core_pow, s21_pow_test_5);
  tcase_add_test(tcase_core_pow, s21_pow_test_6);
  tcase_add_test(tcase_core_pow, s21_pow_test_7);
  tcase_add_test(tcase_core_pow, s21_pow_test_8);
  tcase_add_test(tcase_core_pow, s21_pow_test_9);
  tcase_add_test(tcase_core_pow, s21_pow_test_10);
  tcase_add_test(tcase_core_pow, s21_pow_test_11);
  tcase_add_test(tcase_core_pow, s21_pow_test_12);
  tcase_add_test(tcase_core_pow, s21_pow_test_13);
  tcase_add_test(tcase_core_pow, s21_pow_test_14);
  tcase_add_test(tcase_core_pow, s21_pow_test_15);
  tcase_add_test(tcase_core_pow, s21_pow_test_16);
  tcase_add_test(tcase_core_pow, s21_pow_test_17);
  tcase_add_test(tcase_core_pow, s21_pow_test_18);
  tcase_add_test(tcase_core_pow, s21_pow_test_19);
  tcase_add_test(tcase_core_pow, s21_pow_test_20);
  tcase_add_test(tcase_core_pow, s21_pow_test_21);
  tcase_add_test(tcase_core_pow, s21_pow_test_22);
  tcase_add_test(tcase_core_pow, s21_pow_test_23);
  tcase_add_test(tcase_core_pow, s21_pow_test_24);
  tcase_add_test(tcase_core_pow, s21_pow_test_25);
  tcase_add_test(tcase_core_pow, s21_pow_test_26);
  tcase_add_test(tcase_core_pow, s21_pow_test_27);
  tcase_add_test(tcase_core_pow, s21_pow_test_28);
  tcase_add_test(tcase_core_pow, s21_pow_test_29);
  tcase_add_test(tcase_core_pow, s21_pow_test_30);
  tcase_add_test(tcase_core_pow, s21_pow_test_31);
  tcase_add_test(tcase_core_pow, s21_pow_test_32);
  suite_add_tcase(suite, tcase_core_pow);

  TCase *tcase_core_fmod = tcase_create("fmod");
  tcase_add_test(tcase_core_fmod, s21_fmod_test_1);
  tcase_add_test(tcase_core_fmod, s21_fmod_test_2);
  tcase_add_test(tcase_core_fmod, s21_fmod_test_3);
  tcase_add_test(tcase_core_fmod, s21_fmod_test_4);
  tcase_add_test(tcase_core_fmod, s21_fmod_test_5);
  tcase_add_test(tcase_core_fmod, s21_fmod_test_6);
  tcase_add_test(tcase_core_fmod, s21_fmod_test_7);
  tcase_add_test(tcase_core_fmod, s21_fmod_test_8);
  tcase_add_test(tcase_core_fmod, s21_fmod_test_9);
  tcase_add_test(tcase_core_fmod, s21_fmod_test_10);
  tcase_add_test(tcase_core_fmod, s21_fmod_test_11);
  tcase_add_test(tcase_core_fmod, s21_fmod_test_12);
  tcase_add_test(tcase_core_fmod, s21_fmod_test_13);
  tcase_add_test(tcase_core_fmod, s21_fmod_test_14);
  suite_add_tcase(suite, tcase_core_fmod);

  return suite;
}

int main(void) {
  int failed_count;
  Suite *suite = s21_math_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
