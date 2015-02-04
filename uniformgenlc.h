#ifndef UNIFORMGENLC_H
#define UNIFORMGENLC_H


#include "uniformgen.h"

class UniformGenLC :
    public UniformGen
{
public:
    UniformGenLC(int);
    ~UniformGenLC(void);

    double NextDouble(void);

private :
    int _seed;
    double _current; //WARNING: current must be double because of euclidean divisions

    static const int A = 1103515245;
    static const int C = 12345;
    static const unsigned int M = 2147483648;
};

#endif // UNIFORMGENLC
