
#include "uniformgenlc.h"


UniformGenLC::UniformGenLC(int seed)
{
    _seed = seed;
    _current = seed;
}


UniformGenLC::~UniformGenLC(void)
{
}

double UniformGenLC::NextDouble(void)
{
    _current = (A * (int)_current + C) % M; //WARNING: there is an overflow here, but it does not impact the result
    return _current / M ;
}
