//NEEDS TO BE PID TUNED
#include <intake_pivot.h>

using namespace frc;

void Intake_pivot::run_intake_pivot ( int pivot_start, int pivot_high, int pivot_ball, int ball_out) {
if (mag_switch_claw->Get()==0){
	claw_pivot_talon_enc->SetSelectedSensorPosition(0,0,10);
}


if (mode==0){
//Switching Pos
	
	std::cout<<"automode"<<"current_pivot_pos="<<current_pivot_pos<<'\r';
	if (joy1->GetRawButton(3)==1 and toggle1 ==0) {
	current_pivot_pos = current_pivot_pos +1;
	toggle1 = 1;
	}
	if (joy1->GetRawButton(3)==0 and toggle1 ==1){
	toggle1 = 0;
	}
	if (joy1->GetRawButton(4)==1 and toggle2==0) {
	current_pivot_pos = current_pivot_pos -1;
	toggle2=1;
	}
	if (joy1->GetRawButton(4)==0 and toggle2 ==1){
	toggle2 = 0;
	}
//Determining Ball Pos
	
		if (current_pivot_pos >= 5){
		current_pivot_pos =4;
		}
		if (current_pivot_pos <=0){
		current_pivot_pos = 1;
		}
		if (current_pivot_pos ==1){
		claw_pivot_talon_enc->Set(ControlMode::Position, pivot_start);
		std::cout<<"set pos 0"<<std::endl;
		}
		if (current_pivot_pos ==2){
		claw_pivot_talon_enc->Set(ControlMode::Position, pivot_high);
		std::cout<<"set pos 2"<<std::endl;
		}
		if (current_pivot_pos==3){
		claw_pivot_talon_enc->Set(ControlMode::Position, pivot_ball);
		std::cout<<"setpos3"<<std::endl;
		}
		if (current_pivot_pos==4){
		claw_pivot_talon_enc->Set(ControlMode::Position, ball_out);
		std::cout<<"setpos3"<<std::endl;
		}
	
	


}
//Manual Mode
if (joy1->GetRawButton(8)==1 and mode_toggle1 == 0 and mode_toggle2 ==0){
	mode= 1;
	mode_toggle1 = 1;
}
if (joy1->GetRawButton(8)==0 and mode_toggle1 ==1){
	mode_toggle2=1;
	mode_toggle1=0;
}
if (joy1->GetRawButton(8)== 1 and mode_toggle2 == 1){
	mode = 0;
	mode_toggle2 =2;
}
if (joy1->GetRawButton(8)==0 and mode_toggle2 == 2){
	mode_toggle1=0;
	mode_toggle2=0;
}
if (mode ==1){
	claw_pivot_talon_enc->Set(ControlMode::PercentOutput, -1* joy1->GetRawAxis(5));
	std::cout<<"MANUAL MODE ON"<<'\r';
}

}

