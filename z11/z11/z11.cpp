#include <iostream>
#include <fstream> 
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream input_file("input.txt");
	ofstream output_file("output.txt");

	int N, M, result;

	if (input_file.is_open())
	{
		cout << "��� ��! ���� ������!" << endl;
		input_file >> N >> M;

		if (N > 100 || M > 100)
		{
			cout << "��� ����� ������ ���� ������ 100!";
			return 0;
		}
		if (N + M > 0)
		{
			N = N | M;

			result = 2 - (N & 1);
		}
	}
	else
	{
		cout << "���� �� ������!\n\n" << endl;
		return -1;
	}

	if (output_file.is_open())
	{
		output_file << result;
	}
	output_file.close();

	return 0;
}