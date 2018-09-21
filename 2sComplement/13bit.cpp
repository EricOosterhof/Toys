#include <string>
#include <iostream>
#include <climits>
#include <bitset>

using namespace std;


//13 bit 2s complement is 1 sign bit, n-1 mag bits
string twos( const int &i, const int &n)
{
   int j;
   if ( i & (1<<(n-1)) )
   {
      j = ((~i & ((1<<(n-1))-1))+1)*-1;
//      j = ((~i+1)*-1;
   }
   else
   {
      j = i;
   }

   return to_string(j);   
}

void binout(int x)
{
   cout << x << "  " << bitset<sizeof(int)*CHAR_BIT>(x) << endl;
}

int main()
{
   int i;

   cout << twos(-5,13) << endl;
   cout << twos(0x1fff,13) << endl;

   for ( i = -4095 ; i < 0xfff ; i+=100 )
   {
      cout << twos((const int) i,13) << "   ";
      cout << endl;
         
   }

   cout << endl;



   for ( i = -10 ; i < 10 ; i++ )
   {
      cout << twos((const int) i,13) << "   ";
      cout << endl;
   }

   

   cout << endl;

   cout << bitset<sizeof(int)*CHAR_BIT>(-1) << endl;
   cout << bitset<sizeof(int)*CHAR_BIT>(0x1fff) << endl;

   binout(-1);

   cout << twos((const int) 0x1ff0,13) << "   " << endl;
   cout << twos((const int) 0x1ff2,13) << "   " << endl;
   cout << twos((const int) 0x1ff4,13) << "   " << endl;
   cout << twos((const int) 0x1ff6,13) << "   " << endl;
   cout << twos((const int) 0x1ff8,13) << "   " << endl;
   cout << twos((const int) 0x1ffA,13) << "   " << endl;
   cout << twos((const int) 0x1ffB,13) << "   " << endl;
   cout << twos((const int) 0x1ffC,13) << "   " << endl;
   cout << twos((const int) 0x1ffD,13) << "   " << endl;
   cout << twos((const int) 0x1ffE,13) << "   " << endl;
   cout << twos((const int) 0x1ffF,13) << "   " << endl;

   cout << twos((const int) 0x0ff0,13) << "   " << endl;
   cout << twos((const int) 0x0ff2,13) << "   " << endl;
   cout << twos((const int) 0x0ff4,13) << "   " << endl;
   cout << twos((const int) 0x0ff6,13) << "   " << endl;
   cout << twos((const int) 0x0ff8,13) << "   " << endl;
   cout << twos((const int) 0x0ffA,13) << "   " << endl;
   cout << twos((const int) 0x0ffB,13) << "   " << endl;
   cout << twos((const int) 0x0ffC,13) << "   " << endl;
   cout << twos((const int) 0x0ffD,13) << "   " << endl;
   cout << twos((const int) 0x0ffE,13) << "   " << endl;
   cout << twos((const int) 0x0ffF,13) << "   " << endl;

   cout << twos((const int) 0x0000,13) << "   " << endl;
   cout << twos((const int) 0x0001,13) << "   " << endl;
   cout << twos((const int) 0x0002,13) << "   " << endl;
   cout << twos((const int) 0x0004,13) << "   " << endl;
   cout << twos((const int) 0x0006,13) << "   " << endl;
   cout << twos((const int) 0x0008,13) << "   " << endl;
   cout << twos((const int) 0x000A,13) << "   " << endl;
   cout << twos((const int) 0x000B,13) << "   " << endl;
   cout << twos((const int) 0x000C,13) << "   " << endl;
   cout << twos((const int) 0x000D,13) << "   " << endl;
   cout << twos((const int) 0x000E,13) << "   " << endl;
   cout << twos((const int) 0x000F,13) << "   " << endl;




   return 0;
}
