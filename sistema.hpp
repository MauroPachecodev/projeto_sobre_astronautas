#pragma once
#include <vector>
#include <string>
#include "astronauta.hpp"
#include "voo.hpp"
class Sistema {
public:
    std::vector<Astronauta> listadeastronautas;
    std::vector<Voo> listadevoos;
    Astronauta* buscarAstronauta(const std::string& cpf);
    Voo* buscarVoo(int codigo);
    void imprimirVoo(Voo &voo, std::string estado);
    bool cadastrarastronauta(std::string& cpf, int idade, std::string& nome);
    bool cadastrarvoo(int codigo);
    bool astronautaparavoo(std::string& cpf, int codigo);
    bool removeastronautadevoo(std::string& cpf, int codigo);
    bool lancarvoo(int codigo);
    bool explodirvoo(int codigo);
    bool finalizarvoo(int codigo);
    void listarvoos();
    void listarmortos();
};