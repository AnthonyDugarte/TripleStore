#ifndef TRIPLE_H
#define TRIPLE_H

#include <string>

class Triple
{
private:
  std::string subject;
  std::string predicate;
  std::string object;

public:
  Triple() = delete;
  Triple(const Triple &) = delete;
  Triple(std::string, std::string, std::string) noexcept;

  std::string getSubject() const noexcept;
  std::string getPredicate() const noexcept;
  std::string getObject() const noexcept;

  std::string toString() const noexcept;
};

#endif
