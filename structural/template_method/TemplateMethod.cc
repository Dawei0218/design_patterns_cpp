// C++ Design Patterns: Template Method Design pattern
//
// Author: wangmaolin

#include <iostream>

using std::cout;
using std::endl;

class TemplateMethod
{
public:
  void step1() {}
  void step2() {}
  void step3() {}

  virtual void step4() = 0;
  virtual void step5() = 0;

  void run()
  {
    step1();
    step2();
    step3();
    step4();
    step5();
  }

  virtual ~TemplateMethod() = default;
};

class Application : public TemplateMethod
{
  virtual void step4() override
  {
    cout << "step4" << endl;
  }

  virtual void step5() override
  {
    cout << "step5" << endl;
  }
};
