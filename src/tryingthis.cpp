#include <string>
#include <tryingthis.hpp>

tryingthis::tryingthis(std::string name):
m_name(name)
{
}

tryingthis::~tryingthis()
{
}

void tryingthis::print_name(){
    printf(m_name.c_str());
}
