#include <iostream>
#include <fstream> 
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream input_file("input.txt");
	ofstream output_file("output.txt");

	int N;

	if (input_file.is_open())
	{
		cout << "Все ОК! Файл открыт!" << endl;
		input_file >> N;
		if (N < 0)
		{
			cout << "Одно из входных значений меньше нуля" << endl;
			return -1;
		}
		cout << "N = " << N << endl;
		if (N > 1)
		{
			if (N % 2 == 0)
			{
				if (output_file.is_open())
				{
					output_file << N/2;
				}
				output_file.close();
			}
			if (N % 2 != 0)
			{
				if (output_file.is_open())
				{
					output_file << N;
				}
				output_file.close();
			}
		}
		if (N == 0 || N == 1)
		{
			if (output_file.is_open())
			{
				output_file << "0";
			}
			output_file.close();
		}
	}
	else
	{
		cout << "Файл не открыт!\n\n" << endl;
		return -1;
	}
	system("pause");
	return 0;
}