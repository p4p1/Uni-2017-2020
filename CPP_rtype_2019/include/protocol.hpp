/*
** EPITECH PROJECT, 2017
** protocol.hpp
** File description:
** <..>
*/

#ifndef PROTOCOL_HPP_
#define PROTOCOL_HPP_

namespace protocol {
    enum objType {
        PLAYER,
        BULLET
    };
    enum movement {
        NOTHING,
        DEAD,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    enum messageType {
        CONNECTION,
        MOVEMENT,
        ATTACK,
        UPDATE,
        ERROR
    };
    struct proto {
        enum messageType    type;
        enum objType        object;
        enum movement       mov;
        unsigned int        identifier;
        unsigned int        total_identifier;
        unsigned int        x;
        unsigned int        y;
    };
    class createProtocol {
        public:
            createProtocol();
            ~createProtocol();
            struct proto *createIdentifier(); // server
            struct proto *askIdentifier(); // client
            struct proto *shoot(struct proto *tmp); // client
            struct proto *hit(struct proto *tmp); // server
            struct proto *createBullet(struct proto *shooter); //server
            struct proto *updateInformation(struct proto *tmp); // server
            struct proto *updatePosition(struct proto *tmp,
                enum movement mov, enum objType type); // client
            bool compare(struct proto *p1, struct proto *p2);
            struct proto *setError(struct proto *tmp); // server
            void displayMessage(struct proto *msg) const;
        private:
            unsigned int            start_identifier;
    };
    const unsigned short    port = 5555;
    const unsigned int      buffer_size = sizeof(struct proto);
};

#endif
