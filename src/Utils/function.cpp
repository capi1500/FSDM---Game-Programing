#include "function.hpp"

long double Function::operator ()(long double x){
	return a * x + b;
}

sf::Vector2<long double> Function::cross(const Function& f) const{
	long double x = (f.b - b) / (a - f.a);
	return {x, f(x)};
}

Function::Function(const sf::Vector2<long double>& A, const sf::Vector2<long double>& B){
	a = (A.y - B.y) / (A.x - B.x);
	b = B.y - a * B.x;
}

Function::Function(){
	a = b = 0;
}
