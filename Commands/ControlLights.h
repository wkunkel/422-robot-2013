#ifndef CONTROLLIGHTS_H
#define CONTROLLIGHTS_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Lucario
 */
class ControlLights: public CommandBase {
public:
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End() {};
	virtual void Interrupted() {};
};

#endif