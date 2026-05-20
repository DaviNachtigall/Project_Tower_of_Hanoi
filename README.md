# Tower of Hanoi - Interactive Game in C

---

## Gameplay Preview

<img width="415" height="376" alt="image" src="https://github.com/user-attachments/assets/0a38e807-09dd-4284-9976-21067ff0c40c" />


---

## Rules of the Game
The Tower of Hanoi consists of pegs and a set of disks of different sizes. The objective is to move the entire stack of 4 disks from the first peg to the last peg, following three strict rules:
1. Only one disk can be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack.
3. No larger disk may be placed on top of a smaller disk.

## Data Structures & Concepts Used
* **Data Structure:** Dynamic Stack (Linked List-based Stack).
* **Memory Management:** Dynamic allocation using `malloc()` and proper cleanup with `free()`.
* **Visual Representation:** A custom CLI rendering system that prints the state of the game after every move.

## How to Play on Linux

Make sure you have the `gcc` compiler installed. In your terminal, run the following commands:

```bash
# 1. Compile the game
gcc -o hanoi_game hanoi_tower.c

# 2. Run the executable
./hanoi_game
