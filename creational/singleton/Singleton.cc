// C++ Design Patterns: Thread-safe Singleton
// 
// Author: wangmaolin
#include <pthread.h>
#include <stdlib.h>

class Singleton 
{
 public:
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

  static Singleton& instance()
  {
    pthread_once(&ponce_, &Singleton::init);
    return *instance_;
  }

private:
  Singleton() = default;

  static void destory() { delete instance_; }

  static void init()
  {
    instance_ = new Singleton();
    ::atexit(destory);
  }
  
  static pthread_once_t ponce_;
  static Singleton *instance_;
};

pthread_once_t Singleton::ponce_ = PTHREAD_ONCE_INIT;
Singleton* Singleton::instance_ = nullptr;