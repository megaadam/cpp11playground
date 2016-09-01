#include <iostream>
#include <algorithm>
#include <map>

#include "Sequence.h"
#include "Struct.h"

using namespace MafXpathParser;

Struct::Struct(const std::string& name) : _name(name)
{
}

Struct::Struct(const Struct& s) : _name(s._name)
{
	// C++03
    Clone cloneObj(_attributes);
    std::for_each(s._attributes.begin(), s._attributes.end(), cloneObj);

    // C++14 - Here is another nifty use of lambdas
    // This could be re-written something like below
    // We no longer need the "class Clone" functor.
    auto cloneFunc = [this](auto& attr){this->_attributes[attr.first] = new Sequence(*(attr.second));
    for(const auto& attr: s._attributes) cloneFunc();

    // Or
    auto cloneFunc2 = [this](auto& attr){this->_attributes[attr->first] = new Sequence(*(attr->second));
    std::for_each(s._attributes.begin(), s._attributes.end(), cloneFunc2);

    // A nice explanation of the template expansion of [this](auto& attr)
    // Can be found here:
    // http://stackoverflow.com/questions/17233547/how-does-generic-lambda-work-in-c14/17233649#17233649
}

Struct::~Struct()
{
    Destroy destroy;
    (void) std::for_each(_attributes.begin(), _attributes.end(), destroy);
}

void
Struct::lookupAttribute(const std::string& name,
                        Sequence& result) const
{
    std::map<std::string, Sequence*>::const_iterator it =
        _attributes.find(name);
    if (it != _attributes.end()) {
        Sequence tmp(*(it->second));
        result.splice(tmp);
    }
}

void
Struct::addAttribute(const std::string& name, Sequence* value)
{
    _attributes[name] = value;
}

std::ostream&
Struct::put(std::ostream& os) const
{
    os << "(Struct " << _name << ")";
    return os;
}

const Value*
Struct::clone() const
{
    return new Struct(*this);
}

const std::string
Struct::toString(const std::string& networkManagedElementId) const
{
    std::string result("struct(");

    for (std::map<std::string, Sequence*>::const_iterator i = _attributes.begin();
            i != _attributes.end();
            ++i) {
        if (i != _attributes.begin()) {
            result += ", ";
        }
        result += i->first;
        result += "=";
        result += i->second->toString(networkManagedElementId);
    }

    result += ")";

    return result;
}
