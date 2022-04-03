// C++ Design Patterns: Adapter Design pattern
//
// Author: wangmaoli

// 新接口
class ITarget
{
public:
  virtual ~ITarget() = default;
  virtual void process() = 0;
};

// 老接口
class IAdaptee
{
public:
  virtual ~IAdaptee() = default;
  virtual void foo(int data) = 0;
  virtual int bar() = 0;
};

// 遗留类型
class OldClass : public IAdaptee
{
};

//对象适配器
class Adapter : public ITarget
{
protected:
  IAdaptee *pAdaptee; //组合

public:
  Adapter(IAdaptee *pAdaptee)
  {
    this->pAdaptee = pAdaptee;
  }

  virtual void process()
  {
    int data = pAdaptee->bar();
    pAdaptee->foo(data);
  }
};
