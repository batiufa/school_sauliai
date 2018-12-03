#include "stdafx.h"
#include <fstream>
#include <iostream>
#include "Saulys.h"
#include <string>
#include <cstdlib>
#include <iomanip> 
#include <algorithm>

std::vector<Saulys> getSauliaiFromStream(std::ifstream& stream)
{
	std::vector<Saulys> sauliai;

	int numberOfSauliai = 0;
	stream >> numberOfSauliai;
	while (numberOfSauliai > 0) {
		std::string fN, lN;
		std::vector<double> hits;
		stream >> fN >> lN;
		for (int i = 1; i <= 10; ++i) {
			int temp = 0;
			stream >> temp;
			hits.push_back(temp);
		}
		sauliai.push_back(Saulys(fN, lN, hits));
		--numberOfSauliai;
	}
	return sauliai;
}

std::ofstream& printSauliai(std::ofstream& s, std::vector<Saulys>& sauliai)
{
	for (int i = 0; i < 3; ++i) {
		s << sauliai[i].getFName() << " " << sauliai[i].getLName() << " " << std::fixed << std::setprecision(2) << sauliai[i].getAvg() << std::endl;
	}
	return s;
}

std::vector<Saulys>& sortSauliai(std::vector<Saulys>& saulys)
{
	std::sort(saulys.begin(), saulys.end());
	return saulys;
}

int main()
{
	std::ifstream istream("U1.txt", std::ios_base::in);
	std::vector<Saulys> sauliai = getSauliaiFromStream(istream);
	istream.close();
	std::ofstream ostream("U2.txt", std::ios_base::out);
	printSauliai(ostream, sortSauliai(sauliai));
    return EXIT_SUCCESS;
}

