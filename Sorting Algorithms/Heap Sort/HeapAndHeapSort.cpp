#include <bits/stdc++.h>
using namespace std;
void heapify( vector<int> & arr , const int  SIZE , int i ) {
    const int left =  i * 2  + 1 ,  right = i * 2 + 2  ;
    int MAX = i;
    if( left < SIZE && arr[left] > arr[MAX])
        MAX=left;
    if( right < SIZE && arr[right] > arr[MAX])
        MAX=right;
    if(MAX != i) {
        swap(arr[i],arr[MAX]);
        heapify(arr, SIZE , MAX);
    }
}
void build_Heap(vector<int> & arr ) {
        heapify(arr,arr.size(),0);
    // for (int i = arr.size()/2 -1  ; i >= 0  ;i--) {
    // }
}

void heapsort( vector <int> & arr) {
    build_Heap(arr);
    for (int i = arr.size()-1  ; i >=0; i --) {
        swap (arr[0] , arr[i] );
        heapify(arr ,i , 0);
    }
}
 // 1(p [0] ) 2(c1 (L)  [1] ) 3(c2 (R) [2]  ) 4 5 8 9 6 4
int main () {

}