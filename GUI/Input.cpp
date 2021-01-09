#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

char Input::GetKeyQeueue() {
	char x;
	pWind->GetKeyPress(x);
	return x;
}
string Input::GetSrting(Output *pOut)
{
	string outputString = "this";
	bool exit = true;
	char inputKey;
	while (exit) {
		keytype keyt = pWind->WaitKeyPress(inputKey);
		if (keyt == ESCAPE) {
			exit = false;
			outputString = "";
			break;
		}
		if (keyt == ASCII) {
			if (inputKey == 8) {
				if (!outputString.empty())
					outputString.pop_back();
			}
			else if (inputKey == 13) {
				exit = false;
				break;
			}
			else {
				outputString += inputKey;
			}
			pOut->PrintMsg(outputString);
		}
	}
	return outputString;
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar

		if (y >= 0 && y < UI.ToolItemHeight && x < 13 * UI.ToolItemWidth) {
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			switch (ClickedItemOrder)
			{
			case ACT_COPY: return COPY;
			case ACT_CUT: return CUT;
			case ACT_PASTE: return PASTE;
			case ACT_DELETE: return DEL;
			case ACT_EDIT: return EDIT_Label;
			case ACT_SAVE: return SAVE;
			case ACT_LOAD: return LOAD;
			case ACT_PAUSE: return DSN_MODE;
			case ACT_PLAY: return SIM_MODE;
			case ACT_UNDO: return UNDO;
			case ACT_REDO: return REDO;
			case ACT_TT: return Create_TruthTable;
			case ACT_EXIT: return EXIT;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
		if ( y >= UI.ToolItemHeight && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ComponentsMenuWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
				case ITM_SWITCH: return ADD_Switch;
				case ITM_LED: return ADD_LED;
				case ITM_AND2: return ADD_AND_GATE_2;
				case ITM_OR2: return ADD_OR_GATE_2;
				case ITM_NAND2: return ADD_NAND_GATE_2;
				case ITM_NOR2: return ADD_NOR_GATE_2;
				case ITM_XOR2: return ADD_XOR_GATE_2;
				case ITM_XNOR2: return ADD_XNOR_GATE_2;
				case ITM_NOT: return ADD_INV;
				case ITM_BUFFER: return ADD_Buff;
				case ITM_AND3: return ADD_AND_GATE_3;
				case ITM_NOR3: return ADD_NOR_GATE_3;
				case ITM_XOR3: return ADD_XOR_GATE_3;
				case ITM_CONNECTION: return ADD_CONNECTION;
			
				default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
	
		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}
		
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}


Input::~Input()
{
}
