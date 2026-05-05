#include "voo.hpp"
Voo::Voo(int codigo) {
    this->codigo = codigo;
    this->estadovoo = 0;
}
bool Voo::verificavooemplanejamento() {
    return this->estadovoo == 0;
}