#include <string_view> // for type_name()

/* // usage */
/* int& foo_lref(); */
/* int&& foo_rref(); */
/* int foo_value(); */
/* int main( ){ */
/*   int i = 0; */
/*   const int ci = 0; */
/*   std::cout << "decltype(i) is " << type_name<decltype(i)>() << '\n'; */
/*   std::cout << "decltype((i)) is " << type_name<decltype((i))>() << '\n'; */
/*   std::cout << "decltype(ci) is " << type_name<decltype(ci)>() << '\n'; */
/*   std::cout << "decltype((ci)) is " << type_name<decltype((ci))>() << '\n'; */
/*   std::cout << "decltype(static_cast<int&>(i)) is " << type_name<decltype(static_cast<int&>(i))>() << '\n'; */
/*   std::cout << "decltype(static_cast<int&&>(i)) is " << type_name<decltype(static_cast<int&&>(i))>() << '\n'; */
/*   std::cout << "decltype(static_cast<int>(i)) is " << type_name<decltype(static_cast<int>(i))>() << '\n'; */
/*   std::cout << "decltype(foo_lref()) is " << type_name<decltype(foo_lref())>() << '\n'; */
/*   std::cout << "decltype(foo_rref()) is " << type_name<decltype(foo_rref())>() << '\n'; */
/*   std::cout << "decltype(foo_value()) is " << type_name<decltype(foo_value())>() << '\n'; */
/*   std::cout << type_name<const double>() << '\n'; */  
/* } */

// 輸出物件型態, 使用__PRETTY_FUCTION__
// https://stackoverflow.com/a/20170989/12506676 

#ifndef TYPENAME_H
#define showtype(x) cout << type_name<x>() << '\n';
#define showobj(x) cout << type_name<decltype(x)>() << '\n';

#endif 


template <typename T>
constexpr auto type_name() noexcept {
  std::string_view name = "Error: unsupported compiler", prefix, suffix;
#ifdef __clang__
  name = __PRETTY_FUNCTION__;
  prefix = "auto type_name() [T = ";
  suffix = "]";
#elif defined(__GNUC__)
  name = __PRETTY_FUNCTION__;
  prefix = "constexpr auto type_name() [with T = ";
  suffix = "]";
#elif defined(_MSC_VER)
  name = __FUNCSIG__;
  prefix = "auto __cdecl type_name<";
  suffix = ">(void) noexcept";
#endif
  name.remove_prefix(prefix.size());
  name.remove_suffix(suffix.size());
  return name;
}

