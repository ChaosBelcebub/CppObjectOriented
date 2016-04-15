// Michael Kotzjan
// HFU, 31.03.2016

#include <iostream>
#include <string>

using namespace std;

class Queue
{
  int posinsert, posremove, anz, dim;
  string** queue;

  // Public
  public:
  Queue(int d = 5)
  {
    posinsert = posremove = anz = 0;
    dim = d;
    queue = new string*[dim];

    for (int i = 0; i < dim; ++i)
    {
      queue[i] = new string();
    }
  }

  // Kopierkonstruktor
  Queue(const Queue &q)
  {
    posinsert = posremove = anz = 0;
    dim = q.dim;
    queue = new string*[dim];

    for (int i = 0; i < dim; ++i)
    {
      queue[i] = new string(*q.queue[i]);
    }
  }

  ~Queue()
  {
    for (int i = 0; i < dim; ++i)
    {
      delete queue[i];
    }
    delete[] queue;
  }

  // Insert value
  void insert(string s)
  {
    // Check if queue is full
    if (anz < dim)
    {
      *queue[posinsert] = s;
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
      *queue[posremove] = "";
      posremove = ++posremove % dim;
      --anz;
    } else {
      cout << "Warteschlange ist bereits leer." << endl;
    }
  }

  // Print Queue
  void print()
  {
    cout << "-----" << endl;
    for (int i = 0; i < dim; ++i)
    {
      cout << *queue[i];
      if (i == posinsert)
        cout << " <- posinsert";
      if (i == posremove)
        cout << " <- posremove";
      cout << endl << "-----" << endl;
    }
  }

  // Print the amount of entrys
  void printAmount()
  {
    cout << "Anzahl Einträge: " << anz << endl;
  }

  // Delete queue
  void del()
  {
    posremove = posinsert = anz = 0;
    for (int i = 0; i < dim; ++i)
    {
      *queue[i] = "";
    }
  }

  // Reinitialize
  void reinit(int d)
  {
    if (d == dim)
    {
      del();
    } else {
      for (int i = 0; i < dim; ++i)
      {
        delete queue[i];
      }
      delete[] queue;
      
      posinsert = posremove = anz = 0;
      dim = d;
      queue = new string*[dim];
      for (int i = 0; i < dim; ++i)
      {
        queue[i] = new string();
      }
    }
  }
};

int main()
{
  Queue q1(5);
  // Remove from empty queue
  q1.remove();

  // Insert 3 strings
  q1.insert("String 1");
  q1.insert("String 2");
  q1.insert("String 3");

  // Print queue
  q1.print();

  // Insert 3 more strings
  q1.remove();
  q1.print();
  q1.printAmount();

  Queue q2 = q1;
  q1.remove();
  q1.remove();
  q1.print();
  q2.print();
}

