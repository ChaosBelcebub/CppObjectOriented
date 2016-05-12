// Michael Kotzjan
// HFU, 06.05.2016

#include "./Ex1Vielleicht.h"

// ____________________________________________________________________________
template<typename T> Vielleicht<T>::Vielleicht(T wert) : m_wert(wert), m_leer(false)
{
}

// ____________________________________________________________________________
template<typename T> Vielleicht<T>::Vielleicht() : m_leer(true)
{
}

// ____________________________________________________________________________
template<typename T> bool Vielleicht<T>::leer() const
{
  return m_leer;
}

// ____________________________________________________________________________
template<typename T> const T& Vielleicht<T>::derWert() const
{
  if (m_leer)
  {
    throw EmptyObjException();
  } else {
    return m_wert;
  }
}

// ____________________________________________________________________________
template<typename T> string Vielleicht<T>::text() const
{
  if (m_leer)
  {
    return "leer";
  } else {
    stringstream ss;
    ss << derWert();
    return ss.str();
  }
}

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

template<> Vielleicht<char*> Vielleicht<char*>::operator+(const Vielleicht<char*>& v)
{
  if (leer() || v.leer()) return Vielleicht<char*>();
    // TODO: Finish implementation
    stringstream ss;
    for(int i = 0; m_wert[i] != 0; ++i)
    {
      ss << m_wert[i];
    }
    for(int i = 0; v.m_wert[i] != 0; ++i)
    {
      ss << v.m_wert[i];
    }
    string s = ss.str();
    int size = s.length();
    char* result = new char(size + 1);
    for(int i = 0; i < size; ++i)
    {
      result[i] = s[i];
    }
    result[size] = 0;
    return Vielleicht<char*>(result);
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
  return Vielleicht<string>("");
}

template<> Vielleicht<char*> Vielleicht<char*>::operator/(const Vielleicht<char*>& v)
{
  if (leer() || v.leer()) return Vielleicht<char*>();
  char* result = new char(1);
  result[0] = 0;
  return Vielleicht<char*>(result);
}

// Explicit instantiation, needed for tests
template class Vielleicht<int>;
template class Vielleicht<double>;
template class Vielleicht<string>;
template class Vielleicht<Bruch>;
template class Vielleicht<char*>;
