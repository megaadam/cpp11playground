#ifndef _STRUCT_HH_
#define _STRUCT_HH_

#include <string>
#include <map>

#include "Value.h"

namespace MafXpathParser
{

// A value class representing struct attributes.
// It is created _not_ by the bison parser but is a result of
// looking up a struct attribute in the db.

class Struct : public Value
{
public:
    explicit Struct(const std::string& name);
    ~Struct();
    void lookupAttribute(const std::string& name, Sequence& result) const;
    void addAttribute(const std::string& name, Sequence* value);
    std::ostream& put(std::ostream& os) const;
    const Value* clone() const;
    const std::string toString(const std::string& networkManagedElementId="") const;
private:
    Struct(const Struct& name);

    struct Destroy {
        void operator() (const std::pair<const std::string, Sequence*>& p)
        {
            delete p.second;
        }
    };

    struct Clone {
        Clone(std::map<std::string, Sequence*>& attributes) : _attributes(attributes) {}
        void operator() (const std::pair<const std::string, Sequence*>& p)
        {
            _attributes[p.first] = new Sequence(*(p.second));
        }
        std::map<std::string, Sequence*>& _attributes;
    };

    std::string _name;
    std::map<std::string, Sequence*> _attributes;        // name, sequence of values
    friend class Db;
};

} // namespace XpathParser
#endif
