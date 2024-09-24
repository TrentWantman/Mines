#ifndef TEXTURE_H
#define TEXTURE_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class Texture {
public:
    static sf::Texture& GetTexture(const std::string& filename);

private:
    static std::map<std::string, sf::Texture> textures;
};

#endif // TEXTURE_H
