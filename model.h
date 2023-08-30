#ifndef MODEL_H
#define MODEL_H

#include "easy_import.h"

#include <ostream>
using std::ostream;

class Model {
public:
    string m_tag;
    string m_cnstr;

    explicit Model()
    : m_tag {"default"}
    , m_cnstr {"no args"}
    {
        cout << details("DEF cnstr") << endl;
    };

    explicit Model(string tag)
    : m_tag { move(tag) } 
    , m_cnstr {"with arg"}
    {
        cout << details("ARG cnstr") << endl;
    };

    // if explicit then won't compile on arg passing
    Model(Model const & other)
    : m_tag { move(other.m_tag) }
    , m_cnstr {"copy"}
    {
        cout << details("COPY cnstr") << endl;
    }

    Model(Model && other)
    : m_tag { move(other.m_tag) }
    , m_cnstr {"move"}
    {
        cout << details("MOVE cnstr") << endl;
    }

    ~Model() { 
        cout << details("Dsstr") << endl;
    };

    string details(string && topic = "") const {
        return topic
                .append(" tag: ")
                .append(m_tag)
                .append(" cnstr: ")
                .append(m_cnstr);
    }

    friend ostream& operator<<(ostream& os, Model & m) {
        os << m.details();
        return os;
    }
};

#endif // MODEL_H