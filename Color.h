#ifndef COLOR_H
#define COLOR_H

class Color {
public:
	static constexpr char OS_DELIMITER = '\n';

public:
	static const Color BLACK;
	static const Color WHITE;
	static const Color RED;

public:
	double r = 0;
	double g = 0;
	double b = 0;

public:
	constexpr Color() = default;

	constexpr Color(double const r, double const g, double const b) :
			r(r),
			g(g),
			b(b){}

public:
	Color operator * (double const d) const;
	Color operator + (const Color &c) const;
	void cap();

private:
	static void clamp__(double &a);
};

#endif // COLOR_H
