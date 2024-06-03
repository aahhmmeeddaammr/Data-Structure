#include <bits/stdc++.h>
using namespace std;
/*
 *Bubble sort is   comparison-based sorting algorithm.It repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process is repeated until the list is sorted.
 *Complexity  of Bubble Sort:
    *Best Case:
        *Time Complexity: O(n^2) when the array is already sorted we Can Immprove it to be O(n).
        *Swaps O(1) => NO Swaps
        *comparison O(1) => No comparison
    *Worst and Average Case Time Complexity: O(n^2).
 *Space Complexity: O(1) because it is  an in-place sorting algorithm.
 *Worst Case(Reverse ordered data):
    *The Outter Loop execute (n-1) Times
        *Comparisons:Zero
        *Swaps:Zero
        *Moves:0
    *the Inner Loop execute n(n-1)/2 Times
        *Comparisons: 1comparison  [arr[j] > arr[j + 1]] (n(n-1))/2 Times
        *Swaps: 1 Swap [wap(arr[j],arr[j+1]);] (n(n-1))/2 Times (can Make it less than this number)
        *Moves: 3 moves  (n(n-1))/2 Times
    *Total comparison : n (n - 1) / 2 ~= O(n^2)
    *Total Swaps : n (n - 1) / 2 ~= O(n^2)
    *Total Moves : 3 n (n – 1) / 2 ~=O(n^2)
 *Average Case:
    *The Outter Loop execute (n-1) Times
        *Comparisons:Zero
        *Swaps:Zero
        *Moves:0
    *the Inner Loop execute n(n-1)/2 Times
        *Comparisons: 1comparison  [arr[j] > arr[j + 1]] (n(n-1))/2 Times
        *Swaps: 1 Swap [wap(arr[j],arr[j+1]);] (n(n-1))/2 Times (can Make it less than this number)
        *Moves: 3 moves  (n(n-1))/2 Times
    *Total comparison : n (n - 1) / 2 ~= O(n^2)
    *Total Swaps : n (n - 1) / 2 ~= O(n^2)
    *Total Moves : 3 n (n – 1) / 2 ~=O(n^2)
    *
 *Applications of Bubble Sort:
    *Educational Purposes:
        *Teaching Tool: Bubble sort is often used to introduce the concept of sorting algorithms to beginners because of its simplicity and easy-to-understand mechanics. It helps students grasp the basics of comparison-based sorting algorithms.
        *Algorithm Analysis: Bubble sort is useful for demonstrating algorithmic concepts such as time complexity, space complexity, and the process of optimization.
    *Small Data Sets:
        *For very small datasets, the simplicity of bubble sort can sometimes make it a viable choice. The overhead of more complex sorting algorithms is not justified for small inputs.
    *Detecting Sortedness [In Second CPP implementation Only ]
 *
 */
// Function to perform bubble sort on an array With Best Case O(n^2)
vector <int> Bubble_Sort(vector <int> &arr,int SIZE) {
    // Loop through each element in the array
    for (int i=0 ; i<SIZE ; i++) {
        // Inner loop to compare adjacent elements
        for (int j=0 ; j<SIZE-i-1 ; j++) {
            if(arr[j]>arr[j+1]){
                // Swap the elements if they are in the wrong order
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return arr;// Return the sorted array
}

// Function to perform bubble sort on an array With Best Case O(n)
vector <int> BubbleSort(vector <int> &arr,int SIZE) {
    bool swapped; // Flag to check if a swap was made in the inner loop
    // Loop through each element in the array
    for (int i = 0; i < SIZE - 1; i++) {
        swapped = false; // Reset the swapped flag
        // Inner loop to compare adjacent elements
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements if they are in the wrong order
                swap(arr[j], arr[j + 1]);
                swapped = true; // Set the swapped flag
            }
        }
        // If no elements were swapped in the inner loop, the array is already sorted
        if (!swapped) {
            break;
        }
    }
    return arr; // Return the sorted array
}
int main() {
    cout<<"Ahmed Amr"<<endl;
    vector<int >arr={10,30,0,-1,11,5,4};
    vector<int >arr2={10,30,0,-1,11,5,4};
    auto v=Bubble_Sort(arr , arr.size() );
    auto vv=BubbleSort(arr2 , arr2.size() );
    for (auto i :v) {
        cout<<i<<"  ";
    }
    cout<<endl<<"======================="<<endl;
    for (auto i :vv) {
        cout<<i<<"  ";
    }
}