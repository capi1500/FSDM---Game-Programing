#ifndef PROGRAMOWANIEGIER_SINGLETON_HPP
#define PROGRAMOWANIEGIER_SINGLETON_HPP

#include <iostream>

template<typename T>
class Singleton{
	private:
		static T* instance;
	protected:
		virtual void init(){};
	public:
		static T& get(){
			if(instance == nullptr)
				instance = new T();
			return *instance;
		}
		
		static void remove(){
			delete instance;
		}
		
		virtual ~Singleton() = default;
		
		Singleton(Singleton&) = delete;
};

template <typename T>
T* Singleton<T>::instance = nullptr;

#endif //PROGRAMOWANIEGIER_SINGLETON_HPP
