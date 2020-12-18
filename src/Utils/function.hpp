

#ifndef PROGRAMOWANIEGIER_FUNCTION_HPP
#define PROGRAMOWANIEGIER_FUNCTION_HPP

#include <SFML/System/Vector2.hpp>

class Function{
	public:
		long double a;
		long double b;
		
		long double operator () (long double x) const;
		
		sf::Vector2<long double> cross (const Function& f) const;
		
		Function(const sf::Vector2<long double>& A, const sf::Vector2<long double>& B);
		Function();
};

#endif //PROGRAMOWANIEGIER_FUNCTION_HPP
