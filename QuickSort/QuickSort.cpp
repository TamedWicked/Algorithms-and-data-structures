#include <iostream>
#include <random>

#define num 10

void QuickSort(int arr[], int left, int right);

int main(){
	std::random_device rd;
	std::mt19937 mersenne(rd());
	std::uniform_int_distribution<int> dist(1,20);

	int array[num];
	for(int i=0;i<num;i++)
	{
	array[i]=dist(mersenne);
	}

	for(int i=0;i<num;i++)
	{
		std::cout << array[i] << " ";
	}

	QuickSort(array, 0, num-1);

	std::cout << std::endl;

	for(int i=0;i<num;i++)
	{
		std::cout << array[i] << " ";
	}

	return 0;
}

void QuickSort(int arr[], int left, int right)
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