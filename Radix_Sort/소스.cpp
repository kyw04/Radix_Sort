#include <iostream>
#define MAX 10
using namespace std;

unsigned bits(unsigned x, int k, int j)
{
	unsigned b = ~0;
	return (x >> k) & ~(b << j);
}
void radix_sort(int list[], int n, int b)
{
	int t, i, j;
	if (n > 1 && b >= 0)
	{
		i = 0;
		j = n - 1;
		while (true)
		{
			while (bits(list[i], b, 1) == 0 && i < j) i++;
			while (bits(list[j], b, 1) != 0 && i < j) j--;
			if (i >= j) break;
			t = list[i];
			list[i] = list[j];
			list[j] = t;
		}
		if (bits(list[n - 1], b, 1) == 0) j++;
		radix_sort(list, j, b - 1);
		radix_sort(list + j, n - j, b - 1);
	}
}
int main()
{
	int arr[MAX] = { 10, 4, 6, 3, 7, 9, 1, 5, 8, 2 };

	for (int i = 0; i < MAX; i++)
		cout << arr[i] << ' ';
	cout << endl;

	radix_sort(arr, MAX, 3);

	for (int i = 0; i < MAX; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}