#pragma once
#include <vector>
#include <string>
class Voo {
public:
    int codigo;
    std::vector<std::string> cpfarray;
    int estadovoo;

    Voo(int codigo);
    bool verificavooemplanejamento();
};