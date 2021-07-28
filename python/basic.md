# 기본 문법

## 변수 scope

python은 block scope는 없음.  
> 근데 프로그래머스 코테에서는 아래 answer 에러 발생
```python
  for x in participant:
        if cp_hash[x]:
            continue
        else:
            answer = x
    
    return answer # 어사인 되기전 사용하였다는 에러 발생.. 아.. else안타면.. 그럴수도..

```
