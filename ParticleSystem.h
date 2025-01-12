#pragma once

#include <SFML/Graphics.hpp>
#include <vector>


struct Particle {

    sf::Vector2f velocity;     

    sf::Vector2f position; 

    sf::Color color;           
};


class ParticleSystem : public sf::Drawable, public sf::Transformable {

public:

    ParticleSystem();

    
    void addParticle(sf::Vector2f position, sf::Vector2f velocity, sf::Color color);

    
    void update(sf::Time elapsed, sf::RenderWindow& window);

private:

    std::vector<Particle> particles;   
    
    sf::VertexArray vertices;         

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

