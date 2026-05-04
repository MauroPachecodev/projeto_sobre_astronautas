#include "sistemadeastronauta.h"
using namespace std;
int main(){
    Sistema sistema; 
    string comando;
    while (cin >> comando) {
        bool comandoReconhecido = false;
        if (comando == "FIM") {
            break;
        }

        if (comando == "CADASTRAR_ASTRONAUTA") {
            string cpf, nome;
            int idade;
            cin >> cpf >> idade;
            getline(cin >> ws, nome);
            sistema.cadastrarastronauta(cpf, idade, nome);
            comandoReconhecido = true;
            cout << "Astronauta cadastrado com sucesso." << endl;
        }

        if (comando == "CADASTRAR_VOO") {
            int codigo;
            cin >> codigo;
            sistema.cadastrarvoo(codigo);
            comandoReconhecido = true;
        }

        if (comando == "ADICIONAR_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf;
            cin >> codigo;
            sistema.astronautaparavoo(cpf, codigo);
            comandoReconhecido = true;
        }

        if (comando == "REMOVER_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf;
            cin >> codigo;
            sistema.removeastronautadevoo(cpf, codigo);
            comandoReconhecido = true;
        }

        if (comando == "LANCAR_VOO") {
            int codigo;
            cin >> codigo;
            sistema.lancarvoo(codigo);
            comandoReconhecido = true;
        }

        if(comando == "EXPLODIR_VOO") {
            int codigo;
            cin >> codigo;
            sistema.explodirvoo(codigo);
            comandoReconhecido = true;
        }

        if (comando == "FINALIZAR_VOO") {
            int codigo;
            cin >> codigo;
            sistema.finalizarvoo(codigo);
            comandoReconhecido = true;
        }

        if (comando == "LISTAR_VOOS") {
            sistema.listarvoos();
            comandoReconhecido = true;
        }

        if (comando == "LISTAR_MORTOS") {
            sistema.listarmortos();
            comandoReconhecido = true;
        }

        if (!comandoReconhecido) {
            cout << "Comando não reconhecido." << endl;
        }
    }
    return 0;
}