#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;

std::mutex       m1, m2, m3;
std::timed_mutex tm1, tm2, tm3;

int main()
{   
	std::unique_lock<std::mutex> u1; // [*] ( 생성자에 뮤텍스 없잖아) 즉 아직 뮤텍스 연결안됨, 즉 나중에 뮤텍스 연결하겠다믄것 
    std::unique_lock<std::mutex> u2(m1);                    // 생성자에서 m1.lock() 즉, lock_guard와 동일

   	std::unique_lock<std::mutex> u3(m2, std::try_to_lock);  // m2.try_lock() 호출됨 즉 non-block lock
	
    if ( u3.owns_lock() ) // [*] try_lock의 경우 결과를 확인해야 하니까 owns_lock api 필요, 즉 lock 소유했는지 확인
        std::cout << "acquire lock" << std::endl;
    else 
        std::cout << "fail to lock" << std::endl;


	m3.lock();
	std::unique_lock<std::mutex> u4(m3, std::adopt_lock);   // 이미 lock 을 획득한 뮤텍스 관리


	std::unique_lock<std::timed_mutex> u5(tm1, std::defer_lock); // [*] 나중에 lock 을 호출하겠다는것
                                                            // [*] std::timed_mutex를 넘긴건 아래 예제 보여주려고.
	auto ret = u5.try_lock_for(2s); // [*] lock을 직접 호출


    std::unique_lock<std::timed_mutex> u6(tm2, 2s);  // tm2.try_lock_for(2s) 사용
    std::unique_lock<std::timed_mutex> u7(tm3, std::chrono::steady_clock::now() + 2s );
                                                    // tm3.try_lock_until(시간) 사용
}
// shared_mutex 관리만 빠져있는데,, 이건 lock_shared에서 하는 것