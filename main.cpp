#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int get_decimal_from_roman(string number_in_roman)
{
	int number = 0;
	unordered_map<string, int> combinations;
	unordered_map<char, int> values;

	values['M'] = 1000;
	values['D'] = 500;
	values['C'] = 100;
	values['L'] = 50;
	values['X'] = 10;
	values['V'] = 5;
	values['I'] = 1;

	combinations["IV"] = 4;
	combinations["IX"] = 9;
	combinations["XL"] = 40;
	combinations["XC"] = 90;
	combinations["CD"] = 400;
	combinations["CM"] = 900;

	for (int i = 0; i < number_in_roman.length(); i++)
	{
		char letter = number_in_roman[i];

		int letter_value = values[letter];

		if (i == 0)
		{

			char next_letter = number_in_roman[i + 1];

			int next_letter_value = values[next_letter];

			if (letter_value < next_letter_value)
			{
				string combained = string(1, letter) + next_letter;
				int value = combinations[combained];
				i += 1;

				number += value;
			}
			else
			{
				number += letter_value;
			}
			continue;
		}

		char previous_letter = number_in_roman[i - 1];
		int previous_letter_value = values[previous_letter];

		if (letter_value > previous_letter_value)
		{
			string combained = string(1, letter) + previous_letter;
			int value = combinations[combained];

			number += value;
			i += 1;
			continue;
		}
		char next_letter = number_in_roman[i + 1];
		int next_letter_value = values[next_letter];

		if (letter_value < next_letter_value)
		{
			string combained = string(1, letter) + next_letter;
			int value = combinations[combained];
			i += 1;

			number += value;
			continue;
		}

		number += letter_value;
	}
	return number;
}

int calculate(string type, int a, int b)
{
	if (type == "+")
	{
		return a + b;
	}
	else if (type == "-")
	{
		return a - b;
	}
	else if (type == "*")
	{
		return a * b;
	}
	else {
		return 0;
	}
}

string get_roman_from_decimal(int number)
{
	string number_in_roman;
	while (number != 0)
	{
		if (number - 1000 >= 0)
		{
			number_in_roman += "M";
			number -= 1000;
		}
		else if (number - 900 >= 0)
		{
			number_in_roman += "CM";
			number -= 900;
		}
		else if (number - 500 >= 0)
		{
			number_in_roman += "D";
			number -= 500;
		}
		else if (number - 400 >= 0)
		{
			number_in_roman += "CD";
			number -= 400;
		}
		else if (number - 100 >= 0)
		{
			number_in_roman += "C";
			number -= 100;
		}
		else if (number - 90 >= 0)
		{
			number_in_roman += "XC";
			number -= 90;
		}
		else if (number - 50 >= 0)
		{
			number_in_roman += "L";
			number -= 50;
		}
		else if (number - 40 >= 0)
		{
			number_in_roman += "XL";
			number -= 40;
		}
		else if (number - 10 >= 0)
		{
			number_in_roman += "X";
			number -= 10;
		}
		else if (number - 9 >= 0)
		{
			number_in_roman += "IX";
			number -= 9;
		}
		else if (number - 5 >= 0)
		{
			number_in_roman += "V";
			number -= 5;
		}
		else if (number - 4 >= 0)
		{
			number_in_roman += "IV";
			number -= 4;
		}
		else if (number - 1 >= 0)
		{
			number_in_roman += "I";
			number -= 1;
		}
	};
	return number_in_roman;
}

int main()
{
	string type, first_digit_string, second_digit_string;
	cin >> type;
	cin >> first_digit_string;
	cin >> second_digit_string;
	int first_number = get_decimal_from_roman(first_digit_string);
	int second_number = get_decimal_from_roman(second_digit_string);

	if (type == "/")
	{
		int result1 = first_number / second_number;
		int result2 = first_number % second_number;
		cout << get_roman_from_decimal(result1) << " " << get_roman_from_decimal(result2);
		return 0;
	}

	int result_number = calculate(type, first_number, second_number);
	string result = get_roman_from_decimal(result_number);
	cout << result;



	return 0;
}