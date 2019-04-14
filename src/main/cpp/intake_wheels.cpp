#include <intake_wheels.h>

using namespace frc;


// run this in TeleopPeriodic
void Intake_wheels :: update () {
	
if (joy1->GetRawAxis(2)== 1){
	talon_wheels->Set(ControlMode::PercentOutput, 1);
}
else if (joy1->GetRawAxis(3)==1){

	talon_wheels->Set(ControlMode::PercentOutput, -1);
}
else {
	talon_wheels->Set(ControlMode::PercentOutput, 0);
}

};
