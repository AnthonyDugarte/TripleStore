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
#include <iostream>
#include <set>
using namespace std;

#include "triple.h"
#include "triplestore.h"

void query(TripleStore &store, string q)
{
  set<const Triple *> result = store.query(q);
  cout << "Query \"" << q << "\", result:" << endl;

  for (auto &&it : result)
    cout << it->toString() << endl;
  cout << endl;
}

int main()
{
  TripleStore store;

  store.add("bob", "knows", "jane");
  store.add("bob", "loves", "jane");
  store.add("frank", "knows", "jane");
  store.add("bob", "works_at", "lowes");
  store.add("jane", "works_at", "homedepot");
  store.add("lowes", "isa", "store");
  store.add("homedepot", "isa", "store");
  store.add("homedepot", "isa", "store"); //  isn't added twice

  cout << "Size: " << store.size() << endl;

  query(store, "bob ? jane");
  query(store, "? ? jane");
  query(store, "? works_at ?");
  query(store, "lowes isa ?");
  query(store, "? ? ?");

  store.del("bob", "loves", "jane");
  store.del("foo", "bar", "baz"); // does nothing

  cout << "Size: " << store.size() << endl;

  query(store, "bob ? jane");
  return 0;
}
