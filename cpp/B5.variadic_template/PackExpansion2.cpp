/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : PackExpansion2.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <tuple>
using namespace std;

// Type Expansion (pack expansion 아님!!)
template<typename ... Types> void foo()
{
	// Types : int, char
	pair<Types...>  p1; // pair<int, char>   ok
	tuple<Types...> t1; // tuple<int, char>  ok

	tuple<pair<Types...>> t2;  // tuple<pair<int, char>>
	tuple<pair<Types>...> t2_1; // error, tuple<pair<int>,pair<double>> 이되는데 pair는 type이 두개가 필요해서 error
	tuple<pair<int, Types>...> t4; // tuple< pair<int, int>, pair<int, char>> ok..
    
	pair<tuple<Types...>> p2; // pair< tuple<int, char> >  error , pair인자가 하나라서.. error
	pair<tuple<Types>...> p3; // pair< tuple<int>, tuple<char>> ok

	
	
}

int main()
{
	foo<int, char>();
}
