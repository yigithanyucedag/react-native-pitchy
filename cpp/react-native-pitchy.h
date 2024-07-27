#ifndef PITCHY_H
#define PITCHY_H

#include <vector>

namespace pitchy
{
  double multiply(double a, double b);
  double autoCorrelate(const std::vector<double> &buf, double sampleRate);
}

#endif /* PITCHY_H */
