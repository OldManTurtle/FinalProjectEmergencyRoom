#include "EmergencyRoom.h"

void EmergencyRoom::run(int numTicks)
{
	patient::initNames();

	for (int currentTick = 0; currentTick < numTicks; currentTick++) {
		if (currentTick % minutesPerPatient)
			queue.push(patient(currentTick));	
		for (int i = 0; i < healers.size(); i++) {
			--healers[i];

			if (!(healers.at(i)->hasPatient())) {
				patientWaitTimes.push_back(currentTick-healers[i]->getPatient().getArrivalTime());
				healers[i]->addPatient(queue);
			}
		}
	}

	while (true) {
		std::cout << "Would you like to see the [r]ecord or a [s]pecific patient by name or [e]xit? ";
		std::string response;
		std::cin >> response;
		switch (response[0]) {
		case 'r':
			record.display();
			break;
		case 's':
			std::cout << "What name? ";
			std::cin >> response;
			record.getNumVisits(response);
			break;
		case 'e':
			return;
			break;
		default:
			break;
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
