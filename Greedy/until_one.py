# N이 문제에서 매우 큰 수가 되는 경우 효율적인 풀이 
n, k = map(int, input().split())
result = 0

while True:
  target = (n//k) * k 
  result += (n - target) # N이 K의 배수가 되도록 한 번에 빼는 방식
  n = target
  if n < k:
    break
  result += 1
  n //= k

result += (n-1) 
print(result)
