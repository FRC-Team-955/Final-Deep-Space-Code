//NEEDS TO BE PID TUNED
#ifndef INTAKE_PIVOT_H
#define INTAKE_PIVOT_H

#include <constants.h>

class Intake_pivot {
public:
	Intake_pivot(
TalonSRX* claw_pivot_talon_enc,
frc::Joystick* joy1,
frc::DigitalInput *mag_switch_claw
)
:
claw_pivot_talon_enc(claw_pivot_talon_enc),
mag_switch_claw(mag_switch_claw),
joy1 (joy1){};
int toggle1 = 0;
int toggle2 =0;
int mode = 0;
int mode_toggle1 =0;
int mode_toggle2 =0;
int current_pivot_pos =1;

void run_intake_pivot (int pivot_start, int pivot_high, int pivot_ball, int ball_out);

private:
TalonSRX* claw_pivot_talon_enc;
frc::Joystick* joy1;
frc::DigitalInput * mag_switch_claw;

		






};
#endif
