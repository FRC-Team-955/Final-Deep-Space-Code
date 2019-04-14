#ifndef CLIMBER_H
#define CLIMBER_H

#include <constants.h>

class Climber {
public:
	Climber(
frc::Joystick *joy0, 
frc::DigitalInput *mag_switch_climber,
TalonSRX* climber_talon_arm, 
TalonSRX* climber_talon_wheel, 
frc::Servo *lock_servo)

: joy0(joy0), 
mag_switch_climber(mag_switch_climber),
climber_talon_arm(climber_talon_arm),
climber_talon_wheel(climber_talon_wheel), 
lock_servo(lock_servo){};
	bool servo_toggle1 =false;
	bool servo_toggle2=false;
	bool mag_switch_cancel = false;

void run_climber(double max_speed);
void servo_toggle();
private:
	frc::Joystick* joy0;
	TalonSRX* climber_talon_wheel;
	TalonSRX* climber_talon_arm;
	frc::Servo *lock_servo;
	frc::DigitalInput *mag_switch_climber;
};


#endif
