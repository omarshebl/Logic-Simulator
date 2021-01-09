#include "AddANDgate2.h"
#include "..\ApplicationManager.h"

AddANDgate2::AddANDgate2(ApplicationManager *pApp):Action(pApp)
{
}

AddANDgate2::~AddANDgate2(void)
{
}

void AddANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input AND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void AddANDgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	Component** List = pManager->GetCompList();
	int compcount = pManager->GetCompCount();
	GraphicsInfo Check;
	bool Checker = true;
	for (int i = 0; i < compcount ; i++) {
		Check = List[i]->GetGraphics();
		if (((Cx > (Check.x1 - UI.COMP_Width/2)) && (Cx < (Check.x2 + UI.COMP_Width/2))) && ((Cy > (Check.y1 - UI.COMP_Height/2)) && (Cy < (Check.y2 + UI.COMP_Height/2)))) {
			Checker = false;
		}
	}


	if ((Cy >= (UI.ToolBarHeight+UI.COMP_Height/2)) && Cy < UI.height - (UI.StatusBarHeight + UI.COMP_Height/2) && Cx > (UI.COMP_Width/2) && Cx < (UI.width - UI.COMP_Width/2)) {
		//Calculate the rectangle Corners
		if (Checker) {
			int Len = UI.COMP_Width;
			int Wdth = UI.COMP_Height;

			GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

			GInfo.x1 = Cx - Len / 2;
			GInfo.x2 = Cx + Len / 2;
			GInfo.y1 = Cy - Wdth / 2;
			GInfo.y2 = Cy + Wdth / 2;
			AND2* pA = new AND2(GInfo, AND2_FANOUT);
			pManager->AddComponent(pA);

		}
		else {
			pOut->PrintMsg("You overlapped another gate, TRY AGAIN !");
		}
	}
	else {
		pOut->PrintMsg("Please click inside drawing area, TRY AGAIN !");
	}
}

void AddANDgate2::Undo()
{}

void AddANDgate2::Redo()
{}

