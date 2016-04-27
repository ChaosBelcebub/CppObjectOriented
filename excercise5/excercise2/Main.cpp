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
  
  // 1. Typ Base an ein anderes Objekt vom Typ Derived
  // --> Sollte nicht möglich sein, da wir keinen Zuweisungsoperator
  // --> überladen haben und der Standard Opeator die konvertierung
  // --> nicht kennt.
  // 
  // Fehlermeldung:
  //
  // Main.cpp: In function ‘int main()’:
  // Main.cpp:21:5: error: no match for ‘operator=’ (operand types are ‘Derived’
  // and ‘Base’)
  // d = b;
  //   ^
  // Main.cpp:21:5: note: candidates are:
  // Main.cpp:9:8: note: Derived& Derived::operator=(const Derived&)
  // struct Derived: public Base
  //            ^
  // Main.cpp:9:8: note:   no known conversion for argument 1
  // from ‘Base’ to ‘const Derived&’
  // Main.cpp:9:8: note: Derived& Derived::operator=(Derived&&)
  // Main.cpp:9:8: note:   no known conversion for argument 1
  // from ‘Base’ to ‘Derived&&’
  //
  // d = b;
  
  // 2. Typ Derived an ein anderes Objekt vom Typ Base
  // --> Sollte möglich sein, da hier der Standard Operator greift.
  // --> Die Klasse Derived erbt von Base und somit steht diese
  // --> Info zur Verfügung.
  //
  b = d;
  
  Derived* dP = new Derived();
  Base* bP = new Base();
  // 3. Base * an Derived *
  // --> Auch hier sollte keine Zuweisung möglich sein da eine
  // --> Umwandlung nicht möglich ist.
  //
  // Main.cpp: In function ‘int main()’:
  // Main.cpp:54:6: error: invalid conversion from ‘Base*’ to ‘Derived*’
  // [-fpermissive]
  // dP = bP;
  //    ^
  //
  // dP = bP;
 
  // 4. Derived * an Base *
  // --> Zuweisung ist möglich, da Derived von Base erbt und somit die
  // --> nötigen Infos verfügbar sind.
  bP = dP;
}
