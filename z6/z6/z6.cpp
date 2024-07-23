#include <iostream>
#include <fstream> 
using namespace std;

int Nod(int a, int b)
{
    while (a && b)
    {
        if (a >= b)
        {
            a %= b;
        }
        else
        {
            b %= a;
        }
    }
    return a | b;
}
int main()
{
	setlocale(LC_ALL, "rus");

	ifstream input_file("input.txt");
	ofstream output_file("output.txt");

	int N, K, result;

	if (input_file.is_open())
	{
		cout << "Все ОК! Файл открыт!" << endl;
		input_file >> N >> K;

		if (N > 10000000 || K > 10000000)
		{
			cout << "Оба числа должны быть меньше 10000000!";
			return 0;
		}

		result = (N / Nod(N, K)) * K;

		if (result == 1000000000)
		{
			return 0;
		}
	}
	else
	{
		cout << "Файл не открыт!\n\n" << endl;
		return -1;
	}

	if (output_file.is_open())
	{
		output_file << result;
	}
	output_file.close();

    return 0;
}