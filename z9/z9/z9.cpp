#include <iostream>
#include <fstream> 
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream input_file("input.txt");
	ofstream output_file("output.txt");

	int N, max_elem, min_mark, capacity = 0;

	if (input_file.is_open())
	{
		cout << "Все ОК! Файл открыт!" << endl;
		input_file >> N;

		if (N < 2 || N > 1000)
		{
			cout << "Число альбомов выходит из заданного диапазона. Введите N от 2 до 1000!";
			return 0;
		}

		vector <int> arr(N);
		for (int i = 0; i < N; i++) 
		{
			input_file >> arr[i];
			capacity += arr[i];
		}

		if (capacity > 100000)
		{
			cout << "Вместимость альбомов не может превышать 100 000!";
			return 0;
		}

		int temp;

		for (int i = 0; i < N - 1; i++)
		{
			for (int j = 0; j < N - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}

		max_elem = arr[N - 1];
		min_mark = min(capacity / 2, capacity - max_elem);
	}
	else
	{
		cout << "Файл не открыт!\n\n" << endl;
		return -1;
	}

	if (output_file.is_open())
	{
		output_file << min_mark;
	}
	output_file.close();

	return 0;
}