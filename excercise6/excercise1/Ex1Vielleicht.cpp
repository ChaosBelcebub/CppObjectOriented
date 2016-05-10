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
    ss << m_wert;
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

