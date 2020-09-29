#include <iostream>
#include <string>
#include <list>

#include <ext\mt_allocator.h>

using namespace std;

int main()
{
    list<string, __gnu_cxx::__mt_alloc<string> > ls;

    return 0;
}