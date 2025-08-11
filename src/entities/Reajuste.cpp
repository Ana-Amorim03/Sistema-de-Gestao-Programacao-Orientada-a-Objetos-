#include "Reajuste.h"

Reajuste::Reajuste(Data &data_ocorrencia, const float &reajuste)
    : reajuste_(reajuste), data_ocorrencia_(data_ocorrencia) {}

Data Reajuste::getDataOcorrencia() const { return data_ocorrencia_; }

float Reajuste::getReajuste() const { return reajuste_; }

Reajuste::~Reajuste()
{
  //delete data_ocorrencia_;
}