// Michael Kotzjan
// HFU, 13.05.2016

template<typename T>
T add(T t)
{
  return t;
}

template<typename T, typename... Args>
T add(T first, Args... args)
{
  return first + add(args...);
}
