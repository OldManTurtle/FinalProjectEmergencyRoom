#include "Doctor.h"
#include "Nurse.h"
#include "Record.h"
#include "PatientQueue.h"

int main() {
	//fileio here
	//for loop 7x24x60 random chance to add someone to queue

	PatientQueue h;
	h.push(patient(3));
	h.push(patient(10));
	h.push(patient(13));
	h.push(patient(3));
	h.push(patient(10));
	h.push(patient(13));
	h.push(patient(20));
	h.display();
	system("pause");
	h.nursePop();
	h.display();
	system("pause");
	h.nursePop();
	h.nursePop();
	h.nursePop();
	h.nursePop();
	h.nursePop();
	h.nurseTop();
	h.display();


}