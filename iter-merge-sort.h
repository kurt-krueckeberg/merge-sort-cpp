#ifndef ITER_MERGE_SORT_H
#define ITER_MERGE_SORT_H

#include <algorithm>

// TODO: First just get it running for arrays using indecies, then, convert it to use iterators.

/*
 * For an excellent explanation of this algorithm see:
   http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/7-Sort/merge-sort5.html
 */
namespace algolib {
/*
 * Two different iterator types might not actually needed. It may be that a random access iterator type is always required for both.
 */
template<typename Iterator, typename Comparator> static void merge(Iterator first, Iterator mid,
        Iterator last,
        Iterator buffer_start,
        Comparator C);


//--template<typename Iterator, typename T, Comparator comparer> T *merge_sort(Iterator first, Iterator last, Comparator comparer)
/*
 * Code below from http://www.sinbadsoft.com/blog/a-recursive-and-iterative-merge-sort-implementations/
 *
public static T[] Iter_Merge_Sort(T[] array, IComparer<T> comparer)
{
    for (int i = 1; i <= array.Length / 2 + 1; i *= 2) {

        for (int j = i; j < array.Length; j += 2 * i)  {

            Merge(array, j - i, j, Math.Min(j + i, array.Length), comparer);
        }
    }
 
    return array;
}

static void Merge(T[] array, int start, int middle, int end, IComparer<T> comparer)
{
    T[] merge = new T[end - start];

    int l = 0, r = 0, i = 0;

    while (l < middle - start && r < end - middle)     {
         
        merge[i++] = comparer.Compare(array[start + l], array[middle + r]) < 0 ? array[start + l++] : array[middle + r++];
    }
 
    while (r < end - middle) {

         merge[i++] = array[middle + r++];
    }
 
    while (l < middle - start) {

         merge[i++] = array[start + l++];
    }
 
    Array.Copy(merge, 0, array, start, merge.Length);
}

// converter version

template<typename T, typename Comparator> void Merge(T[] array, int start, int middle, int end, T *temp_buffer,  Comparator compare)
{
    int left = 0, right = 0, i = 0;

    while (left < middle - start && right < end - middle)     {
         
        if ( compare(array[start + l], array[middle + right]) ) {

            temp_buffer[i++] = array[start + l++];

        } else { 

            temp_buffer[i++] = array[middle + right++];
        }
    }
 
    while (right < end - middle) {

         temp_buffer[i++] = array[middle + right++];
    }
 
    while (left < middle - start) {

         temp_buffer[i++] = array[start + l++];
    }
 
    Array.Copy(temp_buffer, 0, array, start, temp_buffer.Length);
}

 */
template<typename T, Comparator comparer> T *merge_sort(T *array, int first, int last, Comparator comparer)
{
    auto length = last + 1 - first;

    T  *temp_buffer = new T[length];

    for (int width = 1; i <= length / 2 + 1; width *= 2)  { /
          
        for (int i = 0; i < length; i += 2 * width) {
            
            /*
             * input: array, first, mid, last, comparator -- where mid is an inclusive endpoint.
             *
             */

            //--algo::merge(a, j - i, j, Math.Min(j + i, array.Length), temp_buffer, comparer);
            int   start = i; 

            int     mid = i + width - 1;

            int tmp_end = i + 2 * width; 

            --tmp_end;

            int     end = std::min(tmp_end, length - 1); 

            algo::merge(array, start, mid, end, temp_buffer, comparer);
        }
    }
 
    return a;
}

/*
 * Merges subarrays  [first, mid] and [mid + 1, last] into a sorted array in working buffer, buffer_start. Then copies the working buffer 
 * over the original segement [first, last]
 */

template<typename T, typename Comparator> static void merge(T *array, int first, int mid, int last,
                                                                  T *buffer_start, Comparator compare)
{
    int first1 = first;
    int last1 = mid;
    
    int first2 = mid + 1;
    int last2 = last;
        
    int index = 0;
    
    /* 
     * While both sub-arrays are not empty, copy the smaller item into the 
     * temporary array buffer.
     */
    int buffer_cursor = buffer_start;
    
    for (; first1 <= last1 && first2 <= last2; ++buffer_cursor) {
        
        if ( compare(*first1, *first2) ) {
            
            *buffer_cursor = *first1++;

        } else {
            
            *buffer_cursor = *first2++;
        }
    }
    
    // finish off the first sub-array, if necessary
    for (;first1 <= last1; ++first1, ++buffer_cursor) {
        
        *buffer_cursor = *first1;
    }
    
    // finish off the second sub-array, if necessary
    for (;first2 <= last2; ++first2, ++buffer_cursor) {
        
        *buffer_cursor = *first2;
    }
         
   // Copy the temp array to the original array
   int length = last + 1 - first;

   int start = buffer_start;
   
    for (int end = start + length; start != end;) {
        
        *first++ = *start++;
    }
}


} // end namespace
#endif
