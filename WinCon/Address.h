#pragma once

// Address class using dynamically-allocated strings
class Address {
public:
  // Constructor
  Address() = default;

  // Destructor
  ~Address();

  // Copy constructor and assignment
  Address(const Address&);
  const Address& operator=(const Address&);

  // Field accessors
  const char* lastname() const { return lastname_; }
  void lastname(const char*);

  const char* firstname() const { return firstname_; }
  void firstname(const char*);

  const char* phone() const { return phone_; }
  void phone(const char*);

  const char* address() const { return address_; }
  void address(const char*);

private:
  // Variable-length data fields
  char* lastname_;
  char* firstname_;
  char* phone_;
  char* address_;

  // Private function for making a copy of a string:
  char* dup(const char* s);
};
