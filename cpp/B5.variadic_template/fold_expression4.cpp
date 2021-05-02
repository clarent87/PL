/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : fold_expression4.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

template<typename ... Types> void foo(Types ... args)
{
	int n1 = (args + ...); // (1 + (2 + 3) )

	(args, ...) // 1 , ( 2, 3 ) // "," 도 이항 연산자다. 
				// [*] 중요한것은 args 자리에 parameter pack에서 나왔던 패턴도 사용할 수 있다. 

	(v.push_back(args), ...); // ( v.push_back(1), (v.push_back(2), v.push_back(3)))
							  // 즉, v.push_back(args)...의 패턴은 v.push_back(args)니까 위에서 설명했든 fold expenssion에 패턴 사용함.

							  // 즉 위코드는 fold expenssion을 이용해서 가변인자의 모든 내용을 벡터에 담는내용.

	for (auto n : v)
		cout << n << endl;
}

int main()
{
	foo(1, 2, 3);
}