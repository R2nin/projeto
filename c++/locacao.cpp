#include <iostream>
#include <string>

// Classe Especialidade
class Especialidade {
private:
    std::string nome;

public:
    Especialidade() {}
    Especialidade(std::string nome) : nome(nome) {}

    std::string getNome() const { return nome; }
    void setNome(std::string novoNome) { nome = novoNome; }

    void imprimir() {
        std::cout << "Especialidade: " << nome << std::endl;
    }

    void ler() {
        std::cout << "Digite o nome da especialidade: ";
        std::cin >> nome;
    }
};

// Classe Profissional (Generalização)
class Profissional {
protected:
    std::string nome;

public:
    Profissional() {}
    Profissional(std::string nome) : nome(nome) {}

    std::string getNome() const { return nome; }
    void setNome(std::string novoNome) { nome = novoNome; }

    virtual void imprimir() {
        std::cout << "Nome do Profissional: " << nome << std::endl;
    }

    virtual void ler() {
        std::cout << "Digite o nome do profissional: ";
        std::cin >> nome;
    }
};

// Classe Servico
class Servico {
private:
    std::string descricao;
    Profissional* profissional;

public:
    Servico() {}
    Servico(std::string descricao, Profissional* profissional) : descricao(descricao), profissional(profissional) {}

    void imprimir() {
        std::cout << "Descrição do Serviço: " << descricao << std::endl;
        profissional->imprimir();
    }

    void ler() {
        std::cout << "Digite a descrição do serviço: ";
        std::cin >> descricao;
    }
};

// Classe Tarefa
class Tarefa {
private:
    std::string descricao;

public:
    Tarefa() {}
    Tarefa(std::string descricao) : descricao(descricao) {}

    void imprimir() {
        std::cout << "Descrição da Tarefa: " << descricao << std::endl;
    }

    void ler() {
        std::cout << "Digite a descrição da tarefa: ";
        std::cin >> descricao;
    }
};

// Classe TipoTarefa (Generalização)
class TipoTarefa : public Tarefa {
private:
    std::string tipo;

public:
    TipoTarefa() {}
    TipoTarefa(std::string descricao, std::string tipo) : Tarefa(descricao), tipo(tipo) {}

    void imprimir() {
        Tarefa::imprimir();
        std::cout << "Tipo da Tarefa: " << tipo << std::endl;
    }

    void ler() {
        Tarefa::ler();
        std::cout << "Digite o tipo da tarefa: ";
        std::cin >> tipo;
    }
};

int main() {
    Especialidade especialidade;
    especialidade.ler();
    especialidade.imprimir();

    Profissional profissional;
    profissional.ler();
    profissional.imprimir();

    Servico servico;
    servico.ler();
    servico.imprimir();

    Tarefa tarefa;
    tarefa.ler();
    tarefa.imprimir();

    TipoTarefa tipoTarefa;
    tipoTarefa.ler();
    tipoTarefa.imprimir();

    return 0;
}