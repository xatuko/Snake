#ifndef CFOOD_HPP
#define CFOOD_HPP

#include "ifood.hpp"

#include <random>

class CFood : public IFood
{
private:
    // members
    int m_x, m_y;
    bool m_has_food;
    std::vector<int> m_free_x, m_free_y;
    
    // methods
public:
    CFood() : IFood() { m_has_food = false; }
    ~CFood() override { }

    std::pair<int,int> getNewFood
                       (const std::vector<std::string> & buf) override;
    
    bool hasFood() override { return m_has_food; }
    void eatFood() override { m_has_food = false; }
    std::pair<int,int> getFood() override;


};

#endif // CFOOD_HPP