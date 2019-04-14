#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <constants.h>


class Elevator {
public:
	Elevator(
TalonSRX* talon_elevator_enc,
frc::DigitalInput* mag_switch_elevator,
frc::Joystick* joy1
)
:
talon_elevator_enc(talon_elevator_enc),
mag_switch_elevator(mag_switch_elevator),
joy1(joy1){};
int current_elevator_pos = 0;
int toggle1 =0;
int toggle2 =0;

int mode = 0;
int mode_toggle1 =0;
int mode_toggle2= 0;
void run_elevator ( double rocket_low_ball_pos,  double rocket_medium_ball_pos, double rocket_high_ball_pos);
private:
TalonSRX* talon_elevator_enc;
frc::DigitalInput *mag_switch_elevator;
frc::Joystick* joy1;

};



#endif
