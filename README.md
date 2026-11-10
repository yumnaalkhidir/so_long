# so_long

A 2D tile-based maze game built with MinilibX: the player moves across a map, collects all items, and reaches the exit while avoiding walls. The bonus version adds enemies.

## Concepts covered
- Map file parsing and validation (shape, walls, collectibles, exit, player start)
- A recursive flood-fill reachability check to confirm all collectibles and the exit are reachable
- Real-time rendering and keyboard input via MinilibX
- Bonus: enemy placement and movement

## Build & run
```sh
make
./so_long maps/map.ber
make bonus
./so_long_bonus maps/map_bonus.ber
```
Move with `W`/`A`/`S`/`D`, quit with `ESC`.

> **Platform note:** this project's Makefile and keybindings target **macOS** (links against the `OpenGL`/`AppKit` frameworks and uses Mac keycodes), and expects MinilibX to be supplied separately at `mlx/` (not vendored in this repo). It will not build on Linux without swapping in the Linux `minilibx-linux` build and updating the link flags.

---
Part of the 42 School curriculum.
