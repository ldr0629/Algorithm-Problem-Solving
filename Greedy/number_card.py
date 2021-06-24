n, m = map(int, input().split())

result = 0
# 한 줄씩 입력받아 확인
for i in range(n): 
  data = list(map(int, input().split()))
  # 현재 행에서 최솟값 찾기
  min_data = min(data)
  # 최솟값 중 가장 큰 수 찾기
  result = max(result, min_data)
 
print(result) 
