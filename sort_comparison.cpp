#include <iostream>
#include <random>
#include <chrono>

void PrintArray(std::vector<int>& arr);
void ComparisonCounting(std::vector<int>& arr, std::vector<int>& counter);
void BubbleSort(std::vector<int>& arr);
void InsertionSort(std::vector<int>& arr);
void SelectionSort(std::vector<int>& arr);
void Merge(std::vector<int>& arr, int lo, int mid, int hi, std::vector<int>& tmp_arr);
void MergeSort(std::vector<int>& arr, int lo, int hi, std::vector<int>& tmp_arr);
void QuickSort(std::vector<int>& arr, int left, int right);

int main(){
	std::random_device rd;
	std::mt19937 mersenne(rd());
	std::uniform_int_distribution<int> dist(0,100);
	std::chrono::duration<double> diff;
	const int num = 20000;
	std::vector<int> numbers1(num);
	std::vector<int> numbers2(num);
	std::vector<int> numbers3(num);
	std::vector<int> numbers4(num);
	std::vector<int> numbers5(num);
	std::vector<int> counter(num);
	std::vector<int> tmp_arr(num);

	for(int i=0;i<num;i++)
	{
		numbers1[i]=dist(mersenne);
		numbers2[i]=numbers1[i];
		numbers3[i]=numbers1[i];
		numbers4[i]=numbers1[i];
		numbers5[i]=numbers1[i];
	}
	//PrintArray(numbers1);

	auto start = std::chrono::high_resolution_clock::now();
	ComparisonCounting(numbers1, counter);
	auto end = std::chrono::high_resolution_clock::now();

	diff = end - start;
	std::cout << "Comparison sort time: " << diff.count() << "s" << std::endl;

	start = std::chrono::high_resolution_clock::now();
	BubbleSort(numbers1);
	end = std::chrono::high_resolution_clock::now();

	diff = end - start;
	std::cout << "Bubble sort time: " << diff.count() << "s" << std::endl;

	start = std::chrono::high_resolution_clock::now();
	InsertionSort(numbers2);
	end = std::chrono::high_resolution_clock::now();
	
	diff = end - start;
	std::cout << "Insertion sort time: " << diff.count() << "s" << std::endl;

	start = std::chrono::high_resolution_clock::now();
	SelectionSort(numbers3);
	end = std::chrono::high_resolution_clock::now();

	diff = end - start;
	std::cout << "Selection sort time: " << diff.count() << "s" << std::endl;

	start = std::chrono::high_resolution_clock::now();
	MergeSort(numbers4, 0, numbers4.size()-1, tmp_arr);
	end = std::chrono::high_resolution_clock::now();

	diff = end - start;
	std::cout << "Merge sort time: " << diff.count() << "s" << std::endl;

	start = std::chrono::high_resolution_clock::now();
	QuickSort(numbers5, 0, numbers5.size()-1);
	end = std::chrono::high_resolution_clock::now();

	diff = end - start;
	std::cout << "Quick sort time: " << diff.count() << "s" << std::endl;

	//PrintArray(numbers1);
	//PrintArray(numbers2);
	//PrintArray(numbers3);
	//PrintArray(numbers4);
	//PrintArray(numbers5);
	return 0;
}

void PrintArray(std::vector<int>& arr)
{
	std::cout << "Sequence: ";
	for(int i=0;i<arr.size();i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void ComparisonCounting(std::vector<int>& arr, std::vector<int>& counter)
{
	for(int i=0;i<arr.size();i++)
	{
		counter[i]=-1;
	}

	for(int i=arr.size()-1;i>=0;i--)
	{
		for(int j=arr.size()-1;j>=0;j--)
		{
			if(arr[i]>=arr[j])
				counter[i]=counter[i]+1;
		}
	}

	return;
}

void BubbleSort(std::vector<int>& arr)
{
	int swap,counter=0;
	for(int i=0;i<arr.size();i++)
	{
		for(int j=0;j<arr.size()-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				counter++;
				swap=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=swap;
			}
		}
		if(counter==0)
			break;
	}
}

void SelectionSort(std::vector<int>& arr)
{
	int min_position;
	int swap;
	for(int i=0;i<arr.size()-1;i++)
	{
		min_position=i;
		for(int j=i+1;j<arr.size();j++)
		{
			if(arr[j]<arr[min_position])
			{
				min_position=j;
			}
		}
		if(min_position!=i)
		{
		swap=arr[i];
		arr[i]=arr[min_position];
		arr[min_position]=swap;
		}
	}
}

void InsertionSort(std::vector<int>& arr)
{
	int j, swap;	
	for(int i=1;i<arr.size();i++)
	{
		j=i;
		while(j>0 && arr[j]<arr[j-1])
		{
			swap=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=swap;
			j--;
		}

	}
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

void QuickSort(std::vector<int>& arr, int left, int right)
{
	int i=left; int j=right;
	int temp;
	int pivot = arr[(left+(right-left)/2)]; //avoids overflow this way

	while(i<=j)
	{
		while(arr[i]<pivot) 
			i++;
		while(arr[j]>pivot) 
			j--;
		
			if(i<=j)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				i++;
				j--;
			}
	}
	if(left<=j) 
		QuickSort(arr, left, j);
	if(i<right) 
		QuickSort(arr, i, right);
}
