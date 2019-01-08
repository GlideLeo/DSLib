#include <iostream>
#include "smartpointer.h"

using namespace std;
using namespace DSLib;

class Test  //Test class
{
public:
    Test()
    {
        cout << "Test()" << endl;
    }

    ~Test()
    {
        cout << "~Test()" << endl;
    }
};

int main()
{
    SmartPointer<Test> sp = new Test();
    SmartPointer<Test> nsp;

    nsp = sp;

    cout << sp.isNull() << endl;
    cout << nsp.isNull() << endl;
    cout << "Hello World!" << endl;
    return 0;
}
