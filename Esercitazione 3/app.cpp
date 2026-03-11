#include "Rectangle.h"
#include "RightHexagonalPrism.h"
#include "RegularHexagon.h"

Shape* selectShape(Shape* object); //Funzione che permette di creare un nuovo oggetto facilmente

int main() {
    Shape *object=0, *object2=0;
    std::cout << "Vertices " << Shape::getVertices() << std::endl; 
 
    object = selectShape(object); object2 = selectShape(object2);
    object->Print(); object2->Print();
    if(*object>*object2){ //Vedo se gli operatori di confronto funzionano tra classi differenti
        if(object->getVolume() ==0 || object2->getVolume() ==0 )
            std::cout << "First object has larger surface" << std::endl;
        else
            std::cout << "First object has larger volume" << std::endl;

    } else {
        if(object->getVolume() ==0 || object2->getVolume() ==0 )
            std::cout << "Second object has larger surface" << std::endl;
        else
            std::cout << "Second object has larger volume" << std::endl;    
    }
    std::cout << "Vertices " << Shape::getVertices() << std::endl; 
    delete object; delete object2;

    std::cout << "Vertices " << Shape::getVertices() << std::endl; 
    return 0;
}

Shape* selectShape(Shape* object) {
    int shape;
    std::cout << "Select the wanted shape: Rectangle [0], RegularHexagon [1], RightHexagonalPrism [2]." << std::endl;
    std::cin >> shape;
    switch(shape) {
        case 0: {
            double a, b;
            std::cout << "Insert the two lengths of the rectangle in meters. " << std::endl;
            std::cin >> a >> b; 
            object = new Rectangle(a, b);
            break;
        }
        case 1: {
            double t;
            std::cout << "Insert the length of the hexagon in meters. " << std::endl;
            std::cin >> t; 
            object = new Hexagon(t);
            break;
        }
        case 2: {
            double t, h;
            std::cout << "Insert the length and height of the hexagonal prism in meters. " << std::endl;
            std::cin >> t >> h; 
            object = new RightHexagon(t, h);
            break;
        }
        default:
            std::cout << "You didn't insert a correct value. " << std::endl;
            break;
    }
    
    return object;
}