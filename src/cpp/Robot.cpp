#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <iostream>
#include <math.h>
#include <Solenoid.h>

#define TALON_TIMEOUT_MILLISECONDS 10

// TODO: Set the SRX up as a regular talon...?
// Set up velocity controls
// Set the feedback device to the encoder

class Robot : public IterativeRobot {
	private:

		TalonSRX *talon_left_noenc, *talon_left_enc, *talon_right_enc, *talon_right_noenc;
		Joystick *joystick;
		Solenoid *solenoid, *solenoid_1;

		bool buttonstate_Left = false;
        bool Left_Button = false;
        bool Turning_Left_Button_On = false;
        bool Toggle_On_Variable_Left = false;
        bool Turning_Left_Button_Off = false;
        bool Toggle_Off_Variable_Left = false;

        bool buttonstate_B = false;
        bool B_Button = false;
        bool Turning_B_Button_On = false;
        bool Toggle_On_Variable_B = false;
        bool Turning_B_Button_Off = false;
        bool Toggle_Off_Variable_B = false;
		
		void RobotInit() { 

			talon_left_enc = new TalonSRX(7);
			talon_right_enc = new TalonSRX(2);
			talon_right_noenc = new TalonSRX(3);
			talon_left_noenc = new TalonSRX(5);
			solenoid = new Solenoid(0);
			solenoid_1 = new Solenoid(1);

			talon_right_noenc->Set(ControlMode::Follower, 2);
			talon_left_noenc->Set(ControlMode::Follower, 7);
			joystick = new Joystick(0);

			std::cout<<"Oh la la! Un cochon. Il est tres beau. Il est plus beau que des cochons! Je s'adore!"<<std::endl;
			std::cout<<"I'm yes a Pig!"<<std::endl;

		}

		void TeleopInit() {
			std::cout<<"I'm a PIGGGGGGGGGGG!"<<std::endl;
		}

		void TeleopPeriodic() {
			bool Getting_the_pneumatic_value = solenoid->Get();
			bool Getting_the_value_of_the_left_button = joystick->GetRawButton(1);
			Left_Button = Getting_the_value_of_the_left_button;

            if (buttonstate_Left == 0)
            {
                if (Left_Button)
                {
                    Turning_Left_Button_On = 1;
                    Toggle_On_Variable_Left = 0;
                }
                else if (Turning_Left_Button_On)
                {
                    Toggle_On_Variable_Left = 1;
                    buttonstate_Left = 1;  
                }
            }
            if (Turning_Left_Button_On){
                solenoid->Set(1);
               
			  }
            if (Toggle_On_Variable_Left)
            {
                if (Left_Button)
                {
                    Turning_Left_Button_Off = 1;
                    Toggle_Off_Variable_Left = 0;
                }
                else if (Turning_Left_Button_Off)
                {
                    Toggle_Off_Variable_Left = 1;
                }
            }
            if (Turning_Left_Button_Off)
            {
                solenoid->Set(0);
              
            }
            if (Toggle_Off_Variable_Left)
            {
                buttonstate_Left = 0;
                Turning_Left_Button_Off = 0;
                Toggle_Off_Variable_Left = 0;
                Toggle_On_Variable_Left = 0;
                Turning_Left_Button_On = 0;
            }

            /////////////

            bool Getting_the_value_of_the_B_button = joystick->GetRawButton(2);
			B_Button = Getting_the_value_of_the_B_button;

            if (buttonstate_B == 0)
            {
                if (B_Button)
                {
                    Turning_B_Button_On = 1;
                    Toggle_On_Variable_B = 0;
                }
                else if (Turning_B_Button_On)
                {
                    Toggle_On_Variable_B = 1;
                    buttonstate_B = 1;  
                }
            }
            if (Turning_B_Button_On){
                solenoid_1->Set(1);
			  }
            if (Toggle_On_Variable_B)
            {
                if (B_Button)
                {
                    Turning_B_Button_Off = 1;
                    Toggle_Off_Variable_B = 0;
                }
                else if (Turning_B_Button_Off)
                {
                    Toggle_Off_Variable_B = 1;
                }
            }
            if (Turning_B_Button_Off)
            {
                solenoid_1->Set(0);
            }
            if (Toggle_Off_Variable_B)
            {
                buttonstate_B = 0;
                Turning_B_Button_Off = 0;
                Toggle_Off_Variable_B = 0;
                Toggle_On_Variable_B = 0;
                Turning_B_Button_On = 0;
            }
			
 			talon_left_enc->Config_kF(0, std::atof(SmartDashboard::GetString("DB/String 0", "0.0").c_str()), TALON_TIMEOUT_MILLISECONDS);
			talon_left_enc->Config_kP(0, std::atof(SmartDashboard::GetString("DB/String 1", "0.0").c_str()), TALON_TIMEOUT_MILLISECONDS);
			talon_left_enc->Config_kI(0, std::atof(SmartDashboard::GetString("DB/String 2", "0.0").c_str()), TALON_TIMEOUT_MILLISECONDS);
			talon_left_enc->Config_kD(0, std::atof(SmartDashboard::GetString("DB/String 3", "0.0").c_str()), TALON_TIMEOUT_MILLISECONDS);

			talon_right_enc->Config_kF(0, std::atof(SmartDashboard::GetString("DB/String 5", "0.0").c_str()), TALON_TIMEOUT_MILLISECONDS);
			talon_right_enc->Config_kP(0, std::atof(SmartDashboard::GetString("DB/String 6", "0.0").c_str()), TALON_TIMEOUT_MILLISECONDS);
			talon_right_enc->Config_kI(0, std::atof(SmartDashboard::GetString("DB/String 7", "0.0").c_str()), TALON_TIMEOUT_MILLISECONDS);
			talon_right_enc->Config_kD(0, std::atof(SmartDashboard::GetString("DB/String 8", "0.0").c_str()), TALON_TIMEOUT_MILLISECONDS);
		}

		void AutonomousInit() {}

		void AutonomousPeriodic() {}

		void DisabledInit() {
			
			std::cout<<"Hi, I'm a pig. Oink"<<std::endl;
		}

		void TestInit(){

		}

		void TestPeriodic() {

		}
		
};

START_ROBOT_CLASS(Robot);