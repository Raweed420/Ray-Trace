#include "Color.h"

Color Color::operator * (double const d) const {
	return Color(
		r * d,
		g * d,
		b * d
	);
}

Color Color::operator + (const Color &c) const {
	return Color(
		(r + c.r) / 2,
		(g + c.g) / 2,
		(b + c.b) / 2
	);
}

void Color::cap() {
	clamp__(r);
	clamp__(g);
	clamp__(b);
}

void Color::clamp__(double &a) {
	if (a < 0x00) {
		a = 0x00;
	}
	else if (a > 0xff) {
		a = 0xff;
	}
}
