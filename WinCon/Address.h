// TinyPIM (c) 1999 Pablo Halpern. File Address.h
#pragma once
#ifndef USED_PRECOMPILE
#include <string>
#endif // USED_PRECOMPILE

// Address class implemented using std::string class
class Address {
public:
  // Default constructor initializes recordId to 0
  // and all strings to empty.
  Address() : recordId_(0) { }

  // The following are automatically generated by the compiler:
  // ~Address();
  // Address(const Address&);
  // Address& operator=(const Address&);

  // Field accessors
  int recordId() const { return recordId_; }
  void recordId(int i) { recordId_ = i; }

  std::string lastname() const { return lastname_; }
  void lastname(const std::string&);

  std::string firstname() const { return firstname_; }
  void firstname(const std::string&);

  std::string phone() const { return phone_; }
  void phone(const std::string&);

  std::string address() const { return address_; }
  void address(const std::string&);

private:
  // Data Fields
  int         recordId_;
  std::string lastname_;
  std::string firstname_;
  std::string phone_;
  std::string address_;
};

bool operator==(const Address&, const Address&);
bool operator< (const Address&, const Address&);
