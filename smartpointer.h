#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include "object.h"

namespace  DSLib
{
template <typename T>
class SmartPointer : public Object //Smart pointer class
{
protected:
    T* m_pointer;
public:
    SmartPointer(T* p = nullptr)    //Constructor
    {
        m_pointer = p;
    }

    SmartPointer(const SmartPointer<T>& obj)    //Copy constructor
    {
        m_pointer = obj.m_pointer;
        const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
    }

    SmartPointer<T>& operator= (const SmartPointer<T>& obj) //Overloaded assignment operator
    {
          if(this != &obj)
          {
              delete m_pointer;
              m_pointer = obj.m_pointer;
              const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
          }
          return *this;
    }

    T* operator-> ()    //Overloaded ->
    {
        return m_pointer;
    }

    T& operator* ()     //Overloaded *
    {
        return *m_pointer;
    }

    bool isNull()       //Judge empty
    {
        return (m_pointer == nullptr);
    }

    T* get()        //Get pointer
    {
        return m_pointer;
    }

    ~SmartPointer()     //Destructor
    {
        delete m_pointer;
    }

};

}
#endif // SMARTPOINTER_H
