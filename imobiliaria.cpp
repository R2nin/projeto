#include <iostream>
#include <string>

// Classe Imovel
class Imovel {
protected:
    std::string endereco;

public:
    Imovel() {}
    Imovel(std::string endereco) : endereco(endereco) {}

    std::string getEndereco() const { return endereco; }
    void setEndereco(std::string novoEndereco) { endereco = novoEndereco; }

    virtual void imprimir() {
        std::cout << "Endereço do Imóvel: " << endereco << std::endl;
    }

    virtual void ler() {
        std::cout << "Digite o endereço do imóvel: ";
        std::cin >> endereco;
    }
};

// Classe Locador
class Locador {
private:
    std::string nome;

public:
    Locador() {}
    Locador(std::string nome) : nome(nome) {}

    std::string getNome() const { return nome; }
    void setNome(std::string novoNome) { nome = novoNome; }

    void imprimir() {
        std::cout << "Nome do Locador: " << nome << std::endl;
    }

    void ler() {
        std::cout << "Digite o nome do locador: ";
        std::cin >> nome;
    }
};

// Classe Profissao
class Profissao {
private:
    std::string nome;

public:
    Profissao() {}
    Profissao(std::string nome) : nome(nome) {}

    std::string getNome() const { return nome; }
    void setNome(std::string novoNome) { nome = novoNome; }

    void imprimir() {
        std::cout << "Profissão: " << nome << std::endl;
    }

    void ler() {
        std::cout << "Digite a profissão: ";
        std::cin >> nome;
    }
};

// Classe TipoImovel
class TipoImovel {
private:
    std::string tipo;

public:
    TipoImovel() {}
    TipoImovel(std::string tipo) : tipo(tipo) {}

    std::string getTipo() const { return tipo; }
    void setTipo(std::string novoTipo) { tipo = novoTipo; }

    void imprimir() {
        std::cout << "Tipo de Imóvel: " << tipo << std::endl;
    }

    void ler() {
        std::cout << "Digite o tipo de imóvel: ";
        std::cin >> tipo;
    }
};

// Classe Locacao
class Locacao {
private:
    double valor;

public:
    Locacao() : valor(0) {}
    Locacao(double valor) : valor(valor) {}

    double getValor() const { return valor; }
    void setValor(double novoValor) { valor = novoValor; }

    void imprimir() {
        std::cout << "Valor da Locação: " << valor << std::endl;
    }

    void ler() {
        std::cout << "Digite o valor da locação: ";
        std::cin >> valor;
    }

    virtual void aumentarValor() {
        valor *= 1.1; // Aumenta em 10%
    }

    virtual void aumentarValor(double percentual) {
        valor *= (1 + percentual/100);
    }
};

int main() {
    Imovel imovel;
    imovel.ler();
    imovel.imprimir();

    Locador locador;
    locador.ler();
    locador.imprimir();

    Profissao profissao;
    profissao.ler();
    profissao.imprimir();

    TipoImovel tipoImovel;
    tipoImovel.ler();
    tipoImovel.imprimir();

    Locacao locacao;
    locacao.ler();
    locacao.imprimir();

    locacao.aumentarValor();
    locacao.imprimir();

    locacao.aumentarValor(20); // Aumenta em 20%
    locacao.imprimir();

    return 0;
}