#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "array.h"
#include "exception.h"

namespace DSLib
{

template < typename T>
class DynamicArray : public Array<T>
{
protected:
    int m_length;

    T* copy(T* array, int len, int newlen)  //O(n)
    {
        T* ret = new T[newlen];

        if(ret != nullptr)
        {
            int size = (len < newlen) ? len : newlen;

            for(int i = 0; i < size; i++)
            {
                ret[i] = array[i];
            }
        }

        return ret;
    }

    void update(T* array, int length) //O(1)
    {
        if(array != nullptr)
        {
            T* temp = this -> m_array;

            this -> m_array = array;
            this -> m_length = length;

            delete [] temp;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to create DynamicArray object ...");
        }
    }

    void init(T* array, int length)  //O(1)
    {
        if(array != nullptr)
        {
            this -> m_array = array;
            this -> m_length = length;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to create DynamicArray object ...");
        }
    }
public:
    DynamicArray(int length) //O(1)
    {
        init(new T[length], length);
//        this -> m_array = new T[length];

//        if(this -> m_array != nullptr)
//        {
//            this -> m_length = length;
//        }
//        else
//        {
//            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to create DynamicArray object ...");
//        }
    }

    DynamicArray(const DynamicArray<T>& obj) //O(n)
    {
//        T* array =  copy(obj.m_array, obj.m_length, obj.m_length);
        init(copy(obj.m_array, obj.m_length, obj.m_length), obj.m_length);
//        this -> m_array = new T[obj.m_length];

//        if(this -> m_array != nullptr)
//        {
//            this -> m_length = obj.m_length;

//            for(int i = 0; i < obj.m_length; i++)
//            {
//                this->m_array[i] = obj.m_array[i];
//            }
//        }
//        else
//        {
//            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to create DynamicArray object ...");
//        }
    }
    DynamicArray<T>& operator= (const DynamicArray<T>& obj) //O(n)
    {
        if(this != &obj)
        {
            //T* array = new T[obj.m_length];
            //T* array = copy(obj.m_array, obj.m_length, obj.m_length);
            update(copy(obj.m_array, obj.m_length, obj.m_length), obj.m_length);

//            if(array != nullptr)
//            {
//                for(int i = 0; i < obj.m_length; i++)
//                {
//                    array[i] = obj.m_array[i];
//                }

//                T* temp = this -> m_array;

//                this -> m_array = array;
//                this -> m_length = obj.m_length;

//                delete [] temp;
//            }
//            else
//            {
//                THROW_EXCEPTION(NoEnoughMemoryException,"No memory to create DynamicArray object ...");
//            }
        }
        return *this;
    }

    int length() const //O(1)
    {
        return m_length;
    }
    void resize(int length) //O(n)
    {
        if(length != m_length)
        {
//            T* array = copy(this->m_array, m_length, length);
            update(copy(this->m_array, m_length, length), length);
//            T* array = new T[length];
//            if(array != nullptr)
//            {
//                int size = (length < m_length) ? length : m_length;


//                for(int i = 0; i < size; i++)
//                {
//                    array[i] = this -> m_array[i];
//                }

//                T* temp = this -> m_array;

//                this -> m_length = length;
//                this -> m_array = array;

//                delete [] temp;
//            }
//            else
//            {
//                THROW_EXCEPTION(NoEnoughMemoryException,"No memory to create DynamicArray object ...");
//            }
        }
    }

    ~DynamicArray() //O(1)
    {
        delete [] this -> m_array;
    }

};

}

#endif // DYNAMICARRAY_H
