#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
#include <fstream>

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	bool Selected = false;
	int GateType;
	string m_Label;
public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	
	virtual void SaveGate(ofstream& filename)=0;
	
	GraphicsInfo GetGraphics();
	void SetGraphics(GraphicsInfo x);
	void SetSelect(bool x);
	bool GetSelect() const;

	void SetType(DsgnMenuItem input);
	int GetType();

	string GetLabel();
	void SetLabel(string input);
	
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
