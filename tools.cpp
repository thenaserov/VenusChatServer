#include "tools.h"

Tools::Tools()
{

}

char *Tools::str2charstar(std::string str)
{
    char *cstar = const_cast<char*>(str.c_str());
    return cstar;
}
