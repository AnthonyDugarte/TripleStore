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
#include "triple.h"

using namespace std;

Triple::Triple(string _subject, string _predicate, string _object) noexcept
    : subject(_subject), predicate(_predicate), object(_object)
{
  //empty
}

std::string Triple::getSubject() const noexcept
{
  return subject;
}
std::string Triple::getPredicate() const noexcept
{
  return predicate;
}
std::string Triple::getObject() const noexcept
{
  return object;
}

std::string Triple::toString() const noexcept
{
  return subject + " " + predicate + " " + object;
}
