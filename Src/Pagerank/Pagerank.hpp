#include "../Matrix/Matrix.hpp"
#include "../Surfer/Surfer.hpp"
#include "../Webpage/Webpage.hpp"

class Pagerank
{
public:
    Pagerank(int pages, int surfers, int rounds, double damping_factor);

    void random_surfer_walk();

    void rank_webpages();

    void print_pagerank();

private:
    std::vector<Surfer> surfers;
    std::vector<Webpage> webpages;
    double damping_factor;
    int rounds;
};