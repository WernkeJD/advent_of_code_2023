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

int correct_callibration(const std::string& filename) {
	std::ifstream callibration_file(filename);

	if (!callibration_file.is_open()) {
		std::cerr << "Failed to open the file!" << std::endl;
		return -1;
	}

	std::string line;
	int total{ 0 };

	while (std::getline(callibration_file, line)) {

		std::vector<int> line_numbers;

		for (char letter : line) {
			if (isdigit(letter)) {
				line_numbers.push_back(letter - '0'); // Convert char to int by subtracting ascii values
				std::cout << letter << std::endl;

			}
		}

		if (!line_numbers.empty()) {
			if (line_numbers.size() > 0 && line_numbers.size() == 1) {
				total += (line_numbers[0] * 11);
				std::cout << total << std::endl;
			}
			else {
				int add_first_last = (line_numbers[0] * 10) + line_numbers[line_numbers.size() - 1];
				total += add_first_last;
				std::cout << total << std::endl;

			}
		}
	}

	return total;
}

int main() {
	std::string filename = "callibration.txt";  
	int result = correct_callibration(filename);


	std::cout << "The total is: " << result << std::endl;

	return 0;
}
