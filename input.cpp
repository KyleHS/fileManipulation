#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//get user input to append to CSC450
void append(const std::string& filename) { //filename is const for downloaded file
	std::string userinput;

	std::cout << "Please enter text to add to file: "; //asks user for input
	std::getline(std::cin, userinput);  //gets user input

	std::ofstream output(filename, std::ios::app);

	if (output.is_open()) {
		output << userinput << "\n";
		output.close(); //closes file
		std::cout << "Data appended to file.\n";
	} else {
		std::cerr << "Error Message: Please open file in order to append.\n"; //error handling
	}
}

//reverses the newly appended to file and reverses characters
void fileReversal(const std::string& fileName, const std::string& newFileName) { //newFileName is const for the reversed program file
	std::ifstream inputFile(fileName);
	std::ofstream outputFile(newFileName);

	if(inputFile.is_open() && outputFile.is_open()) {
		std::string line;
		while (std::getline(inputFile, line)) {
			std::string reversal(line.rbegin(), line.rend()); //reverses here
			outputFile << reversal << "\n";
		}
		inputFile.close(); //closes first file
		outputFile.close(); //closes new file

		std::cout << "Contents of the file were reversed in: " << newFileName << "\n";
	} else {
		std::cerr << "Error Message: Please open both input and output files.\n"; //error handling
	}
}

//main program
int main() {
	const std::string fileName = "CSC450_CT5_mod5.txt"; //download file
	const std::string newFileName = "CSC450-mod5-reverse.txt"; //output file with reversed characters
	append(fileName); //calls append method
	fileReversal(fileName, newFileName); //calls reversal method
	return 0;

}

