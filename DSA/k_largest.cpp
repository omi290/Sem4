#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//using quickselect algorithm 

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickselect(vector<int>& arr, int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);
        if (pi == k) return arr[pi];
        else if (pi > k) return quickselect(arr, low, pi - 1, k);
        else return quickselect(arr, pi + 1, high, k);
    }
    return -1;
}

int main(){
    int T;
    cout<<"Enter test cases: ";
    cin>>T;
    while(T--){
        int n,k;
        cout<<"\nEnter array size : ";
        cin>>n;
        vector<int> arr(n);
        cout<<"Enter the elements to array : ";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<"Enter key : ";
        cin>>k;
        if(k>n || k < 1){
            cout<<"Not Present. \n";
            break;
        }
        int ans = quickselect(arr,0,n-1,k-1);
        cout<<"The element is : "<<ans<<endl;
    }
    
    return 0;
}