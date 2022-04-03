// C++ Design Patterns: Builder Design pattern
//
// Author: wangmaoli

class House
{
};

class IBuilder
{
public:
  IBuilder()
  {
    h = new House();
  }

  House* getHouse() { return h; }

  virtual void build1() = 0;
  virtual void build2() = 0;
  virtual void build3() = 0;
  virtual ~IBuilder() = default;

private:
  House *h;
};


class Director
{
private:
  IBuilder* builder;

public:
  Director(IBuilder* b) : builder(b) {};

  House *construct(){
		builder->build1();
    builder->build2();
    builder->build3();
		return builder->getHouse();
	}
};