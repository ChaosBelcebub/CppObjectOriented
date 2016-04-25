// Michael Kotzjan
// HFU, 25.04.2016

struct Base
{
  int a;
};

struct Derived: public Base
{
  int b;
};

int main()
{
  Derived d;
  Base b;
  b = d;
}
