#pragma once
#include <string>
#include <vector>
class Saulys
{
	std::string firstName;
	std::string lastName;
	double average;
public:
	Saulys(const std::string&, const std::string&, std::vector<double>&);
	std::string getFName() { return firstName; }
	std::string getLName() { return lastName; }
	double getAvg() { return average; }

	bool operator< (const Saulys &other) const {	//Operatorius rusiavimui
		return average > other.average;
	}
};


