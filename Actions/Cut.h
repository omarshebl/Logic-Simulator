#ifndef _CUT_H
#define _CUT_H

#include "action.h"


class Cut :	public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
public:
	Cut(ApplicationManager *pApp);
	virtual ~Cut(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif