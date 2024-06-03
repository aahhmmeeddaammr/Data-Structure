#include <bits/stdc++.h>
using namespace std;
/*
 *Cases of Insertion Sort
    *Best Case (Nearly Sorted): O(n)
    *Average and Worst Case:O(n^2)
    *Space Complixty: O(1)
 *Insertion sort is particularly useful in the following scenarios:
    *Nearly Sorted Arrays: If the array is already nearly sorted, insertion sort performs very efficiently, with a time complexity close to 𝑂(𝑛).
    *This is because it only has to make a few comparisons and shifts for each element.
    *Small Arrays: For small arrays, the overhead of more complex algorithms like quicksort or mergesort is not justified. Insertion sort is simple and has a low constant factor in its 𝑂(𝑛^2) time complexity.
    *Real-Time Systems: Insertion sort can be used when the list is continuously updated with new elements. The new element can be placed in its correct position using insertion sort, and this incremental sorting is efficient.
    *Educational Purposes: It is easy to understand and implement, making it a good choice for teaching the basics of sorting algorithms.
*
 */

/*
 * insertion sort is comparison Sort
     *number of comparisons in insertion sort:
        *Best Case:
            * Outer loop n – 1
                *tmp < data [j-1];  1 comparison x n – 1
            *Total comparison=n−1
            *In the best case, the array is already sorted. For each element, insertion sort will make one comparison to confirm it is already in the correct place.
                *For the first element, no comparison are made.
                *For the second element, one comparison is made.
                *For the third element, one comparison is made, and so on.

        *Worst Case:
            *Outer loop n – 1
                *tmp < data [j-1];  1 comparison x n – 1
            *Inner Loop executes, 1, 2, …, n – 1
                *For each inner loop, there is 1 comparison
            *Total Comparaisons=(1 + 2 + …. + (n - 1)) = n (n – 1) / 2 ~= O(n^2)
            *In the worst case, the array is sorted in reverse order. Every element must be compared with all previously sorted elements.
                *For the first element, no comparison are made.
                *For the second element, one comparison is made.
                *For the third element, two comparisons are made, and so on.
        *Average Case:
            *Outer loop n – 1
                *tmp < data [j-1];  1 comparison x n – 1
            *Inner Loop executes, 1, 2, …, n – 1
                *For each inner loop, there is 1/2 comparison ( (i/2) Because it is the average)
            *Total comparisons=(1 + 2 + …. + (n - 1))/2 = n (n – 1) / 4 ~= O(n^2)
            *The average case analysis assumes that each element is equally likely to be in any position in the sorted array. On average, each element is expected to be compared with half of the previously sorted elements.
                *For the first element, no comparisons are made.
                *For the second element, one comparison is made.
                *For the third element, on average, 1.5 comparisons are made, and so on.
            *number of comparisons in the average case is:(n(n−1))/4 ~=n^2
 */


/*
 * Moves in Insertion Sort
 * Best Case (when the data is in Correct order)
    * Outer loop executes(n – 1)Times
        *T tmp = data [i];  1 move x n – 1 times
        *data [j] = tmp;    1 move x n – 1 times
    *Moves: 2 (n - 1)

    * Average Case
    * Outer loop executes(n – 1)Times
        *T tmp = data [i];  1 move x n – 1 times
        *data [j] = tmp;    1 move x n – 1 times
        *Total Moves in Outer Loop = 2(n-1)
    *Inner loop executes, 1, 2, …, n – 1
        *For each inner loop, there is on average i /2 Moves ( (i/2) Because it is the average)
        *Total Moves in Inner Loop = (1 + 2 + …. + (n - 1))/2 ~=(n (n – 1) )/ 4
    *Total Number Of Moves= Total Moves in Inner Loop+Total Moves in Outer Loop =(1 + 2 + …. + (n - 1))/2 +2(n-1) =n2/4 + 7n/4 – 2 ~=O(n2)
    *


    *Worst Case (when the data is in reverse order)
    * Outer loop executes(n – 1)Times
        *T tmp = data [i];  1 move x n – 1 times
        *data [j] = tmp;    1 move x n – 1 times
        *Total Moves in Outer Loop = 2(n-1)
    *Inner loop executes, 1, 2, …, n – 1 and In Inner Loop there is 1 Move (arr[j] = arr[j - 1];)
        *Total Moves in Inner Loop : (1 + 2 + …. + (n - 1))~=n(n-1)/2
    *Moves = Total Moves in Inner Loop +Total Moves in Outer Loop  =(1 + 2 + …. + (n - 1)) +2(n-1)=n^2/2 + 3n/2 – 2 ~= n^2

 */
// Function to perform insertion sort on an array using  For Loop
vector<int> insertion_Sort(vector<int>& arr, int SIZE) {
    // Start with the second element in the array (index 1)
    for (int i = 1; i < SIZE; i++) {
        int j; // Variable to track the position for shifting elements
        int Key = arr[i]; // Key value to be compared and inserted into the sorted portion
        // Shift elements of the sorted portion of the array to the right to create the position for Key
        for (j = i; j > 0 && Key < arr[j - 1]; j--) {
            arr[j] = arr[j - 1]; // Move elements one position to the right
        }
        // Place the Key value in its correct position within the sorted portion
        arr[j] = Key;
    }
    // Return the sorted array
    return arr;
}

// Function to perform insertion sort on an array using While Loop
vector<int> insertionSort(vector<int>& arr, int SIZE) {
    // Start with the second element in the array (index 1)
    for (int i = 1; i < SIZE; i++) {
        int j = i;// Variable to track the position for shifting elements
        int Key = arr[i];// Key value to be compared and inserted into the sorted portion
        // Shift elements of the sorted portion of the array to the right to create the position for Key
        while (j > 0 && Key < arr[j - 1]) {
            arr[j] = arr[j - 1];// Move elements one position to the right
            j--;
        }
        // Place the Key value in its correct position within the sorted portion
        arr[j] = Key;
    }
    // Return the sorted array
    return arr;
}
int main() {
    cout<<"Ahmed Amr"<<endl;
    vector<int >arr={10,30,0,-1,11,5,4};
    vector<int >arr2={10,30,0,-1,11,5,4};
    auto v=insertion_Sort(arr , arr.size() );
    auto vv=insertion_Sort(arr2 , arr2.size() );
    for (auto i :v) {
        cout<<i<<"  ";
    }
    cout<<endl<<"======================="<<endl;
    for (auto i :vv) {
        cout<<i<<"  ";
    }
}
