//
// Created by Kacper on 11/12/2020.
//

#ifndef PROGRAMOWANIEGIER_VECTOR_HPP
#define PROGRAMOWANIEGIER_VECTOR_HPP

#include <SFML/System/Vector2.hpp>

class Vector{
	public:
		long double x;
		long double y;
		
		long double operator * (const Vector& u) const; // iloczyn wektorowych
		long double operator ^ (const Vector& u) const; // iloczyn skalarny
		
		Vector operator * (const long double r) const; // mnożenie przez skalar
		Vector operator + (const Vector& u) const;
		Vector operator - (const Vector& u) const;
		Vector operator - () const;
		
		Vector& operator *= (const long double r); // mnożenie przez skalar
		Vector& operator += (const Vector& u);
		Vector& operator -= (const Vector& u);
		
		Vector normal() const;
		Vector& normalize();
		
		long double length() const;
		
		sf::Vector2f toVector2f() const;
		
		Vector(sf::Vector2f v);
		Vector(long double x, long double y);
		Vector(const sf::Vector2f& a, const sf::Vector2f& b);
		Vector();
};

#endif //PROGRAMOWANIEGIER_VECTOR_HPP
