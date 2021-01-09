#include "Output.h"
#include "..\ApplicationManager.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = color(117,117,117);
	UI.DarkGrey = color(61, 61, 61);
	UI.ToolBarColor = color(66, 66, 66);

	int ToolMenuCNT = 13;
	
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");

	pWind->SetPen(UI.DarkGrey, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.height);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0,0, UI.width, UI.ToolBarHeight);

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateToolBar();
	CreateStatusBar();		//Create Status bar
	

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.DarkGrey,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateToolBar() const {
	string Tools[ACT_TOOL_CNT];
	Tools[ACT_COPY] = "Images\\menu\\toolbar\\active\\copy.jpg";
	Tools[ACT_CUT] = "Images\\menu\\toolbar\\active\\cut.jpg";
	Tools[ACT_PASTE] = "Images\\menu\\toolbar\\active\\paste.jpg";
	Tools[ACT_DELETE] = "Images\\menu\\toolbar\\active\\delete.jpg";
	Tools[ACT_EDIT] = "Images\\menu\\toolbar\\active\\edit.jpg";
	Tools[ACT_SAVE] = "Images\\menu\\toolbar\\active\\save.jpg";
	Tools[ACT_LOAD] = "Images\\menu\\toolbar\\active\\load.jpg";
	Tools[ACT_PAUSE] = "Images\\menu\\toolbar\\active\\pause.jpg";
	Tools[ACT_PLAY] = "Images\\menu\\toolbar\\active\\play.jpg";
	Tools[ACT_UNDO] = "Images\\menu\\toolbar\\active\\undo.jpg";
	Tools[ACT_REDO] = "Images\\menu\\toolbar\\active\\redo.jpg";
	Tools[ACT_TT] = "Images\\menu\\toolbar\\active\\truth_table.jpg";
	Tools[ACT_EXIT] = "Images\\menu\\toolbar\\active\\exit.jpg";
	for (int i = 0; i < ACT_TOOL_CNT; i++)
		pWind->DrawImage(Tools[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolItemHeight);
}
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//First prepare List of images for each menu item
	string ComponentsMenuImages[ITM_DSN_CNT];
	ComponentsMenuImages[ITM_SWITCH] = "Images\\menu\\gatebar\\active\\switch.jpg";
	ComponentsMenuImages[ITM_LED] = "Images\\menu\\gatebar\\active\\led.jpg";
	ComponentsMenuImages[ITM_AND2] = "Images\\menu\\gatebar\\active\\and.jpg";
	ComponentsMenuImages[ITM_OR2] = "Images\\menu\\gatebar\\active\\or.jpg";
	ComponentsMenuImages[ITM_NAND2] = "Images\\menu\\gatebar\\active\\nand.jpg";
	ComponentsMenuImages[ITM_NOR2] = "Images\\menu\\gatebar\\active\\nor.jpg";
	ComponentsMenuImages[ITM_XOR2] = "Images\\menu\\gatebar\\active\\xor.jpg";
	ComponentsMenuImages[ITM_XNOR2] = "Images\\menu\\gatebar\\active\\xnor.jpg";
	ComponentsMenuImages[ITM_NOT] = "Images\\menu\\gatebar\\active\\not.jpg";
	ComponentsMenuImages[ITM_BUFFER] = "Images\\menu\\gatebar\\active\\buffer.jpg";
	ComponentsMenuImages[ITM_AND3] = "Images\\menu\\gatebar\\active\\and3.jpg";
	ComponentsMenuImages[ITM_NOR3] = "Images\\menu\\gatebar\\active\\nor3.jpg";
	ComponentsMenuImages[ITM_XOR3] = "Images\\menu\\gatebar\\active\\xor3.jpg";
	ComponentsMenuImages[ITM_CONNECTION] = "Images\\menu\\gatebar\\active\\connection.jpg";



	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(ComponentsMenuImages[i],i*UI.ComponentsMenuWidth,UI.ToolItemHeight,UI.ComponentsMenuWidth, UI.ComponentsMenuHeight);


	//Draw a line under the toolbar
	

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)


}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawBUFFER(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\components\\highlighted\\buffer.jpg";
	else  
		GateImage = "Images\\components\\active\\buffer.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.COMP_Width, UI.COMP_Height);
}

void Output::DrawNOT(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\not.jpg";
	else
		GateImage = "Images\\components\\active\\not.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.COMP_Width, UI.COMP_Height);
}

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\and.jpg";
	else
		GateImage = "Images\\components\\active\\and.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.COMP_Width, UI.COMP_Height);
}

void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\or.jpg";
	else
		GateImage = "Images\\components\\active\\or.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.COMP_Width, UI.COMP_Height);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\nand.jpg";
	else
		GateImage = "Images\\components\\active\\nand.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.COMP_Width, UI.COMP_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\nor.jpg";
	else
		GateImage = "Images\\components\\active\\nor.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.COMP_Width, UI.COMP_Height);
}

void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\xor.jpg";
	else
		GateImage = "Images\\components\\active\\xor.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.COMP_Width, UI.COMP_Height);
}

void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\xnor.jpg";
	else
		GateImage = "Images\\components\\active\\xnor.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.COMP_Width, UI.COMP_Height);
}

void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\and3.jpg";
	else
		GateImage = "Images\\components\\active\\and3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.COMP_Width, UI.COMP_Height);
}


void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\nor3.jpg";
	else
		GateImage = "Images\\components\\active\\nor3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.COMP_Width, UI.COMP_Height);
}


void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\xor3.jpg";
	else
		GateImage = "Images\\components\\active\\xor3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.COMP_Width, UI.COMP_Height);
}


void Output::DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\switch_off.jpg";
	else
		GateImage = "Images\\components\\active\\switch_off.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.COMP2_Width, UI.COMP_Height);
}


void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\led_off.jpg";
	else
		GateImage = "Images\\components\\active\\led_off.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.COMP2_Width, UI.COMP_Height);
}





void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	//TODO: Add code to draw connection
}


Output::~Output()
{
	delete pWind;
}
