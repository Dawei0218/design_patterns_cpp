// C++ Design Patterns: Abstract Factory Method
// 
// Author: wangmaolin
#include <iostream>

using std::cout;
using std::endl;

// parse基类
class IParser
{
public:
  virtual void textParse() = 0;
  virtual void FileParse() = 0;
  virtual ~IParser() = default;
};

class JosnParser : public IParser
{
  virtual void textParse() override
  {
    cout << "This is Json Text Parser" << endl;
  }

  virtual void FileParse() override
  {
    cout << "This is Json FIle Parser" << endl;
  }
};

// 工厂基类
class IParseFactory
{
public:
  virtual IParser* createParser() = 0;
  virtual ~IParseFactory() = default;
};

class JosnParserFactory : public IParseFactory
{
  virtual IParser* createParser() override
  {
    return new JosnParser();
  }
};
