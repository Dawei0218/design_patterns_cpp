// C++ Design Patterns: Command Design pattern
//
// Author: wangmaolin

#include <iostream>

using std::cout;
using std::endl;

// Command接口
class ICommand
{
public:
  virtual void execute() = 0;

  virtual ~ICommand() = default;
};

// 具体命令
class ConcreteCommand : public ICommand
{
public:
  virtual void execute() override
  {
    // 会调用receiver
    cout << "ConcreteCommand" << endl;
  }
};

class Invoker
{
private:
  ICommand *command;
public:
  Invoker(ICommand *cmd) : command(cmd) {} 

  virtual void execute()
  {
    command->execute();
  }
};


int main(int argc, char const *argv[])
{
  ICommand *command = new ConcreteCommand();

  Invoker invoke(command);
  invoke.execute();
}
