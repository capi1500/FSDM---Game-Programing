#include <misc/singleton.hpp>
#include <iostream>

class Foo : public Singleton<Foo>{
	public:
		static void print2(){
			std::cout << "Foo\n";
		}
};

int main(){
	Foo::print2();
}