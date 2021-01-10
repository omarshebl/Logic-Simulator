#include "Copy.h"
#include "..\ApplicationManager.h"

Copy::Copy(ApplicationManager *pApp):Action(pApp)
{
}

Copy::~Copy(void)
{
}

void Copy::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void Copy::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	Component** List = pManager->GetCompList();
	int compcount = pManager->GetCompCount();
	int counter = pManager->SelectedCounter();
	if (counter == 1) {
		for (int i = 0; i < compcount; i++) {
			if (List[i]->GetSelect()) {
				pManager->SetCopied(List[i]);
				pManager->SetCopiedCut(0);
				pManager->UnselectALL();
				pOut->PrintMsg("Copied Gate Succesfully !");
			}
		}
	}
	else if (counter == 0) {
		pOut->PrintMsg("No component selected, Select an item first !");
	}
	else {
		pOut->PrintMsg("Cannot perfom copy on multiple components");
	}
	
	


	

}

void Copy::Undo()
{}

void Copy::Redo()
{}

