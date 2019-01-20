#include <iostream>
#include "smartpointer.h"
#include "exception.h"
#include "object.h"

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

class TestObj : public Object
{
public:
    int i;
    int j;
    ~TestObj();
};

TestObj::~TestObj() {}

class Child : public TestObj
{
public:
    int k;
    ~Child();
};

Child::~Child() {}

int main()
{
//    SmartPointer<Test> sp = new Test();
//    SmartPointer<Test> nsp;

//    nsp = sp;

//    cout << sp.isNull() << endl;
//    cout << nsp.isNull() << endl;
//    cout << "Hello World!" << endl;

    SmartPointer<int>* sp = new SmartPointer<int>();

    delete sp;

    InvalidOperationException* e = new InvalidOperationException();

    delete e;
    Object* obj1 = new TestObj();
    Object* obj2 = new Child();

    cout << "obj1= " << obj1 << endl;
    cout << "obj2= " << obj2 << endl;

    delete obj1;
    delete obj2;

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
