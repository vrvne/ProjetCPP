#ifndef UNIFORMGEN_H
#define UNIFORMGEN_H


class UniformGen
{
public:
    UniformGen(void);
    virtual ~UniformGen(void);

    virtual double NextDouble()=0;
};



#endif // UNIFORMGEN
