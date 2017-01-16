#ifndef LYENGINE_VECTOR_H
#define LYENGINE_VECTOR_H

namespace ly {

class Vector {
public:
    float x;
    float y;
    float z;

    Vector();

    Vector(float x, float y);

    Vector(float x, float y, float z);


};

}


#endif //LYENGINE_VECTOR_H
