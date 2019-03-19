#include "triplestore.h"

using namespace std;

TripleStore::TripleStore() noexcept
    : elements()
{
  //empty
}

void TripleStore::add(string subject, string predicate, string object) noexcept
{
  elements[subject][predicate].insert(object);
}

set<const Triple *> TripleStore::query(string q)
{
  vector<string> queries{get_queries(q)};
  set<const Triple *> triples;

  if (queries[0] == "?")
  {
    for (auto &&subject : elements)
    {
      if (queries[1] == "?")
      {
        for (auto &&predicate : get<1>(subject))
        {
          if (queries[2] == "?")
          {
            for (auto &&object : get<1>(predicate))
              triples.insert(new Triple(get<0>(subject), get<0>(predicate), object));
          }
          else if (get<1>(predicate).count(queries[2]))
            triples.insert(new Triple(get<0>(subject), get<0>(predicate), queries[2]));
        }
      }
      else if (get<1>(subject).count(queries[1]))
      {
        if (queries[2] == "?")
        {
          for (auto &&object : get<1>(subject)[queries[1]])
            triples.insert(new Triple(get<0>(subject), queries[1], object));
        }
        else if (get<1>(subject)[queries[1]].count(queries[2]))
          triples.insert(new Triple(get<0>(subject), queries[1], queries[2]));
      }
    }
  }
  else if (elements.count(queries[0]))
  {
    if (queries[1] == "?")
    {
      for (auto &&predicate : elements[queries[0]])
      {
        if (queries[2] == "?")
        {
          for (auto &&object : get<1>(predicate))
            triples.insert(new Triple(queries[0], get<0>(predicate), object));
        }
        else if (get<1>(predicate).count(queries[2]))
          triples.insert(new Triple(queries[0], get<0>(predicate), queries[2]));
      }
    }
    else if (elements[queries[0]].count(queries[1]))
    {
      if (queries[2] == "?")
      {
        for (auto &&object : elements[queries[0]][queries[1]])
          triples.insert(new Triple(queries[0], queries[1], object));
      }
      else if (elements[queries[0]][queries[1]].count(queries[2]))
        triples.insert(new Triple(queries[0], queries[1], queries[2]));
    }
  }

  return triples;
}

size_t TripleStore::size() const noexcept
{
  size_t elements_size{0L};

  for (auto &&subject : elements)
    for (auto &&predicate : get<1>(subject))
      for (auto &&object : get<1>(predicate))
        ++elements_size;

  return elements_size;
}

void TripleStore::del(string subject, string predicate, string object) noexcept
{
  if (elements.count(subject))
    if ((elements[subject]).count(predicate))
      if (elements[subject][predicate].count(object))
      {
        elements[subject][predicate].erase(object);

        if (elements[subject][predicate].size() == 0)
        {
          elements[subject].erase(predicate);

          if (elements[subject].size() == 0)
            elements.erase(subject);
        }
      }
}

vector<string> TripleStore::get_queries(string q)
{
  {
    size_t spaces{0L};

    for (auto &&c : q)
      if (c == ' ')
        ++spaces;

    if (spaces != 2)
      throw logic_error("incomplete sentence");
  }

  vector<string> queries;

  size_t pos{q.find(" ")};
  queries.push_back(q.substr(0, pos));
  queries.push_back(q.substr(pos + 1, q.find(" ", pos + 1) - pos - 1));
  pos = q.find(" ", pos + 1);
  queries.push_back(q.substr(pos + 1));

  return move(queries);
}
