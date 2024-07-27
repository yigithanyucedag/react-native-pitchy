#include "react-native-pitchy.h"

#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <limits>

namespace pitchy
{
	double multiply(double a, double b)
	{
		return a * b;
	}

	double autoCorrelate(const std::vector<double> &buf, double sampleRate)
	{
		// Implements the ACF2+ algorithm
		int SIZE = buf.size();
		double rms = 0;

		for (int i = 0; i < SIZE; ++i)
		{
			double val = buf[i];
			rms += val * val;
		}
		rms = std::sqrt(rms / SIZE);
		if (rms < 0.01) // not enough signal
			return -1;

		int r1 = 0, r2 = SIZE - 1;
		double thres = 0.2;
		for (int i = 0; i < SIZE / 2; ++i)
			if (std::abs(buf[i]) < thres)
			{
				r1 = i;
				break;
			}
		for (int i = 1; i < SIZE / 2; ++i)
			if (std::abs(buf[SIZE - i]) < thres)
			{
				r2 = SIZE - i;
				break;
			}

		std::vector<double> slicedBuf(buf.begin() + r1, buf.begin() + r2);
		SIZE = slicedBuf.size();

		std::vector<double> c(SIZE, 0);
		for (int i = 0; i < SIZE; ++i)
			for (int j = 0; j < SIZE - i; ++j)
				c[i] += slicedBuf[j] * slicedBuf[j + i];

		int d = 0;
		while (c[d] > c[d + 1])
			d++;
		double maxval = -1, maxpos = -1;
		for (int i = d; i < SIZE; ++i)
		{
			if (c[i] > maxval)
			{
				maxval = c[i];
				maxpos = i;
			}
		}
		double T0 = maxpos;

		double x1 = c[T0 - 1], x2 = c[T0], x3 = c[T0 + 1];
		double a = (x1 + x3 - 2 * x2) / 2;
		double b = (x3 - x1) / 2;
		if (a)
			T0 = T0 - b / (2 * a);

		return sampleRate / T0;
	}
}
