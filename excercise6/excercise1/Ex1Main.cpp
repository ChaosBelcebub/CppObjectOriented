// Michael Kotzjan
// HFU, 06.05.2016

#include <iostream>
#include <string>
#include <sstream>
#include "./Ex1Bruch.cpp"
#include "./Ex1EmptyObjException.cpp"

using namespace std;

template<typename T> class Vielleicht
{
  T m_wert;
  bool m_leer;

  public:
  Vielleicht(T wert) : m_wert(wert), m_leer(false)
  {
  }

  Vielleicht() : m_leer(true)
  {
  }

  bool leer() const
  {
    return m_leer;
  }

  const T& derWert() const
  {
    if (m_leer)
    {
      throw EmptyObjException();
    } else {
      return m_wert;
    }
  }

  string text() const
  {
    if (m_leer)
    {
      return "leer";
    } else {
      stringstream ss;
      ss << m_wert;
      return ss.str();
    }
  }

  // + operator
  Vielleicht<T> operator+(const Vielleicht<T>& v);

  // / operator
  Vielleicht<T> operator/(const Vielleicht<T>& v);
};

template<typename T> Vielleicht<T> Vielleicht<T>::operator+(const Vielleicht<T>& v)
{
  if (leer() || v.leer())
  {
    Vielleicht<T> tmp;
    return tmp;
  } else {
    Vielleicht<T> tmp(derWert() + v.derWert());
    return tmp;
  }
}

template<typename T> Vielleicht<T> Vielleicht<T>::operator/(const Vielleicht<T>& v)
{
  if (leer() || v.leer())
  {
    Vielleicht<T> tmp;
    return tmp;
  } else {
    Vielleicht<T> tmp(derWert() / v.derWert());
    return tmp;
  }
}

template<> Vielleicht<string> Vielleicht<string>::operator/(const Vielleicht<string>& v)
{
  if (leer() || v.leer()) return Vielleicht<string>();
  stringstream ss;
  for (unsigned int i = 0; i < m_wert.length(); ++i)
  {
    if (v.derWert().find(m_wert[i]) != string::npos)
    {
      ss << m_wert[i];
    }
  }
  return Vielleicht<string>(ss.str());
}

int main()
{
  cout << endl << "### Integer ###" << endl;
  {
    Vielleicht<int> v1;
    Vielleicht<int> v2(42);
    Vielleicht<int> v3(-5);

    cout << endl << "Wert von v1:" << endl;
    try
    {
      cout << v1.derWert() << endl;
    } catch (EmptyObjException e)
    {
      cout << e.msg << endl;
    }

    cout << "Wert von v2:" << endl;
    try
    {
      cout << v2.derWert() << endl;
    } catch (EmptyObjException e)
    {
      cout << e.msg << endl;
    }

    cout << "Wert von v3:" << endl;
    try
    {
      cout << v3.derWert() << endl;
    } catch (EmptyObjException e)
    {
      cout << e.msg << endl;
    }

    cout << endl << "Ist v1 leer: " << v1.leer() << endl;
    cout << "Ist v2 leer: " << v2.leer() << endl;
    cout << "Ist v3 leer: " << v3.leer() << endl;

    cout << endl << "v1 als String: " + v1.text() << endl;
    cout << "v2 als String: " + v2.text() << endl;
    cout << "v3 als String: " + v3.text() << endl;

    cout << endl << "v1 + v2: " + (v1 + v2).text() << endl;
    cout << "v2 + v3: " + (v2 + v3).text() << endl;

    cout << endl << "v1 / v2: " + (v1 / v2).text() << endl;
    cout << "v2 / v3: " + (v2 / v3).text() << endl;
  }

  cout << endl << "### Double ###" << endl;
  {
    Vielleicht<double> v1;
    Vielleicht<double> v2(4.2);
    Vielleicht<double> v3(-5.3);

    cout << endl << "Wert von v1:" << endl;
    try
    {
      cout << v1.derWert() << endl;
    } catch (EmptyObjException e)
    {
      cout << e.msg << endl;
    }

    cout << "Wert von v2:" << endl;
    try
    {
      cout << v2.derWert() << endl;
    } catch (EmptyObjException e)
    {
      cout << e.msg << endl;
    }

    cout << "Wert von v3:" << endl;
    try
    {
      cout << v3.derWert() << endl;
    } catch (EmptyObjException e)
    {
      cout << e.msg << endl;
    }

    cout << endl << "Ist v1 leer: " << v1.leer() << endl;
    cout << "Ist v2 leer: " << v2.leer() << endl;
    cout << "Ist v3 leer: " << v3.leer() << endl;

    cout << endl << "v1 als String: " + v1.text() << endl;
    cout << "v2 als String: " + v2.text() << endl;
    cout << "v3 als String: " + v3.text() << endl;

    cout << endl << "v1 + v2: " + (v1 + v2).text() << endl;
    cout << "v2 + v3: " + (v2 + v3).text() << endl;

    cout << endl << "v1 / v2: " + (v1 / v2).text() << endl;
    cout << "v2 / v3: " + (v2 / v3).text() << endl;
  }

  cout << endl << "### String ###" << endl;
  {
    Vielleicht<string> v1;
    Vielleicht<string> v2("Spam spam spam egg");
    Vielleicht<string> v3("egg");

    cout << endl << "Wert von v1:" << endl;
    try
    {
      cout << v1.derWert() << endl;
    } catch (EmptyObjException e)
    {
      cout << e.msg << endl;
    }

    cout << "Wert von v2:" << endl;
    try
    {
      cout << v2.derWert() << endl;
    } catch (EmptyObjException e)
    {
      cout << e.msg << endl;
    }

    cout << "Wert von v3:" << endl;
    try
    {
      cout << v3.derWert() << endl;
    } catch (EmptyObjException e)
    {
      cout << e.msg << endl;
    }

    cout << endl << "Ist v1 leer: " << v1.leer() << endl;
    cout << "Ist v2 leer: " << v2.leer() << endl;
    cout << "Ist v3 leer: " << v3.leer() << endl;

    cout << endl << "v1 als String: " + v1.text() << endl;
    cout << "v2 als String: " + v2.text() << endl;
    cout << "v3 als String: " + v3.text() << endl;

    cout << endl << "v1 + v2: " + (v1 + v2).text() << endl;
    cout << "v2 + v3: " + (v2 + v3).text() << endl;

    cout << endl << "v1 / v2: " + (v1 / v2).text() << endl;
    cout << "v2 / v3: " + (v2 / v3).text() << endl;
  }

  cout << endl << "### Bruch ###" << endl;
  {
    Vielleicht<Bruch> v1;
    Vielleicht<Bruch> v2(2);
    Vielleicht<Bruch> v3(4);

    cout << endl << "Wert von v1:" << endl;
    try
    {
      cout << v1.derWert() << endl;
    } catch (EmptyObjException e)
    {
      cout << e.msg << endl;
    }

    cout << "Wert von v2:" << endl;
    try
    {
      cout << v2.derWert() << endl;
    } catch (EmptyObjException e)
    {
      cout << e.msg << endl;
    }

    cout << "Wert von v3:" << endl;
    try
    {
      cout << v3.derWert() << endl;
    } catch (EmptyObjException e)
    {
      cout << e.msg << endl;
    }

    cout << endl << "Ist v1 leer: " << v1.leer() << endl;
    cout << "Ist v2 leer: " << v2.leer() << endl;
    cout << "Ist v3 leer: " << v3.leer() << endl;

    cout << endl << "v1 als String: " + v1.text() << endl;
    cout << "v2 als String: " + v2.text() << endl;
    cout << "v3 als String: " + v3.text() << endl;

    cout << endl << "v1 + v2: " + (v1 + v2).text() << endl;
    cout << "v2 + v3: " + (v2 + v3).text() << endl;

    cout << endl << "v1 / v2: " + (v1 / v2).text() << endl;
    cout << "v2 / v3: " + (v2 / v3).text() << endl;
  }
}
