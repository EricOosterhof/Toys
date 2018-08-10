// From the Pluralsight C++ Fundamental training by Kate Gregory

#include <iostream>
#include <string>

using namespace std;
// Or using std::cout if I only want that one specifically

int main(int argc, char**argv)
{
   cout << "Type your name" << endl;
   string name;
   cin >> name;
   cout << "Hello, " << name << endl;

   return 0;
}
