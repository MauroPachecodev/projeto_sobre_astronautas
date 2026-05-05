#include "astronauta.hpp"
Astronauta::Astronauta(std::string &cpf, int idade, std::string& nome) {
    this->cpf = cpf;
    this->idade = idade;
    this->nome = nome;
    this->vivo = true;
    this->disponivel = true;
}
bool Astronauta::astrounautaestavivo() {
    return this->vivo;
}