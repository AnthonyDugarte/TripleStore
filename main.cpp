#include <iostream>
#include <set>
using namespace std;

#include "triple.h"
#include "triplestore.h"

void query(TripleStore &store, string q)
{
    set<const Triple *> result = store.query(q);
    cout << "Query \"" << q << "\", result:" << endl;

    for(auto && it : result)
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
    store.add("homedepot", "isa", "store"); // isn't added twice

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
