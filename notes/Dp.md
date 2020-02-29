## DP

+ 状态表示
  - 集合
  - 集合的属性: Max/Min/数量
+ 状态计算、集合的划分


```c++
1. 最大子序列和
  vector<int> nums;
  res = max(f[0], f[1], ... f[n-1])
  f[i] = max(f[i-1], 0) + nums[i]
```

```c++
2. 打家劫舍
  vector<int> nums; (nums[i] > 0)
  f[i] 前i个数中选，不选nums[i]
  g[i] 前i个数选，选择nums[i]
  res = max(f[i], g[i])
  f[i] = max(f[i-1], g[i-1])
  g[i] = f[i-1] + nums[i]
```

```c++
3. LIS
  vector<int> nums;
  分类：以i为结尾的上升子序列
  属性：长度最大值
  f[i] = max(f[j]+1) (j<i && f[j]<f[i])
```

```c++
4. 单词距离
  string w1, w2
  insert: f[i, j-1] + 1
  delete: f[i, j]
  repalce: f[i-1, j-1]
  none: f[i-1, j-1] + 1
```
