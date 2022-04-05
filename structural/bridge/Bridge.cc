// C++ Design Patterns: Bridge Design pattern
// 
// Author: wangmaolin

class INet
{
public:
  virtual void connect() = 0;
  virtual void write() = 0;
  virtual void read() = 0;
  virtual void playSound() = 0;
  virtual ~INet() = default;
};

class MobileNet : public INet
{
public:
  virtual void connect() override {}
  virtual void write() override {}
  virtual void read() override {}
  virtual void playSound() override {}
};

class PcNet : public INet
{
public:
  virtual void connect() override {}
  virtual void write() override {}
  virtual void read() override {};
  virtual void playSound() override {};
};

// 如果不把抽象和实现分离
// MobileLite、PcLite、MobilePerfact、PcPerface 就会有m*n个类
// 应该写成Lite、Perfact类，以组合的方式实现，传递对应的抽象
class Messager
{
public: 
  virtual void login() = 0;
  virtual void sendPicture() = 0;
  virtual void sendMessage() = 0;
};

class MessageLite : public Messager
{
public:
  virtual void login()
  {
    net->connect();
  }
  // 与上面类似
  virtual void sendPicture() = 0;
  virtual void sendMessage() = 0;

private:
  INet *net;
};


class MessagePerfact : public Messager
{
public:
  virtual void login()
  {
    // 会播放声音
    net->playSound();
    net->connect();
  }
  // 与上面类似
  virtual void sendPicture() = 0;
  virtual void sendMessage() = 0;

private:
  INet *net;
};