#ifndef PID_H
#define PID_H

#include <constants.h>


class PID {
public:
	PID(
TalonSRX*talon_right_enc,
TalonSRX*talon_left_enc,
TalonSRX*claw_pivot_talon_enc,

TalonSRX*talon_elevator_enc

		)
	:
	talon_right_enc(talon_right_enc),
	talon_left_enc(talon_left_enc),
	claw_pivot_talon_enc(claw_pivot_talon_enc),
	
	talon_elevator_enc(talon_elevator_enc){};
	

	
	void PID_drivebase200();
	void PID_drivebase10();
	void PID_claw_elevator();
private:
TalonSRX*talon_right_enc;
TalonSRX*talon_left_enc;
TalonSRX*claw_pivot_talon_enc;

TalonSRX*talon_elevator_enc;


};

#endif
