#ifndef PROGRAMOWANIEGIER_SINGLETON_HPP
#define PROGRAMOWANIEGIER_SINGLETON_HPP

#include <iostream>

template<typename T>
class Singleton{
	protected:
		Singleton(){}
	public:
		static T& get(){
			static T get;
			return get;
		}
		
		Singleton(Singleton const&) = delete;
		
		void operator =(Singleton const&) = delete;
};

#endif //PROGRAMOWANIEGIER_SINGLETON_HPP
