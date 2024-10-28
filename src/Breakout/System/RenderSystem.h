#pragma once


class Renderable;

class RenderSystem
{
public:
    RenderSystem();
    ~RenderSystem();
    
    void Render() const;

    void RegisterEntity(Renderable* component);
    void UnregisterEntity(const Renderable* component);
    
private:
    std::vector<Renderable*> m_entities;
    sf::RenderTexture* m_renderTexture;

    sf::Shader* m_postProcess;
};
