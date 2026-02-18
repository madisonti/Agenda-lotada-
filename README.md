# 📑 Sistema de Agenda de Clientes (Versão Beta)


## 📝 Descrição do Projeto

Este projeto foi desenvolvido como uma solução personalizada para um desenvolvedor freelancer que necessita de um sistema eficiente para gerir sua carteira de clientes. O software é uma aplicação de terminal escrita em **Linguagem C** que permite o cadastro e a manutenção de dados básicos, garantindo integridade através de IDs gerados automaticamente.

O projeto faz parte do portfólio de lógica de programação e manipulação de estruturas de dados.

## 🚀 Funcionalidades

- **[1] Inserir Novo Cadastro**:
    - Geração automática de código único (ID).
    - Entrada de dados: Nome, Telefone e Endereço.
    - Validação de limite: Capacidade máxima de 5 clientes (Mensagem: "Agenda lotada!").
- **[2] Mostrar Todos os Cadastros**:
    - Listagem formatada de todos os clientes ativos.
    - Validação de banco vazio (Mensagem: "Agenda vazia!").
- **[0] Encerrar**:
    - Finalização segura do programa.

## 🛠️ Detalhes Técnicos

A aplicação utiliza conceitos fundamentais de programação estruturada:
- `struct`: Para definição do tipo de dado "Cliente".
- `Array de Structs`: Para o armazenamento temporário em memória.
- **Gerenciamento de Fluxo**: Uso de `do-while` e `switch-case` para o menu interativo.
- **Manipulação de Buffer**: Uso de `fflush(stdin)` para garantir a leitura limpa de dados do teclado.

## 💻 Pré-requisitos

Para compilar e executar este projeto, você precisará de:
- Um compilador de C (GCC, Clang ou MinGW).
- Ambiente Windows (devido ao uso de chamadas de sistema como `system("pause")` e `system("cls")`).

## 📥 Como executar

1. Clone o repositório:
   ```bash

   git clone 

    Compile o arquivo:
    Bash

    gcc main.c -o agenda.exe

    Execute o programa:
    Bash

    ./agenda.exe

📄 Licença

Este projeto está sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.

Desenvolvido por Madison Santos Oliveira 🚀
---
