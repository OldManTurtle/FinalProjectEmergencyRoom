#ifndef ERHEAP_H
#define ERHEAP_H
#include <vector>
#include <exception>
#include <stdexcept>
#include <iostream>

template <typename patient>
class erHeap {
public:
	patient docTop() {
		if (data.size() == 0)
			return patient(-1); //We should take another look at this
		return data[0];
	}

	patient nurseTop() {
		if (nurseLoc() < 0)
			return patient(-1); //We should take a look at this to see if it should work
		return data[nurseLoc()];

	}

	void docPop();

	void nursePop() {
		int loc = nurseLoc(); //loc is the current position
		if (loc < 0)
			return;
		swap(loc, data.size() - 1); //place the one to be deleted at the end and the end at the current position
		data.pop_back(); // delete the end

						 //This moves the current position to its correct spot
		while (true) {
			//Check to move up
			if (data[loc] > data[(loc - 1) / 2]) {
				swap(loc, (loc - 1) / 2);
				loc = (loc - 1) / 2;
			}
			//This is wrong
			else { //Then it must move down or nothing
				if (loc * 2 + 2 >= data.size()) { //Check to make sure that down right is in range
					if (loc * 2 + 1 >= data.size()) //If not, see if down left is in range
						return;
				}
				else {
					if (data[loc] > data[loc * 2 + 1]) //switch with down left if need be
						swap(loc, loc * 2 + 1);
					return;
				}

				//check if the data should move down to the left
				if ((data[loc] > data[loc * 2 + 1]) && (data[loc * 2 + 1] > data[loc * 2 + 2])) {
					swap(loc, loc * 2 + 1);
					loc = loc * 2 + 1;
				}

				// down to the right?
				else if ((data[loc] > data[loc * 2 + 2])) {
					swap(loc, loc * 2 + 2);
					loc = loc * 2 + 2;
				}
				//If we get here, it can't move up or down, so it ends
				else {
					return;
				}
			}
		}


	}

	void push(patient input) {
		data.push_back(input);

		int loc = data.size() - 1; //loc is the current location

		while (data[loc] > data[(loc - 1) / 2]) {
			swap(loc, (loc - 1) / 2);
			loc = (loc - 1) / 2;
		}



	}

	void display() {
		display(0, 0);
	}


private:

	void display(int lvl, int loc) {
		for (int i = 0; i < lvl; i++) {
			std::cout << "-";
		}
		std::cout << data[loc] << std::endl;


		if (loc * 2 + 1 < data.size())
			display(lvl + 1, loc * 2 + 1);

		if ((loc * 2 + 2) < data.size())
			display(lvl + 1, loc * 2 + 2);


	}

	int nurseLoc() {
		int loc = -1;
		for (int i = 0; i < data.size(); i++) {
			if (data[i] <= 10) {
				loc = i;
				break;
			}

		}

		if (loc == -1)
			return loc;

		for (int i = loc; i < data.size(); i++) {
			if ((data[i] <= 10) && (data[i] > data[loc])) {
				loc = i;
			}
		}
		return loc;
	}

	void swap(int locA, int locB) {
		if ((locA >= data.size()) || (locB >= data.size()) || (locA < 0) || (locB < 0))
		{
			throw(std::range_error("Invalid Range"));
		}
		patient temp = data[locA];
		data[locA] = data[locB];
		data[locB] = temp;
	}

	std::vector<patient> data;

};

#endif