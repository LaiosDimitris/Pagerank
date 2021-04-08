#include <iostream>
#include <cstdlib>
#include "Webpage.hpp"

// Webpage constructor
Webpage::Webpage(std::vector<int> hyperlinks, int id)
{
    this->hyperlinks = hyperlinks;
    this->visits = 0;
    this->id = id;
}

// Return a random external link
int Webpage::get_random_link()
{
    if (this->hyperlinks.empty())
    {
        return -1;
    }
    else
    {
        return this->hyperlinks[std::rand() % this->hyperlinks.size()];
    }
}

// Webpage score setter
void Webpage::set_score(double score)
{
    this->score = score;
}

// Webpage score getter
double Webpage::get_score() const
{
    return this->score;
}