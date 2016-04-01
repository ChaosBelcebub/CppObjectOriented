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

  ~Queue()
  {
    for (int i = 0; i < dim; ++i)
    {
      delete queue[i];
    }
    delete[] queue;
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
  int dim = 8;

  // Tests
  // Initialize queues
  Queue q1(5);
  int** q = new int*[dim];
  for (int i = 0; i < dim; ++i)
  {
    q[i] = new int(i+1);
  }

  Queue q2(dim, q);
  
  // Test 1
  cout << "Test 1: Remove one element from q1." << endl;
  q1.remove();

  // Test 2
  cout << "Test 2: Fill up q1." << endl;
  for (int i = 0; i < 5; ++i)
  {
    q1.insert(i+1);
  }

  // Test 3
  cout << "Test 3: Remove all elements from q1." << endl;
  for (int i = 0; i < 5; ++i)
  {
    q1.remove();
  }

  // Test 4
  cout << "Test 4: Fill up q1 and insert another element." << endl;
  for (int i = 0; i < 6; ++i)
  {
    q1.insert(i+1);
  }

  // Test 5
  cout << "Test 5: Remove one element from q1, add one. Repeat." << endl;
  for (int i = 0; i < 10; ++i)
  {
    q1.remove();
    q1.insert(i+1);
  }

  // Test 6
  cout << "Test 6: Add one element to q2." << endl;
  q2.insert(0);

  // Test 7
  cout << "Test 7: Empty q2." << endl;
  for (int i = 0; i < dim; ++i)
  {
    q2.remove();
  }

  // Test 8
  cout << "Test 8: Remove another element." << endl;
  q2.remove();

  // Test 9
  cout << "Test 9: Fill up q1." << endl;
  for (int i = 0; i < dim; ++i)
  {
    q2.insert(i+1);
  }

  // Test 10
  cout << "Test 10: Remove one element from q2, add one. Repeat." << endl;
  for (int i = 0; i < dim*2; ++i)
  {
    q2.remove();
    q2.insert(i+1);
  }

  // Delete q
  for (int i = 0; i < dim; ++i)
  {
    delete q[i];
  }
  delete[] q;
}
