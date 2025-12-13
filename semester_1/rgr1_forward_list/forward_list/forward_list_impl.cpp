#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <regex>
#include "forward_list_impl.h"

// your code goes here

ForwardList()
: first_(nullptr), size_(0);

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
    Node* temp = this->first_;
    while(temp->next_ != nullptr)
    {
        temp = temp->next_;
    }
    Node new_node(value);
    temp->next_ = &new_node;
}

void ForwardList::push_back2(int32_t value)
{
    ForwardListIterator iter = this->end();
    Node new_node(value);
    (*iter.position_) = &new_node;
}

ForwardList(const ForwardList& rhs)
{
    ForwardListIterator iter = rhs.begin();

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
