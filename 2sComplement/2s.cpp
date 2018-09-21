#include <string>
#include <iostream>
#include <climits>
#include <bitset>

using namespace std;

int main()
{
   int i;

   cout << "Enter integer:";
   cin >> i;

   cout << "i in binary " << bitset<16>(i) << endl;
   cout << "INT_MAX:  " << INT_MAX << " " << bitset<sizeof(int)*CHAR_BIT>(INT_MAX) << endl;
   cout << "INT_MIN:  " << INT_MIN << " " << bitset<sizeof(int)*CHAR_BIT>(INT_MIN) << endl;
   cout << "INT_MIN+1:" << INT_MIN+1 << " " << bitset<sizeof(int)*CHAR_BIT>(INT_MIN+1) << endl;

   cout << "i   = " << i << "\n";
   cout << "-i  = " << -i << "\n";
   cout << "~i  = " << ~i << "\n";

   cout << "_i  = " << ((~i) & (INT_MIN+1)) << "\n";

   cout << "__i  = " << ((~i) & INT_MAX) << "\n";
   cout << "__i  = " << bitset<sizeof(int)*CHAR_BIT>((~i) & INT_MAX) << "\n";
   
      


   return 0;
}
