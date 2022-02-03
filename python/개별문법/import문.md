# Import/from 문

### Import 기본

기본은 모듈(.py같은 단일파일)에 대해 쓰는거라고 보면 된다.  

기본은 네임 스페이스를 구성하는 것

가령 `sss.py` 란 파일이 있다면, `import sss` 는 sss.py안에 있는 함수 변수를 sss란 네임스페이스에 넣는거라고 보면됨.  

이렇게 된 경우 함수 사용은  `sss.func()` 이렇게 네임스페이스를 붙여서 써야 함. 만약 네임스페이스를 변경하고 싶다면 `import sss as ttt` 로 작성하면 된다.  

### from 기본

기본은 현재 namespace로 정의를 가져오는 것인다.  

가령 `from sss import func` 라고 했다면 현재 namespace로 func 함수를 가져왔기 때문에

`func()` 를 곧바로 쓸수 있다. `sss.func()` 는 에러다, sss란 네임스페이스를 가져온적 없기 때문

`from  sss import *` 는 모든 정의를 현재 네임스페이스에 가져오는 건데 `__all__` 키워드로 제어 가능

> 주의! 위 코드는 모듈의 가장 윗쪽 줄에서만 사용가능 >> 검증은 안해봄..

### 심화 - 패키지

폴더 트리형태로 py파일 등을 관리 할수 있는데, 이걸 패키지 라고 한다. 폴더 여도 좋고 zip파일이어도 좋다

둘다 import 문으로 사용 가능.

*물론 최적화가 되냐 안되냐 차이는 있는것으로 보임.*

패키지의 경우 `__init__.py`  파일이 매우 중요하게 사용된다.  왜냐면

패키지 명만 import한다고 해서 해당 패키지의 모듈들을 사용할수 있는것은 아니기 때문에 ( 모듈이 로딩되지 않음), 패키지 안에 `__init__.py`를 만들어서 명시적으로 패키지 이름 import시 하위 패키지 모듈이 import되도록 작업해 주어야 한다.  

위 설명을 예로 보면

```text
LIB
├── __init__.py
└── algorithms
   ├── __init__.py
   ├── array.py
└── tests
    ├── __init__.py
    └── test_array.py
```

일때

`import LIB , import LIB.algorithms` 불가능

→ 단, `__init__.py`에 모듈 로딩 코드가 있다면 가능

`import LIB.algorithms.array` 는 가능

from 문도 기본과 같은 개념으로 사용가능
