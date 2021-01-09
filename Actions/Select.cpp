#include "Select.h"
#include "..\ApplicationManager.h"

Select::Select(ApplicationManager *pApp):Action(pApp)
{
}

Select::~Select(void)
{
}

void Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Select a gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void Select::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	char x =  pIn->GetKeyQeueue();
	

	Component** List = pManager->GetCompList();
	int compcount = pManager->GetCompCount();
	GraphicsInfo Check;
	bool Checker = false;
	for (int i = 0; i < compcount ; i++) {
		Check = List[i]->GetGraphics();
		if (((Cx > Check.x1) && (Cx < Check.x2)) && ((Cy > Check.y1) && (Cy < Check.y2))) {
			if (List[i]->GetSelect()) {
				List[i]->SetSelect(false);
			}
			else {
				List[i]->SetSelect(true);
			}
			Checker = true;
		}
	}
	if (!Checker) {
		for (int i = 0; i < compcount; i++) {
			List[i]->SetSelect(false);
		}
	}

	

}

void Select::Undo()
{}

void Select::Redo()
{}

