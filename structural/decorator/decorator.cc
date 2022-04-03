// C++ Design Patterns: Decorator Design pattern
// 
// Author: wangmaolin

class IStream
{
public:
virtual void read() = 0;
virtual ~IStream() = default;
};

class FileInputStream : public IStream
{
public:
  virtual void read() override
  {
    // read some data from file
  }
};

// 通过组合方式增强功能，避免了类继承过于复杂
// 比如还可以增加加密数据的类
class BufferStream : public IStream
{
private:
  IStream* stream_;
public:
  BufferStream(IStream* stream) : stream_(stream) {}

  virtual void read() override
  {
    // buffer
    // read some data from file
  }
};