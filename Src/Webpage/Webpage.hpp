#include <vector>

class Webpage
{
public:
    int visits;
    int id;

    Webpage(std::vector<int> hyperlinks, int id);

    void set_score(double score);

    double get_score() const;
    
    int get_random_link();

private:
    double score;
    std::vector<int> hyperlinks;
};