#include "pch.h"
#include "Renderable.h"

Renderable::Renderable(Entity* parent) :
    Component(parent),
    m_texture(nullptr),
    m_shader(nullptr)
{
    Game::getRenderSystem().RegisterEntity(this);
}

Renderable::Renderable(const std::string& texture, Entity* parent) :
    Component(parent),
    m_texture(new sf::Texture),
    m_shader(nullptr)
{
    if(!m_texture->loadFromFile(Utils::getResourcesPath() + texture))
    {
        std::cerr << "Failed to load texture" << std::endl;
        return;
    }
    m_texture->setSmooth(true);
    setVertices();
    Game::getRenderSystem().RegisterEntity(this);
}

Renderable::Renderable(const std::string& texture, const std::string& shader, Entity* parent) :
    Component(parent),
    m_texture(new sf::Texture),
    m_shader(new sf::Shader)
{
    if(!m_texture->loadFromFile(Utils::getResourcesPath() + texture))
    {
        std::cerr << "Failed to load texture" << std::endl;
        return;
    }
    if (!m_shader->loadFromFile(Utils::getResourcesPath() + shader, sf::Shader::Fragment))
    {
        std::cerr << "Failed to load shader" << std::endl;
        return;
    }
    m_texture->setSmooth(true);
    setVertices();
    Game::getRenderSystem().RegisterEntity(this);
}

Renderable::~Renderable()
{
    Game::getRenderSystem().UnregisterEntity(this);
    delete m_texture;
}


sf::Texture& Renderable::getTexture() const
{
    return *m_texture;
}

sf::VertexArray& Renderable::getVertexArray()
{
    return m_vertices;
}

sf::Shader& Renderable::getShader() const
{
    return *m_shader;
}


void Renderable::setVertices()
{
    m_vertices = sf::VertexArray(sf::Triangles, 6);
    
    m_vertices[0].position = sf::Vector2f(0, 0);
    m_vertices[1].position = sf::Vector2f(m_texture->getSize().x, 0);
    m_vertices[2].position = sf::Vector2f(0, m_texture->getSize().y);

    m_vertices[3].position = sf::Vector2f(m_texture->getSize().x, 0);
    m_vertices[4].position = sf::Vector2f(m_texture->getSize().x, m_texture->getSize().y);
    m_vertices[5].position = sf::Vector2f(0, m_texture->getSize().y);

    m_vertices[0].texCoords = sf::Vector2f(0, 0);
    m_vertices[1].texCoords = sf::Vector2f(m_texture->getSize().x, 0);
    m_vertices[2].texCoords = sf::Vector2f(0, m_texture->getSize().y);

    m_vertices[3].texCoords = sf::Vector2f(m_texture->getSize().x, 0);
    m_vertices[4].texCoords = sf::Vector2f(m_texture->getSize().x, m_texture->getSize().y);
    m_vertices[5].texCoords = sf::Vector2f(0, m_texture->getSize().y);
}



