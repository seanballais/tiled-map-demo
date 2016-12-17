#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include <algorithm>
#include <cmath>

sf::Vector2i getShapePosition(int mouseX, int mouseY);

int main()
{
    int mouseX = 0;
    int mouseY = 0;

    sf::RenderWindow window(sf::VideoMode(800,600), "Tiled Map Demo");
    sf::RectangleShape shape(sf::Vector2f(50,50));
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(25, 25);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        mouseX = std::min(std::max(mousePos.x, 0), 800);
        mouseY = std::min(std::max(mousePos.y, 0), 600);

        mousePos = getShapePosition(mouseX, mouseY);
        mouseX = mousePos.x;
        mouseY = mousePos.y;

        shape.setPosition(mouseX, mouseY);

        window.clear();
        window.draw(shape);
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
