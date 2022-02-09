# 쓰레드 관련

- ThreadFactory  
  - 말 그래도 Thread를 어떻게 만들지 알려주는것
  - newThread method를 override해야하는데 보통 new Thread 를 이용함
  - ThreadPoolExecutor 의 param으로 줄수도 있음

- ThreadPoolExecutor
  - ThreadPool 만드는것
  - ExecutorService 를 반환. 보통 개발에 이걸이용해서 task를 넘긴다.

- 동작 원리 주의 사항
  - https://leeyh0216.github.io/posts/truth_of_threadpoolexecutor/