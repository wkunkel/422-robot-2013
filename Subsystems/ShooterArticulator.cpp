/**
 * @file ShooterArticulator.cpp
 * @brief Implementation of the Shooter articulator subsystem
 * @author Nyle Rodgers
 */
#define _USE_MATH_DEFINES
#include <cmath>

#include "ShooterArticulator.h"
#include "../Commands/OperateShooterArticulator.h"
#include "../Robotmap.h"

const float PI = 3.14159;

// TODO: put actual numbers in here
const float ShooterArticulator::ZERO_RADIAN_VOLTAGE = 0;
const float ShooterArticulator::ONE_RADIAN_VOLTAGE = 1;
const float ShooterArticulator::ENCODER_RESOLUTION = 64;


ShooterArticulator::ShooterArticulator() : 
	Subsystem("ShooterArticulator"),
	motor( new Talon( DIGITAL_MODULE_PORT,
			          ARTICULATOR_MOTOR_CHANNEL ) ),
	
	encoder( new Encoder( DIGITAL_MODULE_PORT,
	                      ARTICULATOR_ENCODER_CHANNEL_A,
	                      DIGITAL_MODULE_PORT,
	                      ARTICULATOR_ENCODER_CHANNEL_B,
	                      false,
	                      Encoder::k1X  ) ),
	potentiometer( new AnalogChannel( DIGITAL_MODULE_PORT,
			                          ARTICULATOR_POTENTIOMETER_CHANNEL ) ),
	topLimitSwitch( new DigitalInput( DIGITAL_MODULE_PORT,
			                          ARTICULATOR_TOP_LIMIT_SWITCH_CHANNEL ) ),
	bottomLimitSwitch( new DigitalInput( DIGITAL_MODULE_PORT,
			                             ARTICULATOR_BOTTOM_LIMIT_SWITCH_CHANNEL ) ) {
	encoder->SetDistancePerPulse( 2 * PI / ENCODER_RESOLUTION );
	encoder->Start();
	
}
    
void ShooterArticulator::InitDefaultCommand() {
	SetDefaultCommand( new OperateShooterArticulator() );
}

/**
 * Get the current angle, in radians, above horizontal
 *
 * @author Nyle Rodgers
 */ 
double ShooterArticulator::getAngle() {
	return encoder->GetDistance();
//	return ( ( potentiometer->GetAverageVoltage() - ZERO_RADIAN_VOLTAGE) 
//			   / ONE_RADIAN_VOLTAGE );
}

/**
 * Move the acticulator up at full speed
 *
 * @author Nyle Rodgers
 */
void ShooterArticulator::moveUp() {
	//if( topLimitSwitch->Get() ) {
		motor->Set(1.0);
	//} else {
	//	stop();
	//}
}

/**
 * Move the articulator down at full speed
 *
 * @author Nyle Rodgers
 */
void ShooterArticulator::moveDown() {
	//if( bottomLimitSwitch->Get() ) {
		motor->Set(-1.0);
	//} else {
	//	stop();
	//}
}

/**
 * Stop moving the articulator
 *
 * @author Nyle Rodgers
 */
void ShooterArticulator::stop() {
	motor->Set(0.0);
}
