<<<<<<<<<<<<<<  ✨ Codeium Command 🌟 >>>>>>>>>>>>>>>>
#include <iostream>
#include <fstream>
#include <string>
+#include <stdexcept>

struct Registro {
    int codigo;
    std::string nome;
    std::string endereco;
    std::string cidade;
    std::string uf;
};

void lerRegistro(std::ifstream& arquivo, Registro& reg) {
+    if (!arquivo.good() || !arquivo.is_open()) {
+        throw std::runtime_error("Erro ao ler do arquivo.");
+    }
+
    arquivo >> reg.codigo;
+    if (!arquivo.good()) {
+        throw std::runtime_error("Erro ao ler o código.");
+    }
+
    arquivo.ignore(); // Para consumir o caractere de separação
    std::getline(arquivo, reg.nome, ',');
+    if (!arquivo.good()) {
+        throw std::runtime_error("Erro ao ler o nome.");
+    }
+
    std::getline(arquivo, reg.endereco, ',');
+    if (!arquivo.good()) {
+        throw std::runtime_error("Erro ao ler o endereço.");
+    }
+
    std::getline(arquivo, reg.cidade, ',');
+    if (!arquivo.good()) {
+        throw std::runtime_error("Erro ao ler a cidade.");
+    }
+
    std::getline(arquivo, reg.uf);
+    if (!arquivo.good()) {
+        throw std::runtime_error("Erro ao ler o UF.");
+    }
}

void percorrerRegistros(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
+        throw std::runtime_error("Erro ao abrir o arquivo.");
-        std::cerr << "Erro ao abrir o arquivo." << std::endl;
-        return;
    }

    Registro reg;
    while (!arquivo.eof()) {
+        try {
+            lerRegistro(arquivo, reg);
+            std::cout << "Código: " << reg.codigo << std::endl;
+            std::cout << "Nome: " << reg.nome << std::endl;
+            std::cout << "Endereço: " << reg.endereco << std::endl;
+            std::cout << "Cidade: " << reg.cidade << std::endl;
+            std::cout << "UF: " << reg.uf << std::endl;
+            std::cout << "------------------------" << std::endl;
+        } catch (const std::exception& ex) {
+            std::cerr << "Erro ao ler registro: " << ex.what() << std::endl;
+        }
-        lerRegistro(arquivo, reg);
-        std::cout << "Código: " << reg.codigo << std::endl;
-        std::cout << "Nome: " << reg.nome << std::endl;
-        std::cout << "Endereço: " << reg.endereco << std::endl;
-        std::cout << "Cidade: " << reg.cidade << std::endl;
-        std::cout << "UF: " << reg.uf << std::endl;
-        std::cout << "------------------------" << std::endl;
    }

    arquivo.close();
}

int main() {
+    try {
+        percorrerRegistros("arquivo_registros.txt");
+    } catch (const std::exception& ex) {
+        std::cerr << "Erro fatal: " << ex.what() << std::endl;
+        return 1;
+    }
+
-    percorrerRegistros("arquivo_registros.txt");
    return 0;
+}
-}
<<<<<<<  9e57e922-4a25-449f-8a62-7d70a982f8c3  >>>>>>>