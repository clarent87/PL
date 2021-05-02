#include <iostream>
using namespace std;

// Step 1.  가변인자 템플릿 
template<typename ... Types> struct xtuple
{
	static constexpr int N = 0; // 저장하고 있는 요소갰수.
};

int main()
{
	xtuple<>		          t0;
	xtuple<int>		          t1;
	xtuple<int, char>         t2;
	xtuple<int, char, double> t3;

}
 
// tuple 만들기. 
// 1. 가변 인자 템플릿을 사용해서 primary template을 만든다. 
