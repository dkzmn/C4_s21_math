#include "s21_math.h"

int s21_abs(int x) {
  int res = x;
  if (x < 0) res = -x;
  return res;
}

long double s21_fabs(double x) {
  long double res = x;
  if (x < 0) res = -x;
  return res;
}

long double s21_pow_int(double base, int exp) {
  long double res;
  int sign = 1;
  if (exp == 0) {
    res = 1;
  } else if (base == 0) {
    res = 0;
  } else {
    res = 1;
    if (exp < 0) {
      sign = -1;
      exp = -exp;
    }
    while (exp > 0) {
      res *= base;
      exp--;
    }
  }
  if (sign == -1) res = 1 / res;
  return res;
}

long double s21_exp(double x) {
  long double res = 1, res_temp = 1;
  if (x != x) {
    res = S21_NAN;
  } else if (x == S21_INF || x > 11356.5) {
    res = S21_INF;
  } else if (x == -S21_INF || x < -11356.5) {
    res = 0.0;
  } else {
    int sign = 1, i = 1;
    if (x < 0) {
      sign = -1;
      x = -x;
    }
    while (s21_fabs(res_temp) > EPSILON) {
      res_temp = (res_temp / i) * x;
      res += res_temp;
      i++;
    }
    if (sign == -1) res = 1 / res;
  }
  return res;
}

long double s21_sin(double x) {
  long double res = x, res_temp, tmpx;
  if (x == S21_INF || x == -S21_INF || x != x) {
    res = S21_NAN;
  } else {
    int i = 1;
    res = s21_fmod(res, 2 * S21_PI);
    res_temp = res;
    tmpx = res;
    while (s21_fabs(res_temp) > EPSILON) {
      res_temp = -1 * res_temp * tmpx * tmpx / ((2 * i) * (2 * i + 1));
      res += res_temp;
      i++;
    }
  }
  return res;
}

long double s21_cos(double x) {
  long double res = x, res_temp = 1, tmpx;
  if (x == S21_INF || x == -S21_INF || x != x) {
    res = S21_NAN;
  } else {
    int i = 1;
    res = s21_fmod(res, 2 * S21_PI);
    tmpx = res;
    res = 1;
    while (s21_fabs(res_temp) > EPSILON) {
      res_temp = -1 * res_temp * tmpx * tmpx / ((2 * i) * (2 * i - 1));
      res += res_temp;
      i++;
    }
  }
  return res;
}

long double s21_tan(double x) {
  long double res;
  if (x == S21_INF || x == -S21_INF || x != x)
    res = S21_NAN;
  else
    res = s21_sin(x) / s21_cos(x);
  return res;
}

long double s21_log(double x) {
  long double res;
  if (x < 0 || x != x) {
    res = S21_NAN;
  } else if (x == 0) {
    res = -S21_INF;
  } else if (x == S21_INF) {
    res = S21_INF;
  } else {
    res = 1;
    for (int i = 0; i < NCOUNT; i++)
      res = res + 2 * (x - s21_exp(res)) / (x + s21_exp(res));
  }
  return res;
}

long double s21_sqrt(double x) {
  long double res;
  if (x < 0 || x != x) {
    res = S21_NAN;
  } else {
    res = s21_exp(s21_log(x) / 2);
  }
  return res;
}

long double s21_asin(double x) {
  long double res, res_temp;
  if (x < -1 || x > 1 || x != x || x == S21_INF) {
    res = S21_NAN;
  } else {
    int near_one = 0, sign = 1;
    if (x < 0) sign = -1;
    if (1 - s21_fabs(x) < 0.01) {
      x = s21_sqrt(1 - x * x);
      near_one = 1;
    }
    res = x;
    res_temp = x;
    int i = 1;
    while (s21_fabs(res_temp) > EPSILON) {
      res_temp *= x * x * (2 * i - 1) * (2 * i - 1);
      long double tmp = 2.0 * i * (2 * i + 1);
      res_temp /= tmp;
      res += res_temp;
      i++;
    }
    if (near_one == 1) {
      if (sign == 1) {
        res = S21_PI / 2 - res;
      } else {
        res = -S21_PI / 2 + res;
      }
    }
  }
  return res;
}

long double s21_acos(double x) {
  long double res;
  if (x < -1 || x > 1 || x != x || x == S21_INF) {
    res = S21_NAN;
  } else {
    res = S21_PI / 2 - s21_asin(x);
  }
  return res;
}

long double s21_atan(double x) {
  long double res, res_temp;
  if (x != x) {
    res = S21_NAN;
  } else if (x == S21_INF) {
    res = S21_PI / 2;
  } else if (x == -S21_INF) {
    res = -S21_PI / 2;
  } else if (x == -1) {
    res = -S21_PI / 4;
  } else if (x == 1) {
    res = S21_PI / 4;
  } else {
    int more_one = 0, sign = 1;
    if (x > 1 || x < -1) {
      if (x < 0) {
        x = -x;
        sign = -1;
      }
      x = 1 / x;
      more_one = 1;
    }
    res = x;
    res_temp = x;
    int i = 2;
    while (s21_fabs(res_temp) > EPSILON) {
      res_temp = res_temp * -x * x * (2 * i - 3) / (2 * i - 1);
      res += res_temp;
      i++;
    }
    if (more_one == 1) res = S21_PI / 2 - res;
    if (sign == -1) res = -res;
  }
  return res;
}

long double s21_pow(double base, double exp) {
  long double res;
  if (exp == 0 || base == 1) {
    res = 1;
  } else if (base != base || exp != exp) {
    res = S21_NAN;
  } else if (exp == S21_INF) {
    if (s21_fabs(base) < 1)
      res = 0;
    else
      res = S21_INF;
  } else if (exp == -S21_INF) {
    if (s21_fabs(base) < 1)
      res = S21_INF;
    else
      res = 0;
  } else if (base == S21_INF || base == -S21_INF) {
    if (exp > 0)
      res = S21_INF;
    else
      res = 0;
  } else if (base < 0 && s21_ceil(exp) != exp) {
    res = S21_NAN;
  } else {
    int sign_exp = 1;
    if (exp < 0) {
      exp = -exp;
      sign_exp = -1;
    }
    int exp1 = (long long int)s21_floor(exp);
    long double exp2 = exp - exp1;
    if (exp2 > 0)
      res = s21_pow_int(base, exp1) * s21_exp(exp2 * s21_log(base));
    else
      res = s21_pow_int(base, exp1);
    if (sign_exp == -1) res = 1 / res;
  }
  return res;
}

long double s21_floor(double x) {
  long long int int_part;
  long double temp = x;
  long double res;
  if (x == S21_INF) {
    res = S21_INF;
  } else if (x == -S21_INF) {
    res = -S21_INF;
  } else if (x != x) {
    res = S21_NAN;
  } else {
    int_part = (long long int)(temp + EPSILON);
    long double float_part = temp - (long double)int_part;
    if (x == DBL_MAX)
      res = DBL_MAX;
    else if (x == DBL_MIN)
      res = 0.f;
    else if (float_part < 0.0)
      res = int_part - 1;
    else
      res = int_part;
  }
  return res;
}
long double s21_ceil(double x) {
  long long int int_part;
  long double res;
  if (x == S21_INF) {
    res = S21_INF;
  } else if (x == -S21_INF) {
    res = -S21_INF;
  } else if (x != x) {
    res = S21_NAN;
  } else {
    long double temp = x;
    int negative = 0;
    if (temp < 0) {
      temp = -temp;
      negative = 1;
    }
    int_part = (long long int)(temp + EPSILON);
    long double float_part = temp - (long double)int_part;
    if (x == DBL_MAX)
      res = DBL_MAX;
    else if (x == DBL_MIN)
      res = 1.;
    else if (int_part == 0 && float_part == 0.0)
      res = 0.f;
    else if (int_part == 0 && negative)
      res = -0.f;
    else if (negative)
      res = -int_part;
    else if (float_part > 0)
      res = int_part + 1;
    else
      res = int_part;
  }
  return res;
}

long double s21_fmod(double x, double y) {
  long double res;
  long long int mod = 0;
  if (y == 0 || x == S21_INF || x == -S21_INF || x != x || y != y) {
    res = S21_NAN;
  } else if (y == S21_INF || y == -S21_INF) {
    res = x;
  } else {
    mod = x / y;
    res = (long double)x - mod * (long double)y;
  }
  return res;
}
