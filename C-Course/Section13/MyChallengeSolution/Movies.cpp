#include "Movies.hpp"
#include "Movie.hpp"
#include <vector>

Movies::Movies() {};
Movies::~Movies() {};

bool Movies::add_movie(std::string name, std::string rating, int watched) {
        //Check if movie is already in library
        for (const Movie &entry: library) {
            if (entry.get_name() == name) {
                return false;
            }
        }
        //Add movie to library
        library.push_back( Movie(name, rating, watched) );
        return true;
    };

bool Movies::increment_watched(std::string name) {
    //Find movie in library
    for (Movie &entry: library) {
        if (entry.get_name() == name) {
            entry.increment_watched();
            return true;
            }
        }
    return false;
    };

void Movies::display() {
    std::cout << "Titles in library" << std::endl;
    
    for (const Movie &entry: library) {
        entry.display();
        }
    
    };

