/* 
 * File:   main.cpp
 * Author: kurt
 *
 * Created on May 12, 2014, 10:46 AM
 */

#include <cstdlib>
#include <array>
#include "new-generic-merge-sort.h"
#include "print-array.h"

using namespace std;

int main(int argc, char** argv) 
{
    array<int, 10> a{ 9, 8, 7, 5, 0, 4, 10, 2, 3, 1};
    
    int size = a.size();
    
    merge_sort(a, 0, size - 1);
    
    //--print_array(a, 0,  size - 1);     
      
    return 0;
}

