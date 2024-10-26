// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
//PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "AddressBook.h"

TEST(CAddress, eq) {
  Address a;
  a.lastname("Smith");
  a.firstname("Joan");
  a.phone("(617) 555-9876");
  a.address("The Very Big Corporation\nSomewhere, MA 01000");

  Address b(a);
  ASSERT_EQ(a, b);

  Address c(a);
  c.firstname("Joan ");
  ASSERT_NE(a, c);
}
TEST(Book, Create) {
  AddressBook book;
  SUCCEED();
}

TEST(Book, Insert) {
  AddressBook book;

  Address a;
  a.lastname("Smith");
  a.firstname("Joan");
  a.phone("(617) 555-9876");
  a.address("The Very Big Corporation\nSomewhere, MA 01000");

  Address b;
  b.lastname("Adams");
  b.firstname("Abigale");
  b.phone("(212) 555-3734");
  b.address("743 Broadway\nNew York, NY");

  Address c;
  c.lastname("Neighborhood Video");
  c.phone("555-FILM");

  const int a_id = book.insertAddress(a);
  ASSERT_NE(a_id, 0); 
  const int b_id = book.insertAddress(b);
  ASSERT_NE(b_id, 0);
  const int c_id = book.insertAddress(c);
  ASSERT_NE(c_id, 0);

  ASSERT_NE(a_id, b_id);
  ASSERT_NE(b_id, c_id);
  ASSERT_NE(a_id, c_id);

  // Address d has same name as b
  Address d;
  d.lastname("Adams");
  d.firstname("Abigale");
  d.phone("(508) 555-4466");
  d.address("1 Small St.\nMarlboro, MA 02100");

  // Insert address with duplicate name
  const int d_id = book.insertAddress(d);

  ASSERT_NE(c_id, d_id);

  ASSERT_THROW(book.insertAddress(d, a_id), AddressBook::DuplicateId);
}

#pragma warning( disable : 26495)
class TestBook : public ::testing::Test {
protected:
  void SetUp() {
    book = new AddressBook;
    Address a, b, c, d;

    a.lastname("Smith");
    a.firstname("Joan");
    a.phone("(617) 555-9876");
    a.address("The Very Big Corporation\nSomewhere, MA 01000");

    b.lastname("Adams");
    b.firstname("Abigale");
    b.phone("(212) 555-3734");
    b.address("743 Broadway\nNew York, NY");

    c.lastname("Neighborhood Video");
    c.phone("555-FILM");

    // Address d has same name as b
    d.lastname("Adams");
    d.firstname("Abigale");
    d.phone("(508) 555-4466");
    d.address("1 Small St.\nMarlboro, MA 02100");

    ids[0] = book->insertAddress(a);
    ids[1] = book->insertAddress(b);
    ids[2] = book->insertAddress(c);
    // Insert address with duplicate name
    ids[3] = book->insertAddress(d);
  }

  void TearDown() {
    delete book;
  }

  AddressBook* book;
  std::array<int, 4> ids{};
};

TEST_F(TestBook, Erase) {
  for (const auto & id : ids)
    ASSERT_NO_THROW(book->eraseAddress(id));
  
  for (const auto& id : ids)
    ASSERT_THROW(book->eraseAddress(id), AddressBook::AddressNotFound);

}

TEST_F(TestBook, Get) {
  Address aa;
  aa.lastname("Smith");
  aa.firstname("Joan");
  aa.phone("(617) 555-9876");
  aa.address("The Very Big Corporation\nSomewhere, MA 01000");

  const int aa_id = book->insertAddress(aa);

  const Address aa_ = book->getAddress(aa_id);
  ASSERT_EQ(aa.lastname(), aa_.lastname());
  ASSERT_EQ(aa.firstname(), aa_.firstname());
  ASSERT_EQ(aa.phone(), aa_.phone());
  ASSERT_EQ(aa.address(),aa_.address());
}

TEST_F(TestBook, Replace) {
  Address aa;
  aa.lastname("Smith");
  aa.firstname("Joan");
  aa.phone("(617) 555-9876");
  aa.address("The Very Big Corporation\nSomewhere, MA 01000");

  const int aa_id = book->insertAddress(aa);

  const  std::string new_addr = "22 Main St.\nMy town, MA 02200";
  
  aa.address(new_addr);
  book->replaceAddress(aa, aa_id);

  ASSERT_EQ(book->getAddress(aa_id).address(), new_addr);
  
}
