#include <cstdint>
#include <iostream>
#include <iterator>
#include "forward_list_impl.h"

// your code goes here

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

  int32_t& ForwardList::ForwardListIterator::operator&()
  {
      return &position->value_;
  }
