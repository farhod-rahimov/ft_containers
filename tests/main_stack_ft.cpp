#include <iostream>
#include <ctime>

#include "../headers/Stack.hpp"

void constructor ()
{
  ft::vector<int> myv (3,100);          // deque with 3 elements
  ft::vector<int> myvector (2,200);        // vector with 2 elements

  ft::stack<int> first;                    // empty stack
  ft::stack<int, ft::vector<int> > second (myv);         // stack initialized to copy of deque

  ft::stack<int,ft::vector<int> > third;  // empty stack using vector

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';

}

void empty ()
{
 ft::stack<int> mystack;
  int sum (0);

  for (int i=1;i<=10;i++) mystack.push(i);

  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  std::cout << "total: " << sum << '\n';

}

void size ()
{
  ft::stack<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';

}

void top ()
{
  ft::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';

}

void push ()
{
  ft::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

}

void pop ()
{
  ft::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

}

void relational_operators_vector()
{
  ft::vector<int> foo_vector (3,100);   // three ints with a value of 100
  ft::vector<int> bar_vector (2,200);   // two ints with a value of 200
  
  ft::stack<int, ft::vector<int> > foo_stack (foo_vector);   // three ints with a value of 100
  ft::stack<int, ft::vector<int> > bar_stack (bar_vector);   // two ints with a value of 200

  if (foo_stack==bar_stack) std::cout << "foo and bar are equal\n";
  if (foo_stack!=bar_stack) std::cout << "foo and bar are not equal\n";
  if (foo_stack< bar_stack) std::cout << "foo is less than bar\n";
  if (foo_stack> bar_stack) std::cout << "foo is greater than bar\n";
  if (foo_stack<=bar_stack) std::cout << "foo is less than or equal to bar\n";
  if (foo_stack>=bar_stack) std::cout << "foo is greater than or equal to bar\n";
}

void main_stack()
{
    int a = 10000;
    while (a-- != 0)
    {
      constructor();
      empty();
      size();
      top();
      push();
      pop();
      relational_operators_vector();
    }
}

int main()
{
    int start = std::clock();
    main_stack();
    int end = std::clock();
    int t = (end - start) / 1000;
    std::cout << "\nIt took " << t << " milliseconds to run MAIN_STACK_STL.CPP tests" << std::endl;
}