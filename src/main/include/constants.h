#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <frc/WPILib.h>
#include <frc/Joystick.h>
#include<frc/Servo.h>
#include <ctre/Phoenix.h>
#include<frc/DigitalInput.h>
#include <iostream>
#include <math.h>


// talon numbers
const int drivebase_left_enc_talonnum = 0;
const int drivebase_left_noenc_talonnum = 1;
const int drivebase_right_enc_talonnum = 2;
const int drivebase_right_noenc_talonnum = 3;
const int intake_wheels_left_talonnum = 3;
const int intake_wheels_right_talonnum = 2;
const int intake_wheels_talonnum = 2;
const int intake_clamp_talonnum = 3;
const int intake_pivot_talonnum = 3;
const int elevator_enc_talonnum  = 7;
const int elevator_noenc_talonnum = 8;
const int climber_wheels_talonnum = 8;


/*			Joystick #0
	  A2           A3			  1,2=	out/in climber
   _/III\5_______/III\6				3=	
  /  A1             4  \			4=	
 /  (9)A0  7 H 8  3   2 \<-trg		5=	
 \       ^          1   /<-top		6=	
 /     <POV>    A5      \			7=	
/        v     (0)A4     \			8=	
\      ____________      /		A1,A4=	drive
 \____/            \____/
*/
// joystick 0 axis numbers
const int drivebase_move_joynum = 1;
const int drivebase_turn_joynum = 4;
const int servo_toggle_joynum = 2;
const int climber_wheels_control_joynum =1;
const int climber_arm_lowering = 3;
const int climber_arm_raising =4;
// joystick 0 button numbers

// joystick 0 axis/button numbers for diagnostic mode
const int diagnostic_test_joynum = 1;
const int diagnostic_tickup_joynum = 1;
const int diagnostic_tickdown_joynum = 2;


/*			Joystick #1
	  A2           A3			  1,2=	up/down tick elevator
   _/III\5_______/III\6				3=	intake lvl toggle
  /  A1             4  \			4=	\\hatch sequence
 /  (9)A0  7 H 8  3   2 \<-trg	  5,6=	intake out/in
 \       ^          1   /<-top		7=	
 /     <POV>    A5      \		   A1=	
/        v     (0)A4     \		A2,A3=	
\      ____________      /		   A5=	
 \____/            \____/
*/
// joystick 1 axis numbers
const int elevator_up_joynum = 2;
const int elevator_down_joynum = 3;
// joystick 1 button numbers
const int intake_wheels_in_joynum = 3;
const int intake_wheels_out_joynum = 4;
const int intake_clamp_close_joynum = 2;
const int intake_clamp_open_joynum = 3;



// wheel velocities
const float drivebase_max_speed = .75;
const float intake_wheels_speed = 0.4;
const float intake_clamp_speed  = 0.4;


// exponents for variable motion values- this way, most of the joystick's range will correspond to low values, and only the extremes will make high speeds
const int drivebase_move_exp = 5;
const int drivebase_turn_exp = 5;
const int elevator_up_exp = 2;
const int elevator_down_exp = 2;

// raise number to given exponent, but preserve its sign. I made it a preproccessor macro so the compiler wouldn't complain about defining a function multiple times, and it is faster anyway.
#define signedpow(val,exp) copysignf(powf(val,exp),val)

#endif
