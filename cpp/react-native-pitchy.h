#ifndef PITCHY_H
#define PITCHY_H

#include <vector>

namespace pitchy
{
  double autoCorrelate(const std::vector<double> &buf, double sampleRate);
  double calculateVolume(const std::vector<double> &buf);
}

#endif /* PITCHY_H */
