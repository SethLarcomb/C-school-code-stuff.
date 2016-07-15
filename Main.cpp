/* CS 3350 Spring 2015
Author: < Seth Larcomb >
Created: < Jan 29th 2015 >
File: <p1.cpp>

Purpose:
Method summary:
*/

//#include <> or ""
#include <string>
#include <fstream>
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <sstream>
#include <cstdlib> //???

//basicly adds hidden subset to variable
using namespace std;
void quickSort(int arr[], string arr2[], int left, int right);
//main program
int main()
{
	cout << "wait for it... it takes a minute, literally... a.k.a loading..." << endl;
	/***************************Desktop/canterbury.txt*/
string canterbury = "canterbury.txt"; //name of file attached to string canterbury
string mew = "mew.txt";
ifstream fileName(canterbury);     //opens file



string CLH[2500]; //Canterbury line holder
string CWH[2500]; //Canterbury word holder
string MWH[25027];//Mew Word holder
int WCA[25027]; //Word Count Array

string storedWord;
string line;

char Token;

int x = 0;
int y = 0;
int z = 0;
int n = 0;

int left = 0;
int right = 25026; //dont change or it breaks


bool done = false;


if (fileName.is_open())            //isOpen <Legacy way
{
	while (!fileName.eof())
	{
		getline(fileName, line);
		CLH[x] = line;
		//cout << CLH[x] << endl;
		x++;
	}
		fileName.close();               //closes the fill	
}
else
{
	cout << "Error Reading File. ";
}

x = 0;  // reset x to zero for next use

ifstream fileName2(mew); //opens file


if (fileName2.is_open())
{
	while (!fileName2.eof())
	{
		getline(fileName2, line);
		MWH[x] = line;
		//cout << MWH[x] << endl;
		x++;
	}
	fileName2.close();

}
else
{
	cout << "Error Reading File. ";
}

x = 0; // reset counters to zero for next use.


while (!done)
{

	line = CLH[z];
	y = 0;
	char* ptr = &line[y]; 
	//test code
	while (*ptr != '\0')
	{
		if (*ptr == ' ')
		{
			//cout << CWH[x] << endl;
			x++;
		}
		//might need if ptr is not null check space then go to next element
		else
		{
			CWH[x] += *ptr;
			
		}
		ptr++;
	}
	if (*ptr == '\0')
	{
		
		x++;
		//cout << CWH[x] << endl;
	}
	z++;

	if (z == 75)
	{
		done = true;
	}
}

////////////////////////////////////////
//  Bugs up to this point
// ,But and hom-comynge
//	wynne;
//  space after presence.. a.k.a FML
////////////////////////////////////

//resets for later use
x = 0;
y = 0;
z = 0;
done = false;

while (z != 1)
{
		storedWord = CWH[x];              //pull word out of array for future use.

		Token = storedWord.back();
		
			if (Token == ',' || Token == '?' ||
				Token == '!' || Token == '-' ||
				Token == ';' || Token == '.')
			{
				storedWord.pop_back();  //effectly removes special charcter. c++11			
				CWH[x] = storedWord;    //restore back into the array slot  brakes
				//cout << CWH[x] << endl;
			}


		x++;   //go to next word
		if (storedWord == "lay")
		{
			z = 1;
		}
		//hotfix for whole in array... fml
		if (storedWord == "presence")
		{
			x++;
		}
}

//resets for later use
x = 0;
y = 0;
z = 0;
while (z != 1)
{
	storedWord = CWH[x];              //pull word out of array for future use.

	Token = storedWord[0];

	if (isupper(storedWord[0])
	   /*Token == 'A' || Token == 'B'||
		Token == 'C' || Token == 'E' ||
		Token == 'F' || Token == 'G' ||
		Token == 'H' || Token == 'I' || 
		Token == 'J' || Token == 'K' || 
		Token == 'L' || Token == 'M' || 
		Token == 'N' || Token == 'O' || 
		Token == 'P' || Token == 'Q' || 
		Token == 'R' || Token == 'S' || 
		Token == 'T' || Token == 'U' ||
		Token == 'V' || Token == 'W' || 
		Token == 'X' || Token == 'Y' ||
		Token == 'Z'*/
		//does all that for you... nice...
		)
	{
		storedWord[0] = tolower(storedWord[0]);  //effectly removes special charcter. c++11
		CWH[x] = storedWord;    //restore back into the array slot  brakes

	}


	x++;   //go to next word
	if (storedWord == "lay")
	{
		z = 1;
	}
	//hotfix for whole in array... fml
	if (storedWord == "presence")
	{
		x++;
	}
}
z = 0; //reset
x = 0; //return counters back to zero for later use
y = 0; //
//




//loop to start comparing and counting
//IT WORKS!!!
while (x < 25027)
{
	while (y < 602)
	{
		storedWord = MWH[x];
		line = CWH[y];
		//linear search
		//goes through all of CWH and 
		//if(MWH[x] == CWH[y])
		if (storedWord == line)
		{
			n = WCA[x];
			n++;
			WCA[x] = n;
			y++;
		}
		else if (storedWord != line)
		{
			WCA[x] = n;
			y++;
		}
	}
	//if (line == "presence")
	//{
	//	y++;
	//}
	x++;
	y = 0; //reset y for next while loop around of MWH.
	n = 0; //resets counter for next location of WCA
	


}
//resets*/






////////////////////////////////////////////////////////////
//STRICTLY MODERN ENGLISH ORGANIZING///////////////////////
//////////////////////////////////////////////////////////
n = 25026;
x = 25026;
////////////////////////////////////////////////////////
//Need to search for top ten 4 letter strings//////////
//////////////////////////////////////////////////////
//this loop should compare the amount of WCA[x] to WCA[x+1] 
//and see which of the two is higher.
//what is the output?
////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

quickSort(WCA, MWH, left, right);

////////////////////     \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//OUTPUT BABY!!!
////////////////// \     /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


cout << "Top 10 Modern English Words (length >= 4) :" << endl;

while(x > 24993) 
{
	storedWord = MWH[x];

 if(storedWord.size() >= 4)
 {
 cout << MWH[x] << " " << WCA[x] << endl;
 x--;
 }
 else
 {
 x--;
 }
}
/*
while (x > 25015)
{
	cout << MWH[x] << " " << WCA[x] << endl;
	//n--;
	x--;

	//still skipping that stupid space in arrays...
	if (x == 25018)
	{
		//n--;
		x--;
	}
}
*/

/*my little debugger program copy paste*/

//while (x < 200)
//{
//	cout << CWH[x] << endl;
//	x++;
//}
//if all is lost... 'and it is...' 
/*
cout << "number of Modern English Words : 582" << endl;
cout << "number of    Old English Words : 2438" << endl;
cout << "Top 5 Modern English Words (length >=4) :" << endl;
cout << "that  493" << endl;
cout << "this  184" << endl;
cout << "with  183" << endl;
cout << "hath  78" << endl;
cout << "they  73" << endl;
cout << "Top 5 Old English Words (length >=4) :" << endl;
cout << "ther  107" << endl;
cout << "arcite   59" << endl;
cout << "whan   57" << endl;
cout << "shal   50" << endl;
cout << "emelye   44" << endl;
*/
system("PAUSE"); 

}


//algorithm variables
void quickSort(int arr[],string arr2[],int left,int right) {
	int i = left, j = right;
	int tmp;
	string stmp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			stmp = arr2[i];
			arr[i] = arr[j];
			arr2[i] = arr2[j];
			arr[j] = tmp;
			arr2[j] = stmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSort(arr, arr2, left, j);
	if (i < right)
		quickSort(arr, arr2, i, right);
}
///////////////////////////////////////////////////////////