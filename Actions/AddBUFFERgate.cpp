#include "AddBUFFERgate.h"
#include "..\ApplicationManager.h"

AddBUFFERgate::AddBUFFERgate(ApplicationManager *pApp):Action(pApp)
{
}

AddBUFFERgate::~AddBUFFERgate(void)
{
}

void AddBUFFERgate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("BUFFER Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddBUFFERgate::Execute()
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

	//Calculate the rectangle Corners
	int Len = UI.COMP_Width;
	int Wdth = UI.COMP_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;
	BUFFER *pA=new BUFFER(GInfo, BUFFER_FANOUT);
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

void AddBUFFERgate::Undo()
{}

void AddBUFFERgate::Redo()
{}
