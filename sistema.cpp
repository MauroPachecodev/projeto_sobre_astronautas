#include "sistema.hpp"
#include <iostream>
using namespace std; 
Astronauta* Sistema::buscarAstronauta(const string& cpf) {
    for (auto& a : listadeastronautas) {
        if (a.cpf == cpf) {
            return &a; 
        }
    }
    return nullptr; 
}

Voo* Sistema::buscarVoo(int codigo) {
    for (auto& v : listadevoos){
        if (v.codigo == codigo){
            return &v;
        }
    }
    return nullptr;
}

void Sistema::imprimirVoo(Voo &voo, string estado) {
    cout <<"voo de codigo: "<< voo.codigo << endl;
    cout << "voo em estado de: " << estado << endl;
    cout << "cpfs e nomes dos passageiros: " << endl;
    for (auto &j : voo.cpfarray) {
        Astronauta * astronauta = buscarAstronauta(j);
        cout << astronauta->cpf << " - " << astronauta->nome << endl;
    } 
    if (voo.cpfarray.empty()) {
        cout << "nenhum astronauta presente neste voo" << endl; 
    }
}

void Sistema::cadastrarastronauta(string& cpf, int idade, string& nome) {
    if (buscarAstronauta(cpf) != nullptr) {
        cout << "Erro: CPF " << cpf << " já cadastrado no sistema" << endl;
        return;
    }
    listadeastronautas.push_back(Astronauta(cpf, idade, nome));
}

void Sistema::cadastrarvoo(int codigo){
    if (buscarVoo(codigo) != nullptr) {
        cout << "Erro: código " << codigo << " já existente" << endl;
        return;
    }
    listadevoos.push_back(Voo(codigo));
}

void Sistema::astronautaparavoo(string& cpf, int codigo){
    Voo *vooEncontrado = buscarVoo(codigo);
    if(vooEncontrado == nullptr){
        cout << "erro, voo não encontrado" << endl;
        return;
    }
    if (!vooEncontrado->verificavooemplanejamento()){
        cout << "o voo já saiu da fase de planejamento" << endl;
        return;
    }
    Astronauta *astronautaEncontrado = buscarAstronauta(cpf);
    if (astronautaEncontrado == nullptr){
        cout << "astronauta não cadastrado" << endl;
        return;
    }
    if(!astronautaEncontrado->astrounautaestavivo()){
        cout << "o astronauta está morto" << endl;
        return;
    }
    for (const auto&i : vooEncontrado->cpfarray){
        if (i == cpf){
            cout << "astronauta já está presente neste voo" << endl;
            return;
        }
    }
    vooEncontrado->cpfarray.push_back(astronautaEncontrado->cpf);
}

void Sistema::removeastronautadevoo(string& cpf, int codigo){
    Voo * vooAlvo = buscarVoo(codigo);
    if (vooAlvo == nullptr){
        cout << "voo não cadastrado" << endl;
        return;
    }
    if (!vooAlvo->verificavooemplanejamento()){
        cout << "voo não está planejado" << endl;
        return;
    }
    Astronauta * astronautaAlvo = buscarAstronauta(cpf);
    if (astronautaAlvo == nullptr){
        cout << "astronauta não cadastrado" << endl;
        return;
    }
    for (auto i = vooAlvo->cpfarray.begin(); i != vooAlvo->cpfarray.end(); ++i) {
        if (*i == cpf) {
            vooAlvo->cpfarray.erase(i);
            cout << "Astronauta removido do voo." << endl;
            return;
        }
    }
    cout << "Astronauta nao encontrado neste voo." << endl;
}

void Sistema::lancarvoo(int codigo){
    Voo *vooAlvo = buscarVoo(codigo);
    if (vooAlvo == nullptr){
        cout << "voo não está cadastrado" << endl;
        return;
    }
    if(!vooAlvo->verificavooemplanejamento()){
        cout << "voo não planejado" << endl;
        return;
    }
    if (vooAlvo->cpfarray.size() <= 0){
        cout << "voo sem astronautas, erro no lançamento" << endl;
        return;
    }
    for(auto &i : vooAlvo->cpfarray){
        Astronauta * astronauta = buscarAstronauta(i);
        if (astronauta == nullptr || astronauta->vivo == false || astronauta->disponivel == false){
            cout << "astronauta não está vivo ou não está disponível" << endl;
            return;
        }  
    }
    for(auto &i : vooAlvo->cpfarray){
        Astronauta * astronauta = buscarAstronauta(i);
        astronauta->disponivel = false;
    }
    vooAlvo->estadovoo = 1;
}

void Sistema::explodirvoo(int codigo){
    Voo *vooAlvo = buscarVoo(codigo);
    if (vooAlvo == nullptr) {
        cout << "voo não cadastrado" << endl;
        return;
    }
    if (vooAlvo->estadovoo != 1){
        cout << "erro! voo não está em curso" << endl;
        return;
    }
    vooAlvo->estadovoo = 3;
    for (auto &i : vooAlvo->cpfarray){
            Astronauta * astronauta = buscarAstronauta(i);
            astronauta->vivo = false;
            astronauta->disponivel = false;
    }
}

void Sistema::finalizarvoo(int codigo){
    Voo *vooAlvo = buscarVoo(codigo);
    if (vooAlvo == nullptr){
        cout << "Erro: Voo nao encontrado." << endl;
        return;
    }
    if (vooAlvo->estadovoo != 1){
        cout << "voo não está em curso" << endl;
        return;
    }
    vooAlvo->estadovoo = 2;
    for (auto &i : vooAlvo->cpfarray){
        Astronauta * astronauta = buscarAstronauta(i);
        astronauta->disponivel = true;
    }
}

void Sistema::listarvoos() {
    bool temvoo = false;
    for (Voo &i : listadevoos) {
        if (i.estadovoo == 0) {
            imprimirVoo(i, "planejamento");
            temvoo = true;
        }
    }
    for (Voo &i : listadevoos) {
        if (i.estadovoo == 1) {
            imprimirVoo(i, "em curso");
            temvoo = true;
        }
    }
    for (Voo &i : listadevoos) {
        if (i.estadovoo == 2) {
            imprimirVoo(i, "finalizado com sucesso");
            temvoo = true;
        }
    }
    for (Voo &i : listadevoos) {
        if (i.estadovoo == 3) {
            imprimirVoo(i, "finalizado com explosão");
            temvoo = true;
        }
    }
    if (!temvoo){
        cout << "sem voos cadastrados" << endl;
    }
}

void Sistema::listarmortos() {
    bool temmorto = false;
    for (auto &i : listadeastronautas) {
        if (i.vivo == false){
            temmorto = true;
            cout << i.cpf << " - " << i.nome << endl;
            cout << "voos que participou" << endl;
            for (auto &j : listadevoos) {
                for (auto &k : j.cpfarray) {
                    if (k == i.cpf) {
                        cout << j.codigo << endl;
                    }
                }
            }         
        }
    }
    if (!temmorto){
        cout << "não tem mortos no momento" << endl;
    }
}