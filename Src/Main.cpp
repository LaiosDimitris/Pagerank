#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Pagerank/Pagerank.hpp"

int main()
{
    std::srand(std::time(NULL));
    
    int pages = 10, surfers = 3, rounds = 10;
    double damping_factor = 0.85;

    Pagerank pagerank(pages, surfers, rounds, damping_factor);

    pagerank.random_surfer_walk();
    
    pagerank.rank_webpages();

    pagerank.print_pagerank();
}