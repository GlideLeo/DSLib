#include "object.h"
#include <iostream>
#include <cstdlib>

using namespace std;

namespace DSLib
{
void* Object::operator new(unsigned int size) throw()
{
    cout << "Object::operator new : " << size << endl;
    return malloc(size);
}
void Object::operator delete(void* p)
{
    cout << "Object::operator delete : " << p << endl;
    free(p);
}
void* Object::operator new[](unsigned int size) throw()
{
    cout << "Object::operator new[] : " << size << endl;
    return malloc(size);
}
void Object::operator delete[](void* p)
{
    cout << "Object::operator delete[] : " << p << endl;
    free(p);
}
Object::~Object()
{

}
}
