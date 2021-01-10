#include "Cut.h"
#include "..\ApplicationManager.h"

Cut::Cut(ApplicationManager *pApp):Action(pApp)
{
}

Cut::~Cut(void)
{
}

void Cut::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void Cut::Execute()
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
				List[i]->SetSelect(false);
				pManager->SetCopied(List[i]);
				pManager->SetCopiedCut(1);
				compcount--;
				List[i] = List[compcount];
				List[compcount] = NULL;
				pOut->PrintMsg("Cutted Gate Succesfully !");
				pManager->SetCopiedCut(1);
				pManager->SetCompCount(compcount);
				pManager->UnselectALL();
			}
		}
	}
	else if (counter == 0) {
		pOut->PrintMsg("No component selected, Select an item first !");
	}
	else {
		pOut->PrintMsg("Cannot perfom cut on multiple components");
	}
	
	


	

}

void Cut::Undo()
{}

void Cut::Redo()
{}

