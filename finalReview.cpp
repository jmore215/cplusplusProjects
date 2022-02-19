//finalReview.cpp
//May 3, 2016

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//declare struct called Book
struct Book
{
	//fields(properties)
	string title, author;
	int copyrightDate;
	float price;

	//constructor
	Book()	
	{	
		copyrightDate = 2016;
		price = 0.0;	
	}
};

//function protypes
void GetBook(Book &tempBook); 
/*should prompt the user for a single Book.
Input validation:
The cost of the book must be at least $0.01.
The copyright date must be between 0 and 2012.*/

void AppendFile(Book tempBook); //should append the file “books.txt” with the Book that is passed to the function.

void ReadData(Book bookArr[], int n);
/*should accept an array of Books and the number of books to be read in (n).  The function should read in the first n books from the file and store in the array of Books.*/

void DisplayTitles(const Book bookArr[], int n);
/* should accept an array of type Book and the number of books to display(n).  The function should display the title and author of the first n books in the array as follows:
Book 1: Sunshine written by Gilbert
Book 2: Boom! written by Brokaw
Book 3: Beowulf written by McNamara */

int BooksUnderTwelve(const Book bookArr[], int n);
/* should accept an array of Books and the number of the Books(n).  The function should return the number of books in the first n Books in the array that cost less than $12. */

float AverageCost(const Book bookArr[], int n);
/* should accept an array of Books and the number of the Books(n).  The function should return the average cost of the books in the first n Books in the array.*/

int PublishedAfter2006(const Book bookArr[], int n);
/* should accept an array of Books and the number of the Books(n).  The function should return the number of books in the first n Books in the array whose copyright date is after 2006.*/

int main()
{
	//declare an array of type Book, size 10, called bookArray
	Book bookArray[10];

	//declare a single Book object called myBook
	Book myBook;

	int menuChoice = 0;

do
{
	cout<<"Please choose:\n";
	cout<<"1) Enter a new book\n2) See data\n3) Exit\n";
	cout<<"Enter your choice here: ";
	cin>>menuChoice;

	if(menuChoice == 1)
	{
	//call the function GetBook, store the result in myBook
	GetBook(myBook);

	//call AppendFile
	AppendFile(myBook);


	}
	
	else if(menuChoice == 2)
	{
		//read in data for the first 3 Books in the file
		ReadData(bookArray, 3);

		//call DisplayTitles
		DisplayTitles(bookArray, 3);

		//display the number of books under $12
		cout<<"The number of books under $12 = "<<BooksUnderTwelve(bookArray, 3)<<endl;	

		//display the average cost of the books
		cout<<"The average cost of the books = "<<AverageCost(bookArray, 3)<<endl;
		
		//display the number of books whose copyright date is after 2006
		cout<<"The number of books published since 2006 = "<<PublishedAfter2006(bookArray, 3)<<endl;
	}

	else if(menuChoice == 3)
	{
		cout<<"Good bye.\n";
	}
	else
		cout<<"Invalid.\n";
}while (menuChoice != 3);
	

	//display the third book's copyrightDate
	cout<<"The third book's date = "<<bookArray[2].copyrightDate<<endl;

	//display the cost of the first book in the array
	cout<<"the cost of the first book = "<<bookArray[0].price<<endl;

	//display the author and title of myBook
	cout<<"Author and title of myBook = "<<myBook.title<<" "<<myBook.author<<endl;
	



return 0;
}

//function defs

void ReadData(Book bookArr[], int n)
{

	//declare a file pointer
	ifstream infile;
	
	//open books.txt for input
	infile.open("books.txt", ios::in);

	//for loop to read in one record at a time and store in bookArr
	for(int i = 0; i < n; i++)
	{
	infile>>bookArr[i].title>>bookArr[i].author>>bookArr[i].copyrightDate>>bookArr[i].price;

	}
	
	//close file
	infile.close();

}

void GetBook(Book &tempBook)
{

	cout<<"Enter the book's title: ";
	cin>>tempBook.title;

	cout<<"Enter the book's author: ";
	cin>>tempBook.author;

	cout<<"Enter the book's date: ";
	cin>>tempBook.copyrightDate;

	cout<<"Enter the book's price: $";
	cin>>tempBook.price;

}

void AppendFile(Book tempBook)
{
	//declare a file pointer for app
	ofstream outfile;

	//open for app
	outfile.open("books.txt", ios::app);

	//write the new book to the file
	outfile<<tempBook.title<<"\t"<<tempBook.author<<"\t"<<tempBook.copyrightDate<<"\t"<<tempBook.price<<endl;

	//close file
	outfile.close();
}
/* should accept an array of type Book and the number of books to display(n).  The function should display the title and author of the first n books in the array as follows:
Book 1: Sunshine written by Gilbert
Book 2: Boom! written by Brokaw
Book 3: Beowulf written by McNamara */
void DisplayTitles(const Book bookArr[], int n)
{

	for(int i = 0; i < n; i++)
	{
	cout<<"Book "<<i + 1<<": "<<bookArr[i].title<<" written by "<<bookArr[i].author<<endl;

	}

}
/* should accept an array of Books and the number of the Books(n).  The function should return the number of books in the first n Books in the array that cost less than $12. */
int BooksUnderTwelve(const Book bookArr[], int n)
{	//counter
	int bookCount = 0;	

	for(int i = 0; i < n; i++) 
	{
		if(bookArr[i].price < 12)
			bookCount++;
	}

	return bookCount;
}

float AverageCost(const Book bookArr[], int n)
{
	float total = 0.0;

	for(int i = 0; i < n; i++)
	{
	total += bookArr[i].price;

	}

	return total / n;

}
/* should accept an array of Books and the number of the Books(n).  The function should return the number of books in the first n Books in the array whose copyright date is after 2006.*/
int PublishedAfter2006(const Book bookArr[], int n)
{
	//counter
	int count = 0;
	for(int i = 0; i < n; i++)
	{
	if(bookArr[i].copyrightDate > 2006)
		count++;
	
	}
	
	return count;	


}

