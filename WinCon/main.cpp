#include "Address.h"

void dump(const Address& a)
{
  std::cout << a.firstname() << ' ' << a.lastname() << '\n'
    << a.address() << '\n' << a.phone() << '\n' << std::endl;
}

int main()
{
  Address a;
  a.lastname("Smith");
  a.firstname("Joan");
  a.phone("(617) 555-9876");
  a.address("The Very Big Corporation\nSomewhere, MA 01000");
  dump(a);

  // Add phone extention
  a.phone("(617) 555-7777 ext. 112");
  dump(a);

  return 0;
}
