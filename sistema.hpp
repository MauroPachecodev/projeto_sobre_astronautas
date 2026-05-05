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
    void cadastrarastronauta(std::string& cpf, int idade, std::string& nome);
    void cadastrarvoo(int codigo);
    void astronautaparavoo(std::string& cpf, int codigo);
    void removeastronautadevoo(std::string& cpf, int codigo);
    void lancarvoo(int codigo);
    void explodirvoo(int codigo);
    void finalizarvoo(int codigo);
    void listarvoos();
    void listarmortos();
};