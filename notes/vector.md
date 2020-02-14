## **<font color="black">头文件：</font>**

```c++
#include<vector>
template < class T, class Alloc = allocator<T> > class vector; 
```

+ **<font color="black">特点：</font>**

> 1. 连续分配空间
> 2. 通过“重新配置、元素移动、释放元空间”实现动态扩容
> 3. 每次分配时多分配空间，避免每次添加元素时均需扩容（类似Java的StringBuffer）
> 若vector原始大小为0，则分配1,若vertor原始大小不为0，则分配2倍

## **<font color="black">构造函数：</font>**

```c++
default:
  vector<int> a;
fill:
  vertor<int> b(10);
  vector<int> c(10,1);
range:
  vector<int> d(c.begin, c.end);
copy:
  vector<int> e(c); //Assume c is ref
move:
  vector<int> f(&c); //Assume c is ref
initializer list:
  int array[] = {1,2,3,4,5};
  vector<int> g(array, array + sizeof(array)/sizeof(int));
```

## **<font color="black">容量判断：</font>**

```c++
vector<int> v;
v.size();            //向量大小
v.capacity();        //向量容量
v.resize();          //更改向量大小
v.shrink_to_fix();   //减小向量大小到满足所占存储空间大小:
```

## **<font color="black">元素set与get：</font>**

> 获取某个元素
```c++
vector<int> v;
v.front();            //
v.back();
v[1];      //不检查越界
v.at(1);   //检查越界
```
> 添加或删除某个元素
```c++
vector<int> v;
v.assign(5, 10);          //加入5个10
v.push_back(10);          //在尾部 添加10

v.insert(a.begin(), 1);   
v.insert(a.begin(),2,20);  
v.insert(a.begin(),v1.begin(),v1.begin()+2);    
                         
a.pop_back();           
a.erase(a.begin());    
a.erase(a.begin() + 1, a.end());    
a.erase(begin,end);
a.clear();              
```

## **<font color="black">迭代器</font>**

> 分为常量迭代器与非常量
```c++
vector<int> v;
v.begin();           
v.end();

v.cbegin(); //const
v.cend();   //const
```

> 遍历方法
```c++
vector<int> v;
//Method 1
for(int i=0; i<v.size(); i++){
    cout << v[i];
}

//Method 2
vector<int>:: iterator it;
for(it = v.begin(); it != v.end(); it++){
    cout << *it;
}
```

## **<font color="black">排序</font>**
```c++
vector<int> v;
```
> 反转
```c++
#include<algorithm>
reverse(v.begin(), v.end());
```

> 升降序
```c++
#include <algorithm>
...
sort(a.begin(), a.end());               //默认按升序排序，即从小到大。


/* 如果想按降序排序 */
//方式1：可先sort()升序排序，再调用reverse()进行翻转
//方式2：采用与C语言中qsort()类似的方式
bool compare(const int &a, const int &b)
{
    return a > b;   //'>'是降序
}
sort(a.begin(),a.end(),compare);



//qsort()使用区别：compare返回值必须为int,参数必须是const void *，'>'表示升序，'<'表示降序，与sort()中相反
int compare(const void *value1, const void *value2)
{
    return *(int *)value1 - *(int *)value2 > 0 ? 1 : -1;    //这样是升序排序
    return *(int *)value1 - *(int *)value2 > 0 ? -1 : 1;    //这样是降序排序
}

qsort(arr, num, sizeof(arr[0]), compare);
```
