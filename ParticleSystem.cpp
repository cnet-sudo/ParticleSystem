

#include "ParticleSystem.h"

// Конструктор
ParticleSystem::ParticleSystem() {
    vertices.setPrimitiveType(sf::PrimitiveType::Points);
}


void ParticleSystem::addParticle(sf::Vector2f position, sf::Vector2f velocity, sf::Color color) {
    Particle particle;
    particle.position = position;
    particle.velocity = velocity;
    particle.color = color;

    particles.push_back(particle);

    sf::Vertex vertex;
    vertex.position = position;
    vertex.color = color;
    vertices.append(vertex);
}


void ParticleSystem::update(sf::Time elapsed, sf::RenderWindow& window) {

    std::vector<Particle> updatedParticles;
    sf::VertexArray updatedVertices(sf::PrimitiveType::Points);

    for (std::size_t i = 0; i < particles.size(); ++i) {
        Particle& particle = particles[i];
        particle.position += particle.velocity * elapsed.asSeconds();

        if (particle.position.x >= 0 && particle.position.x <= window.getSize().x &&
            particle.position.y >= 0 && particle.position.y <= window.getSize().y) {
            updatedParticles.push_back(particle);

            sf::Vertex vertex;
            vertex.position = particle.position;
            vertex.color = particle.color;
            updatedVertices.append(vertex);
        }
    }

    particles = std::move(updatedParticles);
    vertices = std::move(updatedVertices);
}

void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(vertices, states);
}
