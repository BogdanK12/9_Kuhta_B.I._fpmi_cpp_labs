#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <iterator>
#include "forward_list_impl.h"

// your code goes here

ForwardList::ForwardList()
: first_(nullptr), size_(0){}

ForwardList::ForwardListIterator ForwardList::begin()
{
    ForwardListIterator retval(this->first_);
    return retval;
}

ForwardList::ForwardListIterator ForwardList::end()
{
    Node* temp = this->first_;
    while(temp->next_ != nullptr)
    {
        temp = temp->next_;
    }
    ForwardListIterator retval(temp);
    return retval;
}

// ForwardList::ForwardListIterator ForwardList::begin() const
// {
//     ForwardListIterator retval(this->first_);
//     return retval;
// }

// ForwardList::ForwardListIterator ForwardList::end() const
// {
//     Node* temp = this->first_;
//     while(temp->next_ != nullptr)
//     {
//         temp = temp->next_;
//     }
//     ForwardListIterator retval(temp);
//     return retval;
// }

ForwardList::ForwardListIterator& ForwardList::ForwardListIterator::operator ++()
{
    if(position_ != nullptr)
    {
        position_ = position_->next_;
    }
    return *this;
}

ForwardList::ForwardListIterator ForwardList::ForwardListIterator::operator ++(int)
{
    ForwardListIterator retval = *this;
    ++(*this);
    return retval;
}

bool ForwardList::ForwardListIterator::operator==(const ForwardListIterator& other) const
{
    return this->position_ == other.position_;
}

bool ForwardList::ForwardListIterator::operator!=(const ForwardListIterator& other) const
{
    return !(*this == other);
}

int32_t& ForwardList::ForwardListIterator::operator*() const
{
    return position_->value_;
}

int* ForwardList::ForwardListIterator::operator ->()
{
    return &position_->value_;
}

void ForwardList::push_back(int32_t value)
{
   if(this->first_ == nullptr)
   {
       this->first_ = new Node(value);
       this->size_++;
   }
   else
   {
       Node* temp = this->first_;
       while(temp->next_ != nullptr)
       {
           temp = temp->next_;
       }
       Node* new_node = new Node(value);
       temp->next_ = new_node;
       this->size_++;
   }
}

ForwardList::ForwardList(const ForwardList& rhs)
: first_(nullptr), size_(0)
{
    ForwardListIterator iter = rhs.begin();
    while(iter != rhs.end())
    {
        push_back(*iter);
        ++iter;
    }
}

ForwardList::ForwardList(size_t count, int32_t value)
: first_(nullptr), size_(0)
{
    for(size_t size = 0; size < count; ++size)
    {
        push_back(value);
    }
}

ForwardList::ForwardList(std::initializer_list<int32_t> init)
: first_(nullptr), size_(0);
{
    for(int32_t value : init)
    {
        push_back(value);
    }
}

ForwardList& ForwardList::operator= (const ForwardList rhs)
{
    ForwardList temp(rhs);
    std::swap(this->first_, temp.first_);
    std::swap(this->size_, temp.size_);
    return *this;
}

ForwardList::~ForwardList()
{
    Node* temp = this->first_;
    if (temp == nullptr) {return;}
    Node* temp2 = this->first_->next_;
    while(temp2 != nullptr)
    {
        delete temp;
        temp = temp2;
        temp2 = temp2->next_;
    }
}

void ForwardList::PushFront(int32_t value)
{
    Node* temp = this->first_->next_;
    Node* new_node = new Node(value);
    this->first_ = new_node;
    new_node->next_ = temp;
}

void ForwardList::pop_next(Node* point)
{
    if(point == nullptr || point->next_ == nullptr){ return;}
    Node* temp = point->next_->next_;
    delete point->next_;
    point->next_ = temp;
}

void ForwardList::PopFront()
{
    if(this->first_ == nullptr){ return;}
    Node* temp = this->first_->next_;
    delete this->first_;
    this->first_ = temp;
    --this->size_;
}

void ForwardList::Remove(int32_t value)
{
    Node* temp = this->first_;
    ForwardListIterator iter = this->begin();
    ForwardListIterator iter_end = this->end();
    size_t first_row = 0;
    while(iter != iter_end && *iter == value)
    {
        ++first_row;
        ++iter;
    }
    for(size_t i = 0; i < first_row; ++i)
    {
        this->PopFront();
    }
    temp = this->first_;
    while(temp != nullptr && temp->next_ != nullptr)
    {
        if(temp->next_->value_ == value)
        {
            this->pop_next(temp);
        } else
        {
            temp = temp->next_;
        }
    }
}

bool ForwardList::FindByValue(int32_t value)
{
    ForwardList::ForwardListIterator iter = this->begin();
    ForwardList::ForwardListIterator iter_end = this->end();
    while(iter != iter_end)
    {
        if(*iter == value)
        {
            return true;
        }
        ++iter;
    }
    return false;
}

void ForwardList::Print(std::ostream& out)
{
    ForwardList::ForwardListIterator iter = this->begin();
    ForwardList::ForwardListIterator iter_end = this->end();
    while(iter != iter_end)
    {
        out << *iter << " ";
        ++iter;
    }
}

void ForwardList::Clear()
{
    while(this->first_ != nullptr)
    {
           this->PopFront();
    }
}

int32_t ForwardList::Front() const
{
    if(this->first_ != nullptr)
    {
        return this->first_->value_;
    }
}

size_t ForwardList::Size() const
{
    return this->size_;
}
