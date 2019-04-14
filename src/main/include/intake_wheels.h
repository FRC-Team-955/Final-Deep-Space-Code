#ifndef INTAKE_WHEELS_H
#define INTAKE_WHEELS_H

#include <constants.h>


class Intake_wheels {
public:
	// initialize intake_wheels
	Intake_wheels(
		// receive parameters
		frc::Joystick *joy1,
		TalonSRX *talon_wheels
	):
		// initialize member variables
		joy1(joy1),
		talon_wheels(talon_wheels)
	{
		// run on initialization
		std::cout<<"initializing intake_wheels";
	};

	// run this in TeleopPeriodic
	void update();
private:
	frc::Joystick *joy1;
	TalonSRX *talon_wheels;
	bool inButton=false, outButton=false;
	float suckSpeed=intake_wheels_speed;
};

#endif
