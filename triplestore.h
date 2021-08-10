/*
    <https://github.com/AnthonyDugarte/TripleStore/blob/master/LICENSE>

    TripleStore, save and search for triplets sentences
    Copyright (C) 2021  Anthony Dugarte contact@anthonydugarte.dev

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
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
