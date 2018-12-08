#include "EmergencyRoom.h"

void EmergencyRoom::run(unsigned int numTicks)
{

	for (unsigned int currentTick = 0; currentTick < numTicks; currentTick++) {
		std::cout << currentTick << "-" << queue.getSize() << std::endl;
		if (rand() % minutesPerPatient == 0)
			queue.push(Patient(currentTick));

		for (int i = 0; i < healers.size(); i++) {
			healers[i]->decTime();

			if (queue.docTop().getSeverity() != -1) {
				if (!(healers.at(i)->hasPatient())) {
					healers[i]->addPatient(queue, record);
					if(healers[i]->getPatient().getArrivalTime() != -1)
						patientWaitTimes.push_back(currentTick - (healers[i]->getPatient().getArrivalTime()));
				}
			}
		}
	}

	while (true) {
		std::cout << "Would you like to see the [r]ecord or a [s]pecific patient by name or [e]xit? ";
		std::string response;
		std::cin >> response;
		double sum = 0;
		switch (response[0]) {
		case 'r':
			record.display();
			std::cout << "Average Wait Time: ";
			for (int i = 0; i < patientWaitTimes.size(); i++) {
				sum += patientWaitTimes[i];
			}
			sum = sum / patientWaitTimes.size();
			std::cout << sum << std::endl;

			std::cout << "Patients left in queue: " << queue.getSize() << std::endl;
			std::cout << "Number of Treatments: " << patientWaitTimes.size() << std::endl;
			std::cout << "Number of Patients Treated: " << record.numPeople() << std::endl;
			break;
		case 's':
			std::cout << "What name? ";
			std::cin >> response;
			std::cout << record.getNumVisits(response) << std::endl;
			break;
		case 'e':
			return;
			break;
		default:
			break;
		}
	}

}

void EmergencyRoom::altrun(unsigned int numTicks)
{

	for (unsigned int currentTick = 0; currentTick < numTicks; currentTick++) {
		std::cout << currentTick << "-" << queue.getSize() << std::endl;
		if (rand() % minutesPerPatient == 0)
			queue.push(Patient(currentTick));

		for (int i = 0; i < healers.size(); i++) {
			healers[i]->decTime();

			if (queue.docTop().getSeverity() != -1) {
				if (!(healers.at(i)->hasPatient())) {
					healers[i]->addPatient(queue, record);
					if (healers[i]->getPatient().getArrivalTime() != -1)
						patientWaitTimes.push_back(currentTick - (healers[i]->getPatient().getArrivalTime()));
				}
			}
		}
	}
}

EmergencyRoom::EmergencyRoom(int numDoc, int numNurse, int rate):minutesPerPatient(rate)
{
	for (int i = 0; i < numDoc; i++)
		healers.push_back(new Doctor);

	for (int i = 0; i < numNurse; i++)
		healers.push_back(new Nurse);

}

std::string EmergencyRoom::getData()
{
	std::string x = "";
	double sum = 0;
	for (int i = 0; i < patientWaitTimes.size(); i++) {
		sum += patientWaitTimes[i];
	}
	sum = sum / patientWaitTimes.size();
	x = x + std::to_string(sum) + std::string(",") + std::to_string(minutesPerPatient);
	return x;
}
