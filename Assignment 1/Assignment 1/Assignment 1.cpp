/*
Kenny Huynh
Date: 09/11/2023
Assignment 1
*/

#include "Functions.h"

int main() {
	ifstream infile;
	istringstream inSS;
	string fileNum, fileLine;
	int numArray[200];
	int i = 0, occupiedIdx = -1, idx, size;
	//opens text file of 10x10 integers and verifies if it's open
	infile.open("integers.txt");
	if (!infile.is_open()) {
		cout << "Could not open the input file integers.txt" << '\n';
		return -1;
	}
	//reads file line by line, breaks line further into strings
	//converts strings into ints and adds them to array
	while (getline(infile, fileLine)) {
		inSS.clear();
		inSS.str(fileLine);

		while (inSS >> fileNum) {
			numArray[i] = stoi(fileNum);
			++i;
			++occupiedIdx; //keeps track of indexes that have been used
		}
	} 
	//assigning the size of the array to variable size
	size = sizeof(numArray) / sizeof(int);

	//calling the 4 functions
	idx = checkExists(numArray, size);
	changeInteger(numArray);
	addInteger(numArray, occupiedIdx);
	replaceVal(numArray);

	infile.close();
}