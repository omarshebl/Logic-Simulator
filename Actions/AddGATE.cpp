#include "AddGATE.h"
#include "..\ApplicationManager.h"

AddGATE::AddGATE(ApplicationManager *pApp):Action(pApp)
{
}

AddGATE::~AddGATE(void)
{
}

void AddGATE::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message

	//Wait for User Input

	//Clear Status Bar
	
}

void AddGATE::Execute(int x)
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();


	Action* pAct = NULL;

	switch (x) {
		case ITM_SWITCH:
			pAct = new AddANDgate2(pManager);
			break;

		case ITM_LED:
			//DO THIS
			break;

		case ITM_AND2:
			//DO THIS
			break;

		case ITM_OR2:
			//DO THIS
			break;

		case ITM_NAND2:
			//DO THIS
			break;

		case ITM_NOR2:
			//DO THIS
			break;

		case ITM_XOR2:
			//DO THIS
			break;

		case ITM_XNOR2:
			//DO THIS
			break;

		case ITM_NOT:
			//DO THIS
			break;

		case ITM_BUFFER:
			//DO THIS
			break;

		case ITM_AND3:
			//DO THIS
			break;

		case ITM_NOR3:
			//DO THIS
			break;

		case ITM_XOR3:
			//DO THIS
			break;
		default:
			break;
	}


	
}

void AddGATE::Undo()
{}

void AddGATE::Redo()
{}

