#include "EmergencyRoom.h"

void EmergencyRoom::run(int numTicks)
{
	patient::initNames();

	for (int currentTick = 0; currentTick < numTicks; currentTick++) {
		if (currentTick % minutesPerPatient)
			queue.push(patient());
		for (int i = 0; i < healers.size(); i++) {
			--healers[i];

			if (!(healers.at(i)->hasPatient()))
				healers[i]->addPatient(queue);
		}
	}

}

EmergencyRoom::EmergencyRoom(int numDoc, int numNurse)
{
	for (int i = 0; i < numDoc; i++)
		healers.push_back(new Doctor);

	for (int i = 0; i < numNurse; i++)
		healers.push_back(new Nurse);

}
