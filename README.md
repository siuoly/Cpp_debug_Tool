# Cpp_debug_Tool
直接cout 各種容器,vector,map,tuple,....等等的lib。使用template完成

支援列表:vector,array,deque,list,pair,tuple,map

用法:

##   #include "output.h"

**!!**`using namespace Tool;`

### vector

```cpp
std::cout << vector<int>(5,10) ;   // 10 10 10 10 10
// 2-dimension vector
vector< vector<int>> v2{ {1,2,3}, {4,5,6} }; 
std::cout << v2;	 // 1 2 3
									// 4 5 6
									// size(2,3)
```

### array

```cpp
array< float,5> a1{};
std::cout << a1;  // 0 0 0 0 0
array< array<long,3>, 4> a2{ {{1,2,3},{4,5,6},{7,8,9}}  };                                           std::cout << a2;
// 123
// 456
// 789
// 000
// size:(4,3)
```

### list

```cpp
  std::cout << list<int>{ 1,2,3,4,5 } ;                                                                   // 1->2->3->4->5
```
### pair

```cpp
cout << make_pair('a',10);  // (a,10)
```
### tuple

```cpp
cout << make_tuple( 1,2,3,'a',1.123); // (1, 2, 3, a, 1.123)
// nested tuple
cout << make_tuple(
  make_tuple("Hello",'w',"orld", make_tuple(123)),
 1,2,3,'a',1.123) << '\n'; }
// ((Hello, w, orld, (123)), 1, 2, 3, a, 1.123)
```

### map

```cpp
  cout << map{ make_pair("a",1) ,
              make_pair("b", 2) } ;
// a:1
// b:2
```

