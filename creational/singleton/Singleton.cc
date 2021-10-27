// C++ Design Patterns: Singleton
// 
// Author: wangmaolin

#include <iostream>

class Singleton
{
public:
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

  static Singleton* get()
  {
    if (!instance_)
    {
      instance_ = new Singleton();
    }
    return instance_;
  }

  static void reset()
  {
    if (instance_) 
    {
      delete instance_;
    }
  }

  void print()
  {
    std::cout << "singleton demo" << std::endl;
  }

private:
  Singleton() = default;
  static Singleton *instance_;
};

Singleton* Singleton::instance_ = nullptr;

int main()
{
  Singleton::get()->print();
  Singleton::reset();

  return 0;
}