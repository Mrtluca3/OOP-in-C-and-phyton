#include "Source.h"

Source::Source(Mesh& grid, std::string field): grid_(grid)
{
    double elem=0.;
    if(field != "scalar"){
        std::cout << "Not valid type of field, please use scalar. "<< std::endl;
        exit(1);
    }
    std::cout << "Insert the values of the field:" <<std::endl;
    
    scalar_.reserve(grid.N());
    for(size_t i=0; i<grid.N(); i++)
        {   
            while (!(std::cin >> elem)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Try again: ";
            }
            scalar_.push_back(elem);
        }
}