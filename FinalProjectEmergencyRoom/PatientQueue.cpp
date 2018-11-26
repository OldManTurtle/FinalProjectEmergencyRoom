#include "PatientQueue.h"



patient PatientQueue::docTop()
{
	if (data.size() == 0)
		return patient(-1); //We should take another look at this
	return data[0];
}

patient PatientQueue::nurseTop()
{
	if (nurseLoc() < 0)
		return patient(-1); //We should take a look at this to see if it should work
	return data[nurseLoc()];

}

void PatientQueue::nursePop()
{
	int loc = nurseLoc(); //loc is the current position
	if (loc < 0)
		return;
	swap(loc, data.size() - 1); //place the one to be deleted at the end and the end at the current position
	data.pop_back(); // delete the end

					 //This moves the current position to its correct spot
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

void PatientQueue::push(patient input)
{
	data.push_back(input);

	int loc = data.size() - 1; //loc is the current location

	while (data[loc] > data[(loc - 1) / 2]) {
		swap(loc, (loc - 1) / 2);
		loc = (loc - 1) / 2;
	}
}

PatientQueue::PatientQueue()
{
}


PatientQueue::~PatientQueue()
{
}

void PatientQueue::display(int lvl, int loc)
{
	for (int i = 0; i < lvl; i++) {
		std::cout << "-";
	}
	std::cout << data[loc].getSeverity() << std::endl;


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
	patient temp = data[locA];
	data[locA] = data[locB];
	data[locB] = temp;
}
