#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <string>
#include "ObjectContainer.hpp"

#include "Network.hpp"

const std::string pathToImage = "./res/sprites/background.jpg";
const std::string pathToPlayer = "./res/sprites/ship.png";

class SFML
{
    public:
        SFML(char *);
        ~SFML() = default;
        void draw();
        void parseProto(struct protocol::proto *pnt);
        typedef struct gameObject
        {
            protocol::proto *proto;
            sf::Texture t;
            sf::Sprite  sp;
        } GameObject;

    private:
        sf::RenderWindow *window;
        char                *_addr;
        unsigned int        my_id;
        sf::Sprite        backgroundSprite;
        sf::Texture       backgroundTexture;
        std::vector<GameObject *> go;
        Network             *n;
        Client *c;
        protocol::createProtocol    *pro;
        struct protocol::proto      *point;
};

#endif
