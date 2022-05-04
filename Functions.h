//Anthony Franklin afranklin18@cnm.edu
//C++ Templates and Sorting Algorithms
//03/21/2022
//Functions.h

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <fstream>
#include <iostream>
#include <string>


template<typename T>
void copyArray(T originArray[], T destinationArray[], int Size)
{
	for (int i{ 0 }; i < Size; i++)
	{
		destinationArray[i] = originArray[i];
	}
}


template<typename T>
void readFile(T destinationArray[], string Filename, int Size)
{
	ifstream file(Filename);
	if (file.is_open())
	{
		int count{ 0 };
		T x;
		while (count < Size && file >> x)
		{
			// and read integer from file
			destinationArray[count] = x;
			count++;
		}
		file.close();
	}
}
template<typename T>
void readFileS(T destinationArray[], string Filename, int Size) //Gets full line of string, including punctuation
{
	ifstream file(Filename);
	if (file.is_open())
	{
		int count{ 0 };
		T x;
		while (count < Size)
		{
			getline(file, x);
			destinationArray[count] = x;
			count++;
		}
		file.close();
	}
}

template<typename T>
string firstTen(T arr[], int Size)
{
	string output;
	if (Size >= 10)
	{
		for (int i{ 0 }; i < 10; i++)
		{
			output.append(to_string(arr[i]) + "\n");
		}
	}
	return output;
}


template<typename T>
string lastTen(T arr[], int Size)
{
	string output;
	if (Size >= 10)
	{
		for (int i{ 0 }; i < Size; i++)
		{
			while (i < Size - 10)
			{
				i++;
				continue;
			}
			output.append(to_string(arr[i]) + "\n");
		}
		return output;
	}
	
}


template<typename T>
string firstTenP(T arr[], int Size)
{
	string output;
	if (Size >= 10)
	{
		for (int i{ 0 }; i < 10; i++)
		{
			output.append((arr[i]).GetName() + "\n");
		}
	}
	return output;
}


template<typename T>
string lastTenP(T arr[], int Size)
{
	string output;
	if (Size >= 10)
	{
		for (int i{ 0 }; i < Size; i++)
		{
			while (i < Size - 10)
			{
				i++;
				continue;
			}
			output.append((arr[i]).GetName() + "\n");
		}
		return output;
	}

}

template<typename T>
string firstTenS(T arr[], int Size)
{
	string output;
	if (Size >= 10)
	{
		for (int i{ 0 }; i < 10; i++)
		{
			output.append(arr[i] + "\n");
		}
	}
	return output;
}


template<typename T>
string lastTenS(T arr[], int Size)
{
	string output;
	if (Size >= 10)
	{
		for (int i{ 0 }; i < Size; i++)
		{
			while (i < Size - 10)
			{
				i++;
				continue;
			}
			output.append(arr[i] + "\n");
		}
		return output;
	}

}
#endif // !FUNCTIONS_H
