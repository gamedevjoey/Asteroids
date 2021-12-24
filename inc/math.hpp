#pragma once

namespace Math 
{
  extern float const DEG_PER_RAD;
  extern float const RAND_MAX_RECIPROCAL;
  extern float const PI_2;

  float GetRandFloat(float min, float max);
  void RandInit();
}