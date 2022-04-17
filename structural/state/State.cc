#include <iostream>

using std::cout;
using std::endl;

// 状态操作接口
class State
{
public:
  virtual void operate1() = 0;
  virtual void operate2() = 0;

  virtual ~State() = default;
};

class State1 : public State
{
public:
  virtual void operate1() { cout << "State1 operate1" << endl; }
  virtual void operate2() { cout << "State1 operate2" << endl; };
};

class State2 : public State
{
public:
  // 可能会进行设置StateMachine状态类等等
  virtual void operate1() { cout << "State2 operate1" << endl; }
  virtual void operate2() { cout << "State2 operate2" << endl; };
};

class StateMachine : public State
{
private:
  State *state_;

public:
  virtual void operate1()
  {
    state_->operate1();
  }
  virtual void operate2()
  {
    state_->operate2();
  }
};
