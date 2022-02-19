//COP1334C Fall 2013 Exam 2
//Name: Jennifer Moreno

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

//function prototypes:

//return type: string
//parameters: none
//This function prompts for and returns the user's name
string GetName();

//return type: void
//parameters: 1 string by reference(social)
//This function prompts for and returns a social security number
void GetSSN(string &social);

//return type: float
//parameters: none
//This function prompts for and returns the weekly hours worked.
//The number of hours worked must be between 0 and 168.
float GetWeeklyHours();

//return type: void
//parameters: 1 float by ref(payrate)
//This function prompts for the hourly pay rate.  
//The pay rate must be greater than $7.67.
void GetHourlyPay(float &payrate);

//return type: void
//parameters: 1 float by ref(ins)
//This function prompts for and returns the amount deducted for health insurance.
//The amount paid can not be negative.
void GetHealthInsurance(float &ins);

//return type: float
//parameters: 2 floats by value(hours, payrate)
//This function calculates and returns the weekly pay.
//Any hours over 40 are considered overtime and are paid time and a half.
float GrossPay(float hours, float payrate);

//return type: float
//parameters: 1 float by value(grosspay)
//This function calculates and returns the amount deducted for Medicare.
//Medicare is 1.5% of the gross pay. 
float Medicare(float grosspay);

//return type: float
//parameters: 1 float by value(grosspay)
//This function calculates and returns the amount deducted for Social Security.
//Social Security is 6.5% of the gross pay. 
float SocialSecurity(float grosspay);

//return type: float
//parameters: 1 float by value(grosspay)
//This function calculates and returns the amount deducted for federal taxes.
//Federal taxes are based on Annual Income and are calculated as follows:
/*
$0.00 to $8500.00		10%
$8500.01 to $34500		15%
$34500.01 to $83600		25%
$83600.01 to $174400.00		28%
$174400.00	to $379150.00	33%
Over $379150.00		35%
*/
float FederalTax(float grosspay);

//return type: float
//parameters: 5 floats by value(grosspay,health,med, ss, fed)
//This function calculates and returns the net pay after health insurance, medicare, ss, and fed taxes are deducted.
float NetPay(float grosspay, float health, float med, float ss, float fed);

//return type: void
//parameters: 2 strings and 8 floats by value(name, ssn, hours, payrate, gross, health, med, ss, fed, net)
//This function displays a paycheck as follows:
/*
********************************************************
Employee Name: John Doe		SSN#: 123-33-3334
********************************************************
Hours Worked: 				60
Hourly Pay:					$12.50
Regular Gross Pay:			$875.00
Health Insurance:			$62.00
Medicare: 					$13.13
Social Security:			$56.88
Federal Withholding Tax:	$218.75
Net Pay:					$524.24			
*/
void DisplayPaycheck(string name, string ssn, float hours, float payrate, float gross, float health, float med, float ss, float fed, float net);

int main()
{
	//declare and initialize variables
	string myname, myssn;
	float myweeklyhours = 0.0, myhourlypay = 0.0, myhealth = 0.0;
	float mygross = 0.0, mynet = 0.0, mymed = 0.0, myfed = 0.0, myss = 0.0;
	int menuChoice = 0;
	
	//create menu and call functions to complete the program
	do 
	{
		cout << "1) Create an Employee Pay Check\n\n";
		cout << "2) Exit\n\n";
		cout << "Enter your choice: ";
		cin >> menuChoice;
	} while (menuChoice != 2);


	if (menuChoice = 1)
	{
		myname = GetName();

		GetSSN(myssn);

		myweeklyhours = GetWeeklyHours();

		GetHourlyPay(myhourlypay);

		GetHealthInsurance(myhealth);

		mygross = GrossPay(myweeklyhours, myhourlypay);

		mymed = Medicare(mygross);

		myss = SocialSecurity(mygross);

		myfed = FederalTax(mygross);

		mynet = NetPay(mygross, myhealth, mymed, myss, myfed);

		DisplayPaycheck(myname, myssn, myweeklyhours, myhourlypay, mygross, myhealth, mymed, myss, myfed, mynet);
	}

	else if (menuChoice = 2)
	{
		cout << "Have a nice day!\n";
	}

	else
	{
		//Display Invalid
		cout << "Invalid! You must choose 1 or 2 from the menu.\n\n";
	}


return 0;
}


//function definitions
//This function prompts for and returns the user's name
string GetName()
{
	string name;
	cout << "Enter your name: ";
	cin >> name;
	cout << endl;

	return name;
}

//This function prompts for and returns a social security number
void GetSSN(string &social)
{
	cout << "Enter your social security number: ";
	cin >> social;
	cout << endl;
}

//This function prompts for and returns the weekly hours worked.
//The number of hours worked must be between 0 and 168.
float GetWeeklyHours()
{
	float hours = 1.0;
	do
	{
		cout << "How many hours did you work: ";
		cin >> hours;
		if (hours < 0 || hours > 168)
		{
			//Display invalid
			cout << "Invalid! The number of hours worked must be between 0 and 168\n\n";
		}
	} while (hours < 0 || hours > 168);


	return hours;
}

//This function prompts for the hourly pay rate.
//The pay rate must be greater than $7.67.
void GetHourlyPay(float &payrate)
{
	do
	{
		cout << "What is your hourly pay?: ";
		cin >> payrate;
		if (payrate < 7.67)
		{
			//Display invalid
			cout << "Invalid! The hourly pay must be greater than $7.67.\n\n";
		}

	} while (payrate < 7.67);
}

//This function prompts for and returns the amount deducted for health insurance.
//The amount paid can not be negative.
void GetHealthInsurance(float &ins)
{
	do
	{
		cout << "How much do you pay in health insurance?: ";
		cin >> ins;
		if (ins < 0)
		{
			//Display invalid
			cout << "Invalid! The amount paid can not be negative.\n\n";
		}
	} while (ins < 0);
}

//This function calculates and returns the weekly pay.
//Any hours over 40 are considered overtime and are paid time and a half.
float GrossPay(float hours, float payrate)
{
	if (hours <= 40)
		return hours * payrate;
	else
		return (hours * payrate) * 1.5;
}

//This function calculates and returns the amount deducted for Medicare.
//Medicare is 1.5% of the gross pay. 
float Medicare(float grosspay)
{
	return grosspay * 0.015;
}

//This function calculates and returns the amount deducted for Social Security.
//Social Security is 6.5% of the gross pay. 
float SocialSecurity(float grosspay)
{
	return grosspay * 0.065;
}

//This function calculates and returns the amount deducted for federal taxes.
//Federal taxes are based on Annual Income and are calculated as follows:
/*
$0.00 to $8500.00			10%
$8500.01 to $34500			15%
$34500.01 to $83600			25%
$83600.01 to $174400.00		28%
$174400.00	to $379150.00	33%
Over $379150.00				35%
*/
float FederalTax(float grosspay)
{
	float annual = 0.0
	annual = grosspay * 52
	if (annual >= 0.0 || annual <= 8500)
		return annual * 0.10;
	else if (annual >= 8500.01 || annual <= 34500)
		return annual * 0.15;
	else if (annual >= 34500.01 || annual <= 83600)
		return annual * 0.25;
	else if (annual >= 83600.01 || annual <= 174400.00)
		return annual * 0.28;
	else if (annual >= 174400.01 || annual <= 379150.00)
		return annual * 0.33;
	else
		return annual * 0.35;
}

//This function calculates and returns the net pay after health insurance, medicare, ss, and fed taxes are deducted.
float NetPay(float grosspay, float health, float med, float ss, float fed)
{
	return grosspay - (health + med + ss + fed);
}

//This function displays a paycheck as follows:
/*
********************************************************
Employee Name: John Doe		SSN#: 123-33-3334
********************************************************
Hours Worked: 				60
Hourly Pay:					$12.50
Regular Gross Pay:			$875.00
Health Insurance:			$62.00
Medicare: 					$13.13
Social Security:			$56.88
Federal Withholding Tax:	$218.75
Net Pay:					$524.24
*/
void DisplayPaycheck(string name, string ssn, float hours, float payrate, float gross, float health, float med, float ss, float fed, float net)
{
	cout << fixed << setprecision(2);
	cout << "**************************************\n";
	cout << "Employee Name: " << name << "\t" << "SSN#: " << ssn << endl;
	cout << "**************************************\n\n";
	cout << "Hours Worked: \t\t\t$" << hours << endl;
	cout << "Hourly Pay: \t\t\t$" << payrate << endl;
	cout << "Regular Gross Pay: \t\t$" << gross << endl;
	cout << "Health Insurance: \t\t$" << health << endl;
	cout << "Medicare: \t\t\t$" << med << endl;
	cout << "Social Security: \t\t$" << ss << endl;
	cout << "Federal Withholding Tax: \t$" << fed < endl;
	cout << "Net Pay: \t\t\t$" << net << endl;
}





