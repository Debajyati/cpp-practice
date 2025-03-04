#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k) {
    deque<int> dq;  // Stores indexes of elements in decreasing order
    
    for (int i = 0; i < n; i++) { 
        // Remove elements that are out of the current window
        if (!dq.empty() && dq.front() == i - k) { 
            dq.pop_front();  // Remove element that is out of the window
        }
        // Remove elements from back that are smaller than the current element
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();  // Remove smaller elements as they are useless
        }
        // Add current element index to deque
        dq.push_back(i);

        // Print max element of window (only after first k elements)
        if (i >= k - 1) {
             cout << arr[dq.front()] << " ";
        }
    }
    cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
