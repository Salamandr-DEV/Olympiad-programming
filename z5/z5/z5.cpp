#include <iostream>
#include <fstream> 
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream input_file("input.txt");
	ofstream output_file("output.txt");

	int N, max_age = 0, min_position = -1;

	if (input_file.is_open())
	{
		cout << "Все ОК! Файл открыт!" << endl;
		input_file >> N;
		
		if (N >= 100)
		{
			cout << "Число жильцов должно быть меньше 100";
			return 0;
		}

		for (int i = 0; i < N; ++i) 
		{
			int age, sex;

			input_file >> age >> sex;

			if (sex == 1 && age > max_age) 
			{
				max_age = age;
				min_position = i + 1;
			}
		}
	}
	else
	{
		cout << "Файл не открыт!\n\n" << endl;
		return -1;
	}

	if (output_file.is_open())
	{
		output_file << min_position;
	}
	output_file.close();

	return 0;
}