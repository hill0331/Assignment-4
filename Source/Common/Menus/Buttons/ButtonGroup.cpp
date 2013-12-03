#include "ButtonGroup.h"
#include "Button.h"
#include "../../Input/Input.h"

ButtonGroup::ButtonGroup()
{
	m_SelectedButton = -1; // nothing selected immediately - button 0 will go selected if a key pressed
	m_PressedButton = -1;

}

ButtonGroup::~ButtonGroup()
{
	for (int i = 0; i < m_Buttons.size(); i++)
	{
		if (m_Buttons.at(i) != NULL)
		{
			delete m_Buttons.at(i);
			m_Buttons.at(i) = NULL;
		}
	}
	m_Buttons.clear();
}

void ButtonGroup::update(double delta)
{
	for (int i = 0; i < m_Buttons.size(); i++)
	{
		if (m_Buttons.at(i) != NULL)
		{
			m_Buttons.at(i)->update(delta);
		}
	}
}

void ButtonGroup::paint()
{
	for (int i = 0; i < m_Buttons.size(); i++)
	{
		m_Buttons.at(i)->paint();
	}

}

void ButtonGroup::reset()
{

}

void ButtonGroup::addButton(Button *button)
{
	m_Buttons.push_back(button);
}

void ButtonGroup::initializeGroup()
{

}

void ButtonGroup::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	//Handle mouse movement events here
	for (int i = 0; i < m_Buttons.size(); i++)
	{
		Button *b = m_Buttons.at(i);

		// we now need to implement the state change logic we described.
		if (b->getState() != DISABLED_BUTTON && b->getState() != TRIGGERED_BUTTON)
		{

			if (b->inButton(positionX, positionY) && b->getState() != PRESSED_BUTTON)
			{
				b->setState(IN_FOCUS_BUTTON);
			}
			else
			{
				if (b->inButton(positionX, positionY) == false)
				{
					b->setState(ENABLED_BUTTON);
				}
			}
		}
	}
}


void ButtonGroup::mouseLeftClickDownEvent(float positionX, float positionY)
{
	//Handle mouse left click down events here
	for (int i = 0; i < m_Buttons.size(); i++)
	{
		Button *b = m_Buttons.at(i);

		// we now need to implement the state change logic we described.
		if (b->getState() != DISABLED_BUTTON && b->getState() != TRIGGERED_BUTTON)
		{
			if (b->inButton(positionX, positionY))
			{
				b->setState(PRESSED_BUTTON);
			}
		}
	}
}

void ButtonGroup::mouseRightClickDownEvent(float positionX, float positionY)
{
	//Handle mouse right click down events here
}

void ButtonGroup::mouseLeftClickUpEvent(float positionX, float positionY)
{
	for (int i = 0; i < m_Buttons.size(); i++)
	{
		Button *b = m_Buttons.at(i);

		// we now need to implement the state change logic we described.
		if (b->getState() == PRESSED_BUTTON)
		{
			b->setState(IN_FOCUS_BUTTON);

			handleButtonTrigger(i);
		}
	}
}

void ButtonGroup::mouseRightClickUpEvent(float positionX, float positionY)
{
	//Handle mouse right click up events here
}

void ButtonGroup::keyDownEvent(int keyCode)
{
	//Handle keyboard down events here
	if (keyCode == KEYCODE_SPACE)
	{
		if (m_SelectedButton == -1)
		{
			return; // nothing selected, so nothing to do
		}

		m_PressedButton = m_SelectedButton;
		m_Buttons[m_SelectedButton]->setState(PRESSED_BUTTON);
	}
}

void ButtonGroup::keyUpEvent(int keyCode)
{
	//Handle keyboard up events here
	// three things a button group cares about wrt keys
	// up
	// down
	// space
	if (keyCode == KEYCODE_UP_ARROW)
	{
		int buttonCounter = 0;

		if (m_SelectedButton != -1)
		{
			if (m_Buttons[m_SelectedButton]->getState() != DISABLED_BUTTON && m_Buttons[m_SelectedButton]->getState() != TRIGGERED_BUTTON)
			{
				m_Buttons[m_SelectedButton]->setState(ENABLED_BUTTON);
			}
		}

		//m_SelectedButton = (m_SelectedButton - 1) % m_Buttons.size();

		if (m_SelectedButton - 1 > -1)
		{
			m_SelectedButton = (m_SelectedButton - 1);
		}
		else
		{
			m_SelectedButton = m_Buttons.size() - 1;
		}

		while (m_Buttons[m_SelectedButton]->getState() == DISABLED_BUTTON || m_Buttons[m_SelectedButton]->getState() == TRIGGERED_BUTTON)
		{
			if (m_SelectedButton - 1 > -1)
			{
				m_SelectedButton = (m_SelectedButton - 1);
			}
			else
			{
				m_SelectedButton = m_Buttons.size() - 1;
			}

			buttonCounter++;

			if (buttonCounter >= m_Buttons.size())
			{
				buttonCounter = 0;
				break;
			}
		}

		m_Buttons[m_SelectedButton]->setState(IN_FOCUS_BUTTON);
	}
	else if (keyCode == KEYCODE_DOWN_ARROW)
	{
		//infinite loop counter
		int buttonCounter = 0;

		// move to next button
		if (m_SelectedButton != -1)
		{
			if (m_Buttons[m_SelectedButton]->getState() != DISABLED_BUTTON || m_Buttons[m_SelectedButton]->getState() == TRIGGERED_BUTTON)
			{
				m_Buttons[m_SelectedButton]->setState(ENABLED_BUTTON);
			}
		}
		m_SelectedButton = (m_SelectedButton + 1) % m_Buttons.size();

		//While you are on a disabled button, loop though to find one that is not
		while (m_Buttons[m_SelectedButton]->getState() == DISABLED_BUTTON || m_Buttons[m_SelectedButton]->getState() == TRIGGERED_BUTTON)
		{
			m_SelectedButton = (m_SelectedButton + 1) % m_Buttons.size();

			buttonCounter++;

			//if all buttons are disabled, stop looping
			if (buttonCounter >= m_Buttons.size())
			{
				buttonCounter = 0;
				break;
			}
		}

		m_Buttons[m_SelectedButton]->setState(IN_FOCUS_BUTTON);
	}
	else if (keyCode == KEYCODE_SPACE)
	{
		if (m_SelectedButton == -1)
		{
			return; // nothing selected, so nothing to do
		}

		if (m_PressedButton == m_SelectedButton)
		{
			handleButtonTrigger(m_SelectedButton);
			m_PressedButton = -1;
		}
	}
}

const char* ButtonGroup::getType()
{
	return BUTTON_GROUP_TYPE;
}

void ButtonGroup::setGroupAlpha(float alpha)
{
	for (int i = 0; i < m_Buttons.size(); i++)
	{
		if (m_Buttons.at(i) != NULL)
		{
			m_Buttons.at(i)->setAlpha(alpha);
		}
	}
}
