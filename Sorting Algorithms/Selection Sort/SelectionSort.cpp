#include <bits/stdc++.h>
using namespace std;

/*
 * Averge = Best = Worst =O(n^2) (every Case)
 * Selection sort is comparison-based sorting algorithm. It's not as efficient as some more advanced algorithms like quicksort or mergesort for large datasets, but it is straightforward and easy to understand. It works by repeatedly finding the minimum (or maximum) element from the unsorted portion and moving it to the beginning (or end) of the sorted portion.
 * When to Use Selection Sort:
    *Small Arrays: Similar to insertion sort, selection sort is efficient for small arrays due to its simplicity and low overhead.
    *Memory Constraint: Selection sort performs well in scenarios where memory usage is a concern, as it sorts the array in place.
    *Educational Purposes: Its simplicity makes it an excellent choice for teaching sorting algorithms.
 *Space Complexity: O(1) (In-place sorting)
 *comparisons:
        *The number of comparisons in selection sort is always the same regardless of the input arrangement, which is:(n(n-1))/2 ~=O(n^2)
        *This is because each element is compared with every other element in the unsorted portion of the array
*Moves =3(n-1) ~=O(n)
 */


// Function to perform selection sort on an array Using Big number of Swaps , Swaps = O(n)
vector<int> Selsection_Sort(vector<int> &arr ,int SIZE) {
    int Swaps=0;
    for(int i=0 ,j;i<SIZE ;i++) {
        int Tmp=i;
        for (j=i;j<SIZE;j++) {
            if(arr[j]<arr[Tmp])
                Tmp=j;
        }
        swap(arr[Tmp],arr[i]);
        Swaps++;
    }
    cout<<"Number Of Swaps is: "<<Swaps<<endl; // Number Of Swaps is: 7
    return arr;
}

// Function to perform selection sort on an array Using minimum number of Swaps < O(n)
vector<int> SelsectionSort(vector<int> &arr ,int SIZE) {
    int Swaps=0;
    for(int i=0 ,j;i<SIZE ;i++) {
        int minIndex=i;
        for (j=i;j<SIZE;j++) {
            if(arr[j]<arr[minIndex])
                minIndex=j;
        }
        if(minIndex!=i) {

            swap(arr[minIndex],arr[i]);
            Swaps++;
        }
    }
    cout<<"Number Of Swaps is: "<<Swaps<<endl; //Number Of Swaps is: 5
    return arr;
}

int main() {
    cout<<"Ahmed Amr"<<endl;
    vector<int >arr={10,30,0,-1,11,5,4};
    vector<int >arr2={10,30,0,-1,11,5,4};
    auto v=Selsection_Sort(arr , arr.size() );
    auto vv=SelsectionSort(arr2 , arr2.size() );
    for (auto i :v) {
        cout<<i<<"  ";
    }
    cout<<endl<<"======================="<<endl;
    for (auto i :vv) {
        cout<<i<<"  ";
    }
}