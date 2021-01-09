#ifndef _PASTE_H
#define _PASTE_H

#include "action.h"
#include "AddGATE.h"


class Paste :	public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
public:
	Paste(ApplicationManager *pApp);
	virtual ~Paste(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif