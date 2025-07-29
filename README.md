# 🧙‍♂️ Dungeon Adventure Game

A terminal-based dungeon crawler game written in **C**. Select your team of heroes, explore dungeons, fight monsters, and survive through 3 increasingly difficult rounds!

 🎮 Features

- 🔹 Select up to 4 heroes:
- 🗡️ Barbarian (B) — Strong and fearless
- 🪓 Dwarf (D) — Tough and versatile
- 🏹 Elf (E) — Fast and accurate
- 🔮 Wizard (W) — Powerful long-range attacks
- 🧱 Randomly generated dungeon with:
- Walls and furniture
- Random monster placements
- Turn-based combat and movement
- 🎲 Dice-based attack and defense mechanics
- 👾 Zargon controls monsters on each enemy turn
- 🎯 3 rounds of increasing challenge (easy → medium → hard)

---
⚙️ How to Compile & Run

1. Open terminal in the folder where the `.c` file is.
2. Compile the file with GCC:

```bash
gcc hero_dungeon_game.c -o DungeonAdventure
./DungeonAdventure
---

```
## 🖼️ Sample Output

```
  A B C D E F
--------------
1 |. . # # . .
2 |. @ . # . .
3 |B . . . 2 .
4 |. . . @ . .
5 |. # . . . .
6 |W . . . . .

You chose: B! Life: 8
You chose: W! Life: 4

Give movement order (e.g. B>D3R1):
You chose B to move! Remaining moves: 8
Move successful. Remaining moves: 6
```
## 📜 License

This project is licensed under the **MIT License**.

```
MIT License

Copyright (c) 2025 [George]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction...
```

---
---

## 👤 Author

Made by [George]  
Feel free to fork, clone, or suggest improvements!

