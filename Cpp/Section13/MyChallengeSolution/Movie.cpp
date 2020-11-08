#include "Movie.hpp"

Movie::Movie(std::string n, std::string r, int w): name(n), rating(r), watched(w) {}

Movie::~Movie() {};

//Copy constructor
Movie::Movie(const Movie &source): Movie{source.name, source.rating, source.watched} {};

void Movie::display() const {
        std::cout << name << ", " << rating << ", " << watched << std::endl;
    };
