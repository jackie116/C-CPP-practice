//Maximum Subarray Sum
//Divide and Conquer 
#include <iostream>
#include<vector>
using namespace std;
vector<int> right_edge;
vector<int> left_edge;
int count_vec=-1; 
int num_vec=0;
int num_m=0;
//比大小
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int max(int a, int b, int c) { return max(max(a, b), c); }
//從中間往兩旁加到最大
int max_plus(int arr[], int l, int m, int h)
{
	count_vec++;
	left_edge.push_back(0);
	right_edge.push_back(0);
	int count = 0;
	int temp=0;
	int sum = 0;
	int left_sum = 0;
	for (int i = m; i >= l; i--)
	{
		if (arr[i] < 0)count++;
		if (count < 2) {
			sum = sum + arr[i];
			if (sum > left_sum) {
				left_sum = sum;	
				left_edge[count_vec] = i;
			}
		}
	}
	//cout << endl;
	if (count >= 1)count = 1;
	sum = 0;
    int right_sum = 0;
	for (int i = m + 1; i <= h; i++)
	{
		if (arr[i] < 0)count++;
		if (count < 2) {
			sum = sum + arr[i];
			if (sum > right_sum) {
				right_sum = sum;
				right_edge[count_vec] = i;
			}
		}
	}
	temp = left_sum + right_sum;
	if (temp > num_m) {
		num_m = temp;
		num_vec = count_vec;
	}
	//cout << endl;
	//cout << num_m << endl << num_vec << endl;
	return max(left_sum, right_sum, temp);
}
//選出切的點傳入
int max_cut(int arr[], int l, int h)
{
	if (l == h) return arr[l];
	int m = (l + h) / 2;
	return max(max_cut(arr, l, m),max_cut(arr, m + 1, h),max_plus(arr, l, m, h));
}

int main()
{
	int n;
	int temp;
	cin >> n;
	//創動態陣列
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[i] = temp;
	}
    int max_sum = max_cut(arr, 0, n - 1);
	//印出結果
	cout << "Answer:" << max_sum << endl;
	cout << "S[" << left_edge[num_vec]<< "]~S[" << right_edge[num_vec] << "]:";
	for (int i = left_edge[num_vec]; i <= right_edge[num_vec]; i++) {
		cout << arr[i] << " ";
	}
	
	cout << endl;
	system("pause");
}