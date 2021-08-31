/*
 * Useage
#include <iostream>

int main(){
	using namespace Tool;

	Dice<float> d;
	for(int i=100;i;--i)
		std::cout << d() << ' ';  
  // or cout << d ;
    
	Dice<int> d2(12,30);
	for(int i=100;i;--i)
		std::cout << d2() << ' ';
	
}
*/
#ifndef DICE_H
#define DICE_H

#include <type_traits>
#include <random>
#include <chrono>
#include <vector>
#include "Interval.h"

namespace Tool{
	template<class T=int >
	struct Dice{
			typename std::conditional
				< std::is_integral<T>::value ,
				std::uniform_int_distribution<T> ,
				std::uniform_real_distribution<T> >::type dist;

			std::default_random_engine generator;

			Dice(T start=0, T end=100)
				:dist(start, end){
				generator.seed( current_count() );
			}

			T operator()(){ return  dist(generator); }
			operator T(){ return  dist(generator); }

	};

	template<class T>
	std::vector<T> make_vector(int size, T start=0 , T end=100) {
		std::vector<T> v; v.reserve(size);
		Tool::Dice<T> d(start,end);
		for(int i=0;i<size;++i) v.push_back( d );
		return  v;
	}


	
}
#endif 
