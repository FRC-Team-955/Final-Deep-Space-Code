#include <iostream>
#include <drivebase.h>

using namespace frc;


// run this in TeleopPeriodic
void Drivebase :: full_speed () {
	std::cout<<"Fast"<<std::endl;
	//std::cout<<"updating drivebase";

	// collect values from joystick
	move = -1 *joy0->GetRawAxis( drivebase_move_joynum );
	turn = joy0->GetRawAxis( drivebase_turn_joynum );

	// skew the values to get tiny motion with the belly of the joystick range and high values at the extremes
	move = signedpow(move,drivebase_move_exp);
	turn = signedpow(turn,drivebase_turn_exp);

	//std::cout<<"\tskewed move = "<<move<<"\tskewed turn = "<<turn;

	// scale the values based on the max allowed speed
	move *= .75;
	turn *= .75;

	// write to motors
	talon_left_enc->Set(ControlMode::PercentOutput,  move+turn);
	talon_right_enc->Set(ControlMode::PercentOutput, -move+turn);

	//std::cout<<"\tleft moving at speed "<<move-turn<<"\tright moving at speed "<<move+turn<<std::endl;
}

void Drivebase :: choice_speed (float max_speed) {
	std::cout<<"Slow"<<std::endl;
	//std::cout<<"updating drivebase";

	// collect values from joystick
	move = -1 *joy0->GetRawAxis( drivebase_move_joynum );
	turn = joy0->GetRawAxis( drivebase_turn_joynum );

	// skew the values to get tiny motion with the belly of the joystick range and high values at the extremes
	move = signedpow(move,drivebase_move_exp);
	turn = signedpow(turn,drivebase_turn_exp);

	//std::cout<<"\tskewed move = "<<move<<"\tskewed turn = "<<turn;

	// scale the values based on the max allowed speed
	move *= max_speed;
	turn *= max_speed;

	// write to motors
	talon_left_enc->Set(ControlMode::PercentOutput,  move+turn);
	talon_right_enc->Set(ControlMode::PercentOutput, -move+turn);

	//std::cout<<"\tleft moving at speed "<<move-turn<<"\tright moving at speed "<<move+turn<<std::endl;
}

void Drivebase :: update(){
	state_from_button = joy0->GetRawButton(6);
	if (state_from_button == 0 && button_state == 0 && toggle_state == 0)
	{
		full_speed();
		//choice_speed(0.40);
	}
	if (state_from_button == 1 && button_state == 0)
	{
		toggle_state = 1;
	}
	if (state_from_button == 0 && toggle_state == 1)
	{
		button_state = 1;
		choice_speed(0.40);
		//full_speed();
	}
	if (state_from_button == 1 && button_state == 1)
	{
		toggle_state = 0;
	}
	if (state_from_button == 0 && button_state == 1 && toggle_state == 0)
	{
		full_speed();
		//choice_speed(0.40);
		button_state = 0;
	}
}

//can you please check this code?
