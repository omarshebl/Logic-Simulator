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

Component::Component()
{}

Component::~Component()
{}

