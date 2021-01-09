#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	MODE AppMode;		//Application Mode (design or simulation)
	
	static const int	width = 1358, height = 900,	//Window width and height
		wx = 15, wy = 15,			//Window starting coordinates
		StatusBarHeight = 50,	//Status Bar Height
		ToolBarHeight = 125,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		ToolItemHeight = 50,
		ToolItemWidth = 50,		//Width of each item in toolbar menu
		ComponentsMenuHeight = 75,
		ComponentsMenuWidth = 96;

	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color
	color DarkGrey;
	color ToolBarColor;


	//This should be calculated accurately because it will be used later to create connections between gates
	//For now, we will assume that rect width = 50 and height = 50
	static const int	COMP_Width = 80,		//AND2 Gate Image default width
						COMP_Height = 48,		//AND2 Gate Image default height
						COMP2_Width = 48;
	
}UI;	//create a single global object UI

#endif