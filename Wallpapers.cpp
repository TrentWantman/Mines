#include "Wallpapers.h"

#include "Texture.h"

Wallpapers::Wallpapers() {
    phoneAFriendWallPaper.setTexture(Texture::GetTexture("phoneAFriend"));
    phoneAFriendWallPaper.setPosition(450,0);
}

