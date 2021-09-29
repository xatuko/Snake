#ifndef IFOOD_HPP
#define IFOOD_HPP

#include <utility>
#include <vector>
#include <string>

class IFood
{
public:
    IFood() = default;
    virtual ~IFood() = default;
    virtual std::pair<int, int> getNewFood
                                (const std::vector<std::string> & buf) = 0;
    virtual bool hasFood() = 0;
    virtual void eatFood() = 0;
    virtual std::pair<int,int> getFood() = 0;
};

#endif // IFOOD_HPP