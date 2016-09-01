#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

#include <list>

#include "Value.h"

namespace MafXpathParser
{

// A class that represents a xpath Sequence.
class Sequence
{
public:
    Sequence();
    explicit Sequence(const std::list<const Value*>& nodes);
    explicit Sequence(const Value* expr);
    Sequence(const Sequence& s);
    /**
     * no virtual destructor since there is a need
     * for this class to be memory efficient.
     * Also the NotOwningSequence dont want this destructor
     * to be called.
     */
    ~Sequence();

    std::ostream& put(std::ostream& os) const;
    const std::string toString(const std::string& networkManagedElementId="") const;
    bool exists(EvalContext& evalContext) const;
    bool isTrue() const;

    /**
     * Methods to access/add values etc
     */

    /**
     * Since the Dns class has a set of values, counting is needed.
     * this should not be too bad since size on list has O(n)
     * complexity according to specs.
     */
    size_t size() const
    {
        size_t result = 0;
        for (std::list<const Value*>::const_iterator i = _values.begin();
                i != _values.end();
                ++i) {
            result += (*i)->size();
        }
        return result;
    }

    void addValue(const Value* n);
    void addValueFront(const Value* n);
    const Value& firstValue() const;
    const Value& secondValue() const;
    std::list<const Value*>& getValues();
    const std::list<const Value*>& getValues() const;
    void splice(const Sequence& s)
    {
        _values.splice(_values.end(), const_cast<Sequence&>(s)._values);
    }
    struct Destroy {
        void operator ()(const Value* v)
        {
            delete v;
        }
    };
private:
    Sequence& operator = (const Sequence&); // Not allowed
    struct NotExist {
        NotExist(EvalContext& evalContext): _evalContext(evalContext) {}
        bool operator() (const Value* v)
        {
            return !v->exists(_evalContext);
        }
        EvalContext& _evalContext;
    };
    struct Copy {
        Copy(std::list<const Value*>& values) : _values(values)
        {
            ;
        }
        void operator ()(const Value* v)
        {
            _values.push_back(v->clone());
        }
        std::list<const Value*>& _values;
    };
protected:
    /**
     * A sequence is a list of values
     */
    std::list<const Value*> _values;
};

// Class to make sure the destructor does not delete
// the values in the sequence.
class NotOwningSequence : public Sequence
{
public:
    ~NotOwningSequence()
    {
        _values.clear();
    }
};

inline
std::ostream&
operator<<(std::ostream& os, const Sequence& s)
{
    s.put(os);
    return os;
}

} // namespace XpathParser

#endif
