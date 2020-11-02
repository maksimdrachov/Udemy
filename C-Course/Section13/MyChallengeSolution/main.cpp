#include <iostream>
#include "Movie.hpp"
#include "Movies.hpp"

std::string user_entry;

//Function prototypes
void increment_watched(Movies &movies, std::string name);
void add_movie(Movies &movies, std::string name, std::string rating, int watched);

void increment_watched(Movies &movies, std::string name) {
        if (movies.increment_watched(name)) {
                std::cout << name << " watch incrmented" << std::endl;
            }
        else {
                std::cout << name << " not found" << std::endl;
            }
    }
    
void add_movie(Movies &movies, std::string name, std::string rating, int watched) {
        if (movies.add_movie(name, rating, watched)) {
                std::cout << name << " added" << std::endl;
            }
        else {
                std::cout << name << " already exists" << std::endl;
            }
    }

int main() {
    
    Movies my_movies;
    
    my_movies.display();
    
    add_movie(my_movies, "Big", "PG-13", 2);
    add_movie(my_movies, "Star Wars", "PG", 5);
    add_movie(my_movies, "Cinderella", "PG", 7);
    
    my_movies.display(); // Big, Star Wars, Cinderella
    
    add_movie(my_movies, "Cinderella", "PG", 7);    // Already exists
    add_movie(my_movies, "Ice Age", "PG", 12);      // OK
    
    my_movies.display();        // Big, Star Wars, Cinderella, Ice Age
    
    increment_watched(my_movies, "Big");
    increment_watched(my_movies, "Ice Age");
    
    my_movies.display();
    
    increment_watched(my_movies, "XXX");         // XXX not found
    
    
    return 0;
}
