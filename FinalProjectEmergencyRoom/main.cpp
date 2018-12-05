#include "Doctor.h"
#include "Nurse.h"
#include "Record.h"
#include "PatientQueue.h"

int main() {
	//fileio here
	//for loop 7x24x60 random chance to add someone to queue
	patient::initNames();

	Record r;
	r.addName("chris", 20);
	r.addName("chris", 1);
	r.addName("Aiden", 5);
	r.addName("Abby", 16);
	r.addName("Bell", 6);
	
	r.display();
	

	


}