#pragma once

#include <cstddef>
#include <cstdint>
#include <iterator>
#include <iostream>

class ForwardList {

private:
    struct Node {
        int32_t value_;
        Node* next_;

        explicit Node(int value) : value_(value), next_(nullptr) {
        }
    };
    Node* first_;
    size_t size_;

public:
    class ForwardListIterator {
    private:
        Node* position_;
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int32_t;
        using pointer = value_type*;
        using reference = value_type&;

        explicit ForwardListIterator(Node* position) : position_(position) {}

        ForwardListIterator& operator++();

        ForwardListIterator operator++(int);

        bool operator==(const ForwardListIterator& other) const;

        bool operator!=(const ForwardListIterator& other) const;

        reference operator*() const;

        pointer operator->();

    };
    
    // methods for "ranged-based for loop"
    // 1) non-const version
    ForwardListIterator begin();
        // your code goes here
    ForwardListIterator end();
        // your code goes here

    // 2) const version
    // TODO: think about return type
    // (is it exactly ForwardListIterator?)
    ForwardListIterator begin() const;
    ForwardListIterator end() const;
    // default constructor
    ForwardList();

    // copy constructor
    ForwardList(const ForwardList& rhs);

    // Constructs a ForwardList with `count` copies of elements with value `value`.
    ForwardList(size_t count, int32_t value);

    // Constructs a ForwardList with std::initializer_list<int32_t>
    ForwardList(std::initializer_list<int32_t> init);

    // operator= overloading
    ForwardList& operator=(const ForwardList& rhs);

    // destructor
    ~ForwardList();

    // insert new element on the top of the list
    void PushFront(int32_t value);

    void push_back(int32_t value);

    void pop_next(Node* point);

    // delete first element of the list
    void PopFront();

    // remove every occurence of an element in the list
    // whose value equals to param `value`,
    // the remaining elements must remain in the same order
    void Remove(int32_t value);

    // erases all the elements
    void Clear();

    // find list's element by the `value`
    // returns true, if element exists
    // otherwise, returns false
    bool FindByValue(int32_t value);

    // print list's elements to stream separated by space
    void Print(std::ostream& out);

    // get first element of the list
    int32_t Front() const;

    // get size of the list
    size_t Size() const;

};
