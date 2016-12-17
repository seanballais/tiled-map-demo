#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include <algorithm>
#include <cmath>
#include <vector>

sf::Vector2i getShapePosition(int mouseX, int mouseY);

int main()
{
    std::vector<sf::Color> colorVector;
    colorVector.push_back(sf::Color::Blue);
    colorVector.push_back(sf::Color::Green);
    colorVector.push_back(sf::Color::Red);
    colorVector.push_back(sf::Color::Yellow);
    colorVector.push_back(sf::Color::Black);
    //std::vector<sf::RectangleShape> shapePositions;
    int colorIndex = 0;

    int mouseX = 0;
    int mouseY = 0;

    sf::RenderWindow window(sf::VideoMode(800,600), "Tiled Map Demo");
    sf::RectangleShape tmpShape(sf::Vector2f(50,50));
    tmpShape.setFillColor(colorVector.at(colorIndex));
    tmpShape.setOrigin(25, 25);

    while (window.isOpen()) {
        sf::Event event;

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        mouseX = std::min(std::max(mousePos.x, 0), 800);
        mouseY = std::min(std::max(mousePos.y, 0), 600);

        mousePos = getShapePosition(mouseX, mouseY);
        mouseX = mousePos.x;
        mouseY = mousePos.y;

        tmpShape.setPosition(mouseX, mouseY);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Right) {
                    colorIndex = (colorIndex + 1) % colorVector.size();
                }
            }
        }

        tmpShape.setFillColor(colorVector.at(colorIndex));

        window.clear();
        window.draw(tmpShape);
        window.display();
    }

    return 0;
}

sf::Vector2i getShapePosition(int mouseX, int mouseY)
{
    int xLowerLimit = mouseX - (mouseX % 50);
    int yLowerLimit = mouseY - (mouseY % 50);

    sf::Vector2i newMousePos(xLowerLimit + 25, yLowerLimit + 25);
    return newMousePos;
}
