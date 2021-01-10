#ifndef _ADD_GATE_H
#define _ADD_GATE_H

#include "action.h"
#include "AddANDgate2.h"
#include "AddANDgate3.h"
#include "AddBUFFERgate.h"
#include "AddLED.h"
#include "AddNANDgate2.h"
#include "AddNORgate2.h"
#include "AddNORgate3.h"
#include "AddNOTgate.h"
#include "AddORgate2.h"
#include "AddSWITCH.h"
#include "AddXNORgate2.h"
#include "AddXORgate2.h"
#include "AddXORgate3.h"



class AddGATE :	public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddGATE(ApplicationManager *pApp);
	virtual ~AddGATE(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Execute(int Type, GraphicsInfo GInfo, string label = "");

	virtual void Undo();
	virtual void Redo();


};

#endif