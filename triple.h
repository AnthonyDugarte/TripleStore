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
