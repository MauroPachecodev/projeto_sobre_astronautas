#include <bits/stdc++.h>
using namespace std;
class Astronauta{
    public:
    string cpf;
    string nome;
    int idade;
    bool vivo;
    bool disponivel;
    Astronauta(string &cpf, int idade, string& nome){
        this->cpf = cpf;
        this->idade = idade;
        this->nome = nome;
        this->vivo = true;
        this->disponivel = true;
    }
    bool astrounautaestavivo(){
        return this->vivo;
    }
};
class Voo{
    public:
    int codigo;
    vector<string> cpfarray;
    int estadovoo;
    Voo(int codigo){
        this->codigo = codigo;
        this->estadovoo = 0;
    }
    bool verificavooemplanejamento(){
        return this->estadovoo == 0;
    }
};
class Sistema{
    public:
    vector<Astronauta> listadeastronautas;
    vector<Voo> listadevoos;
    Astronauta* buscarAstronauta(const string& cpf) {
        for (auto& a : listadeastronautas) {
            if (a.cpf == cpf) {
                return &a; 
            }
        }
            return nullptr; 
        }
    Voo* buscarVoo(int codigo) {
        for (auto& v : listadevoos){
            if (v.codigo == codigo){
                return &v;
            }
        }
        return nullptr;
    }
    void cadastrarastronauta(string& cpf, int idade, string& nome){
    if (buscarAstronauta(cpf) != nullptr) {
            cout << "Erro: CPF " << cpf << " já cadastrado no sistema" << endl;
            return;
        }
        listadeastronautas.push_back(Astronauta(cpf, idade, nome));
    }
    void cadastrarvoo(int codigo){
    if (buscarVoo(codigo) != nullptr) {
            cout << "Erro: código " << codigo << " já existente" << endl;
            return;
        }
        listadevoos.push_back(Voo(codigo));
    }
    void astronautaparavoo(string& cpf, int codigo){
        Voo *vooEncontrado = buscarVoo(codigo);
        if(vooEncontrado == nullptr){
            cout << "erro, voo não encontrado" << endl;
            return;
        }
        if (!vooEncontrado->verificavooemplanejamento()){
            cout << "o voo já sai da fase de planejamento" << endl;
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
    void removeastronautadevoo(string& cpf, int codigo){
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
    void lancarvoo(int codigo){
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
    void explodirvoo(int codigo){
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
    void finalizarvoo(int codigo){
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
    void listarvoos(){
        for(Voo &i : listadevoos){
            if (i.estadovoo == 0){
                cout <<"voo de codigo: "<< i.codigo << endl;
                cout << "voo em estado de: planejamento " << endl;
                cout << "cpfs e nomes dos passageiros: " << endl;
                for (auto &j : i.cpfarray){
                    Astronauta * astronauta = buscarAstronauta(j);
                    cout << astronauta->cpf << endl;
                    cout << astronauta->nome << endl;
                }
            }
        }
        for(Voo &i : listadevoos){
            if (i.estadovoo == 1){
                cout <<"voo de codigo: "<< i.codigo << endl;
                cout << "voo em estado de: em curso" << endl;
                cout << "cpfs e nomes dos passageiros: " << endl;
                for (auto &j : i.cpfarray){
                    Astronauta * astronauta = buscarAstronauta(j);
                    cout << astronauta->cpf << endl;
                    cout << astronauta->nome << endl;
                }
            }
        }
        for(Voo &i : listadevoos){
            if (i.estadovoo == 2){
                cout <<"voo de codigo: "<< i.codigo << endl;
                cout << "voo em estado de: finalizado com sucesso " << endl;
                cout << "cpfs e nomes dos passageiros: " << endl;
                for (auto &j : i.cpfarray){
                    Astronauta * astronauta = buscarAstronauta(j);
                    cout << astronauta->cpf << endl;
                    cout << astronauta->nome << endl;
                }
            }
        }
        for(Voo &i : listadevoos){
            if (i.estadovoo == 3){
                cout <<"voo de codigo: "<< i.codigo << endl;
                cout << "voo em estado de: finalizado com explosão" << endl;
                cout << "cpfs e nomes dos passageiros: " << endl;
                for (auto &j : i.cpfarray){
                    Astronauta * astronauta = buscarAstronauta(j);
                    cout << astronauta->cpf << endl;
                    cout << astronauta->nome << endl;
                }
            }
        }
    }
    void listarmortos(){
        for (auto &i : listadeastronautas){
            if (i.vivo == false){
                cout << i.cpf << endl;
                cout << i.nome << endl;
                cout << "voos que participou" << endl;
                for (auto &j : listadevoos)
                {
                    for (auto &k : j.cpfarray)
                    {
                        if(k == i.cpf){
                            cout << j.codigo << endl;
                        }
                    }
                }         
            }
        }
    }
};
int main(){
    Sistema sistema; 
    string comando;
    while (cin >> comando) {
        if (comando == "FIM") {
        break;
        }
    if (comando == "CADASTRAR_ASTRONAUTA") {
        string cpf, nome;
        int idade;
        cin >> cpf >> idade;
        getline(cin >> ws, nome);
        sistema.cadastrarastronauta(cpf, idade, nome);
    }
    if (comando == "CADASTRAR_VOO"){
        int codigo;
        cin >> codigo;
        sistema.cadastrarvoo(codigo);
    }
    if (comando == "ADICIONAR_ASTRONAUTA"){
        string cpf;
        int codigo;
        cin >> cpf;
        cin >> codigo;
        sistema.astronautaparavoo(cpf, codigo);
    }
    if (comando == "REMOVER_ASTRONAUTA"){
        string cpf;
        int codigo;
        cin >> cpf;
        cin >> codigo;
        sistema.removeastronautadevoo(cpf, codigo);
    }
    if (comando == "LANCAR_VOO"){
        int codigo;
        cin >> codigo;
        sistema.lancarvoo(codigo);
    }
    if(comando == "EXPLODIR_VOO"){
        int codigo;
        cin >> codigo;
        sistema.explodirvoo(codigo);
    }
    if (comando == "FINALIZAR_VOO"){
        int codigo;
        cin >> codigo;
        sistema.finalizarvoo(codigo);
    }
    if (comando == "LISTAR_VOOS"){
        sistema.listarvoos();
    }
    if (comando == "LISTAR_MORTOS"){
        sistema.listarmortos();
    }
}
    return 0;
}