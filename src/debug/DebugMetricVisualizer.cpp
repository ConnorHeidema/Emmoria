#include "../../inc/debug/DebugMetricVisualizer.hpp"

#include <list>

DebugMetricVisualizer::DebugMetricVisualizer()
	: m_type("DebugMetricVisualizer")
	, m_characterSize(24)
	, m_lastCharactersPressed("")
	, m_leftMousePositionPressed("")
	, m_RightMousePositionPressed("")
	, m_timeRun("")
	, m_minutesElapsed(0)
	, m_secondsElapsed(0)
	, m_clock()
	, m_lastSeconds(0)
	, m_frameCountString("")
{
	m_font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf");
}


void DebugMetricVisualizer::Update()
{
	m_lastCharactersPressed = "";
	m_leftMousePositionPressed = "";
	m_RightMousePositionPressed = "";

	m_timeRun = GetTimeString_();
	m_framesInSecond++;

	CheckKey_();
	CheckMouse_();
}

void DebugMetricVisualizer::draw(
	sf::RenderTarget& target,
	sf::RenderStates states) const
{
	sf::Text thisText;
	thisText.setFont(m_font);
	thisText.setPosition(sf::Vector2f(0.f, 0.f));
	thisText.setCharacterSize(m_characterSize);
	thisText.setFillColor(sf::Color::White);
	thisText.setString(GetDebugString_());
	target.draw(thisText, states);
}

std::string DebugMetricVisualizer::GetTimeString_()
{
	sf::Time elapsedTime = m_clock.getElapsedTime();
	int seconds = int(elapsedTime.asSeconds()) % 60;
	if (seconds != m_lastSeconds)
	{
		m_frameCountString = "Frames in last second: " + std::to_string(m_framesInSecond);
		m_framesInSecond = 0;
		m_lastSeconds = seconds;
	}
	int minutes = elapsedTime.asSeconds() / 60;
	return std::to_string(minutes) + ":" + std::to_string(seconds);
}

void DebugMetricVisualizer::CheckKey_()
{
	std::string ret = "";
	#define IS_PRESSED_DEBUG(x) \
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::x)) \
		{ \
			m_lastCharactersPressed += #x; \
			m_lastCharactersPressed += " "; \
		}

		IS_PRESSED_DEBUG(A) IS_PRESSED_DEBUG(B) IS_PRESSED_DEBUG(C) IS_PRESSED_DEBUG(D)
		IS_PRESSED_DEBUG(E)	IS_PRESSED_DEBUG(F) IS_PRESSED_DEBUG(G) IS_PRESSED_DEBUG(H)
		IS_PRESSED_DEBUG(I) IS_PRESSED_DEBUG(J) IS_PRESSED_DEBUG(K) IS_PRESSED_DEBUG(L)
		IS_PRESSED_DEBUG(M) IS_PRESSED_DEBUG(N) IS_PRESSED_DEBUG(O)	IS_PRESSED_DEBUG(P)
		IS_PRESSED_DEBUG(Q)	IS_PRESSED_DEBUG(R) IS_PRESSED_DEBUG(S)	IS_PRESSED_DEBUG(T)
		IS_PRESSED_DEBUG(U)	IS_PRESSED_DEBUG(V)	IS_PRESSED_DEBUG(W)	IS_PRESSED_DEBUG(X)
		IS_PRESSED_DEBUG(Y)	IS_PRESSED_DEBUG(Z)

		IS_PRESSED_DEBUG(Num1) IS_PRESSED_DEBUG(Num2) IS_PRESSED_DEBUG(Num3)
		IS_PRESSED_DEBUG(Num4) IS_PRESSED_DEBUG(Num5) IS_PRESSED_DEBUG(Num6)
		IS_PRESSED_DEBUG(Num7) IS_PRESSED_DEBUG(Num8) IS_PRESSED_DEBUG(Num9)

		IS_PRESSED_DEBUG(Left)
		IS_PRESSED_DEBUG(Right)
		IS_PRESSED_DEBUG(Up)
		IS_PRESSED_DEBUG(Down)

	#undef IS_PRESSED_DEBUG
}

void DebugMetricVisualizer::CheckMouse_()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_leftMousePositionPressed += "Left at : (" +
		std::to_string(sf::Mouse::getPosition().x) + ", " +
		std::to_string(sf::Mouse::getPosition().y) + ")";
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		m_RightMousePositionPressed += "Right at : (" +
		std::to_string(sf::Mouse::getPosition().x) + ", " +
		std::to_string(sf::Mouse::getPosition().y) + ")";
	}
}

std::string DebugMetricVisualizer::GetDebugString_() const
{
	return
		m_leftMousePositionPressed + "\n" +
		m_RightMousePositionPressed + "\n" +
		m_lastCharactersPressed + "\n" +
		m_timeRun + "\n" +
		m_frameCountString;
}
