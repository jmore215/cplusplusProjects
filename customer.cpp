//customers.cpp
//Jennifer Moreno
//March 1, 2016
//This program writes a report based on information about a company's customers

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{

	//Declare and initialize variables
	char menuChoice = ' ';
	float totalBalance = 0.0, averageBalance = 0.0, bal1 = 0.0, bal2 = 0.0, bal3 = 0.0, bal4 = 0.0;
	string fname1, fname2, fname3, fname4, lname1, lname2, lname3, lname4;

	//Declare a file pointer for input
	ifstream infile;
	//Declare a file pointer for output
	ofstream outfile;

		do
		{

			//Display Menu
			cout << "*********************************************\n\n";
			cout << "Please choose 1-3 from the following menu: \n";
			cout << "\t1) Create Customer Report" << endl;
			cout << "\t2) Display Total and Average Balance" << endl;
			cout << "\t3) Exit" << endl;
			cout << endl;
			cout << "*********************************************\n";

			//Prompt for menuChoice
			cout << "Enter your menu choice: ";
			cin >> menuChoice;
			cout << endl;

				switch (menuChoice)

				{
				case '1':

						//Open file "customers.txt" for input
						infile.open("customers.txt", ios::in);

						//If no file
						if (!infile)
							cout << "File Not Found!\n\n";

						//Read in "customers.txt"
						infile >> fname1 >> lname1 >> bal1;
						infile >> fname2 >> lname2 >> bal2;
						infile >> fname3 >> lname3 >> bal3;
						infile >> fname4 >> lname4 >> bal4;

						//Close file "customers.txt"
						infile.close();

						//Open file "report.txt" for output
						outfile.open("report.txt", ios::out);

						//Write Data to "report.txt"
						outfile << "Name\t\tBalance Owed" << endl;
						outfile << "----------------------------" << endl;
						outfile << fname1 << " " << lname1 << "\t$" << fixed << showpoint << setprecision(2) << bal1 << endl;
						outfile << fname2 << " " << lname2 << "\t$" << fixed << showpoint << setprecision(2) << bal2 << endl;
						outfile << fname3 << " " << lname3 << "\t$" << fixed << showpoint << setprecision(2) << bal3 << endl;
						outfile << fname4 << " " << lname4 << "\t$" << fixed << showpoint << setprecision(2) << bal4 << endl;

						//Close file "report.txt"
						outfile.close();

						break;

				case '2':

						//Open file "customers.txt" for input
						infile.open("customers.txt", ios::in);

						//If no file
						if (!infile)
							cout << "File Not Found!\n\n";

						//Read in "customers.txt"
						infile >> fname1 >> lname1 >> bal1;
						infile >> fname2 >> lname2 >> bal2;
						infile >> fname3 >> lname3 >> bal3;
						infile >> fname4 >> lname4 >> bal4;

						//Close file "customers.txt"
						infile.close();

						//Calculate the total balance
						totalBalance = bal1 + bal2 + bal3 + bal4;

						//Calculate the average balance
						averageBalance = totalBalance / 4;

						//Display Total Balance
						cout << fixed << setprecision(2);
						cout << "The Total Balance is: $" << totalBalance << endl;

						//Display Average Balance
						cout << fixed << setprecision(2);
						cout << "The Average Balance is: $" << averageBalance << endl;
						cout << endl;

						break;

				case '3':

						//Display "Have a nice day!"
						cout << "Have a nice day!\n\n";

						break;


				default:
					
						//Display Invalid
						cout << "Invalid! You must choose 1-3 from the menu!\n\n";
				}


		} while (menuChoice != '3');

			return 0;
}