#include <string>
#include <vector>
#include <list>

using namespace std;

typedef long (*HshFunc)(string);

template <class T>
class HASH
{
public:
	HASH(void);
	HASH(int tsize, HshFunc theFunc) ;     
	int insert( T & );
	int find(string key);
	~HASH(void) {}
private:
	vector< list<T> > hshTable;    // suitable for use with chaining, (not done here though)
	HshFunc func;				   //  store pointer to the passed function  !!!
};



/* HASH constructor
 * tsize    table size
 * f        function pointer, signature defined by HshFunc typedef  (above)
 *
 * Method: allocate table, set function
*/
template <class T>
HASH<T>::HASH( int tsize, HshFunc f){
	hshTable.clear();
    hshTable.resize( tsize );
//cout << " the size is " << hshTable.size() << endl;
    func = f;
}

/* insert.
 *  inserts T object val into table uing linear probing
 *  precondition: space is available in the table
 *
 * method:
 *   getKey from val object.
 *   hash key , check location in table.
 *   if location is empty, add T object to location
 *   else probe table from location (mod) to find
 *   empty space.
 *   return number of probes required.
*/

template <class T>
int HASH<T>::insert( T & val ) {
    long hval = func( val.getKey() );
    int count = 1;
    int loc  = hval % hshTable.size();
    while ( ! hshTable[loc].empty() ) {
          loc = (loc +1) % hshTable.size();
          count++;
    }
    hshTable[loc].push_front( val );
    return count;
}


/*   find
*
*    NOT  a real find function
*    Provided simply to study the implementation
*
*       return # probes required
*
*/
template <class T>
int HASH<T>::find( string key ) {

     int probeCount = -1;
     return  probeCount;
}
