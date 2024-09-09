#include "Texture.h"

std::map<std::string, sf::Texture> Texture::textures;

sf::Texture& Texture::GetTexture(const std::string& filename) {
    if (textures.find(filename) == textures.end()) {
        textures[filename].loadFromFile("./textures/" + filename + ".png");
    }
    return textures[filename];
}
