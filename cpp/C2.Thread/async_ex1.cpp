#include <chrono>
#include <iostream>
#include <future>
#include <random>
#include <vector>
#include <string>
#include <numeric>
#include <execution>

static const int NUM = 100000000; // 1억

std::vector<int> v1, v2;

// 두개의 벡터에 1억번 돌면서 난수를 채워주는 코드
void fill_vector()
{
    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<int> dist(0,100);

    v1.reserve(NUM);
    v2.reserve(NUM);

    for (int i=0; i< NUM; ++i)
    {
        v1.push_back(dist(engine));
        v2.push_back(dist(engine));
    }
}


// 두 벡터의 내적, 한큐에 두개를 내적함
long long f1()
{
    return std::inner_product(v1.begin(), v1.end(), v2.begin(), 0LL);
}

// 두 벡터의 내적, 쓰레드 4개에 두 벡터의 구간을 나누어서 내적
long long f2()
{
    auto future1= std::async([]{return std::inner_product(&v1[0],            &v1[v1.size()/4],  &v2[0],0LL);});
    auto future2= std::async([]{return std::inner_product(&v1[v1.size()/4],  &v1[v1.size()/2],  &v2[v1.size()/4],0LL);});
    auto future3= std::async([]{return std::inner_product(&v1[v1.size()/2],  &v1[v1.size()*3/4],&v2[v1.size()/2],0LL);});
    auto future4= std::async([]{return std::inner_product(&v1[v1.size()*3/4],&v1[v1.size()],    &v2[v1.size()*3/4],0LL);});

    return future1.get() + future2.get() + future3.get() + future4.get(); // 따로 구한 결과를 더함
}

// 함수 포인터를 받아서 해당 함수의 걸리는 시간을 측정
void measure_execution_time( std::string name, long long(*f)()  )
{
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now(); 
    long long result = f();
    std::chrono::system_clock::time_point end  = std::chrono::system_clock::now(); 

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    
    std::cout << name << " : " << result << ", " << time_span.count() << " seconds." << std::endl;;
}

int main()
{
    fill_vector();
    std::cout << "start.. inner_product" << std::endl;
    measure_execution_time("f1", f1);
    measure_execution_time("f2", f2);
}

// 두 함수의 성능차이는 g++환경에서 12배나 남