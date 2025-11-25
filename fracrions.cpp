#include <cfenv>
#include <iostream>
// just fraction

int maximal_common_divisor(int a, int b)
{
  while(a > 0 && b > 0)
  {
    a = a % b;
    if(!a) return b;
    b = b % a;
    if(!b) return a;
  }
  return 1;
}

struct Fraction {
  int num_;
  int denom_;

  Fraction& minimize()
  {
    int mcd = maximal_common_divisor(this->num_, this->denom_);
    if(mcd != 1)
    {
      this->num_ /= mcd;
      this->denom_ /= mcd;
    }
    return *this;
  }

  Fraction operator+(Fraction &q)
  {
    int future_denom_ = (this->denom_ * q.denom_) / maximal_common_divisor( this->denom_, q.denom_);
    this->num_ = (this->num_ * (future_denom_ / this->denom_)) + (q.num_ * (future_denom_ / q.denom_));
    this->denom_ = future_denom_;
    this->minimize();
    return *this;
  }
 

  Fraction operator - (Fraction &q)
  {
    int future_denom_ = (this->denom_ * q.denom_) / maximal_common_divisor( this->denom_, q.denom_);
    this->num_ = (this->num_ * (future_denom_ / this->denom_)) - (q.num_ * (future_denom_ / q.denom_));
    this->denom_ = future_denom_;
    this->minimize();
    return *this;
  }

  Fraction& operator -= (Fraction &q)
  {
    *this = *this - q;
    return *this;
  }

  Fraction& operator *(const Fraction &q)
  {
    this->num_ *= q.num_;
    this->denom_ *= q.denom_;
    int mnm = maximal_common_divisor(this->denom_, this->denom_);
    if(mnm != 1)
    {
      this->num_ /= mnm;
      this->denom_ /= mnm;
    } 
    return *this;
  }

  Fraction& operator *=(const Fraction &q)
  {
    *this = *this * q;
    return *this;
  }

  Fraction& operator /(const Fraction &q)
  {
    this->num_ *= q.denom_;
    this->denom_ *= q.num_;
    int mnm = maximal_common_divisor(this->denom_, this->denom_);
    if(mnm != 1)
    {
      this->num_ /= mnm;
      this->denom_ /= mnm;
    } 
    return *this;
  }

  Fraction operator ++ (int)
  {
    Fraction temp = *this;
    this->num_ += this->denom_;
    return temp;
  }

  Fraction operator -- (int)
  {
    Fraction temp = *this;
    this->num_ += this->denom_;
    return temp;
  }

  Fraction operator ++()
  {
    this->num_ += this->denom_;
    return *this;
  }

  Fraction operator --()
  {
    this->num_ -= this->denom_;
    return *this;
  }

  Fraction& operator += (Fraction &q)
  {
    *this = *this + q;
    return *this;
  }
  
  Fraction& operator = (const Fraction &a)
  {
    if(this == &a)
    {
      return *this;
    }
    this->num_ = a.num_;
    this->denom_ = a.denom_;
    return *this;
  }
    
  Fraction(const Fraction &other): num_(other.num_), denom_(other.denom_) {}  
  
  bool operator > (const Fraction &frac) const
  {
    return static_cast<double>(this->num_)/this->denom_ > static_cast<double>(frac.num_)/frac.denom_;
  }

  bool operator >= (const Fraction &frac) const 
  {
    return static_cast<double>(this->num_)/this->denom_ >= static_cast<double>(frac.num_)/frac.denom_;
  }

  bool operator < (const Fraction &frac) const
  {
    return static_cast<double>(this->num_)/this->denom_ < static_cast<double>(frac.num_)/frac.denom_;
  }

  bool operator <= (const Fraction &frac) const 
  {
    return static_cast<double>(this->num_)/this->denom_ <= static_cast<double>(frac.num_)/frac.denom_;
  }

  bool operator ==(const Fraction &frac) const 
  {
    return static_cast<double>(this->num_)/this->denom_ == static_cast<double>(frac.num_)/frac.denom_;
  }

  bool operator !=(const Fraction &frac) const
  {
    return static_cast<double>(this->num_)/this->denom_ != static_cast<double>(frac.num_)/frac.denom_;
  }
    
  Fraction(int num = 0, unsigned denom = 1) : num_(num), denom_(denom){};

  friend std::ostream& operator<< (std::ostream& os, Fraction q)
  {
    os << q.num_ << "/" << q.denom_;
    return os;
  }

  friend std::istream& operator>> (std::istream& is, Fraction q) 
  {
    is >> q.num_ >> q.denom_;
    return is;
  }

  operator int() const
  {
    return num_ / denom_;  
  }
  
  ~Fraction(){};
  
};

bool cmp_ascending(const Fraction &q1, const Fraction &q2)
{
  return q1 > q2;
}

bool cmp_falling(const Fraction &q1, const Fraction &q2)
{
  return q1 < q2;
}

void sort_fractions_bubble(Fraction* arr, int arr_size, bool (*cmp)(const Fraction &q1, const Fraction &q2))
{  
  for(int j = 0; j < arr_size - 1; ++j)
  {
    for(int i = 1; i < arr_size - j; ++i)
      {
      if(cmp(arr[i - 1], arr[i]))
      {
        Fraction temp = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = temp;
      }
  }
  }
}

int main()
{
  std::cout << "Print down your fraction:";
  Fraction frac1, frac2;
  std::cin >> frac1 >> frac2;
  Fraction dd(0, 1);
  if(frac1 < frac2 || frac1++ < frac2) std::cout << frac2;
  Fraction* arr = new Fraction[5];
  arr[0] = Fraction(1, 3);
  arr[1] = Fraction(1, 5);
  arr[2] = Fraction(1, 6);
  arr[3] = Fraction(1, 7);
  arr[4] = Fraction(1, 10);
  sort_fractions_bubble(arr, 5, cmp_ascending);
  for(int i = 0; i < 5; ++i)
  {
    std::cout << arr[i] << " "; 
  }
  sort_fractions_bubble(arr, 5, cmp_falling);
  for(int i = 0; i < 5; ++i)
  {
    std::cout << arr[i] << " "; 
  }
}
