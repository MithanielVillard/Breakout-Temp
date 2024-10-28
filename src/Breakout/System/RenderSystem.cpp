#include "pch.h"

RenderSystem::RenderSystem() : m_renderTexture(new sf::RenderTexture), m_postProcess(new sf::Shader)
{
    if (!m_renderTexture->create(WINDOW_WIDTH, WINDOW_HEIGHT))
    {
        std::cerr << "Failed to create render texture" << std::endl;
        return;
    }

    if (!m_postProcess->loadFromFile(Utils::getResourcesPath() + "/Shaders/PostProcess.frag", sf::Shader::Fragment))
    {
        std::cerr << "Failed to load post process shader" << std::endl;
    }
}

RenderSystem::~RenderSystem()
{
    delete m_renderTexture;
}


void RenderSystem::RegisterEntity(Renderable* entity)
{
    if (entity == nullptr) return;
    m_entities.push_back(entity);
}

void RenderSystem::UnregisterEntity(const Renderable* entity)
{
    if (entity == nullptr) return;
    auto it = std::find(m_entities.begin(), m_entities.end(), entity);
    m_entities.erase(it);
}

void RenderSystem::Render() const
{
    m_renderTexture->clear(sf::Color(72,72,72,255));
    for(Renderable* component : m_entities)
    {
        sf::RenderStates state = sf::RenderStates::Default;
        state.transform *= component->getEntity()->getTransform();
        state.texture = &component->getTexture();
        sf::Shader& shader = component->getShader();
        shader.setUniform("texture", sf::Shader::CurrentTexture);
        shader.setUniform("resolution", sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
        shader.setUniform("blur_radius", 10.0f);
        state.shader = &shader;
        m_renderTexture->draw(component->getVertexArray(), state);
    }
    m_renderTexture->display();

    m_postProcess->setUniform("screen_texture", sf::Shader::CurrentTexture);
    Game::getWindow().draw(sf::Sprite(m_renderTexture->getTexture()), m_postProcess);
}


