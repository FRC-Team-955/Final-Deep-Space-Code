#include <intake_clamp.h>

using namespace frc;


// run this in TeleopPeriodic
void Intake_clamp :: update () {

	//std::cout<<"updating intake_clamp";

	// collect values from joystick
	closeButton = joy1->GetRawButton( 5 );
	openButton = joy1->GetRawButton( 6 );

	//std::cout<<"\tclose-"<<closeButton<<"  open-"<<openButton;

	// container variable for motor speed; default speed=0
	clampSpeed = 0.0;

	// if either button is pressed, change the clamping velocity from zero
	if(openButton) clampSpeed =-.75;
	// if both buttons are pressed, "close" overwrites "open"
	if(closeButton) clampSpeed = .75;

	// write to motors
	talon_clamp->Set(ControlMode::PercentOutput, clampSpeed );

	//std::cout<<"\tclamp speed="<<clampSpeed<<std::endl;
};
