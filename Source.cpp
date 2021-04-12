#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 15;

void fill_random(vector <int>& Arr, int min, int max)
{
	for (int i = 0; i < N; i++)
	{
		Arr[i] = rand() % (max - min + 1) + min;
	}
}

void print(vector <int>& Arr)
{
	cout << "\n";
	for (int i = 0; i < N; i++)
	{
		cout << Arr[i] << "\t";
	}
	cout << "\n";
}

void heapify(vector <int>& Arr, int size, int index)
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int current = index;
	if (left < size) 
	{
		if (Arr[left] > Arr[current])
		{
			current = left;
		}
	}
	if (right < size) 
	{
		if (Arr[right] > Arr[current])
		{
			current = right;
		}
	}
	if (current != index)
	{
		swap(Arr[current], Arr[index]);
		heapify(Arr, size, current);
	}
}

void heapsort(vector <int>& Arr, int size)
{
	for (int i = size - 1; i > 0; i--)
	{
		swap(Arr[0], Arr[i]);
		heapify(Arr, i, 0);
		print(Arr);
	}
}

int main()
{
	srand(time(NULL));

	vector <int> Arr(N);
	fill_random(Arr, 1, 100);
	print(Arr);

	for (int i = N / 2; i >= 0; i--)
	{
		heapify(Arr, N, i);
	}
	print(Arr);

	heapsort(Arr, N);
}
