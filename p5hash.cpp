/*    Seth Larcomb     
      
*/

/*  Edit this section to report your results

HFI        1.0 Probes     1.25 Probes    1.50  Probes    2.0 Probes
lameHash     1701           NNNN           NNNN            NNNN 
hash #1      NNNN           NNNN           NNNN            NNNN 
hash #2      NNNN           NNNN           NNNN            NNNN 
hash #3      NNNN           NNNN           NNNN            NNNN 
hash #4      NNNN           NNNN           NNNN            NNNN 
hash #5      NNNN           NNNN           NNNN            NNNN 

*/

#include "HASH.h"
#include <iostream>
#include <fstream>

/*  someClass   is intended to represent an item that we wish to be able
to lookup in some container via its key.

this class could have lots of other data fields and 
corresponding getters/setters.

the key feature here is that it have a key field and
a getter function:   getKey
which can be used by the hash class
*/
class someClass {
public:
	string  getKey() { return key; }
	someClass( string theKey = ""){
		key = theKey;
	}
private:
	string key;
	// other data fields
};

/*     hash functions go here    */

//int h(char* x) {
//	int i, sum;
//	for (sum = 0, i = 0; x[i] != '\0'; i++)
//		sum += (int)x[i];
//	return sum % 10000;
//}


/* lameHash:
a particularly lame hash function - just for demo purposes 
*/

long lameHash( string key ) {
long x = (int)key[0];
long y = 12341*(int) key[ key.size()-1];
	return (x+y);

}

/* nextPrime:
find the next prime number after num
*/
int nextPrime( int num) {

	num++;                       // first candidate is the next number after num
	if ( num % 2 == 0) num++;    // even numbers can't be prime.

	for ( int candidate = num; ; candidate+=2 ) {  // generate candidates for the next prime, test each one

		bool indivisible = true;				                   // assume candidate is prime 
		for ( int divisor = 3; divisor < candidate; divisor++) {   // check all possible divisors
			if ( candidate % divisor == 0) {                       //  no remainder means divisor divides into candidate evenly.
				indivisible = false;                               //     so candidate is not prime.
				//      would be a good idea to stop checking now
			}
		}

		if ( indivisible ) return candidate;					   //  if we get thru all divisors and none of them divide evenly
		//   then the candidate IS a prime number, return it.
	}
	return -1;  // will never happen, placate compiler.

}

/* getData
reads  the words from the file into the vector rawData
assumes there are exactly 100 strings
*/
void getData( vector<string> & rawdata )
{
	ifstream infile("data.txt");
	string aString;

	for ( int i=0; i < 100; i++ ) {
		getline( infile, aString);
		rawdata.push_back(aString);
		cout << aString << endl;
	}
}


/*  main  

given a hash function and a hash table size, main will add all words in vector rawData to the hash Table
and print out the number of probes required.  100 is the best possible result.

*/

int main() { 

	int tableSize = 1251;
	int sum;

	vector<string> rawData;                 //  stores words so we only need to read them once

	getData( rawData );					    // read data from file

	HASH<someClass> test1( tableSize, lameHash);			// create a HASH instance.
	sum = 0;
	for ( int i = 0; i < (int) rawData.size(); i++ ) {
		someClass aClass( rawData[i] );					// create an instance of someClass with the ith key
		sum += test1.insert( aClass );				    // insert into the Hash Table, keep track of # of probes
	}
	cout << "number of probes required for table size: " << tableSize << "  "  << sum << endl;

}

