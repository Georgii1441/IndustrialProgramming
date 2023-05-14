#include "Figure.h"

using namespace sf;

Figure::Figure(RenderWindow& window, Vector2f pos, Vector2i square_size, float scale)
	: height(square_size.y), width(square_size.x), window(window), figure(pos), scale(scale)
{
	cube->setOutlineColor(Color(78, 87, 84));
	cube->setOutlineThickness(-1);
	cube->setSize(Vector2f(scale, scale));
	for (int i = 0; i < width; i++)
	{
		std::vector<sf::Color> v;
		for (int j = 0; j < height; j++) {
			v.push_back(Color::Black);
		}
		square.push_back(v);
	}
	restart();
}

void Figure::restart()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			square[i][j] = Color::Black;
		}
	}
	type_of_figure.y = d(random);
	color_of_figure.y = d(random);
	score = 0;
	new_figure();
}

void Figure::new_figure()
{
	type_of_figure.x = type_of_figure.y;
	color_of_figure.x = color_of_figure.y;
	for (int i = 0; i < 4; i++)
	{
		t[i].x = figures[type_of_figure.x][i] % 2 + static_cast<float>(floor(width / 2));
		t[i].y = static_cast<float>(figures[type_of_figure.x][i] / 2);
	}
	type_of_figure.y = d(random);
	color_of_figure.y = d(random);
	delay = 250;
}

void Figure::update(Time const& deltaTime)
{
	framerate += deltaTime;
	if (framerate > milliseconds(delay))
	{
		framerate = milliseconds(0);
		if (check(ch::x) && click_dx != 0)
		{
			for (int i = 0; i < 4; i++) t[i].x += click_dx; click_dx = 0;
		}
		if (check(ch::y)) { for (int i = 0; i < 4; i++)  t[i].y += click_dy; }
		else
		{
			for (int i = 0; i < 4; i++)
			{
				if (static_cast<int>(t[i].y) == 2) { restart(); return; }
				square[static_cast<size_t>(t[i].x)][static_cast<size_t>(t[i].y)] = Color(colors_of_figure[color_of_figure.x]);
			}
			int numLine = 0;
			for (int j = 0; j < height; j++)
			{
				int line = 0;
				for (int i = 0; i < width; i++)
				{
					if (square[i][j] != Color::Black) line++;
					if (line == width)
					{
						line_dead(j);
						numLine++;
					}
				}
			}
			if (numLine != 0)
			{
				score += 3 * (numLine * numLine);
			}
			new_figure();
		}
	}
}

void Figure::Direction_of_figure(direction dir)
{
	click_dx = static_cast<float> (dir);
}

void Figure::rotate()
{
	if (check(ch::rotation))
	{
		sf::Vector2f centerRotation = t[1];
		for (int i = 0; i < 4; i++)
		{
			float x = t[i].y - centerRotation.y;
			float y = t[i].x - centerRotation.x;
			t[i].x = centerRotation.x - x;
			t[i].y = centerRotation.y + y;
		}
	}
}

void Figure::speed()
{
	delay = 10;
}

void Figure::line_dead(int g)
{
	for (int i = g; i > 0; i--)
	{
		for (int j = 0; j < width; j++)
		{
			square[j][i] = square[j][static_cast<size_t>(i - 1)];
		}
	}
}

bool Figure::check(ch ch)
{
	switch (ch)
	{
	case Figure::ch::x:
	{	for (int i = 0; i < 4; i++)
	{
		if ((t[i].x + click_dx < 0) ||
			(t[i].x + click_dx > static_cast<float>(width - 1))) return false;
		if ((static_cast<int>(t[i].y) >= 0) &&
			(square[static_cast<size_t>(t[i].x + click_dx)][static_cast<size_t>(t[i].y)]
				!= sf::Color::Black))  return false;
	}
	break; }

	case Figure::ch::y:
	{	for (int i = 0; i < 4; i++)
	{
		if ((t[i].y + click_dy) > static_cast<float>(height - 1))  return false;
		if ((static_cast<int>(t[i].y + click_dy) >= 0) &&
			(square[static_cast<size_t>(t[i].x)][static_cast<size_t>(t[i].y + click_dy)]
				!= sf::Color::Black))  return false;
	}
	break; }

	case Figure::ch::rotation:
	{ sf::Vector2f centerRotation = t[1];
	for (int i = 0; i < 4; i++)
	{
		float x = t[i].y - centerRotation.y;
		float y = t[i].x - centerRotation.x;
		if (((centerRotation.x - x) < 0) || ((centerRotation.x - x) > static_cast<float>(width - 1)) ||
			((centerRotation.y + y) > static_cast<float>(height - 1))) return false;
		if ((static_cast<int>(centerRotation.y + y) >= 0) &&
			(square[static_cast<size_t>(centerRotation.x - x)][static_cast<size_t>(centerRotation.y + y)]
				!= sf::Color::Black))  return false;
	}
	break; }

	default:
		break;
	}
	return true;
}

void Figure::draw()
{
	if (position_maket.x >= 0)
	{
		cube->setFillColor(colors_of_figure[color_of_figure.y]);
		for (int i = 0; i < 4; i++)
		{
			cube->setPosition((figures[type_of_figure.y][i] % 2) * scale, (static_cast<float>(figures[type_of_figure.y][i] / 2)) * scale);
			cube->move(position_maket);
			window.draw(*cube);
		}
	}
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			cube->setFillColor(square[i][j]);
			cube->setPosition(static_cast<float>(i) * scale, static_cast<float>(j) * scale);
			cube->move(figure);
			window.draw(*cube);
		}
	}
	cube->setFillColor(colors_of_figure[color_of_figure.x]);
	for (int i = 0; i < 4; i++)
	{
		cube->setPosition(t[i].x * scale, t[i].y * scale);
		cube->move(figure);
		window.draw(*cube);
	}
}

int Figure::get_score() const
{
	return score;
}

Vector2f Figure::getPosition()
{
	Vector2f pos;
	pos.x = t[1].x * scale + figure.x;
	pos.y = t[1].y * scale + figure.y;
	return pos;
}

void Figure::maket(Vector2f posmak)
{
	position_maket = posmak;
}