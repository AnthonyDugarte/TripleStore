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
