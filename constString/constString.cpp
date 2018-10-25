#include <iostream>
#include <string>

using namespace std;
// Or using std::cout if I only want that one specifically

class test
{
 public:
  test(const string &name) : mName(name) {};
  const string name() { return mName; };

private:
    const string mName;
};

int main(int argc, char**argv)
{
  string foo("foo");
  test t(foo);
  test t2(string("bar"));
  test t3("foobar");
  
  cout << t.name() << endl;
  cout << t2.name() << endl;
  cout << t3.name() << endl;
  
   return 0;
}
