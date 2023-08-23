#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>

class Model {
public:
    std::string m_tag;
    std::string m_cnstr;

    explicit Model()
    : m_tag {"default"}
    , m_cnstr {"no args"}
    {
        std::cout << details("DEF cnstr") << std::endl;
    };

    explicit Model(std::string tag)
    : m_tag { std::move(tag) } 
    , m_cnstr {"with arg"}
    {
        std::cout << details("ARG cnstr") << std::endl;
    };

    // if explicit then won't compile on arg passing
    Model(Model const & other)
    : m_tag { std::move(other.m_tag) }
    , m_cnstr {"copy"}
    {
        std::cout << details("COPY cnstr") << std::endl;
    }

    Model(Model && other)
    : m_tag { std::move(other.m_tag) }
    , m_cnstr {"move"}
    {
        std::cout << details("MOVE cnstr") << std::endl;
    }

    ~Model() { 
        std::cout << details("Dsstr") << std::endl;
    };

    std::string details(std::string && topic = "") const {
        return topic
                .append(" tag: ")
                .append(m_tag)
                .append(" cnstr: ")
                .append(m_cnstr);
    }
};

#endif // MODEL_H