#include "Surfer.hpp"

// Surfer constructor
Surfer::Surfer(int init_pos)
{
    // Set initial position of surfer
    this->position = init_pos;
}

// Surfer position setter
void Surfer::set_position(int pos)
{
    this->position = pos;
}

// Surfer position getter
int Surfer::get_position() const
{
    return this->position;
}