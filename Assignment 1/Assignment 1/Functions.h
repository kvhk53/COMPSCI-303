#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

bool isValid(string str);

int checkExists(int arr[], int size);

void changeInteger(int arr[]);

void addInteger(int arr[], int& occupiedIdx);

void replaceVal(int arr[]);