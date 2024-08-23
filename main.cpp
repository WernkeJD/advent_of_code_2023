
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


const int numbers[] = {
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
};


int correct_callibration(std::ifstream callibration_file) {

	std::string line;
	callibration_file.open();
	int total{ 0 };


	while (std::getline(callibration_file, line)) {

		std::vector<int> line_numbers;
		int line_length{ line.length() };

		for (int i{ 0 }, i < line_length, i++) {
			
			char letter = line[i];

			for (int n{ 0 }, n < numbers.length(), n++) {

				if (letter == numbers[n]) {
					line_numbers.push_back(n)
				}
				else {
					continue
				}
			}
		}

		int add_first_last{ line_numbers[0] + line_numbers[line_numbers.length() - 1] };

		total = total + add_first_last;
	}

	return total
};

int main() {

	return correct_callibration(callibration.txt)

};