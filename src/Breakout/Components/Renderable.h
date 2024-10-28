#pragma once

class Entity;

class Renderable : public Component
{
public:
    Renderable(Entity* parent);
    Renderable(const std::string& texture, Entity* parent);
    Renderable(const std::string& texture, const std::string& shader, Entity* parent);
    ~Renderable() override;

    sf::Texture& getTexture() const;
    sf::Shader& getShader() const;
    sf::VertexArray& getVertexArray();

private:
    void setVertices();
    //By default, we draw a plane made out of two triangles to display a simple sprite
protected:
    sf::VertexArray m_vertices;
    sf::Texture* m_texture;
    sf::Shader* m_shader;
};
