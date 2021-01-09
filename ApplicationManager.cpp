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





int ApplicationManager::GetCompCount() const{
	return CompCount;
}

void ApplicationManager::SetCompCount(int x)  {
	CompCount = x;
}

Component** ApplicationManager::GetCompList() {
	return CompList;
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
	Copied = cComp;
}

Component* ApplicationManager::GetCopied() {
	return Copied;
}
ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
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