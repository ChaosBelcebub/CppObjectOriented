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
  cout << endl << "--- Test 1 ---" << endl;
  cout << "Remove from empty queue:" << endl << endl;
  q1.remove();

  cout << endl << "--- Test 2 ---" << endl;
  cout << "Insert 3 strings:" << endl << endl;
  q1.insert("String 1");
  q1.insert("String 2");
  q1.insert("String 3");

  cout << endl << "--- Test 3 ---" << endl;
  cout << "Print Queue:" << endl << endl;
  q1.print();
  q1.printAmount();

  cout << endl << "Test 4" << endl;
  cout << "Insert 3 more strings:" << endl << endl;
  q1.insert("String 4");
  q1.insert("String 5");
  q1.insert("String 6");

  cout << endl << "Test 5" << endl;
  cout << "Remove 3 strings:" << endl << endl;
  q1.remove();
  q1.remove();
  q1.remove();

  cout << endl << "Test 6" << endl;
  cout << "Print Queue:" << endl << endl;
  q1.print();
  q1.printAmount();

  cout << endl << "Test 7" << endl;
  cout << "Remove 3 more strings:" << endl << endl;
  q1.remove();
  q1.remove();
  q1.remove();

  cout << endl << "Test 8" << endl;
  cout << "Refill and delete the hole queue. Print afterwards:" << endl << endl;
  for (int i = 0; i < 5; ++i)
  {
    q1.insert("StringTest");
  }
  q1.del();
  q1.print();
  q1.printAmount();

  cout << endl << "Test 9" << endl;
  cout << "Reinit queue and print:" << endl << endl;
  q1.reinit(2);
  q1.print();
  q1.printAmount();

  cout << endl << "Test 10" << endl;
  cout << "Fill q1, copy into q2, delete q1 and print q2:" << endl << endl;
  q1.insert("A");
  q1.insert("B");
  Queue q2 = q1;
  q1.del();
  q2.print();
  q2.printAmount();
}

