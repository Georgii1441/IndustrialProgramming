#pragma once
#include "Manager.h"
#include <array>
#include <vector>
#include <chrono>
#include <random>
#include <math.h>

using namespace sf;
using namespace std;

class Figure
{
public:
	enum class direction { left = -1, nuLL, right };
	enum class ch { x, y, rotation };
	explicit Figure(RenderWindow&, Vector2f, Vector2i, float);
	void Direction_of_figure(direction);
	void draw();
	void update(Time const&);
	void rotate();
	Vector2f getPosition();
	void speed();
	void restart();
	int get_score() const;
	void mustet(bool);
	void maket(Vector2f);

private:
	const int height;
	const int width;
	const float click_dy = 1.0f; 
	vector<vector<Color>> square;
	array<array<int, 4>, 7> figures
	{ {{1,3,5,7},{2,4,5,7},{3,4,5,6},{3,4,5,7},{2,3,5,7},{3,5,6,7},{2,3,4,5}} }; 
	array<Vector2f, 4> t;
	array<Color, 7> colors_of_figure{ {Color::Blue, Color::Cyan, Color::Yellow,
		Color::Green, Color::Magenta, Color::Red, Color::White} };
	unique_ptr<RectangleShape> cube = make_unique<RectangleShape>();
	long long seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine random = default_random_engine(static_cast<long>(seed));
	uniform_int_distribution<int> d = uniform_int_distribution<int>(0, 6);
	RenderWindow& window;
	const Vector2f figure;
	Time framerate;
	Vector2i type_of_figure;
	Vector2i color_of_figure;
	void new_figure(); 
	void line_dead(int);
	bool check(ch); 
	Int32 delay; 
	float click_dx; 
	int score; 
	float scale;
	Vector2f position_maket = Vector2f(-1, -1);
};