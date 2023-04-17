# dp

## max-profit-with-k-transactions

### 문제

prices = [5, 11, 3, 50, 60, 90] 
k = 2

prices의 인덱스는 날짜임, k는 거래 횠수 즉 위 날짜에서 2번 거래해서 최대이익을 
보면 얼마인지 알려줘야함

- 중요 포인트
  - share를 하루에 하나밖에 가지지 못함. 이게 핵심
  - 즉 [5, 11, 3, 50, 60, 90]  에서 3에 사서 90에 하나의 주식을 팔았다면
  - 나머지 하나의 tx는 [5,11] 에서 읽어나야함.
  - > 그리고 max_diff는 각 단계마다 구해 둘수 있음. 수식상.. ( 이거 수식 찾는게 난관이겠네..)

### 해답

- chatgpt를 이용한 해답은 정확하긴 한데, 설명은 이상했음. 

```python
def max_profit(prices, k):
    if not prices:
        return 0
    
    n = len(prices)
    if k >= n//2:
        return sum(max(prices[i+1]-prices[i], 0) for i in range(n-1))
    
    dp = [[0]*n for _ in range(k+1)]
    for i in range(1, k+1):
        max_diff = -prices[0]
        for j in range(1, n):
            dp[i][j] = max(dp[i][j-1], prices[j]+max_diff)
            max_diff = max(max_diff, dp[i-1][j]-prices[j])
    
    return dp[k][n-1]
    
# example usage
prices = [5, 11, 3, 50, 60, 90]
k = 2
print(max_profit(prices, k))  # output: 93

```
