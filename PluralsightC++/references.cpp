
#include <iostream>
#include <string>


using namespace std;

// string operator=(const string l, const string r)  {
//   cout << "You're a dumbass/n";
//   return "You're a dumbass";
// }

string& operator+ (string &l, string &r) {
   cout << "overloaded operator+\n";
   return l;
}


int myLen( const string &s)
{
  //s = s + "APPENDAGE";
  return s.length();
}

int
main(int argc, char** argv)
{
//  cout << "Hello world\n";

  string s("Hello world\n");
  string &rs = s;
//   cout << "Length s is " << myLen(s) << endl;
//   cout << "Length rs is " << myLen(rs) << endl;

  cout << rs+rs;

  return 0;
}
