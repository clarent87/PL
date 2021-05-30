// g++ reorder1.cpp –S –masm=intel -O2
// cl reorder1.cpp /FAs /c /O2
#include <atomic>
int a = 0;
int b = 0;

// thread A
void foo()
{
    a = b + 1;
    
    //----- fence -----------
    //__asm { mfence } // [*] 이건 intel명령어 fence instruction은 cpu마다 다르다. 
                        //[*] fence위의 명령어는 아래로 내려오지 못함
                        //[*] 즉, mov a eax가 b=1아래로 내려가는 것이 방지됨
                        //[*] 잘못생각하면, 컴파일시에만 opcode 순서 맞추면 되는게 아닌가 싶은데, reordering은 실행시간에도
                        //[*] 일어날수 있다고 하니까, mfence opcode가 있는 것으로 보임
    std::atomic_thread_fence( std::memory_order_release); // [*] cpp 표준에서 제공하는 fence
    
    b = 1;
}

// thread B
void goo()
{
    if ( b == 1 )
    {
        // a == 1 을 보장할수 있을까 ? 
        // [*] 원래 foo은 a = b + 1; b = 1; 만 있는 코드 였다. 
        // [*] 이때 foo thread 및 goo thread가 동작했다면, 
        // [*] foo가 먼저 돌아서 b=1을 실행했다면,  a = b + 1은 그 전에 완료가 되었을테니  a==1이어야 정상.. 이지 않냐? 란 질문
        // [*] 답) -- 중요 -- 
        // [*] 최적화 없이 빌드 했을때 asm파일을 보면 코드의미 그대로 asm파일이 나옴 즉, b==1이면 a==1를 보장할 수있음
        // [*] but -O2 주고 빌드하면 asm이 의도와는 다르게 나옴 (b에1 넣고, 그다음 a에 값이 업데이트 되는 형태로 asm이 나옴)
        // [*] 따라서 b==1일때 a==1임을 보장하지 못함
    } 
}






