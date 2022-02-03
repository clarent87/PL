# argment 관련

positional arguments와 keyword arguments
https://mingrammer.com/understanding-the-asterisk-of-python/#positional-arguments%EB%A7%8C-%EB%B0%9B%EC%9D%84-%EB%95%8C

## argparse

```python
import argparse

parser = argparse.ArgumentParser(description='Process some integers.')
parser.add_argument('integers', metavar='N', type=int, nargs='+',
                    help='an integer for the accumulator')
parser.add_argument('--sum', dest='accumulate', action='store_const',
                    const=sum, default=max,
                    help='sum the integers (default: find the max)')

# metavar은 help에 출력되는 이름
# dest는 변수 이름. 
# position arg인 경우 add_argument의 첫번째 인자가 dest의 값으로 사용됨 ( 즉 dest 명시 하면 에러나는데,, 딱히 문서에 설명은 없네.. )
# type의 경우 명령행 인자를 1차적으로 가공하는 함수. (즉, type 처리후 choice 검사가 진행됨)
```