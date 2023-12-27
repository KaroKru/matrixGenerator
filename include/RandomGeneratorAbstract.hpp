#ifndef RANDOMGENERATORABSTRACT_HPP
#define RANDOMGENERATORABSTRACT_HPP

class RandomGeneratorAbstract
{
    public:
    RandomGeneratorAbstract() = default;
    virtual ~RandomGeneratorAbstract() = default;

    virtual void initialValues(int minimum, int maximum) = 0;
    virtual int randomNumber() = 0;

    protected:
    unsigned int maximumValue{0};
    unsigned int minimumValue{0};
};

#endif