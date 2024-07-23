#include <iostream>
#include <fstream> 
#include <vector>
#include <set>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream input_file("input.txt");
	ofstream output_file("output.txt");

	string word, anagramma;

	if (input_file.is_open())
	{
		cout << "Все ОК! Файл открыт!" << endl;
		input_file >> word;

		word = "mouse";

		vector<char> arr;

		for (int i = 0; i < word.size(); i++)
		{
			arr.push_back(word[i]);	
		}

		anagramma = arr[0];
		char  temp;
		for (int i = 1; i < arr.size() - 1; i++)
		{
			for (int j = 1; j < arr.size() - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					anagramma += arr[i];
				}
			}
		}
		cout << anagramma;
	}
	else
	{
		cout << "Файл не открыт!\n\n" << endl;
		return -1;
	}


	return 0;
}