#include "cfood.hpp"

std::pair<int,int> CFood::getNewFood(const std::vector<std::string> & buf)
{
    m_free_x.clear();
    m_free_y.clear();

    for (int y = 0; y < buf.size(); y++)
    {
        for (int x = 0; x < buf[y].size(); x++)
        {
            if (buf[y][x] == ' ')
            {
                m_free_x.push_back(x);
                m_free_y.push_back(y);
            }
        }
    }

    std::random_device rd;
    std::default_random_engine dre(rd());
    std::uniform_int_distribution<> uni_dist(0, m_free_x.size());

    int idx = uni_dist(dre);
    m_x = m_free_x[idx];
    m_y = m_free_y[idx];

    m_has_food = true;

    return std::make_pair(m_x, m_y);
}

std::pair<int,int> CFood::getFood()
{
    return std::make_pair(m_x, m_y);
}