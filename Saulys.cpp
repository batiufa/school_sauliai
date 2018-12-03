#include "Saulys.h"



Saulys::Saulys(const std::string& fN, const std::string& lN, std::vector<double>& hits)
{
	firstName = fN;
	lastName = lN;

	double hitSum = 0;
	for (double hit : hits) {
		hitSum += hit;
	}
	average = hitSum / hits.size();
}

