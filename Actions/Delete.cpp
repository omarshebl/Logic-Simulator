#include "Delete.h"
#include "..\ApplicationManager.h"

Delete::Delete(ApplicationManager *pApp):Action(pApp)
{
}

Delete::~Delete(void)
{
}

void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void Delete::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	Component** List = pManager->GetCompList();
	int compcount = pManager->GetCompCount();
	int counter = pManager->SelectedCounter();
	if (counter >= 1) {
		for (int k = 0; k < counter; k++) {
			for (int i = 0; i < compcount; i++) {
				if (List[i]->GetSelect()) {
					compcount--;
					if (List[i]->GetType() == ITM_SWITCH)
						pManager->DeleteSWITCH();
					if (List[i]->GetType() == ITM_LED)
						pManager->DeleteLED();
					delete [] List[i];
					List[i] = List[compcount];
					List[compcount] = NULL;
					pOut->PrintMsg("Deleteted Succesfully !");
					pManager->SetCompCount(compcount);
				}
			}
		}
	}
	else {
		pOut->PrintMsg("No component selected, Select an item first !");
	}
	
	


	

}

void Delete::Undo()
{}

void Delete::Redo()
{}

