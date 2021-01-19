#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/SpeedControllerGroup.h>

#include <rev/CANSparkMax.h>
#include "AHRS.h"

#include <ControllerManager.hpp>
#include <frc/DoubleSolenoid.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
  
  /* DriveTrain Spark Max and Motors*/
  // rev::CANSparkMax m_leftTopMotor{TopLeft, 
  //   rev::CANSparkMax::MotorType::kBrushless};

  // rev::CANSparkMax m_rightTopMotor{TopRight, 
  //   rev::CANSparkMax::MotorType::kBrushless};

  rev::CANSparkMax m_leftMiddleMotor{MiddleLeft, 
    rev::CANSparkMax::MotorType::kBrushless};

  rev::CANSparkMax m_rightMiddleMotor{MiddleRight, 
    rev::CANSparkMax::MotorType::kBrushless};

  rev::CANSparkMax m_leftBottomMotor{LeftBot, 
    rev::CANSparkMax::MotorType::kBrushless};

  rev::CANSparkMax m_rightBottomMotor{RightBot, 
    rev::CANSparkMax::MotorType::kBrushless};

  frc::SpeedControllerGroup RightMotors{  m_rightMiddleMotor, m_rightBottomMotor };
  frc::SpeedControllerGroup LeftMotors{  m_leftMiddleMotor, m_leftBottomMotor };
  frc::DoubleSolenoid shooterHood{10, 2, 5}; 


  FRC5572Controller Driver{0};

  static const int
  TopLeft = 1, // GOOD
  TopRight = 2, // GOOD
  
  MiddleLeft = 3, // GOOD
  MiddleRight = 4, // GOOD

  LeftBot = 5, // GOOD
  RightBot = 6, // GOOD

  LeftShoot = 7, // GOOD
  RightShoot = 8; // GOOD
  

};
