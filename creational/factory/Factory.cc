// C++ Design Patterns: Factory Method
// 
// Author: wangmaolin
#include <iostream>

using std::cout;
using std::endl;

// 设计了一个parser，可以包含json、xml、yaml

// parse基类
class IParser
{
public:
  virtual void parse() = 0;
  virtual ~IParser() = default;
};

class JosnParser : public IParser
{
  virtual void parse() override
  {
    cout << "This is JsonParser" << endl;
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

