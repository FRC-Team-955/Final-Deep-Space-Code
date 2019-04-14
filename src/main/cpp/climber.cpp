#include <climber.h>

using namespace frc;
void Climber::servo_toggle(){

	if (joy0->GetRawButton(servo_toggle_joynum)==1 and !servo_toggle1 and !servo_toggle2){
		//unlocks servo
		lock_servo->Set(1.0);
		servo_toggle1 = true;
	}
	if (joy0->GetRawButton(servo_toggle_joynum)==0 and servo_toggle1 ){
		servo_toggle2 = true;
	}
	if (joy0->GetRawButton(servo_toggle_joynum)==1 and servo_toggle2 and servo_toggle1){
		//lock_servo
		lock_servo->Set(0);
		servo_toggle1 = false;
	}
	if (joy0->GetRawButton(servo_toggle_joynum)==0 and servo_toggle2 and !servo_toggle1){
		servo_toggle1 = false;
		servo_toggle2 = false;
	}

}
void Climber::run_climber (double max_speed){


	servo_toggle();
//sets a button to write to ClimberWheel
climber_talon_wheel->Set(ControlMode::PercentOutput, max_speed*joy0->GetRawButton(5));
//lowers and brings up the climberArm
if (climber_talon_arm->GetSelectedSensorPosition(0)<-1300){
	climber_talon_arm->Set(ControlMode::PercentOutput, -1*joy0->GetRawButton(2));
}
else if (joy0->GetRawButton(1)==1){
	climber_talon_arm->Set(ControlMode::PercentOutput, 1 );
}
else if (joy0->GetRawButton(2)==1){
	climber_talon_arm->Set(ControlMode::PercentOutput, -1 );
}
else {
	climber_talon_arm->Set(ControlMode::PercentOutput, 0);
}





if (mag_switch_climber->Get()==0){
climber_talon_arm->SetSelectedSensorPosition(0,0,10);
}
//MAG switch hard stop
if (mag_switch_climber->Get() == 0 and !mag_switch_cancel){
	climber_talon_arm->Set(ControlMode::PercentOutput, 0);
} 
//Releases MagSwitch so talon can move. It is a PRESS AND HOLD FUNCTION!
if (joy0->GetRawButton(6)==1 ){
	mag_switch_cancel = true;
}
else {
	mag_switch_cancel = false;
}
}
