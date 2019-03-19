#ifndef TRIPLE_STORE_H
#define TRIPLE_STORE_H

#include <vector>
#include <map>
#include <set>

#include "triple.h"

class TripleStore
{
  using _Object = std::set<std::string>;
  using _Predicate = std::map<std::string, _Object>;
  using _Subject = std::map<std::string, _Predicate>;
  using tripleStore = _Subject;

  tripleStore elements;

  std::vector<std::string> get_queries(std::string);
public:
  TripleStore() noexcept;

  void add(std::string, std::string, std::string) noexcept;
  void del(std::string, std::string, std::string) noexcept;

  std::set<const Triple *> query(std::string);

  size_t size() const noexcept;
};
#endif
