# 전문가를 위한 파이썬

## 4장 텍스트와 바이트

### 4.4

- python 2.5는 소스코드 인코딩은 ascii, python 3부터는 utf-8

## 14장

### 14.10

- `yield from`
  - 제네레이터 여러개를 합칠때 씀. 약간 flatmap 같은 느낌 
  - 예제는 다음과 같다. 
  - `yield from` 없을때
    ```python
    def chain(*iterables):
        for it in iterables:
            for i in it:
                yield i
    
    s = 'ABC'
    t = tuple(range(3))
    list(chain(s,t))
    ```
  - `yield from` 버전
    ```python
    def chain(*iterables):
        for i in iterables:
            yield from i
    
    s = 'ABC'
    t = tuple(range(3))
    list(chain(s,t))
    ```

## 16장 코루틴

- 제너레이터 변경점
  - 기존 제너레이터는 return으로 기타 값을 return하면 종료하는 거고 이때 SyntaxError가 발생하였음
    - > none반환시  stopIteration 에러 발생하고 이걸 받아서 처리하는게 보통이었음 ( foreach구현이나 list 컴프리헨션같은것들이 이 예외로 제너레이터의 끝을 인식할듯)
  - 이제는 제너레이터에서 값을 반환할수 있다. 
  - 이때 값은 StopIteration의 value로 넘어옴.

- `@coroutine` 데코레이터 -578p
  - 코루틴 사용시 next를 먼저 해줘야하는데 이거 안써도 되게 해줌
  - `yield from` 과 `@coroutine` 데코레이터는 함께 쓸수 없다. 

- p588 🌟 코루틴과  `yield from` 에 대한 중요한 내용이다. 
  - > 이해하는데 큰 어려움은 없다. 확실함.

## 17장 future 동시성

> 다시 봐야 할듯.. 기본적인 threadpool, processpool에서 받은 객체에대 map method 쓰는거 까지 봄.

## asyncio

> 일단 조대표 async 랑 await 설명은 간단함. 물론 function 이 뭐가 있는지는 애매하지만..
> 책 내용은 전혀 이해가 안됨

- 참고 링크
  - https://kdw9502.tistory.com/6
    - > 최신 같음
  - https://dojang.io/mod/page/view.php?id=2469
    - > 3.7이하 asyncio사용
    - > 이게 그나마 설명이 이해가 가는듯
  - https://wikidocs.net/117438

- async with  
  - https://soooprmx.com/async-%EB%B9%84%EB%8F%99%EA%B8%B0-%EC%BB%A8%ED%85%8D%EC%8A%A4%ED%8A%B8-%EB%A7%A4%EB%8B%88%EC%A0%80/