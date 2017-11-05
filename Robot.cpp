#include <iostream>
#include <memory>
#include <string>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include <cstdlib>
#include <Joystick.h>
#include <CANTalon.h>
#include <time.h>
#include <XboxController.h>
#include <RobotDrive.h>
//================================================================================
//                         Romell the III                                       //
//================================================================================

class Robot: public frc::IterativeRobot {
public:
	void RobotInit() {

		//when the robot becomes activated it will initalize
				LeftStick = new Joystick(1);
				RightStick = new Joystick(0);

				xbox = new Joystick(2);
	}

	/*
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString line to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional comparisons to the
	 * if-else structure below with additional strings. If using the
	 * SendableChooser make sure to add them to the chooser code above as well.
	 */
	void AutonomousInit() override {

	}

	void AutonomousPeriodic() {

	}

	void TeleopInit() {
		myDrive->SetExpiration(20000);

		//Safety Codes
				myDrive->SetSafetyEnabled(false);
	}

	void TeleopPeriodic() {

				//=============   Drive   =================
				LeftStickInput = LeftStick->GetY();
				RightStickInput = RightStick->GetY();

				LeftStickInput = LeftStickInput * -0.5;
				RightStickInput = RightStickInput * -0.5;

				if(RightStick->GetRawButton(1)==true)
				{
					LeftStickInput = RightStick->GetY();


				}
				if(LeftStick->GetRawButton(2)==true)
				{
					LeftStickInput = LeftStickInput / 2;
					RightStickInput = RightStickInput / 2;
				}
	}

	void TestPeriodic() {
		lw->Run();
	}

private:
	frc::LiveWindow* lw = LiveWindow::GetInstance();

		CANTalon *DriveL1;
		CANTalon *DriveL2;

		CANTalon *DriveR1;
		CANTalon *DriveR2;
		RobotDrive *myDrive;

		Joystick *xbox;

		Joystick *LeftStick;

		float LeftStickInput = 0.0;
		Joystick *RightStick;

		float RightStickInput = 0.0;
};

START_ROBOT_CLASS(Robot)
