
#include "ParticleSystem.h"
#include <random>


std::random_device rd;
std::mt19937 gen(rd());


float randomFloat(float min, float max) {
    std::uniform_real_distribution<float> dist(min, max);
    return dist(gen);
}

int randomInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

int main() {
    
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Particle System with Modules");

    ParticleSystem particles;

    sf::Clock clock;                   
    sf::Clock mousePressTimer;         

    bool isMousePressed = false;       
    sf::Vector2f emitterPosition;      

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                isMousePressed = true;
                mousePressTimer.restart();
                emitterPosition = sf::Vector2f(sf::Mouse::getPosition(window));
            }

            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                isMousePressed = false;
            }
        }

        sf::Time elapsed = clock.restart();

        
        if (isMousePressed) {

            if (mousePressTimer.getElapsedTime().asMilliseconds() >= 1.0f) {
                mousePressTimer.restart(); 

                float angle = randomFloat(0.f, 360.f) * 3.14f / 180.f;
                float speed = randomFloat(50.f, 200.f);

                sf::Vector2f velocity(std::cos(angle) * speed, std::sin(angle) * speed);
                sf::Color color = sf::Color(randomInt(0, 255), randomInt(0, 255), randomInt(0, 255));

                particles.addParticle(emitterPosition, velocity, color);

            }
        }

        particles.update(elapsed, window);

        window.clear();
        window.draw(particles);
        window.display();
    }

    return 0;
}
