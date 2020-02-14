## 并查集

+ 在计算机科学中，**并查集**是一种树型的数据结构，用于**处理一些不交集（Disjoint Sets）的合并及查询问题**。有一个**联合-查找算法**（**union-find algorithm**）定义了两个用于此数据结构的操作：

  > **Find**：**确定元素属于哪一个子集**。这个**确定方法就是不断向上查找找到它的根节点**，它可以**被用来确定两个元素是否属于同一子集**。
  >
  > **Union**：**将两个子集合并成同一个集合**。

+ 实现

1. 基本实现

   ```c++
   /*
    * 使用一个数组模拟集合，初始化时另father[i] = i
   */
   int Find(int element){
       if(father[element] == element)
           return element;
       else
           return Find(element)
   }
   
   void Union(int element_a, int element_b){
       int parent_a = Find(element_a);
       int parent_b = Find(element_b);
       father[parent_b] = parent_a;
   }
   ```

2. 变形（记录每个集合元素个数）

   ```c++
   /*
    * 初始化时将father数组初始化为-1，在Union时在每个集合的代表元素中记录每个集合的元素个数，以-N表示，
    * 其余元素用正数记录其父元素
   */
   int Find(int element){
       if(father[element] == -1)
           return element;
       else
           return Find(element);
   }
   
   void Union(int element_a, int element_b){
       int parent_a = Find(element_a);
       int parent_b = Find(element_b);
       father[parent_a] += father[parent_b]; 
       father[parent_b] = parent_a;
   }
   ```

3. 优化——路径压缩

   ```c++
   /*
    * 在执行Find操作时将沿途节点直接连接到根上
   */
   int Find(int element){
       if(father[element] == -1)
           return element;
       else
           return father[element] = Find(element);
   }
   
   int Find(int element){
       int root = element;
       while(root != father[root])
           root = parent[root];
       
       int ptr = element;
       int temp;
       while(ptr != root){
           temp = parent[ptr];
           parent[ptr] = root;
           ptr = temp;
   	}
       return root;
   }
   ```

4. 优化——按秩合并

   ```c++
   /*
    * 使用秩表示树的深度，将较小的树连接到较大的树上。单位树深度为0，合并时两树高度相同则合并后树秩加一
    * 这里使用了rank数组储存了各集合的秩，father数组初始化为i
    * 也可parent数组使用负数表示秩以代替rank数组，但需注意下标问题
   */
   int Find(int element){
       if(father[element] == element)
           return element;
       else
           return Find(element)
   }
   
   void Union(int element_a, int element_b){
       int parent_a = Find(element_a);
       int parent_b = Find(element_b);
       
       if(parent_a == parent_b)
           return;
       if(rank[parent_a] < rank[parent_b])
           parent[parent_a] = parent_b;
       else{
           parent[parent_b] = parent_a;
           if(rank[parent_a] == rank[parent_b])
               rank[parent_a]++;
       }
   }
   ```

   

