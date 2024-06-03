#include <bits/stdc++.h>
using namespace std;
int partation(vector<int> & arr , int B, int L) {
    int start=B, end = L , Pivot_Postion=B;
    while (true) {
        while ( arr[Pivot_Postion]<=arr[end] && Pivot_Postion!=end) {
            end--;
        }
        if(Pivot_Postion==end)
            break;
        if(arr[Pivot_Postion]> arr[end]) {
            swap(arr[Pivot_Postion],arr[end]);
            Pivot_Postion=end;
        }
        while (arr[Pivot_Postion]>arr[start] && Pivot_Postion!=start) {
            start++;
        }
        if(Pivot_Postion == start)
            break;
        if ( arr[Pivot_Postion]<arr[start] ) {
            swap(arr[Pivot_Postion],arr[start]);
            Pivot_Postion=start;
        }
    }
    return Pivot_Postion;
}

void QuickSort(vector<int>& arr , int s,int e){
    if(s<e) {
        int pivot = partation(arr,s,e);
        QuickSort(arr,s,pivot-1);
        QuickSort(arr,pivot+1,e);
    }
}
int main() {
    vector arr={10,30,0,-1,11,5,4};
     QuickSort(arr,0,6) ;
    for (auto i :arr) {
        cout<<i<<"  ";
    }
}
