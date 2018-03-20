/*
 *
 * (C) Copyright John Maddock 1999-2005. 
 * Use, modification and distribution are subject to the 
 * Boost Software License, Version 1.0. (See accompanying file 
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 *
 * This file provides some example of type_traits usage -
 * by "optimising" various algorithms:
 *
 * opt::copy - optimised for trivial copy (cf std::copy)
 *
 */

#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <iterator>
#include <memory>
#include <cstring>

#include <chrono>
#include <type_traits>
// #include <boost/test/included/prg_exec_monitor.hpp>
// #include <boost/timer.hpp>
// #include <boost/type_traits.hpp>

template<typename _Tp>
struct has_trivial_assign : public std::integral_constant<bool, std::is_pod<_Tp>::value>
{ };

using std::cout;
using std::endl;
using std::cin;

namespace opt{

//
// opt::copy
// same semantics as std::copy
// calls memcpy where appropriate.
//

namespace detail{

template<typename I1, typename I2, bool b>
I2 copy_imp(I1 first, I1 last, I2 out, const std::integral_constant<bool, b>&)
{
   while(first != last)
   {
      *out = *first;
      ++out;
      ++first;
   }
   return out;
}

template<typename T>
T* copy_imp(const T* first, const T* last, T* out, const std::true_type&)
{
   memmove(out, first, (last-first)*sizeof(T));
   return out+(last-first);
}


}

template<typename I1, typename I2>
inline I2 copy(I1 first, I1 last, I2 out)
{
   //
   // We can copy with memcpy if T has a trivial assignment operator,
   // and if the iterator arguments are actually pointers (this last
   // requirement we detect with overload resolution):
   //
   typedef typename std::iterator_traits<I1>::value_type value_type;
   return detail::copy_imp(first, last, out, has_trivial_assign<value_type>());
}

}   // namespace opt

namespace non_opt
{

template<typename I1, typename I2>
inline I2 copy(I1 first, I1 last, I2 out)
{
   return opt::detail::copy_imp(first, last, out, std::false_type());
}
}

//
// define some global data:
//
const int array_size = 1000;
int i_array_[array_size] = {0,};
const int ci_array_[array_size] = {0,};
char c_array_[array_size] = {0,};
const char cc_array_[array_size] = { 0,};
//
// since arrays aren't iterators we define a set of pointer
// aliases into the arrays (otherwise the compiler is entitled
// to deduce the type passed to the template functions as
// T (&)[N] rather than T*).
int* i_array = i_array_;
const int* ci_array = ci_array_;
char* c_array = c_array_;
const char* cc_array = cc_array_;

const int iter_count = 1000000;

int main()
{
   typedef std::chrono::high_resolution_clock Clock;
   typedef std::chrono::milliseconds duration;

   int i;
   cout << "Measuring times in milli-seconds per 1000 elements processed" << endl << endl;
   cout << "testing copy...\n"
   "[Some standard library versions may already perform this optimisation.]" << endl;
   
   // cache load:
   opt::copy(ci_array, ci_array + array_size, i_array);

   // time optimised version:
   auto start = Clock::now();
   for(i = 0; i < iter_count; ++i)
   {
      opt::copy(ci_array, ci_array + array_size, i_array);
   }
   auto result = std::chrono::duration_cast<duration>(Clock::now() - start);
   cout << "opt::copy<const int*, int*>: " << result.count() << endl;

   // cache load:
   non_opt::copy(ci_array, ci_array + array_size, i_array);

   // time non-optimised version:
   start = Clock::now();
   for(i = 0; i < iter_count; ++i)
   {
      non_opt::copy(ci_array, ci_array + array_size, i_array);
   }
   result = std::chrono::duration_cast<duration>(Clock::now() - start);
   cout << "non_opt::copy<const int*, int*>: " << result.count() << endl;

   // cache load:
   std::copy(ci_array, ci_array + array_size, i_array);

   // time standard version:
   start = Clock::now();
   for(i = 0; i < iter_count; ++i)
   {
      std::copy(ci_array, ci_array + array_size, i_array);
   }
   result = std::chrono::duration_cast<duration>(Clock::now() - start);
   cout << "std::copy<const int*, int*>: " << result.count() << endl;

   // cache load:
   opt::copy(cc_array, cc_array + array_size, c_array);

   // time optimised version:
   start = Clock::now();
   for(i = 0; i < iter_count; ++i)
   {
      opt::copy(cc_array, cc_array + array_size, c_array);
   }
   result = std::chrono::duration_cast<duration>(Clock::now() - start);
   cout << "opt::copy<const char*, char*>: " << result.count() << endl;

   // cache load:
   non_opt::copy(cc_array, cc_array + array_size, c_array);

   // time optimised version:
   start = Clock::now();
   for(i = 0; i < iter_count; ++i)
   {
      non_opt::copy(cc_array, cc_array + array_size, c_array);
   }
   result = std::chrono::duration_cast<duration>(Clock::now() - start);
   cout << "non_opt::copy<const char*, char*>: " << result.count() << endl;

   // cache load:
   std::copy(cc_array, cc_array + array_size, c_array);

   // time standard version:
   start = Clock::now();
   for(i = 0; i < iter_count; ++i)
   {
      std::copy(cc_array, cc_array + array_size, c_array);
   }
   result = std::chrono::duration_cast<duration>(Clock::now() - start);
   cout << "std::copy<const char*, char*>: " << result.count() << endl;

   return 0;
}