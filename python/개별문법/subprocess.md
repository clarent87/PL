# 쉘 명령어 실행

기본적으로 exe는 내 메모리를 실행할 실행파일로 덮어씌우는 거임.  ( 원래 리눅스에서도 exe함수들은 그런 원리 인듯)


```python 
obj = subprocess.run("ls /", check=True) 
# check명시하면 프로세스 수행후 실패시 자동으로 exception 발생
# obj.check_returncode()를 호출한 것과 같음

```
https://soooprmx.com/archives/5932
https://docs.python.org/3/library/subprocess.html