# ifndef CIRCLE_HPP
# define CIRCLE_HPP

#include <string>
#include "vec2.hpp"
#include "color.hpp"
#include "mat2.hpp"
#include <iostream>
#include <set>

class Circle{
private:
	Vec2 center_;
	float radius_;
    RGB color_;
	float thickness_;
    std::string name_;
public:
	Circle();
	Circle(Vec2 v, float r,RGB c, float d, std::string n);
	float circumference() const;
	bool is_inside(Vec2 v) const;

    std::string getName() const;
    float getRadius() const;
    float getPosX();
    float getPosY();
    float getColorR();
    float getColorG();
    float getColorB();

    std::ostream& print(std::ostream& os) const;

    bool operator<(Circle const& rhs) const
    {
        return (radius_ < rhs.radius_);
    }
    bool operator>(Circle const& rhs) const
    {
        return (radius_ > rhs.radius_);
    }
    bool operator==(Circle const& rhs) const
    {
        return (radius_ == rhs.radius_);
    }
};

std::ostream& operator<<(std::ostream& os, Circle const& circ);

#endif
