#pragma once
#include <cstddef>
#include <cstdlib>
#include <initializer_list>
#include <iostream>

class Vector {
private:
    std::size_t capacity_;
    std::size_t size_;
    int* array_;

    void resize_if_needed();

public:

    Vector();

    Vector(int size);

    Vector(const Vector &other);

    Vector(std::initializer_list<int> init_list);

    ~Vector();

    Vector& operator = (const Vector &other);

    int& operator [] (size_t index) const;

    int& operator [] (size_t index);

    size_t Size() const;

    size_t Capacity() const;
    
    void PushBack(int element);

    void PopBack();

    void Reserve(size_t size);

    void Swap(Vector &other);

    void Clear();

    int& At(size_t index);

    int& At(size_t index) const;

    friend std::ostream & operator<< (std::ostream & os, const Vector &vec);

};
