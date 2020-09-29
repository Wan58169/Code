#include <iostream>

// allocator头文件声明
#include <ext\array_allocator.h>
#include <ext\mt_allocator.h>
#include <ext\debug_allocator.h>
#include <ext\pool_allocator.h>
#include <ext\bitmap_allocator.h>
#include <ext\malloc_allocator.h>
#include <ext\new_allocator.h>

using namespace std;

int main()
{
    int *p;

    // default_allocator
    allocator<int> a1;
    p = a1.allocate(1);
    a1.deallocate(p, 1);

    // mt_allocator
    __gnu_cxx::__mt_alloc<int> a2;
    p = a2.allocate(1);
    a2.deallocate(p, 1);

    // pool_allocator
    __gnu_cxx::__pool_alloc<int> a3;
    p = a3.allocate(1);
    a3.deallocate(p, 1);

    // bitmap_allocator
    __gnu_cxx::bitmap_allocator<int> a4;
    p = a4.allocate(1);
    a4.deallocate(p, 1);

    // new_allocator
    __gnu_cxx::new_allocator<int> a5;
    p = a5.allocate(1);
    a5.deallocate(p, 1);

    // malloc_allocator
    __gnu_cxx::malloc_allocator<int> a6;
    p = a6.allocate(1);
    a6.deallocate(p, 1);

    // array_allocator
    __gnu_cxx::array_allocator<int> a7;
    p = a7.allocate(1);
    a7.deallocate(p, 1);

    return 0;
}