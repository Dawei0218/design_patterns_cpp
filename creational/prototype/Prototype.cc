// C++ Design Patterns: Prototype Design pattern
// 
// Author: wangmaolin
class ISplitter
{
public:
virtual ISplitter* clone() = 0;
virtual void split() = 0;

virtual ~ISplitter() = default;
};

class TxtSplitter : public ISplitter
{
public:
  virtual void split() override {}

  virtual ISplitter* clone() override
  {
    return new TxtSplitter(*this);
  }
};