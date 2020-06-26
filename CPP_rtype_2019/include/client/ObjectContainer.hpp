#ifndef OBJECTCONTAINER_HPP_
#define OBJECTCONTAINER_HPP_

#include "protocol.hpp"

class ObjectContainer
{
public:

    ObjectContainer(protocol::objType ot, protocol::movement m, unsigned int id, unsigned int x, unsigned int y) : _ot(ot), _direction(m), _id(id), _x(x), _y(y) {}
    ObjectContainer(protocol::proto p) : _ot(p.object), _direction(p.mov), _id(p.identifier), _x(p.x), _y(p.y) {}
    ~ObjectContainer() = default;
    
    protocol::objType getObjType(void) { return _ot; }
    protocol::movement getDirection(void) { return _direction; }
    unsigned int getId(void) { return _id; }
    unsigned int getXAxis(void) { return _x; }
    unsigned int getYAxis(void) { return _y; }

    void        setXAxis(unsigned int x) { _x = x; }
    void        setYAxis(unsigned int y) { _y = y; }

private:

    protocol::objType  _ot;
    protocol::movement _direction;
    unsigned int       _id;
    unsigned int       _x;
    unsigned int       _y;
  
};

#endif