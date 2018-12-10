//////////////////////////////////
//Title: PatientQueue.cpp
//Authors: Abby Jahns, Aiden McIlraith, Chris Roberts
//Last Modified: 12/7/2018
//Purpose: Implement the PatientQueue class
//////////////////////////////////

#include "PatientQueue.h"



Patient PatientQueue::docTop()
{
	if (data.size() == 0)
		return Patient(); //We should take another look at this
	return data[0];
}

Patient PatientQueue::nurseTop()
{
	if (nurseLoc() < 0)
		return Patient(); //We should take a look at this to see if it should work
	return data[nurseLoc()];

}

void PatientQueue::docPop()
{
	this->pop(0);
}

void PatientQueue::nursePop()
{
	this->pop(this->nurseLoc());
}

void PatientQueue::push(Patient input)
{
	data.push_back(input);

	int loc = data.size() - 1; //loc is the current location

	while (data[loc] > data[(loc - 1) / 2]) {
		swap(loc, (loc - 1) / 2);
		loc = (loc - 1) / 2;
	}
}

bool PatientQueue::hasName(std::string name)
{
	for (int i = 0; i < data.size(); i++) {
		if (data[i].getName() == name)
			return true;
	}
	return false;
}

void PatientQueue::uptickWait(int currentTick)
{
	for (int i = 0; i < data.size(); i++) {
		if ((data[i].getSeverity() < 20) && ((currentTick - data[i].getArrivalTime()) % 30 == 0)) {
			//Every half hour, severity increases by one
			data[i].iterateSeverity();
			reorganize(i);
		}
		else if ((data[i].getSeverity() >= 20) && ((currentTick - data[i].getArrivalTime()) % 30 == 0)) {
			//If the patient is at 20, they die if they should tick up
			Patient::kill(data[i].getName());
			pop(i);

		}
	}
}

PatientQueue::PatientQueue()
{
}

PatientQueue::~PatientQueue()
{
}

void PatientQueue::pop(int loc)
{
	//loc is the current position
	if (loc < 0)
		return;
	swap(loc, data.size() - 1); //place the one to be deleted at the end and the end at the current position
	data.pop_back(); // delete the end
	if (loc >= data.size()) //return if the thing removed was the last item
		return;
	//This moves the current position to its correct spot
	reorganize(loc);
}

void PatientQueue::reorganize(int loc) {
	while (true) {
		//Check to move up
		if (data[loc] > data[up(loc)]) {
			swap(loc, up(loc));
			loc = up(loc);
		}
		//This is wrong
		else { //Then it must move down or nothing
			if (right(loc) >= data.size()) { //Check to make sure that down right is in range
				if (left(loc) >= data.size()) //If not, see if down left is in range
					return;
				else {
					if (data[left(loc)] > data[loc]) //switch with down left if need be
						swap(loc, left(loc));
					return;
				}
			}


			if ((data[left(loc)] > data[right(loc)])) {
				if (data[left(loc)] > data[loc]) {
					swap(loc, left(loc));
					loc = left(loc);
				}
				else {
					return;
				}
			}
			else {
				if (data[right(loc)] > data[loc]) {
					swap(loc, right(loc));
					loc = right(loc);
				}
				else {
					return;
				}
			}
		}
	}
}

void PatientQueue::display(int lvl, int loc)
{
	for (int i = 0; i < lvl; i++) {
		std::cout << "-";
	}
	std::cout << data[loc].getName() << ">>" << data[loc].getSeverity() << std::endl;


	if (loc * 2 + 1 < data.size())
		display(lvl + 1, loc * 2 + 1);

	if ((loc * 2 + 2) < data.size())
		display(lvl + 1, loc * 2 + 2);


}

int PatientQueue::nurseLoc()
{
	int loc = -1;
	for (int i = 0; i < data.size(); i++) {
		if (data[i].getSeverity() <= 10) {
			loc = i;
			break;
		}

	}

	if (loc == -1)
		return loc;
	
	for (int i = loc; i < data.size(); i++) {
		if ((data[i].getSeverity() <= 10) && (data[i] > data[loc])) {
			loc = i;
		}
	}
	return loc;
}

void PatientQueue::swap(int locA, int locB)
{
	if ((locA >= data.size()) || (locB >= data.size()) || (locA < 0) || (locB < 0))
	{
		throw(std::range_error("Invalid Range"));
	}
	Patient temp = data[locA];
	data[locA] = data[locB];
	data[locB] = temp;
}
