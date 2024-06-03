#include <bits/stdc++.h>
using namespace std;

/*
 *Shell Sort is a generalization of insertion sort that allows the exchange of items that are far apart. The idea is to arrange the list of elements so that, starting anywhere,taking every nth  element produces a sorted list. Such a list is said to be n-Sorted . Initially, the list is n-Sorted for a large value of n. The value of nis then reduced and the list is n-Sorted for the new value of n This process continues until n=1. When n=1, the list is sorted using a basic insertion sort.
 *The Worst Case if O(n^2)
 *Some cases may be O(n(logn)^2)
 *When to Use Shell Sort:
    *Intermediate List Sizes: Shell sort is more efficient than bubble sort, selection sort, and insertion sort for medium-sized lists.
    *When Memory Usage is a Concern: Shell sort is an in-place sorting algorithm, meaning it doesn't require additional memory for a separate array.
    *Non-uniform Distribution of Elements: Shell sort can handle non-uniform distributions of elements well and often performs better than other quadratic time-complexity sorting algorithms in such cases.
    *Improved Performance over Insertion Sort: Shell sort can be particularly useful when the array size is moderately large (a few thousand elements), where insertion sort would be too slow.
 *
 */



// Function to perform Shell Sort on the given array
// arr: the array to be sorted
// SIZE: the size of the array
vector<int> Shell_Sort(vector<int>& arr, int SIZE) {
    // Start with a large gap, then reduce the gap
    for (int Gap = SIZE / 2; Gap > 0; Gap /= 2) {
        // Perform a gapped insertion sort for this gap size
        for (int i = Gap, j = 0; i < SIZE; i++) {
            int Key = arr[i];  // Store the current element
            // Shift earlier gap-sorted elements up until the correct location for Key is found
            for (j = i; j >= Gap && Key < arr[j - Gap]; j -= Gap) {
                arr[j] = arr[j - Gap];
            }
            // Put Key in its correct location
            arr[j] = Key;
        }
    }
    return arr;  // Return the sorted array
}


int main() {
    cout<<"Ahmed Amr"<<endl;
    vector<int >arr={10,30,0,-1,11,5,4};
    // vector<int >arr2={10,30,0,-1,11,5,4};
    auto v=Shell_Sort(arr , arr.size() );
    // auto vv=insertion_Sort(arr2 , arr2.size() );
    for (auto i :v) {
        cout<<i<<"  ";
    }
    // cout<<endl<<"======================="<<endl;
    // for (auto i :vv) {
    //     cout<<i<<"  ";
    // }
}