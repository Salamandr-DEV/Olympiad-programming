#include <iostream>
#include <fstream> 
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream input_file("input.txt");
	ofstream output_file("output.txt");

	int X, Y, Z;
	int result;

	if (input_file.is_open())
	{
		cout << "Все ОК! Файл открыт!" << endl;
		input_file >> X >> Y >> Z;
		if (X < 1000 && Y < 1000 && Z < 1000)
		{
			cout << X << endl << Y << endl << Z << endl;
			result = X + Y - Z;
			if (result > 0)
			{
				if (output_file.is_open())
				{
					output_file << result;
				}
				output_file.close();
			}
			else
			{
				if (output_file.is_open())
				{
					output_file << "imposible\n";
				}
				output_file.close();
			}
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