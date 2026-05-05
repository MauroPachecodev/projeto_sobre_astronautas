#pragma once
#include <string>

class Astronauta {
public:
    std::string cpf;
    std::string nome;
    int idade;
    bool vivo;
    bool disponivel;
    Astronauta(std::string &cpf, int idade, std::string& nome);
    bool astrounautaestavivo();
};