#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> candidatos;
    std::vector<int> votos(8, 0); // Initialize votes vector with 0 for each candidate, null votes and blank votes

    // Read candidate names
    for (int i = 0; i < 7; i++) {
        std::string nome;
        std::cout << "Digite o nome do candidato " << i+1 << ": ";
        std::cin >> nome;
        candidatos.push_back(nome);
    }

    int voto;
    while (true) {
        std::cout << "Digite o codigo do voto (ou 0 para encerrar): ";
        std::cin >> voto;

        if (voto == 0) {
            break;
        }

        if (voto >= 1 && voto <= 7) {
            votos[voto-1]++; // Increment vote count for the respective candidate
        } else if (voto == 8) {
            votos[7]++; // Increment null votes count
        } else if (voto == 9) {
            votos[8]++; // Increment blank votes count
        } else {
            std::cout << "Codigo de voto invalido." << std::endl;
        }
    }

    // Find the candidate with the most votes
    int maxVotes = votos[0];
    int indiceVencedor = 0;

    for (int i = 1; i < 7; i++) {
        if (votos[i] > maxVotes) {
            maxVotes = votos[i];
            indiceVencedor = i;
        }
    }

    // Print the total number of votes for each candidate, null votes, blank votes and the winner's name
    std::cout << "Resultados da eleicao:" << std::endl;
    for (int i = 0; i < 7; i++) {
        std::cout << "Candidato " << candidatos[i] << ": " << votos[i] << " votos" << std::endl;
    }
    std::cout << "Votos nulos: " << votos[7] << std::endl;
    std::cout << "Votos em branco: " << votos[8] << std::endl;
    std::cout << "Candidato vencedor: " << candidatos[indiceVencedor] << std::endl;

    return 0;
}
