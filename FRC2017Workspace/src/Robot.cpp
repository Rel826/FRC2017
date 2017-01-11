#include "WPILib.h"
#include "Joystick.h"
#include "MyJoystick.h"
//rachel test
#define USB0 0
#define USB1 1
#define USB2 2

#define PWM0 0
#define PWM1 1
#define PWM2 2
#define PWM3 3
#define PWM4 4
#define PWM5 5
#define PWM6 6
#define PWM7 7
#define PWM8 8
#define PWM9 9

#define DIO0 0
#define DIO1 1
#define DIO2 2
#define DIO3 3
#define DIO4 4
#define DIO5 5
#define DIO6 6
#define DIO7 7
#define DIO8 8
#define DIO9 9

#define PCM0 0
#define PCH0 0
#define PCH1 1

#define ANALOG0 0

#define PULSEIN -0.03865131578
#define PULSECM -0.09815789473

class Robot: public IterativeRobot
{
	RobotDrive drive;
	Encoder driveEncoder;
	Joystick rightStick;
	Joystick leftStick;
	Compressor compressor;

	bool enabled;
	bool pressureStatus;
	float current;

	enum {
		step0,
		done
	} autoStep = step0;

	Robot()
	{
		drive.SetExpiration(0.1);
		rightStick(USB0);
		leftStick(USB1);
	}

	~Robot(){}

private:
	void RobotInit(){
		CameraServer::GetInstance()->StartAutomaticCapture("cam0");
		driveEncoder.Reset();

		driveEncoder.SetDistancePerPulse(PULSEIN);
		enabled = compressor.Enabled();
		pressureStatus = compressor.GetPressureSwitchValue();
		current = compressor.GetCompressorCurrent();

		compressor.SetClosedLoopControl(true);
	}


	void AutonomousInit()
	{
		autoStep = step0;
		driveEncoder.Reset();
	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		drive.TankDrive(rightStick, leftStick);
	}

	void TestPeriodic()
	{

	}
};

START_ROBOT_CLASS(Robot)
