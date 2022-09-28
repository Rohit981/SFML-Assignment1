#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);
    float radius = shape.getRadius();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.key.code == sf::Keyboard::Space) {
                sf::Texture texture;
                texture.create(window.getSize().x, window.getSize().y);
                texture.update(window);
                if (texture.copyToImage().saveToFile("Homework 1 Screenshot.png"))
                {
                    std::cout << "Screenshot saved to Homework 1 Screenshot.png" << std::endl;
                }
            }
            else if (event.key.code == sf::Keyboard::R)
            {
                shape.setFillColor(sf::Color::Red);
                std::cout << "Circle Color Changed to Red" << std::endl;


            }
            else if (event.key.code == sf::Keyboard::G)
            {
                shape.setFillColor(sf::Color::Green);
                std::cout << "Circle Color Changed to Green" << std::endl;


            }
            else if (event.key.code == sf::Keyboard::B)
            {
                shape.setFillColor(sf::Color::Blue);
                std::cout << "Circle Color Changed to Blue" << std::endl;


            }
            else if (event.key.code == sf::Keyboard::Up)
            {
                
                radius += 4.f;
                shape.setRadius(radius);
                std::cout << "Circle radius changed to:"<< shape.getRadius() << std::endl;


            }
            else if (event.key.code == sf::Keyboard::Down)
            {
                
                radius -= 4.f;
                shape.setRadius(radius);
                std::cout << "Circle radius changed to:" << shape.getRadius() << std::endl;
                


            }
            
           

            
        }

        //window.clear();
        shape.setPosition(sf::Mouse::getPosition(window).x - shape.getRadius(), sf::Mouse::getPosition(window).y - shape.getRadius());
        window.draw(shape);
        window.display();
    }
    return 0;
}