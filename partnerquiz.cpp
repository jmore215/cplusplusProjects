/*partnerquiz.cpp
Chris, Michail, Jennifer
April 28, 2016
This program practices  on structs and arrays*/

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;


struct Car
{

	//Properties (data members)
	string make, model;
	int year;
	float cost;

	Car()
	{
		make= "Dodge";
		model = "Challenger";
		year = 2016;
		cost = 64195.00;

	}



};

//Function Prototypes

void GetCars(Car[], int);


void DisplayCar(Car);


float AverageCost(const Car[], int);



Car Newest(const Car[], int);


void DiscountCars(Car[], int);





int main()
{

	Car myCar[3];


	GetCars(myCar, 3);

	cout << "Make\tModel\tyear\tCost\n";
	cout << "------------------------------------\n";

	for (int i = 0; i < 3; i++)
	{
		DisplayCar(myCar[i]);
	}


	return 0;
}




//Function Definitions

void GetCars(Car tempCar[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the Make for Car " << i + 1 << ": ";
		cin >> tempCar[i].make;
		cout << endl;
		cout << "Enter the Model for Car " << i + 1 << ": ";
		cin >> tempCar[i].model;
		cout << endl;
		cout << "Enter the Year for Car " << i + 1 << ": ";
		cin >> tempCar[i].year;
		cout << endl;
		cout << "Enter the Cost for Car " << i + 1 << ": $";
		cin >> tempCar[i].cost;
		cout << endl;
	}

}


void DisplayCar(Car tempCar)
{
	
	cout << tempCar.make << " " << tempCar.model << " " << tempCar.year << " $" << tempCar.cost << endl;
}


float AverageCost(const Car tempCost[], int size)
{

	float average = 0.0 ,cost=0.0;

	for (int i = 0; i < size; i++)
	{
		cost += tempCost[i].cost;
		average = cost/size;
	}

	return average;
}



Car Newest(const Car tempCar[], int size)
{
	Car newest;
	newest = tempCar[0];

	for (int i = 1; i < size; i++)
	{
		if (tempCar[i].year > newest.year)
		{
			newest = tempCar[i];
		}


	}
	return newest;
}


void DiscountCars(Car tempDis[], int size)
{
	float discount = 0.0;
	for (int i = 0; i < size; i++)
	{
		tempDis[i].cost = tempDis[i].cost*0.90;
	}

}
