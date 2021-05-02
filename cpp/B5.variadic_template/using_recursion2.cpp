#include<iostream>
#include<tuple>
using namespace std;

void foo() {} // 재귀의 종료를 위해서.. (사실 재귀가 아니긴 함)

template<typename T, typename ... Types> void foo(T value, Types ... args)
{
    // --- 재귀같지만 재귀가 아님을 증명하는 코드
    static int n = 0;
    ++n;

    cout << n << endl;
    // --- end

    foo(args...); // foo(3.4,"AA")
                  // foo("AA") 
                  // foo() 
                  // 사실 위 함수들이 전부만들어 지는것. 따라서 foo함수가 큰경우는 사용을 지양하는게 좋다. 
    
}

int main()
{
    foo(1,3.4,"AA"); // args : 1,3.4,"AA"
}

// parameter pack에서 각 요소를 꺼내는 방법
// 1. pack expansion -> 배열 또는 tuple에 담아서 쓴다. 
// 2. 재귀 호출과 유사한 호출식을 사용한다.
//   - 모든 인자를 가변 인자로 하지 말고, 1번쨰 인자는 이름 있는 변수로 받는다. 
// 3. Fold Exprossion사용 -> c++ 17부터..  (다음예제에서 나옴.)