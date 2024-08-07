/*
Copyright (C) 2024 Ian Sloat

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <vector>

using std::size_t;

namespace me::data {
		
	double calculateMean(const std::vector<double>& data);

	double calculateMedian(const std::vector<double>& data);

	double calculateStdDev(const std::vector<double>& data, double mean);

	std::vector<size_t> findOutliers(const std::vector<double>& data, double threshold);

	void calculateQuartiles(const std::vector<double>& data, double& Q1, double& Q3);

	std::vector<size_t> findOutliersIQR(const std::vector<double>& data);
	
}