#ifndef DIAGNOSTIC_H
#define DIAGNOSTIC_H

#include <constants.h>
#include <typeinfo> // we may need this for type differentiation


class Diagnostic {
public:
	// initialize diagnostic
	Diagnostic (
		// receive parameters
		frc::Joystick *joy,
		TalonSRX *drivebase_left_enc,
		TalonSRX *drivebase_left_noenc,
		TalonSRX *drivebase_right_enc,
		TalonSRX *drivebase_right_noenc,
		TalonSRX *intake_wheels,
		TalonSRX *intake_clamp,
		TalonSRX *intake_pivot,
		TalonSRX *elevator_enc,
		TalonSRX *elevator_noenc,
		TalonSRX *climber_wheels
	):
		// initialize member variables
		joy(joy),// joystick
		talonCatalog{// all the talons arranged in an array
			drivebase_left_enc,
            drivebase_left_noenc,
            drivebase_right_enc,
            drivebase_right_noenc,
            intake_wheels,
            intake_clamp,
			intake_pivot,
            elevator_enc,
            elevator_noenc,
			climber_wheels
		}
	{
		// run on initialization
		std::cout<<"initializing diagnostic";
	};

	// run this in TestPeriodic
	void update();

private:
	// tick the ID number up or down
	void tickID(bool sign);
	// write to the currently selected talon using the builtin ID
	void writeToCurrentTalon(float speed);

	// all the talons are arranged in an array, so we can acces them by ID
	TalonSRX* talonCatalog[10]={};
	frc::Joystick *joy;

	// which talon is being tested right now?
	int currentID=0;
	// booleans for toggling buttons
	bool isPressedA=false;
	bool wasntPressedA=true;
	bool isPressedB=false;
	bool wasntPressedB=true;
};

#endif
