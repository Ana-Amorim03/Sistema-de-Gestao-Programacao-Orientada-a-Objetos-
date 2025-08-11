#ifndef REAJUSTE_H
#define REAJUSTE_H
#include "Data.h"
class Reajuste
{
public:
    Reajuste(Data &data_ocorrencia, const float &reajuste);
    Data getDataOcorrencia() const;
    float getReajuste() const;
    ~Reajuste();

private:
    float reajuste_;
    Data data_ocorrencia_;
};
#endif // REAJUSTE_H