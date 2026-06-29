Text-Based RPG Engine:
A lightweight, high-performance C++ Text-Based RPG game engine utilizing Object-Oriented Programming (OOP) principles to simulate dynamic turn-based combat encounters. The project features a progressive leveling system, customizable player mechanics, scaling enemy AI, and automated inventory management.

🎮 Game Features
Turn-Based Combat System: Engaging tactical battle system featuring basic attacks, defense shields, and specialized elemental/status skills.

Dynamic Enemy AI: Enemies evaluate their current resource pools to execute random actions, casting powerful status skills like Poison, Fire, or Frost when energy permits, and reverting to basic strikes during low-energy phases.

Progression & Leveling: Winning battles increases the player's level, seamlessly scaling maximum stats (Health, Energy, Attack) and unlocking new combat equipment.

Inventory & Consumables: Integrated inventory tracking system managing weapons (Sword, Spear) and active status doses (Soul Dose for healing, Energy Dose for resource recovery).

Resource Emergency Management: Features an automated recovery mechanism (skip) that safely restores health and energy when the player attempts an action with insufficient stamina.

🛠️ Technical Implementation
Language: C++11 / C++14.

OOP Paradigms: Strong separation of concerns using decoupled classes for Player, Enemies, and Tools.

Memory Efficiency: Heavy utilization of std::vector sequential containers for dynamic dynamic asset tracking and safe runtime element deletion.

UX Enhancements: ANSI escape sequences utilized natively within the terminal output to provide color-coded diagnostic stat readouts (Red for Health, Blue for Energy, etc.).
