#include <iostream>
#include <fstream> 
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream input_file("input.txt");
	ofstream output_file("output.txt");

	int t1, t2;
	string mode;

	if (input_file.is_open())
	{
		cout << "Все ОК! Файл открыт!" << endl;
		input_file >> t1 >> t2 >> mode;
		cout << "t1 = " << t1 << endl << "t2 = " << t2 << endl << "mode = " << mode << endl;
		if (t1 < 50 && t1 > -50 && t2 < 50 && t2 > -50)
		{
			if (mode == "freeze")
			{
				if (t1 > t2)
				{
					if (output_file.is_open())
					{
						output_file << t2;
					}
					output_file.close();
				}
				else
				{
					if (output_file.is_open())
					{
						output_file << t1;
					}
					output_file.close();
				}
			}
			if (mode == "heat")
			{
				if (t1 < t2)
				{
					if (output_file.is_open())
					{
						output_file << t2;
					}
					output_file.close();
				}
				else
				{
					if (output_file.is_open())
					{
						output_file << t1;
					}
					output_file.close();
				}
			}
			if (mode == "auto")
			{
				if (output_file.is_open())
				{
					output_file << t2;
				}
				output_file.close();
			}
			if (mode == "fan")
			{
				if (output_file.is_open())
				{
					output_file << t1;
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
	return 0;
}