#include <iostream>
#include <fstream> 
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream input_file("input.txt");
	ofstream output_file("output.txt");

	int W, H, R;

	if (input_file.is_open())
	{
		cout << "Все ОК! Файл открыт!" << endl;
		input_file >> W >> H >> R;
		if (W < 0 || H < 0 || R < 0)
		{
			cout << "Одно из входных значений меньше нуля" << endl;
			return -1;
		}
		if (W < 1000000000 && H < 1000000000 && R < 1000000000)
		{
			cout << "W = " << W << endl << "H = " << H << endl << "R = " << R << endl;
			if (W > R && H > R)
			{
				if (output_file.is_open())
				{
					output_file << "YES\n";
				}
				output_file.close();
			}
			else
			{
				if (output_file.is_open())
				{
					output_file << "NO\n";
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