#include "sistema.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Sistema sistema; 
    string comando;

    while (cin >> comando) {
        if (comando == "FIM") {
            break;
        }

        else if (comando == "CADASTRAR_ASTRONAUTA") {
            string cpf, nome;
            int idade;
            cin >> cpf >> idade;
            getline(cin >> ws, nome);
            if(sistema.cadastrarastronauta(cpf, idade, nome)) {
                cout << "Astronauta cadastrado com sucesso." << endl;
            }
        }

        else if (comando == "CADASTRAR_VOO") {
            int codigo;
            cin >> codigo;
            if(sistema.cadastrarvoo(codigo)) {
                cout << "Voo cadastrado com sucesso." << endl;
            }
        }

        else if (comando == "ADICIONAR_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            if(sistema.astronautaparavoo(cpf, codigo)) {
                cout << "Astronauta adicionado ao voo " << codigo << " com sucesso." << endl;
            }
        }

        else if (comando == "REMOVER_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            if(sistema.removeastronautadevoo(cpf, codigo)) {
                cout << "Astronauta removido do voo " << codigo << " com sucesso." << endl;
            }
        }

        else if (comando == "LANCAR_VOO") {
            int codigo;
            cin >> codigo;
            if(sistema.lancarvoo(codigo)) {
                cout << "Voo " << codigo << " lancado com sucesso! Boa sorte aos astronautas." << endl;
            }
        }

        else if (comando == "EXPLODIR_VOO") {
            int codigo;
            cin >> codigo;
            if(sistema.explodirvoo(codigo)) {
                cout << "Voo " << codigo << " encerrado com uma explosao catastrofica." << endl;
            }
        }

        else if (comando == "FINALIZAR_VOO") {
            int codigo;
            cin >> codigo;
            if(sistema.finalizarvoo(codigo)) {
                cout << "Voo " << codigo << " finalizado com sucesso. Astronautas retornaram em seguranca." << endl;
            }
        }

        else if (comando == "LISTAR_VOOS") {
            sistema.listarvoos();
        }

        else if (comando == "LISTAR_MORTOS") {
            sistema.listarmortos();
        }
        else {
            cout << "Comando nao reconhecido." << endl;
        }
    }

    return 0;
}