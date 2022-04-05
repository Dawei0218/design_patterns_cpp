// C++ Design Patterns: Decorator Design pattern
//
// Author: wangmaolin

// 基类
class IStream
{
public:
  virtual void read() = 0;

  virtual ~IStream() = default;
};

// FileStream
class FileStream : public IStream
{
public:
  virtual void read() override
  {
  }
};

// MemoryStream
class MemoryStream : public IStream
{
public:
  virtual void read() override
  {
  }
};

// Decorator
class Decorator : public IStream
{
protected:
  IStream *stream;

  Decorator(IStream *stm) : stream(stm) {}
};

// BufferStream
class BufferStream : public Decorator
{
public:
  BufferStream(IStream *stream) : Decorator(stream) {}

  virtual void read() override
  {
    // buffer
    stream->read();
  }
};