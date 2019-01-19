#include <iostream>
#include "smartpointer.h"
#include "exception.h"

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
//    SmartPointer<Test> sp = new Test();
//    SmartPointer<Test> nsp;

//    nsp = sp;

//    cout << sp.isNull() << endl;
//    cout << nsp.isNull() << endl;
//    cout << "Hello World!" << endl;

    try
    {
        THROW_EXCEPTION(InvalidOperationException, "Test");
        //throw ArithmeticException("Test", __FILE__, __LINE__);
    }
    catch(const Exception& e)
    {
        cout << "catch(const Exception& e)" << endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    }
    return 0;
}
