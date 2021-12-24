#define _USE_MATH_DEFINES

#include <cmath>
#include "math.hpp"
#include <stdlib.h>
#include <time.h>

float const Math::DEG_PER_RAD = 180 / M_PI;
float const Math::RAND_MAX_RECIPROCAL = 1.0f / ((float)RAND_MAX);
float const Math::PI_2 = M_PI * 2.0f;

float Math::GetRandFloat(float min, float max)
{
  return (min + RAND_MAX_RECIPROCAL * (max-min) * rand());
}
void Math::RandInit()
{
  srand(time(NULL));
}