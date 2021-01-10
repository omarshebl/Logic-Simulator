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
}

void AddGATE::Execute()
{
}

void AddGATE::Execute(int Type, GraphicsInfo GInfo, string label)
{

	switch (Type) {
		case ITM_SWITCH: {
			SWITCH* pA = new SWITCH(GInfo, SWITCH_FANOUT);
			if (label != "")
				pA->SetLabel(label);
			pManager->AddComponent(pA);
		}
		break;

		case ITM_LED: {
			LED* pA = new LED(GInfo, LED_FANOUT);
			if (label != "")
				pA->SetLabel(label);
			pManager->AddComponent(pA);
			}
			break;

		case ITM_AND2: {
			AND2* pA = new AND2(GInfo, AND2_FANOUT);
			if (label != "")
				pA->SetLabel(label);
			pManager->AddComponent(pA);
		}
			break;

		case ITM_OR2: {
			OR2* pA = new OR2(GInfo, OR2_FANOUT);
			if (label != "")
				pA->SetLabel(label);
			pManager->AddComponent(pA);
		}
			break;

		case ITM_NAND2: {
			NAND2* pA = new NAND2(GInfo, NAND2_FANOUT);
			if (label != "")
				pA->SetLabel(label);
			pManager->AddComponent(pA);
		}
			break;

		case ITM_NOR2: {
			NOR2* pA = new NOR2(GInfo, NOR2_FANOUT);
			if (label != "")
				pA->SetLabel(label);
			pManager->AddComponent(pA);
		}
			break;

		case ITM_XOR2: {
			XOR2* pA = new XOR2(GInfo, XOR2_FANOUT);
			if (label != "")
				pA->SetLabel(label);
			pManager->AddComponent(pA);
		}
			break;

		case ITM_XNOR2: {
			XNOR2* pA = new XNOR2(GInfo, XNOR2_FANOUT);
			if (label != "")
				pA->SetLabel(label);
			pManager->AddComponent(pA);
		}
			break;

		case ITM_NOT: {
			NOT* pA = new NOT(GInfo, NOT_FANOUT);
			if (label != "")
				pA->SetLabel(label);
			pManager->AddComponent(pA);
		}
			break;

		case ITM_BUFFER: {
			BUFFER* pA = new BUFFER(GInfo, BUFFER_FANOUT);
			if (label != "")
				pA->SetLabel(label);
			pManager->AddComponent(pA);
		}
			break;

		case ITM_AND3: {
			AND3* pA = new AND3(GInfo, AND3_FANOUT);
			if (label != "")
				pA->SetLabel(label);
			pManager->AddComponent(pA);
		}
			break;

		case ITM_NOR3: {
			NOR3* pA = new NOR3(GInfo, NOR3_FANOUT);
			if (label != "")
				pA->SetLabel(label);
			pManager->AddComponent(pA);
		}
			break;

		case ITM_XOR3: {
			XOR3* pA = new XOR3(GInfo, XOR3_FANOUT);
			if (label != "")
				pA->SetLabel(label);
			pManager->AddComponent(pA);
		}
			break;
	}
}

void AddGATE::Undo()
{}

void AddGATE::Redo()
{}

