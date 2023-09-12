#include "Functions.h"

//returns bool based on whether entered string is only numeric values to verify inputs
bool isValid(string str) {
	return str.find_first_not_of("0123456789") == string::npos;
}

//function to check if integer exists in function and returns the index
int checkExists(int arr[], int size) {
	int idx = -1, findNum;
	string userInt;
	//ask user for input and verifies if input is numeric with previous function, loops until it is
	cout << "What integer would you like to find in the array? ";
	cin >> userInt;
	while (!isValid(userInt)) {
		cout << "\nInvalid input. Try again!\nWhat integer would you like to find in the array? ";
		cin >> userInt;
	}
	findNum = stoi(userInt); //converts string user input into int

	//iterate through array to find the inputted integer
	for (int i = 0; i < size; i++) {
		if (arr[i] == findNum)
			idx = i;
	}

	//outputs if the integer is found and tells user the index, else output it's not found and idx remains -1
	if (idx != -1)
		cout << "\nInteger " << findNum << " is found at index " << idx << '\n';
	else
		cout << "\nInteger " << findNum << " is not in the array\n";

	return idx;
}

//function ask user for an index and new integer and replacing old integer at that index
void changeInteger(int arr[]) {
	int idx, oldInt;
	string userIdx, userInt;

	//ask user for index and uses same process to verify input
	cout << "\nChoose an index to change the integer at that index in the array: ";
	cin >> userIdx;
	while (!isValid(userIdx)) {
		cout << "\nInvalid input. Try again!\n"
			 << "Choose an index to change the integer at that index in the array: ";
		cin >> userIdx;
	}
	//converts string input to int and saves integer at index to oldInt
	try {
		idx = stoi(userIdx);
		oldInt = arr[idx];
	}
	catch (out_of_range& ex) {
		cerr << "Error: " << ex.what() << '\n';
		cerr << "Invalid index. Enter a valid index from 0 to 99\n";
	}
	//ask user for new integer to replace old integer, loops until valid input
	cout << "\nThe integer at index " << idx << " is " << oldInt
		 << "\nWhat would you like to change the integer to? ";
	cin >> userInt;
	while (!isValid(userInt) || stoi(userInt) == oldInt) {
		if (stoi(userInt) == oldInt) {
			cout << "\nNew integer can't be the same as old integer. Try again!" 
				 << "\nWhat would you like to change the integer to ? ";
			cin >> userInt;
		}
		else {
			cout << "\nInvalid input. Try again!\nWhat would you like to change the integer to? ";
			cin >> userInt;
		}
	}
	//replaces old integer at the inputted index with new inputted integer
	arr[idx] = stoi(userInt);
	cout << "\nThe integer at index " << idx << " was modified from " << oldInt << " to " << arr[idx] << '\n';
}

//function to add an integer to the end of indexes that have already been filled
void addInteger(int arr[], int& occupiedIdx) {
	string userInt;
	int chosenInt;
	//ask user for an integer, verifying it same as before
	cout << "\nChoose an integer to add at the end of the array? ";
	cin >> userInt;
	while (!isValid(userInt)) {
		cout << "\nInvalid input. Try again!\n Choose an integer to add at the end of the array? ";
		cin >> userInt;
	}
	
	chosenInt = stoi(userInt);
	occupiedIdx += 1; //updates the number of occupied indexes
	arr[occupiedIdx] = chosenInt; //adds the inputted integer to the new index in the array
	cout << '\n' << chosenInt << " was added to the end of the array at index " << occupiedIdx << '\n';
}

//function to convert integer at selected index to 0
void replaceVal(int arr[]) {
	int idx, oldInt;
	string userIdx, userInt;

	cout << "\nChoose an index to change the integer at that index to 0: ";
	cin >> userIdx;
	while (!isValid(userIdx) || stoi(userIdx) == 0) {
		if (stoi(userIdx) == 0) {
			cout << "\nValue at index is already 0. Try again!\n"
				 << "Choose an index to change the integer at that index to 0: ";
			cin >> userIdx;
		}
		else {
			cout << "\nInvalid input. Try again!\n"
				<< "Choose an index to change the integer at that index to 0: ";
			cin >> userIdx;
		}
	}

	idx = stoi(userIdx);
	oldInt = arr[idx];

	arr[idx] = 0;
	cout << "\nThe integer at index " << idx << " was modified from " << oldInt << " to 0\n";
}