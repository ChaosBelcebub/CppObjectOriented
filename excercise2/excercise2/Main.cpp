// Michael Kotzjan
// HFU, 31.03.2016

#include <iostream>

using namespace std;

class Queue
{
  int posinsert = 0, posremove = 0, anz = 0, dim = 0;
  int** queue;

  // Public
  public:
  Queue(int d = 5)
  {
    dim = d;
    queue = new int*[dim];

    for (int i = 0; i < dim; ++i)
    {
      queue[i] = new int();
    }
  }

  Queue(int d, int** q)
  {
    dim = d;
    anz = d;
    queue = q;
  }

  // Insert value
  void insert(int i)
  {
    // Check if queue is full
    if (anz < dim)
    {
      *queue[posinsert] = i;
      posinsert = ++posinsert % dim;
      ++anz;
    } else {
      cout << "Warteschlange ist bereits voll." << endl;
    }
  }

  // Remove value
  void remove()
  {
    // Check if queue is empty
    if (anz > 0)
    {
      cout << "Entfernt: " << *queue[posremove] << endl;
      posremove = ++posremove % dim;
      --anz;
    } else {
      cout << "Warteschlange ist bereits leer." << endl;
    }
  }
};

int main(int argc, char *argv[])
{
  Queue q1(5);
  int** q = new int*[5];
  for (int i = 0; i < 5; ++i)
  {
    q[i] = new int((i+1) * 12);
  }

  Queue q2(5, q);
  
  for (int i = 0; i < 6; ++i)
  {
    q2.remove();
    q2.insert(i);
  }

  for (int i = 0; i < 6; ++i)
  {
    q2.remove();
  }
}
