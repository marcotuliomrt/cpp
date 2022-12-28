import time

def MA(X, n):
  y = 0
  for i in range(n):
    y = 0
    for j in range(i):
      y += X[j]
    y = y/(i+1)
  return round(y,2)

def MA_v2(X, n):
  y = 0
  for i in range(n):
    # y = 0
    # for j in range(i):
    #   y += X[j]
    # y = y/(i+1)
    y += X[i]
  y = y/n
  return round(y,2)


if __name__ == "__main__":
  start = time.time()
  x= [3,2,1,6,4,2,1,0]
  print(MA(x, len(x)))
  end = time.time() - start
  print(f"Demorou: {end}")

  start = time.time()
  x= [3,2,1,6,4,2,1,0]
  print(MA_v2(x, len(x)))
  end = time.time() - start
  print(f"Demorou: {end}")