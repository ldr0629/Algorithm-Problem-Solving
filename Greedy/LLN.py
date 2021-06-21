n, m, k = map(int, input().split()) # m의 크기가 매우 커지는 경우 (시간 초과를 고려한 코드)
data = list(map(int, input().split()))

data.sort() 
max_one = data[n-1]
max_two = data[n-2]

# 가장 큰 수가 더해지는 횟수 계산
count = int(m / k + 1) * k  # m을 k+1로 나눈 몫은 수열이 반복되는 횟수이고 이에 k를 곱해준 것은 가장 큰 수가 등장하는 횟수.
count += m % k + 1 # m이 k+1로 나누어떨어지지 않는 경우 m을 k+1로 나눈 나머지만큼 가장 큰 수가 추가적으로 더해진다.
 
 
result = 0 
result += count * max_one 
result += (m - count) * max_two

print(result)
