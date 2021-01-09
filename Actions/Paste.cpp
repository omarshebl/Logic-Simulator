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

	if (C != NULL) {
		if ((Cy >= (UI.ToolBarHeight + UI.COMP_Height / 2)) && Cy < UI.height - (UI.StatusBarHeight + UI.COMP_Height / 2) && Cx >(UI.COMP_Width / 2) && Cx < (UI.width - UI.COMP_Width / 2)) {
			pManager->AddComponent(C);
			Component** List = pManager->GetCompList();
			int compcount = pManager->GetCompCount();
			int Len = UI.COMP_Width;
			int Wdth = UI.COMP_Height;
			GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

			GInfo.x1 = Cx - Len / 2;
			GInfo.x2 = Cx + Len / 2;
			GInfo.y1 = Cy - Wdth / 2;
			GInfo.y2 = Cy + Wdth / 2;
			List[compcount - 1]->SetGraphics(GInfo);
			pOut->PrintMsg("Component Pasted Successfully !");
			pManager->UnselectALL();
		}
		else {
			pOut->PrintMsg("Please click inside the drawing area, Try Again !");
		}
	}
	else {
		pOut->PrintMsg("No previous component was copied or cut.");
	}
}

void Paste::Undo()
{}

void Paste::Redo()
{}

