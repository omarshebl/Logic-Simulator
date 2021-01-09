#ifndef _COPY_H
#define _COPY_H

#include "action.h"


class Copy :	public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
public:
	Copy(ApplicationManager *pApp);
	virtual ~Copy(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif