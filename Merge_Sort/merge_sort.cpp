#include <iostream>
#include <random>

void Merge(std::vector<int>& arr, int lo, int mid, int hi, std::vector<int>& tmp_arr);
void MergeSort(std::vector<int>& arr, int lo, int hi, std::vector<int>& tmp_arr);
void PrintArray(std::vector<int>& arr);

int main(){
	const int length=10;

	std::random_device rd;
	std::mt19937 mersenne(rd());
	std::uniform_int_distribution<int> dist(1,length);

	std::vector<int> brojevi;
	for(int i=0;i<length;i++)
	{
		brojevi.push_back(dist(mersenne));
	}

	std::vector<int> brojevi_temp(length);

	//PrintArray(brojevi);
	MergeSort(brojevi, 0, brojevi.size()-1, brojevi_temp);
	//PrintArray(brojevi);
	return 0;
}
	

void PrintArray(std::vector<int>& arr)
{
	for(int i=0;i<arr.size();i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void MergeSort(std::vector<int>& arr, int lo, int hi, std::vector<int>& tmp_arr)
{
	int mid;
	if(lo<hi)
	{
		mid=lo+(hi-lo)/2;
		MergeSort(arr, lo, mid, tmp_arr);
		MergeSort(arr, mid+1, hi, tmp_arr);
		Merge(arr, lo, mid, hi, tmp_arr);
	}
	tmp_arr.clear();
}

void Merge(std::vector<int>& arr, int lo, int mid, int hi, std::vector<int>& tmp_arr)
{
	int k;
	int n1=lo;
	int n2=mid+1;

	for(k=lo;k<=hi;k++)
	{
		if(n1 > mid)
			tmp_arr[k]=arr[n2++];
		else if(n2 > hi)
			tmp_arr[k]=arr[n1++];
		else if(arr[n1] < arr[n2])
			tmp_arr[k]=arr[n1++];
		else
			tmp_arr[k]=arr[n2++];
	}
	for(k=lo;k<=hi;k++)
	{
		arr[k]=tmp_arr[k];
	}
	return;
}