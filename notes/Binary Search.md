## Binary Search

+ 存在两段性的性质

+ 模板
**L**  <font color="red">+----------------------------+</font><font color="green">+----------------------------+</font>  **R**
**M为L,R中点**

1. 搜索最左侧绿色点
  - M为绿色：**[L, R] -> [L, M] (即R = M)**
  - M为红色：**[L, R] -> [M+1, L] (即L = M+1)**
  - **mid =  floor(L+2)/2 = L + R >> 1** 

2. 搜索最右侧红色点
  - M为红色：**[L, R] -> [M, R] (即L = M)**
  - M为绿色：**[L, R] -> [L, M-1] (即R = M-1)**
  - **mid =  ceil(L+2)/2 = L + R + 1 >> 1**

