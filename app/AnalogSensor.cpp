#include <AnalogSensor.hpp>
#include <numeric>
#include <vector>
#include <memory>

AnalogSensor::AnalogSensor(unsigned int samples)
    : mSamples(samples)
{
}

AnalogSensor::~AnalogSensor()
{
}

int AnalogSensor::Read()
{
    /* Instead of using old version pointers without deleting them, it is safer
       to use smart pointers */

    //std::vector<int> *readings = new std::vector<int>(mSamples, 10);

    std::unique_ptr<std::vector<int>> readings (new std::vector<int>(mSamples, 10));

    double result = std::accumulate( readings->begin(), readings->end(), 0.0 ) / readings->size();
    return result;
}
