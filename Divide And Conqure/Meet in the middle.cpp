
// https://cses.fi/problemset/result/2943874/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define setbits(n) __builtin_popcountll(n);
 
// void merge(int arr[], int low, int mid, int high) {
// 	// left arry index -> [low .. mid]
// 	// right arry index -> [mid+1..high]
 
// 	int l = low;
// 	int r = mid + 1;
// 	vector<int> temp;
// 	while(l <= mid && r <= high) {
// 		if(arr[l] <= arr[r]) {
// 			temp.push_back(arr[l++]);
// 		}
// 		else {
// 			temp.push_back(arr[r++]);
// 		}
// 	}
 
//     // if the right ran out and we still have something on the left
// 	while(l<=mid) {
// 		temp.push_back(arr[l++]);
// 	}
 
// 	// if the left ran out and we still have something on the right
// 	while(r<=high) {
// 		temp.push_back(arr[r++]);
// 	}
 
// 	// temp will have elements in the index-> [0, 1, 2, 3....] -> [high - low + 1] elements
// 	// you need to rearrange them in [low...mid....high]
 
// 	// copying back
 
// 	int j = 0;
// 	for(int i = low; i<=high;i++) {
// 		arr[i] = temp[i - low]; // (low - low) // (low + 1 - low) // (low + 2 - low)
// 		// getting confused then right this
// 		// arr[i] = temp[j++];
// 	}
 
// }
 
// void mergeSort(int arr[], int low, int high) {
// 	if(low >= high) return;
 
// 	int mid = (low + high) >> 1;
// 	// once this recursion is solve
// 	mergeSort(arr, low, mid);
// 	// once this recursion is solved
// 	mergeSort(arr, mid+1, high);
 
// 	// i will have the left part sorted and the right part also sorted
// 	merge(arr, low, mid, high);
// }
 
 
 
 
// int merge(int arr[], int low, int mid, int high) {
// 	// left arry index -> [low .. mid]
// 	// right arry index -> [mid+1..high]
 
// 	int l = low;
// 	int r = mid + 1;
// 	vector<int> temp;
// 	int cnt = 0;
// 	while(l <= mid && r <= high) {
// 		if(arr[l] <= arr[r]) {
// 			temp.push_back(arr[l++]);
// 		}
// 		else {
// 			cnt += mid - l + 1;
// 			temp.push_back(arr[r++]);
// 		}
// 	}
 
//     // if the right ran out and we still have something on the left
// 	while(l<=mid) {
// 		temp.push_back(arr[l++]);
// 	}
 
// 	// if the left ran out and we still have something on the right
// 	while(r<=high) {
// 		temp.push_back(arr[r++]);
// 	}
 
// 	// temp will have elements in the index-> [0, 1, 2, 3....] -> [high - low + 1] elements
// 	// you need to rearrange them in [low...mid....high]
 
// 	// copying back
 
// 	int j = 0;
// 	for(int i = low; i<=high;i++) {
// 		arr[i] = temp[i - low]; // (low - low) // (low + 1 - low) // (low + 2 - low)
// 		// getting confused then right this
// 		// arr[i] = temp[j++];
// 	}
// 	return cnt;
// }
 
// int mergeSort(int arr[], int low, int high) {
// 	if(low >= high) return 0;
 
// 	int mid = (low + high) >> 1;
// 	// once this recursion is solve
// 	int left = mergeSort(arr, low, mid);
// 	// once this recursion is solved
// 	int right = mergeSort(arr, mid+1, high);
 
// 	// i will have the left part sorted and the right part also sorted
// 	int cnt = merge(arr, low, mid, high);
 
// 	return cnt + left + right;
// }
 
 
 
 
// void mergeSort(int arr[], int low, int high) {
// 	if(low >= high) return;
 
// 	int mid = (low + high) >> 1;
// 	// once this recursion is solve
// 	mergeSort(arr, low, mid);
// 	// once this recursion is solved
// 	mergeSort(arr, mid+1, high);
 
// 	// i will have the left part sorted and the right part also sorted
// 	merge(arr, low, mid, high);
// }
 
 
 
 
// void merge(int arr[], int low, int mid, int high) {
// 	// left arry index -> [low .. mid]
// 	// right arry index -> [mid+1..high]
 
// 	int l = low;
// 	int r = mid + 1;
// 	vector<int> temp;
// 	while(l <= mid && r <= high) {
// 		if(arr[l] <= arr[r]) {
// 			temp.push_back(arr[l++]);
// 		}
// 		else {
// 			temp.push_back(arr[r++]);
// 		}
// 	}
 
//     // if the right ran out and we still have something on the left
// 	while(l<=mid) {
// 		temp.push_back(arr[l++]);
// 	}
 
// 	// if the left ran out and we still have something on the right
// 	while(r<=high) {
// 		temp.push_back(arr[r++]);
// 	}
 
// 	// temp will have elements in the index-> [0, 1, 2, 3....] -> [high - low + 1] elements
// 	// you need to rearrange them in [low...mid....high]
 
// 	// copying back
 
// 	int j = 0;
// 	for(int i = low; i<=high;i++) {
// 		arr[i] = temp[i - low]; // (low - low) // (low + 1 - low) // (low + 2 - low)
// 		// getting confused then right this
// 		// arr[i] = temp[j++];
// 	}
 
// }
 
// int counting(int arr[], int low, int mid, int high) {
// 	int l = low;
// 	int r = mid+1;
// 	int cnt = 0;
// 	for(int i = r;i<=high;i++) {
// 		while(l<=mid && a[l] <= 2*a[r]) l++;
 
// 		cnt += (mid - l + 1);
// 	}
// 	return cnt;
// }
 
// int mergeSort(int arr[], int low, int high) {
// 	if(low >= high) return 0;
 
// 	int mid = (low + high) >> 1;
// 	// once this recursion is solve
// 	int left = mergeSort(arr, low, mid);
// 	// once this recursion is solved
// 	int right = mergeSort(arr, mid+1, high);
// 	int cnt = counting(arr, low, mid, high);
// 	// i will have the left part sorted and the right part also sorted
// 	merge(arr, low, mid, high);
 
// 	return cnt + left + right;
// }
 
void generateSum(int ind, int size, int arr[],
                 unordered_map<int, int> &sumMap, int sum) {
	if (ind > size) {
		sumMap[sum]++;
		return;
	}
	// pick
	generateSum(ind + 1, size, arr, sumMap, sum + arr[ind]);
 
	// not pick
	generateSum(ind + 1, size, arr, sumMap, sum);
}
 
 
void mim(int arr[], int n, int k) {
	unordered_map<int, int> leftSum, rightSum;
	int mid = n / 2;
	if(n % 2 == 0) mid--; 
	generateSum(0, mid, arr, leftSum, 0);
	generateSum(mid + 1, n - 1, arr, rightSum, 0);
 
	int cnt = 0;
	for (auto it : leftSum) {
		int c1 = it.second; 
		int c2 = rightSum[k - it.first]; 
		cnt += (c1 * c2);
	}
	cout << cnt;
}

 
signed main() {

	int n;
	cin >> n;
	int k;
	cin >> k;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
 
	mim(arr, n, k);
 
	return 0;
 
}


 