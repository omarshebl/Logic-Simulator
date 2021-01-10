#include "GUI/Output.h"
#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddANDgate3.h"
#include "Actions\AddBUFFERgate.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddNORgate2.h"
#include "Actions\AddNORgate3.h"
#include "Actions\AddNOTgate.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddXORgate3.h"
#include "Actions\AddLED.h"
#include "Actions\AddSWITCH.h"

#include "Actions\Select.h"
#include "Actions\Copy.h"
#include "Actions\Cut.h"
#include "Actions\Paste.h"
#include "Actions\Delete.h"
#include "Actions\Edit.h"
#include "Actions\Save.h"
#include "Actions\Load.h"
#include "Actions\AddGATE.h"
#include <iostream>
using namespace std;




int ApplicationManager::GetCompCount() const{
	return CompCount;
}

void ApplicationManager::SetCompCount(int x)  {
	CompCount = x;
}

Component** ApplicationManager::GetCompList() {
	return CompList;
}


Component* ApplicationManager::GetSelectedComp()
{
	Component* pointer = NULL;
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->GetSelect())
			pointer = CompList[i];
	}
	return pointer;
}

int ApplicationManager::SelectedCounter() const {
	int counter = 0;
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->GetSelect())
			counter++;
	}
	return counter;
}

void ApplicationManager::UnselectALL()  {
	for (int i = 0; i < CompCount; i++) {
		CompList[i]->SetSelect(false);
	}
}

void ApplicationManager::SetCopied(Component* cComp) {
	Clipboard = cComp;
}

void ApplicationManager::ResetCopied()
{
	Clipboard = NULL;
}

Component* ApplicationManager::GetCopied() {
	return Clipboard;
}

void ApplicationManager::SetCopiedCut(int input) {
	CopiedCut = input;
}

int ApplicationManager::GetCopiedCut() {
	return CopiedCut;
}

void ApplicationManager::SetCuttedGate(GraphicsInfo input)
{
	Clipboard->SetGraphics(input);
}

void ApplicationManager::SaveGates(ofstream& filename)
{
	for (int i = 0; i < CompCount; i++) {
		CompList[i]->SaveGate(filename);
	}
}

void ApplicationManager::LoadGates(ifstream& filename)
{
	int X, Y;
	string label;
	string compType;
	int gateType = 14;
	GraphicsInfo G;

	while (filename >> compType && compType != "-1") {
		if (filename.eof()) {
			break;
		}

		filename >> label;
		filename >> X >> Y;

		if (label == "&")
			label = "";

		if (compType == "AND2") {
			cout << "and";
			G = CreateGraphics(X, Y, ITM_AND2);
			gateType = ITM_AND2;
		}
		else if (compType == "OR2") {
			cout << "or";
			G = CreateGraphics(X, Y, ITM_OR2);
			gateType = ITM_OR2;
		}
		else if (compType == "NOT") {
			G = CreateGraphics(X, Y, ITM_NOT);
			gateType = ITM_NOT;
		}
		else if (compType == "NAND2") {
			cout << "nand";
			G = CreateGraphics(X, Y, ITM_NAND2);
			gateType = ITM_NAND2;
		}
		else if (compType == "NOR2") {
			cout << "nor";
			G = CreateGraphics(X, Y, ITM_NOR2);
			gateType = ITM_NOR2;
		}
		else if (compType == "XOR2") {
			cout << "xor";
			G = CreateGraphics(X, Y, ITM_XOR2);
			gateType = ITM_XOR2;
		}
		else if (compType == "XNOR2") {
			G = CreateGraphics(X, Y, ITM_XNOR2);
			gateType = ITM_XNOR2;
		}
		else if (compType == "AND3") {
			G = CreateGraphics(X, Y, ITM_AND3);
			gateType = ITM_AND3;
		}
		else if (compType == "NOR3") {
			G = CreateGraphics(X, Y, ITM_NOR3);
			gateType = ITM_NOR3;
		}
		else if (compType == "XOR3") {
			G = CreateGraphics(X, Y, ITM_XOR3);
			gateType = ITM_XOR3;
		}
		else if (compType == "BUFFER") {
			G = CreateGraphics(X, Y, ITM_BUFFER);
			gateType = ITM_BUFFER;
		}
		else if (compType == "SWITCH") {
			G = CreateGraphics(X, Y, ITM_SWITCH);
			gateType = ITM_SWITCH;
		}
		else if (compType == "LED") {
			G = CreateGraphics(X, Y, ITM_LED);
			gateType = ITM_LED;
		}
		if (gateType != 14) {
			cout << "hi";
			AddGATE* pAct = new AddGATE(this);
			pAct->Execute(gateType, G, label);
			delete pAct;
		}
	}


}

void ApplicationManager::DeleteAll()
{
	for (int i = 0; i < CompCount; i++) {
		delete CompList[i];
		CompList[i] = NULL;
	}
	CompCount = 0;
}

ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	SWITCHSC = 0;
	LEDSC = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	if (pComp->GetType() == ITM_SWITCH)
		SWITCHSC++;

	if (pComp->GetType() == ITM_LED)
		LEDSC++;

	CompList[CompCount++] = pComp;		
}
void ApplicationManager::DeleteLED()
{
	LEDSC--;
}
void ApplicationManager::DeleteSWITCH()
{
	SWITCHSC--;
}
bool ApplicationManager::CheckOverlap(int Cx, int Cy)
{
	GraphicsInfo Check;
	bool Checker = false;
	for (int i = 0; i < CompCount; i++) {
		Check = CompList[i]->GetGraphics();
		if (((Cx > (Check.x1 - UI.COMP_Width / 2)) && (Cx < (Check.x2 + UI.COMP_Width / 2))) && ((Cy > (Check.y1 - UI.COMP_Height / 2)) && (Cy < (Check.y2 + UI.COMP_Height / 2)))) {
			Checker = true;
		}
	}
	return Checker;
}
bool ApplicationManager::CheckDrawArea(int Cx, int Cy)
{
	bool checker = false;
	if ((Cy >= (UI.ToolBarHeight + UI.COMP_Height / 2)) && Cy < UI.height - (UI.StatusBarHeight + UI.COMP_Height / 2) && Cx >(UI.COMP_Width / 2) && Cx < (UI.width - UI.COMP_Width / 2)) {
		checker = true;
	}
	return checker;
}
bool ApplicationManager::GetClickedComponent(int Cx, int Cy, Component*& pointer)
{
	GraphicsInfo Check;
	bool Checker = false;
	for (int i = 0; i < CompCount; i++) {
		Check = CompList[i]->GetGraphics();
		if (((Cx > Check.x1) && (Cx < Check.x2)) && ((Cy > Check.y1) && (Cy < Check.y2))) {
			Checker = true;
			pointer = CompList[i];
		}
	}
	return Checker;
}
GraphicsInfo ApplicationManager::CreateGraphics(int Cx, int Cy, int GateType)
{
	GraphicsInfo output;
	int Len = UI.COMP_Width;
	if (GateType == ITM_SWITCH || GateType == ITM_LED) {
		Len = UI.COMP2_Width;
	}
	int Wdth = UI.COMP_Height;
	output.x1 = Cx - Len / 2;
	output.x2 = Cx + Len / 2;
	output.y1 = Cy - Wdth / 2;
	output.y2 = Cy + Wdth / 2;
	return output;
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////


void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;

		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(this);
			break;

		case ADD_Buff:
			pAct = new AddBUFFERgate(this);
			break;

		case ADD_INV:
			pAct = new AddNOTgate(this);
			break;

		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;

		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;

		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;

		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			break;

		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			break;

		case ADD_XOR_GATE_3:
			pAct = new AddXORgate3(this);
			break;

		case ADD_NOR_GATE_3:
			pAct = new AddNORgate3(this);
			break;

		case ADD_LED:
			pAct = new AddLED(this);
			break;

		case ADD_Switch:
			pAct = new AddSWITCH(this);
			break;

		case ADD_CONNECTION:
			//TODO: Create AddConection Action here
			break;

		case SELECT:
			pAct = new Select(this);
			break;

		case COPY:
			pAct = new Copy(this);
			break;

		case CUT:
			pAct = new Cut(this);
			break;

		case PASTE:
			pAct = new Paste(this);
			break;

		case DEL:
			pAct = new Delete(this);
			break;

		case EDIT_Label:
			pAct = new Edit(this);
			break;

		case SAVE:
			pAct = new Save(this);
			break;

		case LOAD:
			pAct = new Load(this);
			break; 

		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	OutputInterface->ClearDrawingArea();
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(OutputInterface);

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}