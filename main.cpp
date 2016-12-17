#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include <algorithm>

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
        mouseX = std::min(std::max((int) mousePos.x, 0), 800);
        mouseY = std::min(std::max((int) mousePos.y, 0), 600);

        shape.setPosition(mouseX, mouseY);

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
