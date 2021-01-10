#include "Paste.h"
#include "..\ApplicationManager.h"


Paste::Paste(ApplicationManager *pApp):Action(pApp)
{
}

Paste::~Paste(void)
{
}

void Paste::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Click inside the drawing area to paste");


	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void Paste::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Component* C = pManager->GetCopied();
	int CopiedCut = pManager->GetCopiedCut();
	
	if (C != NULL) {
		AddGATE* pAct = NULL;
		int GateType = C->GetType();
		if (pManager->CheckDrawArea(Cx,Cy))
		{
			bool overlap = pManager->CheckOverlap(Cx, Cy);
			if (overlap) {
				pOut->PrintMsg("You overlapped another component, Please Try Again !");
			}
			else {
				GraphicsInfo GInfo;
				GInfo = pManager->CreateGraphics(Cx, Cy, GateType);
				if (CopiedCut == 0) {
					pAct = new AddGATE(pManager);
					pAct->Execute(GateType, GInfo);
					pOut->PrintMsg("Component Pasted Successfully !");
				}
				else if (CopiedCut == 1) {
					pManager->SetCuttedGate(GInfo);
					pManager->AddComponent(C);
					pManager->ResetCopied();
					pManager->SetCopiedCut(0);
					pOut->PrintMsg("Component Pasted Successfully !");
				}
			}
		}
		else {
			pOut->PrintMsg("Please click inside the drawing area, Try Again !");
		}
	} else {
		pOut->PrintMsg("No previous component was copied or cut.");
	}
}

void Paste::Undo()
{}

void Paste::Redo()
{}

