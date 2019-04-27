#ifndef VEC2_HPP
#define VEC2_HPP

struct Vec2{

		// def constructor
	Vec2();

	// val constructor
	Vec2(float x, float y);

	// variables
	float x;
	float y;

	// vec2 methods
	void setX(float x);
	void setY(float y);

	float getX();
	float getY();
};

#endif //VEC2_HPP

/*Include-Guards:
Verhindern das mehrfache Einbinden. Hier "ifndef" und "define"
*/