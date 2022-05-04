//Anthony Franklin afranklin18@cnm.edu
//C++ Templates and Sorting Algorithms
//03/21/2022
//Driver.cpp

#include "Sort.h"
#include "Functions.h"
#include "FranklinPersonGen/PersonGen.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <format>

using namespace std;
const int SIZE = 200000;
const int STR_SIZE = 25000;
const int PERSON_SIZE = 10000;
int* Nums, * TmpNums;
string* strArr, * strCopy;
Person* Persons, * TmpPersons;
const string FILENAME = "BJTest200K.txt";
const string STR_FILENAME = "BJName25000.txt";




int main() {

	string outputFileName;
	cout << "Anthony Franklin afranklin18@cnm.edu\nFranklinP6\n03/21/2022\nThis program sorts any object supporting < and >, and prints how long each sort took into an output file.\n\nPlease enter the name of the output file you would like the program to create (eg Times.txt): " << endl;

 	cin >> outputFileName;
	cin.ignore();
	
	ofstream outputFile(outputFileName);
	if (outputFile.is_open())
	{
		cout << "Output File OK; Printing to " + outputFileName << endl;
	}

	Sort <int>   intSorter;      //sorter for integers
	Sort <string>   strSorter;   //sorter for strings
	Sort <Person> pSorter;

	Date today;
	outputFile << "Anthony Franklin           " << today.GetFormattedDate() << endl;
	outputFile << format("\nNumber of integer values sorted by each routine:	  {}", SIZE);
	outputFile << format("\nNumber of string values sorted by each routine:	  {}", STR_SIZE);
	outputFile << format("\nNumber of Persons sorted by each routine:	           {}", PERSON_SIZE);
	//INTEGERS
	Nums = new int[SIZE];
	TmpNums = new int[SIZE];
	readFile(Nums, FILENAME, SIZE);
	copyArray(Nums, TmpNums, SIZE);

	outputFile << "\n\nTemplate Sort information for integers\nName of Sort Function:	Time to Complete Function in secs/ms: ";
	cout << firstTen(TmpNums, SIZE);
	cout << lastTen(TmpNums, SIZE);
	cout << "\nCalling BubbleSort now.";
	auto start{ chrono::high_resolution_clock::now() };
	intSorter.BubbleSort(TmpNums, SIZE);
	auto stop{ chrono::high_resolution_clock::now() };
	auto ms{ chrono::duration_cast<chrono::milliseconds>(stop - start).count() };
	cout << "Time to complete BubbleSort in sec: " << to_string(ms / 1000) << endl;
	cout << "Time to complete BubbleSort in ms: " << to_string(ms) << endl;
	outputFile << "\nBubbleSort                     " + to_string(ms / 1000) + '/' + to_string(ms);
	cout << firstTen(TmpNums, SIZE);
	cout << lastTen(TmpNums, SIZE);
	copyArray(Nums, TmpNums, SIZE);
	
	cout << firstTen(TmpNums, SIZE);
	cout << lastTen(TmpNums, SIZE);
	cout << "\nCalling comb11 now.";
	start = chrono::high_resolution_clock::now();
	intSorter.Comb11Sort(TmpNums, SIZE);
	stop = chrono::high_resolution_clock::now();
	ms = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
	cout << "Time to complete Comb11Sort in sec: " << to_string(ms / 1000) << endl;
	cout << "Time to complete Comb11Sort in ms: " << to_string(ms) << endl;
	outputFile << "\nComb11Sort                   " + to_string(ms / 1000) + '/' + to_string(ms);
	cout << firstTen(TmpNums, SIZE);
	cout << lastTen(TmpNums, SIZE);
	copyArray(Nums, TmpNums, SIZE);


	cout << firstTen(TmpNums, SIZE);
	cout << lastTen(TmpNums, SIZE);
	cout << "\nCalling insertion sort now.";
	start = chrono::high_resolution_clock::now();
	intSorter.InsertionSort(TmpNums, SIZE);
	stop = chrono::high_resolution_clock::now();
	ms = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
	cout << "Time to complete InsertionSort in sec: " << to_string(ms / 1000) << endl;
	cout << "Time to complete InsertionSort in ms: " << to_string(ms) << endl;
	outputFile << "\nInsertionSort                  " + to_string(ms / 1000) + '/' + to_string(ms);
	cout << firstTen(TmpNums, SIZE);
	cout << lastTen(TmpNums, SIZE);
	copyArray(Nums, TmpNums, SIZE);


	cout << firstTen(TmpNums, SIZE);
	cout << lastTen(TmpNums, SIZE);
	cout << "\nCalling selection sort now.";
	start = chrono::high_resolution_clock::now();
	intSorter.SelectionSort(TmpNums, SIZE);
	stop = chrono::high_resolution_clock::now();
	ms = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
	cout << "Time to complete SelectionSort in sec: " << to_string(ms / 1000) << endl;
	cout << "Time to complete SelectionSort in ms: " << to_string(ms) << endl;
	outputFile << "\nSelectionSort                  " + to_string(ms / 1000) + '/' + to_string(ms);
	cout << firstTen(TmpNums, SIZE);
	cout << lastTen(TmpNums, SIZE);
	copyArray(Nums, TmpNums, SIZE);


	cout << firstTen(TmpNums, SIZE);
	cout << lastTen(TmpNums, SIZE);
	cout << "\nCalling shaker sort now.";
	start = chrono::high_resolution_clock::now();
	intSorter.ShakerSort(TmpNums, SIZE);
	stop = chrono::high_resolution_clock::now();
	ms = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
	cout << "Time to complete ShakerSort in sec: " << to_string(ms / 1000) << endl;
	cout << "Time to complete ShakerSort in ms: " << to_string(ms) << endl;
	outputFile << "\nShakerSort                     " + to_string(ms / 1000) + '/' + to_string(ms);
	cout << firstTen(TmpNums, SIZE);
	cout << lastTen(TmpNums, SIZE);
	//Cleaning up and deleting our new objects
	delete[] Nums;
	Nums = nullptr;
	delete[] TmpNums;
	TmpNums = nullptr;


	//STRINGS
	strArr = new string[STR_SIZE];
	strCopy = new string[STR_SIZE];
	readFileS(strArr, STR_FILENAME, STR_SIZE);
	copyArray(strArr, strCopy, STR_SIZE);

	outputFile << "\n\nTemplate Sort information for strings\nName of Sort Function:	Time to Complete Function in secs/ms: ";
	cout << firstTenS(strCopy, STR_SIZE);
	cout << lastTenS(strCopy, STR_SIZE);
	cout << "\nCalling BubbleSort now.";
	start = chrono::high_resolution_clock::now();
	strSorter.BubbleSort(strCopy, STR_SIZE);
	stop = chrono::high_resolution_clock::now();
	ms = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
	cout << "Time to complete BubbleSort in sec: " << to_string(ms / 1000) << endl;
	cout << "Time to complete BubbleSort in ms: " << to_string(ms) << endl;
	outputFile << "\nBubbleSort                     " + to_string(ms / 1000) + '/' + to_string(ms);
	cout << firstTenS(strCopy, STR_SIZE);
	cout << lastTenS(strCopy, STR_SIZE);
	copyArray(strArr, strCopy, STR_SIZE);

	cout << firstTenS(strCopy, STR_SIZE);
	cout << lastTenS(strCopy, STR_SIZE);
	cout << "\nCalling comb11 now.";
	start = chrono::high_resolution_clock::now();
	strSorter.Comb11Sort(strCopy, STR_SIZE);
	stop = chrono::high_resolution_clock::now();
	ms = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
	cout << "Time to complete Comb11Sort in sec: " << to_string(ms / 1000) << endl;
	cout << "Time to complete Comb11Sort in ms: " << to_string(ms) << endl;
	outputFile << "\nComb11Sort                   " + to_string(ms / 1000) + '/' + to_string(ms);
	cout << firstTenS(strCopy, STR_SIZE);
	cout << lastTenS(strCopy, STR_SIZE);
	copyArray(strArr, strCopy, STR_SIZE);

	cout << firstTenS(strCopy, STR_SIZE);
	cout << lastTenS(strCopy, STR_SIZE);
	cout << "\nCalling insertion sort now.";
	start = chrono::high_resolution_clock::now();
	strSorter.InsertionSort(strCopy, STR_SIZE);
	stop = chrono::high_resolution_clock::now();
	ms = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
	cout << "Time to complete InsertionSort in sec: " << to_string(ms / 1000) << endl;
	cout << "Time to complete InsertionSort in ms: " << to_string(ms) << endl;
	outputFile << "\nInsertionSort                  " + to_string(ms / 1000) + '/' + to_string(ms);
	cout << firstTenS(strCopy, STR_SIZE);
	cout << lastTenS(strCopy, STR_SIZE);
	copyArray(strArr, strCopy, STR_SIZE);

	cout << firstTenS(strCopy, STR_SIZE);
	cout << lastTenS(strCopy, STR_SIZE);
	cout << "\nCalling selection sort now.";
	start = chrono::high_resolution_clock::now();
	strSorter.SelectionSort(strCopy, STR_SIZE);
	stop = chrono::high_resolution_clock::now();
	ms = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
	cout << "Time to complete SelectionSort in sec: " << to_string(ms / 1000) << endl;
	cout << "Time to complete SelectionSort in ms: " << to_string(ms) << endl;
	outputFile << "\nSelectionSort                  " + to_string(ms / 1000) + '/' + to_string(ms);
	cout << firstTenS(strCopy, STR_SIZE);
	cout << lastTenS(strCopy, STR_SIZE);
	copyArray(strArr, strCopy, STR_SIZE);

	cout << firstTenS(strCopy, STR_SIZE);
	cout << lastTenS(strCopy, STR_SIZE);
	cout << "\nCalling shaker sort now.";
	start = chrono::high_resolution_clock::now();
	strSorter.ShakerSort(strCopy, STR_SIZE);
	stop = chrono::high_resolution_clock::now();
	ms = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
	cout << "Time to complete ShakerSort in sec: " << to_string(ms / 1000) << endl;
	cout << "Time to complete ShakerSort in ms: " << to_string(ms) << endl;
	outputFile << "\nShakerSort                     " + to_string(ms / 1000) + '/' + to_string(ms);
	cout << firstTenS(strCopy, STR_SIZE);
	cout << lastTenS(strCopy, STR_SIZE);
	//Cleaning up and deleting our new objects
	delete[] strArr;
	delete[] strCopy;
	strArr = nullptr;
	strCopy = nullptr;


	outputFile << "\n\nTemplate Sort information for Persons\nName of Sort Function:	Time to Complete Function in secs/ms: ";
	//PERSONS
	Persons = new Person[PERSON_SIZE];
	TmpPersons = new Person[PERSON_SIZE];
	PersonGen* pg = new PersonGen;
	for (int i{ 0 }; i < PERSON_SIZE; i++)
	{
		if (pg->UseFile(STR_FILENAME))
		{
			Persons[i] = pg->GetPerson();
		}
	}


	copyArray(Persons, TmpPersons, PERSON_SIZE);
	cout << firstTenP(TmpPersons, PERSON_SIZE);
	cout << lastTenP(TmpPersons, PERSON_SIZE);
	cout << "\nCalling BubbleSort now.";
	start = chrono::high_resolution_clock::now();
	pSorter.BubbleSort(TmpPersons, PERSON_SIZE);
	stop = chrono::high_resolution_clock::now();
	ms = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
	cout << "Time to complete BubbleSort in sec: " << to_string(ms / 1000) << endl;
	cout << "Time to complete BubbleSort in ms: " << to_string(ms) << endl;
	outputFile << "\nBubbleSort                     " + to_string(ms / 1000) + '/' + to_string(ms);
	cout << firstTenP(TmpPersons, PERSON_SIZE);
	cout << lastTenP(TmpPersons, PERSON_SIZE);
	copyArray(Persons, TmpPersons, PERSON_SIZE);

	cout << firstTenP(TmpPersons, PERSON_SIZE);
	cout << lastTenP(TmpPersons, PERSON_SIZE);
	cout << "\nCalling comb11 now.";
	start = chrono::high_resolution_clock::now();
	pSorter.Comb11Sort(TmpPersons, PERSON_SIZE);
	stop = chrono::high_resolution_clock::now();
	ms = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
	cout << "Time to complete Comb11Sort in sec: " << to_string(ms / 1000) << endl;
	cout << "Time to complete Comb11Sort in ms: " << to_string(ms) << endl;
	outputFile << "\nComb11Sort                   " + to_string(ms / 1000) + '/' + to_string(ms);
	cout << firstTenP(TmpPersons, PERSON_SIZE);
	cout << lastTenP(TmpPersons, PERSON_SIZE);
	copyArray(Persons, TmpPersons, PERSON_SIZE);

	cout << firstTenP(TmpPersons, PERSON_SIZE);
	cout << lastTenP(TmpPersons, PERSON_SIZE);
	cout << "\nCalling insertion sort now.";
	start = chrono::high_resolution_clock::now();
	pSorter.InsertionSort(TmpPersons, PERSON_SIZE);
	stop = chrono::high_resolution_clock::now();
	ms = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
	cout << "Time to complete InsertionSort in sec: " << to_string(ms / 1000) << endl;
	cout << "Time to complete InsertionSort in ms: " << to_string(ms) << endl;
	outputFile << "\nInsertionSort                  " + to_string(ms / 1000) + '/' + to_string(ms);
	cout << firstTenP(TmpPersons, PERSON_SIZE);
	cout << lastTenP(TmpPersons, PERSON_SIZE);
	copyArray(Persons, TmpPersons, PERSON_SIZE);

	cout << firstTenP(TmpPersons, PERSON_SIZE);
	cout << lastTenP(TmpPersons, PERSON_SIZE);
	cout << "\nCalling selection sort now.";
	start = chrono::high_resolution_clock::now();
	pSorter.SelectionSort(TmpPersons, PERSON_SIZE);
	stop = chrono::high_resolution_clock::now();
	ms = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
	cout << "Time to complete SelectionSort in sec: " << to_string(ms / 1000) << endl;
	cout << "Time to complete SelectionSort in ms: " << to_string(ms) << endl;
	outputFile << "\nSelectionSort                  " + to_string(ms / 1000) + '/' + to_string(ms);
	cout << firstTenP(TmpPersons, PERSON_SIZE);
	cout << lastTenP(TmpPersons, PERSON_SIZE);
	copyArray(Persons, TmpPersons, PERSON_SIZE);

	cout << firstTenP(TmpPersons, PERSON_SIZE);
	cout << lastTenP(TmpPersons, PERSON_SIZE);
	cout << "\nCalling shaker sort now.";
	start = chrono::high_resolution_clock::now();
	pSorter.ShakerSort(TmpPersons, PERSON_SIZE);
	stop = chrono::high_resolution_clock::now();
	ms = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
	cout << "Time to complete ShakerSort in sec: " << to_string(ms / 1000) << endl;
	cout << "Time to complete ShakerSort in ms: " << to_string(ms) << endl;
	outputFile << "\nShakerSort                     " + to_string(ms / 1000) + '/' + to_string(ms);
	outputFile.close();
	cout << firstTenP(TmpPersons, PERSON_SIZE);
	cout << lastTenP(TmpPersons, PERSON_SIZE);
	delete[] Persons;
	delete[] TmpPersons;
	Persons = nullptr;
	TmpPersons = nullptr;



	cout << "Thank you for using my sorting program, goodbye!";
	return 0;
}