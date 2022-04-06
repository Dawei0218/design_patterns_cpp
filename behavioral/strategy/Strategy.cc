// C++ Design Patterns: Strategy Design pattern
//
// Author: wangmaolin

// 根据上下文提供 + - 操作类

class IStrategy
{
public:
  virtual int doOperation(int num1, int num2) = 0;

  virtual ~IStrategy() = default;
};

// 加法
class Addition : public IStrategy
{
public:
  virtual int doOperation(int num1, int num2) override
  { 
    return (num1 + num2);
  }
};

// 减法
class Subtraction : public IStrategy
{
public:
  virtual int doOperation(int num1, int num2) override
  { 
    return (num1 - num2);
  }
};

// context
class Context
{
private:
  IStrategy *strategy;
public:
  Context(IStrategy *s) : strategy(s) {}

  void execute(int num1, int num2)
  {
    strategy->doOperation(num1, num2);
  }
};
