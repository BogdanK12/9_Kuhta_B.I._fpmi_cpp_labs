#include "vector_impl.h"
#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <ostream>
#include <stdexcept>

  Vector::Vector(): capacity_(0), size_(0), array_(nullptr){};

  Vector::Vector(int size)
  : capacity_(2 * size), size_(size), array_(new int[capacity_])
  {
    for(int i = 0; i < size; ++i)
    {
      this->array_[i] = 0;
    }
  };

  Vector::~Vector()
  {
    delete [] this->array_;
  }

  Vector::Vector(const Vector &other)
  : capacity_(other.capacity_), size_(other.size_), array_(new int[capacity_])
  {
    std::copy(other.array_, other.array_ + this->size_, this->array_); 
  }

  Vector::Vector(std::initializer_list<int> init_list)
  : capacity_(init_list.size()), size_(capacity_), array_(new int[this->capacity_])
  {
    int i = 0;
    for(const int& num : init_list)
    {
      this->array_[i] = num;
      ++i;
    }
  }

  Vector& Vector::operator = (const Vector &other)
  {
    if(this == &other)
    {
      return *this;
    }
    this->capacity_ = other.capacity_;
    this->size_ = other.size_;
    delete [] this->array_;
    this->array_ = new int[capacity_];
    std::copy(other.array_, other.array_ + this->size_, this->array_);
    return *this;
  }

  int& Vector::operator [] (size_t index) const
  {
    return this->array_[index];
  }

  void Vector::resize_if_needed()
  {
    if(this->array_ == nullptr){
      this->capacity_ = 2;
      this->array_ = new int[this->capacity_];
    } else if(this->size_ == capacity_)
    {
      int* temp_array = new int[this->capacity_ * 2];
      std::copy(this->array_, this->array_ + this->size_, temp_array);
      this->capacity_ *= 2;
      delete [] this->array_;
      this->array_ = temp_array;
      temp_array = nullptr;    
    }
  }
  
  void Vector::PushBack(int element)
  {
    this->resize_if_needed();
    this->array_[size_] = element;
    ++this->size_;
  }

  void Vector::PopBack()
  {
    if(this->size_ == 0)
    {
      return;
    } else
    {
      --this->size_;
      this->array_[this->size_] = 0;
    }
  }

  size_t Vector::Capacity() const {
      return this->capacity_;
  }

  size_t Vector::Size() const
  {
    return this->size_;
  }

  void Vector::Reserve(size_t size)
  {
    if (this->array_ == nullptr)
    {
      this->array_ = new int[size];
      this->capacity_ = size;
    }
  }

  void Vector::Clear()
  {
    delete [] this->array_;
    this->array_ = new int[this->capacity_];
    this->size_ = 0;
  }

  void Vector::Swap(Vector &other)
  {
    if(this == &other){
      return;
    } else
    {
      size_t temp_capacity = other.capacity_;
      size_t temp_size = other.size_;
      int* temp_array = other.array_;
      other.capacity_ = this->capacity_;
      other.size_ = this->size_;
      other.array_ = this->array_;
      this->capacity_ = temp_capacity;
      this->size_ = temp_size;
      this->array_ = temp_array;
      temp_array = nullptr;
    }
  }

  int& Vector::At (size_t index)
  {
    if(index < this->size_)
    {
      return this->array_[index];
    } else
    {
      throw std::out_of_range("This argument is unavaible: Vector has only " + std::to_string(this->size_));
    }
  }

  std::ostream& operator<< (std::ostream& os, const Vector &vec)
  {
    os << "[";
    for(size_t i = 0; i < vec.size_; ++i)
    {
      os << vec.array_[i];
      if (i < vec.size_ - 1) {
        os << ", ";
      }
    }
    os << "]";
    return os;
  }
