#ifndef DRIVEBASE_H
#define DRIVEBASE_H

#include <constants.h>


class Drivebase {
public:
	// initialize drivebase
	Drivebase(
		// receive parameters
		frc::Joystick *joy0,
		TalonSRX *talon_left_enc,
		TalonSRX *talon_left_noenc,
		TalonSRX *talon_right_enc,
		TalonSRX *talon_right_noenc
	):
		// initialize members with given parameters
		joy0(joy0),
		talon_left_enc(talon_left_enc),
		talon_left_noenc(talon_left_noenc),
		talon_right_enc(talon_right_enc),
		talon_right_noenc(talon_right_noenc)
	{
		// run on initialization
		std::cout<<"initializing drivebase";
		// setup talons so they run in pairs
		talon_left_noenc->Set(ControlMode::Follower, talon_left_enc->GetDeviceID() );
		talon_right_noenc->Set(ControlMode::Follower, talon_right_enc->GetDeviceID() );
		// print encoder motor ID's
		std::cout<<"\ttalon_left_enc ID="<<talon_left_enc->GetDeviceID();
		std::cout<<"\ttalon_right_enc ID="<<talon_right_enc->GetDeviceID()<<std::endl;
	};

	//run this in TeleopPeriodic
	void full_speed();
	void choice_speed(float max_speed);
	void update();
	
private:
	frc::Joystick *joy0;
	TalonSRX *talon_left_enc, *talon_left_noenc;
	TalonSRX *talon_right_enc, *talon_right_noenc;
	float move=0.0, turn=0.0;
	bool state_from_button = 0;
	bool button_state = 0;
	bool toggle_state = 0;
};

#endif
