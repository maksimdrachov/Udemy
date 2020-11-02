#ifndef MOVIES_HPP
#define MOVIES_HPP

#include <vector>
#include "Movie.hpp"

class Movies
{
private:
    std::vector<Movie> library;
public:
    Movies();
    ~Movies();
    
    
    //Adds a new movie title to the library vector, needs to make sure there are no copies present. (Returns true if added correctly)
    bool add_movie(std::string name, std::string rating, int watched);
    
    //Looks up movie title and increases times watched by 1 (Returns true if increased correctly)
    bool increment_watched(std::string name);
    
    //Displays all the titles in the library (Return void, prints out titles)
    void display();

};

#endif // MOVIES_HPP
