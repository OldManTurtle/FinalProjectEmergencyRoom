//////////////////////////////////
//Title: Record.cpp
//Authors: Abby Jahns, Aiden McIlraith, Chris Roberts
//Last Modified: 12/7/2018
//Purpose: Implement the Record class
//////////////////////////////////

#include "Record.h"
#include <stdexcept>

void Record::addName(std::string input, int sev)
{
	//If the element is in the map
	if (data.count(input)) {
		data.at(input).push_back(sev);
	}
	//Otherwise
	else {
		data.insert(std::pair < std::string, std::vector<int>>(input, { sev }));
	}
}

int Record::getNumVisits(std::string input)
{
	//If the element is in the map
	if (data.count(input)) {
		return data.at(input).size();
	}
	//Otherwise
	else {
		std::cerr << "getNumVisits Failure. Name does not exist." << std::endl;
		return -1;
	}
	
}

void Record::display()
{
	std::map<std::string, std::vector<int>>::iterator i = data.begin();
	while (i != data.end()) {
		std::cout << i->first << std::endl;
		for (int j = 0; j < i->second.size(); j++) {
			std::cout << "   Visit " << j + 1 << ": " << i->second[j] << std::endl;
		}
		++i;
	}
}

int Record::getSeverityOfVisit(std::string name, int visit)
{
	if (data.count(name)) {
		if (data.at(name).size() >= visit) {
			std::cerr << "getSeverityOfVisits Broke. No such visit." << std::endl;
			return -1;
		}
		return data.at(name).at(visit);
	}
	else {
		std::cerr << "getSeverityOfVisits Broke. No such name." << std::endl;
		return -1;
	}
}
