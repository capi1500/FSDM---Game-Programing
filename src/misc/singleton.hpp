#ifndef PROGRAMOWANIEGIER_SINGLETON_HPP
#define PROGRAMOWANIEGIER_SINGLETON_HPP

template<typename T>
class Singleton{
	protected:
		Singleton(){}
	public:
		static T& get(){
			static T instance;
			return instance;
		}
		
		Singleton(Singleton const&) = delete;
		
		void operator =(Singleton const&) = delete;
};

#endif //PROGRAMOWANIEGIER_SINGLETON_HPP
