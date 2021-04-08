#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

#include "PageRank.hpp"

// Pagerank constructor
Pagerank::Pagerank(int pages, int surfers, int rounds, double damping_factor)
{
    this->rounds = rounds;
    this->damping_factor = damping_factor;

    // Create a web graph
    Matrix web_graph(pages, pages);

    for (int i = 0; i < web_graph.get_rows(); i++)
    {
        // Store webpage hyperlinks
        std::vector<int> hyperlinks; 

        for (int j = 0; j < web_graph.get_cols(); j++)
        {
            if (i == j) { continue; }

            web_graph[i][j] = std::rand() % 2;

            if (web_graph[i][j] == 1)
            {
                hyperlinks.push_back(j);
            }
        }

        // Create a webpage
        this->webpages.push_back(Webpage(hyperlinks, i));
    }

    // Print the graph
    for (int i = 0; i < web_graph.get_rows(); i++)
    {
        for (int j = 0; j < web_graph.get_cols(); j++)
        {
            std::cout << web_graph[i][j] << " ";
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    // Create surfers
    for (int i = 0; i < surfers; i++)
    {
        // Set surfer initial position
        int init_pos = std::rand() % this->webpages.size();

        this->surfers.push_back(Surfer(init_pos));

        // Print surfer initial position
        std::cout << "Surfer " << i << " initial position in webpage " << init_pos << std::endl;
    }
    std::cout << std::endl;
}

// Random surfer walk from page to page
void Pagerank::random_surfer_walk()
{
    for (int rnd = 1; rnd <= (this->rounds * this->webpages.size()); rnd++)
    {
        std::cout << "Round " << rnd << std::endl;

        for (int i = 0; i < this->surfers.size(); i++)
        {
            // Get surfers current position
            int current_pos = surfers[i].get_position();
            
            // Get new position
            int new_pos;

            // Jump to a random page
            if (std::rand() % 100 > this->damping_factor * 100)
            {
                new_pos = std::rand() % webpages.size();
            }
            // Or follow a random hyperlink from the current page
            else
            {
                new_pos = webpages[current_pos].get_random_link();

                // If current page has no hyperlinks to other pages
                // then jump to a random page
                if (new_pos == -1)
                {
                    new_pos = std::rand() % webpages.size();
                }
            }

            // Set the new surfer positions
            surfers[i].set_position(new_pos);

            // Increase the visits of current page
            webpages[new_pos].visits++;

            // Print surfer's move
            std::cout << "Surfer " << i << " moved from webpage " << current_pos << " to webpage " << new_pos << std::endl;
        }
    }
    std::cout << std::endl;
}


// Rank webpages
void Pagerank::rank_webpages()
{
    int total_visits = 0;

    // Get amount of total visits
    for (int i = 0; i < this->webpages.size(); i++)
    {
        total_visits += this->webpages[i].visits;
    }

    // Calculate the score of each webpage
    for (int i = 0; i < this->webpages.size(); i++)
    {
        double score = (double)this->webpages[i].visits / (double)total_visits;

        this->webpages[i].set_score(score);
    }

    // Sort the webpages in descending order by score
    std::sort(this->webpages.begin(), this->webpages.end(), [](const Webpage &webpage1, const Webpage &webpage2)
    {
        return webpage1.get_score() > webpage2.get_score();
    });
}


// Print webpages
void Pagerank::print_pagerank()
{
    for (int i = 0; i < this->webpages.size(); i++)
    {
        std::cout << i + 1 << ". Webpage " << this->webpages[i].id << ": " << this->webpages[i].get_score() << std::endl;
    }
}