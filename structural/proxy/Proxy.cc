// C++ Design Patterns: Proxy Design pattern
// 
// Author: wangmaolin

class ISubject
{
public:
  virtual void process() = 0;
};

class RealSubject : public ISubject
{
public:
  virtual void process() {}
};

class SubjectProxy : public RealSubject
{
public:
  virtual void process() 
  {
    // 做一些其他处理
    RealSubject::process();
  }
};