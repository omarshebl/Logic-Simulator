#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
}

GraphicsInfo Component::GetGraphics() {
	return m_GfxInfo;
}

void Component::SetGraphics(GraphicsInfo x) {
	m_GfxInfo=x;
}
void Component::SetSelect(bool x) {
	Selected = x;
}

bool Component::GetSelect() const {
	return Selected;
}

void Component::SetType(DsgnMenuItem input) {
	GateType = input;
}

int Component::GetType() {
	return GateType;
}

string Component::GetLabel()
{
	return m_Label;
}

void Component::SetLabel(string input)
{
	m_Label = input;
}

Component::Component()
{}

Component::~Component()
{}

