/*
** EPITECH PROJECT, 2018
** SFML.cpp
** File description:
** <..>
*/

#include "SFML.hpp"

SFML::SFML(char *addr)
    : window(new sf::RenderWindow(sf::VideoMode(800, 600), "R_TYPE")), _addr(addr)
{
    backgroundTexture.loadFromFile(pathToImage);
    backgroundSprite.setTexture(backgroundTexture);
    c = new Client(_addr, 1234);
    pro = new protocol::createProtocol();
    n = new Network(c, pro);
    usleep(1000000);
    point = pro->askIdentifier();
    c->send(point);
    c->recvmsg();
    pro->displayMessage(c->getProto());
}

void SFML::parseProto(struct protocol::proto *pnt)
{
    gameObject  *tmp = nullptr;

    if (pnt->type == protocol::CONNECTION) {
        tmp = new gameObject;
        my_id = pnt->identifier;
        tmp->proto = pnt;
        tmp->t.loadFromFile(pathToPlayer);
        tmp->sp.setTexture(tmp->t);
        go.push_back(tmp);
    } else if (pnt->type == protocol::MOVEMENT) {
        for (auto it = go.begin();it != go.end();it++){
            if ((*it)->proto->identifier == pnt->identifier) {
                (*it)->sp.setPosition(pnt->x, pnt->y);
            }
        }
    }
    //pro->displayMessage(c->getProto());
}

void SFML::draw()
{
    while (window->isOpen()){
        window->clear();
        window->draw(backgroundSprite);
        for (auto it = go.begin();it != go.end();it++){
            window->draw((*it)->sp);
        }
        window->display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            n->move_up(point);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            n->move_down(point);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            n->move_right(point);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            n->move_left(point);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            n->shoot(point);
        }
        usleep(100000);
        c->recvmsg();
        parseProto(c->getProto());
    }
}
