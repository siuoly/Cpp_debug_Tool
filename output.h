// must include 
/* using namespace Tool;  */

/* 
// Usage
int main( ){
  using namespace Tool;  // must include

  std::cout << vector<int>(5,10) ;
    // 10 10 10 10 10

  vector< vector<int>> v2{ {1,2,3}, {4,5,6} };
  std::cout << v2;
  // 1 2 3
  // 4 5 6
  // size(2,3)


  array< float,5> a1{};
  std::cout << a1;
    // 0 0 0 0 0 

  array< array<long,3>, 5> a2{ {{1,2,3},{4,5,6},{7,8,9}}  };
  std::cout << a2;

  std::cout << list<int>{ 1,2,3,4,5 } ;
  // 1->2->3->4->5


  cout << make_tuple( 1,2,3,'a',1.123) ;
  cout << make_pair('a',10);

  cout << map{ make_pair("a",1) , 
              make_pair("b", 2) } ;

}

*/


#ifndef OUTPUT_H
#define OUTPUT_H

#include <vector>
#include <array>
#include <deque>
#include <utility>
#include <tuple>
#include <list>
#include <map>

namespace Tool{
	using namespace std;

  //vector 1D
  template<typename T>
  std::ostream& operator<<(std::ostream& os,const vector<T>& v)
  {
    for(const auto &i:v) os << i << ' '; return os;
  }

  //vector 2D
  template<typename T>
  std::ostream& operator<<(std::ostream& os,const vector<vector<T>>& v)
  { 
    for(auto& i:v) os << i <<endl;  
    os << "size: (" << v.size() << "," << v[0].size() << ")"<<endl;
    return os; 
  }

  // array
  template< typename T , size_t N >
  std::ostream& operator<<(std::ostream& os,const array<T,N>& a)
  { for(auto& i:a) os << i ; return os; }
   
  // array 2D
  template< typename T ,size_t m ,size_t n >
  std::ostream& operator<<(std::ostream& os,const array< array<T,n> ,m>& a)
  { 
    for( auto& i:a) os << i << endl;
    os <<"size:(" << a.size() << ','<< a[0].size() << ')' << endl; 
    return os; 
  }
   

  //deque 1D
  template<typename T>
  std::ostream& operator<<(std::ostream& os,const deque<T>& v)
  {
    for(const auto &i:v) os << i << ' '; return os;
  }

  // list
  template< typename T >
    std::ostream& operator<<(std::ostream& os,const std::list<T>& li )
    {   
      auto i = li.begin();
      if( i!= li.end())  os << *i; 
      ++i; 
      for( ; i!=li.end(); ++i)
        os << "-->" << *i ;

      return os;
    }

  // tuple: cout << make_tuple( 1,2,3,'a',1.123) 
  template<class TupType, size_t... I>
    std::ostream& tuple_print(std::ostream& os,
        const TupType& _tup, std::index_sequence<I...>)
    {
      os << "(";
      (..., (os << (I == 0 ? "" : ", ") << std::get<I>(_tup)));
      os << ")";
      return os;
    }
  template<class... T>
    std::ostream& operator<< (std::ostream& os, const std::tuple<T...>& _tup)
    {
      return tuple_print(os, _tup, std::make_index_sequence<sizeof...(T)>());
    }


  // pair: cout << make_pair('a',10);
  template< class T,class U >
    std::ostream& operator<<(std::ostream& os,const pair<T,U> &p)
    {
      os << '(' << p.first << ',' << p.second << ')' ;
      return os;
    }

  // map: 
  template< class T, class U >
    std::ostream& operator<<(std::ostream& os, const std::map<T,U> &m )
    {
      for( const auto& i:m)
        os << i.first<< ":" << i.second << std::endl;
      return os; 
    }
}
#endif 
