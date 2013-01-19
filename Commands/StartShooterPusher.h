/**
* @file Shooter.cpp
* @brief Definition start shooter pusher command
* @author Nyle Rodgers
*/

#ifndef START_SHOOTER_PUSHER_H
#define START_SHOOTER_PUSHER_H

#include "../CommandBase.h"

/**
 * @brief Starts the pusher motor
 *
 * This should be run at the beginning of the match
 */
class StartShooterPusher: public CommandBase {
public:
	StartShooterPusher();
	virtual void Initialize();
	virtual bool IsFinished();
};

#endif // START_SHOOTER_PUSHER_H