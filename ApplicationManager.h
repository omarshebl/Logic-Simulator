#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	int SWITCHSC;
	int LEDSC;
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	
	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	Component* Clipboard = NULL;
	int CopiedCut; // 0 = Copy, 1 = Cut
	

public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	void DeleteLED();
	void DeleteSWITCH();

	bool CheckOverlap(int Cx, int Cy);
	bool CheckDrawArea(int Cx, int Cy);
	bool GetClickedComponent(int Cx, int Cy, Component*& pointer);

	GraphicsInfo CreateGraphics(int Cx, int Cy, int Type);

	Component** GetCompList();
	int GetCompCount() const;
	void SetCompCount(int x);

	Component* GetSelectedComp();
	int SelectedCounter() const;
	void UnselectALL();
	void SetCopied(Component* cComp);
	void ResetCopied();
	Component* GetCopied();

	void SetCopiedCut(int input);
	int GetCopiedCut();
	void SetCuttedGate(GraphicsInfo input);


	void SaveGates(ofstream& filename);
	void LoadGates(ifstream& filename);


	void DeleteAll();

	//destructor
	~ApplicationManager();
};

#endif