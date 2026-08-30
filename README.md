# Torre de Hanói - Jogo Interativo em C
---
## Prévia do Jogo
<img width="415" height="376" alt="image" src="https://github.com/user-attachments/assets/0a38e807-09dd-4284-9976-21067ff0c40c" />

---
## Regras do Jogo
A Torre de Hanói é composta por pinos e um conjunto de discos de tamanhos diferentes. O objetivo é mover toda a pilha de 4 discos do primeiro pino para o último pino, seguindo três regras rígidas:

1. Apenas um disco pode ser movido de cada vez.
2. Cada movimento consiste em retirar o disco do topo de uma das pilhas e colocá-lo no topo de outra pilha.
3. Nenhum disco maior pode ser colocado sobre um disco menor.

## Estruturas de Dados & Conceitos Utilizados
* **Estrutura de Dados:** Pilha Dinâmica (Pilha baseada em Lista Encadeada).
* **Gerenciamento de Memória:** Alocação dinâmica usando `malloc()` e liberação adequada com `free()`.
* **Representação Visual:** Um sistema de renderização em CLI personalizado que exibe o estado do jogo após cada movimento.

## Como Jogar no Linux
Certifique-se de ter o compilador `gcc` instalado. No seu terminal, execute os seguintes comandos:

```bash
# 1. Compile o jogo
gcc -o hanoi_game hanoi_tower.c
# 2. Execute o programa
./hanoi_game
```
