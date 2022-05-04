//Anthony Franklin afranklin18@cnm.edu
//C++ Templates and Sorting Algorithms
//03/21/2022
//Sort.h


#ifndef SORT_H
#define SORT_H




using namespace std;

template<class T> class Sort
{
public:
	Sort() = default;
	void BubbleSort(T arr[], int length);
	void Comb11Sort(T arr[], int length);
	void InsertionSort(T arr[], int length);
	void SelectionSort(T arr[], int length);
	void ShakerSort(T arr[], int length);
private:
	void swap(T& a, T& b);






};
int getNextGap(int gap)
{
	// Shrink gap by Shrink factor
	gap = gap / 1.3;

	if (gap < 1)
		return 1;
	return gap;
}

template <class T>
void Sort <T>::swap(T& a, T& b)
{
	auto t = a;
	a = b;
	b = t;
}
template <class T>
void Sort <T>::BubbleSort(T arr[], int total)
{
	for (int i{ 0 }; i < total - 1; i++)
		for (int j{ 1 }; j < total; j++)
			if (arr[j - 1] > arr[j])
				swap(arr[j], arr[j - 1]);
}


template <class T>
void Sort <T>::Comb11Sort(T arr[], int total)
{
	int gap = total;

	while (gap != 1)
	{
		// Find next gap
		gap = getNextGap(gap);

		// Compare all elements with current gap
		for (int i = 0; i < total - gap; i++)
		{
			if (arr[i] > arr[i + gap])
			{
				swap(arr[i], arr[i + gap]);
			}
		}
	}
}

template <class T>
void Sort <T>::InsertionSort(T arr[], int total)
{
	int i, j;
	T key;
	for (i = 1; i < total; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

template <class T>
void Sort <T>::SelectionSort(T arr[], int total)
{
	for (int i{ 0 }; i < total - 1; i++)
	{
		// Find the minimum element in unsorted array 
		int minIndex = i;
		for (int j{ i + 1 }; j < total; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;

		// Swap the found minimum element with the first element 
		swap(arr[minIndex], arr[i]);
	}
}

template <class T>
void Sort <T>::ShakerSort(T arr[], int total)
{
	bool isChanged = true;
	int start = 0;
	int end = total - 1;
	while (isChanged)
	{
		isChanged = false;
		for (int i = start; i < end; ++i)
		{
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isChanged = true;
			}

		}
		if (!isChanged) //Nothing needed changed; our sort is complete.
			break;
		isChanged = false;
		--end;

		//Working backwards now
		for (int i = end - 1; i >= start; --i)
		{

			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				isChanged = true;
			}
		}
		++start;
	}
}

#endif