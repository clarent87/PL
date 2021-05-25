#include <iostream>
#include <string>
#include <thread>

void f1()                { }
void f2(int a, double d) { }
void f3(int a, int& b, std::string&& s) { b = 100;} // 이거 string의 move생성자 호출될듯

int main()
{
    int n = 0;
    std::string s = "hello";

    // 쓰레드의 func에 파라메터를 넘길때는 아래와 같이 넘기면된다. 
    // cpp은 가변인자가 가능하기 때문( c면 구조체?로 넘겨야 한다함 )
    std::thread t1(&f1);
    std::thread t2(&f2, 10, 3.4); 
    std::thread t3(&f3, 10, std::ref(n), std::move(s) ); // [*] 중요! 쓰레드간에 참조를 넘길때는 std::ref를 써야함, rvalue는 그냥 move쓰면되고.. 
                                                        // [*] 근데 특정 쓰레드의 지역변수 n을 다른 쓰레드로 보내는건 굉장히 위험하니, 조심해야한다. 
                                                        // [*] 왜냐면 해당 쓰레드가 죽어버리면 n참조는 잘못된 참조가 되기 때문
                                                        // [*] std::ref는 레퍼런스 래퍼 이다
                                                        // [*] ref3.cpp예제를 보면 원리는 알수 있는데, 아마 n을 넣으면 t3의 생성자가 int n으로 되기 때문일듯
                                                        // [*] 즉, function에 파라메터가 다이렉트로 들어가는게 아닌,, 한다리 거치니까.. std::ref가 필요한것으로 보임
    t1.join();
    t2.join();
    t3.join();

    std::cout << s << std::endl; // "" [*] 이거 s가 move로 f3에 넘어갔기 때문에 자원을 상실해서 그런다. (아마 move생성자 때문일듯)
    std::cout << n << std::endl; // 100
}


