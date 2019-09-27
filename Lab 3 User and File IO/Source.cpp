/* Benjamin Roe
 C++ Fall 2019
 Due September 26, 2019
 Lab 3 File I/O
 Write an interactive C++ program that computes and outputs the mean and
 standard deviation of a set of four integers that are inputted by a file.
*/

#include <iostream>
#include <fstream>
using namespace std;

/* Defining of all variable and function names.
The same variable names are used for both the user input and the file input. */
int Input1;
int Input2;
int Input3;
int Input4;
float mean = 0;
float sd = 0;
void findMean();
void fileInput();

int main()
//Tells the other functions to run as well as outputting to the screen.
{
	cout << "Input four numbers to get back their mean and standard deviation." << endl;
	cin >> Input1 >> Input2 >> Input3 >> Input4; //User inputs four numbers.
	findMean();
	cout << "The mean of the four numbers you input is " << mean << "." << endl;
	cout << "The standard deviation of the four numbers you input is " << sqrt(sd) << "." << endl << endl;
	//Results from user inputs are output to the screen.
	fileInput();
	return 0;
}

void findMean()
//Finds the mean and standard deviation for both the user inputs and the file inputs.
{
	mean = float(Input1 + Input2 + Input3 + Input4)/4; //Finds mean.
	sd = (pow((Input1 - mean), 2) + pow((Input2 - mean), 2) + pow((Input3 - mean), 2) + pow((Input4 - mean), 2))/4;
	//Finds standard deviation.
}

void fileInput()
//Calls the input and output files and retrieves from the input and returns to the output.
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("C:/Users/ROE26/Desktop/inMeanStd.dat");
	outFile.open("C:/Users/ROE26/Desktop/outMeanStd.dat");
	//Actually calls the the files.
	inFile >> Input1 >> Input2 >> Input3 >> Input4; //Gets input from the file.
	findMean();
	outFile << "The mean of the four numbers the file input is " << mean << "." << endl;
	outFile << "The standard deviation of the four the file input is " << sqrt(sd) << "." << endl;
	//Outputs to the file
}