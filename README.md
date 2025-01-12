# Blade & Stone

Blade & Stone is a 2D action-adventure game built using the Raylib library. The game features a character navigating through a world filled with enemies and obstacles.

![Gameplay GIF](path/to/your/gameplay.gif)

## Building the Project

To build the project, follow these steps:

1. **Clone the repository**:
    ```sh
    git clone https://github.com/yourusername/blade-and-stone.git
    cd blade-and-stone
    ```

2. **Install Raylib**:
    Follow the instructions on the [Raylib official website](https://www.raylib.com/) to install Raylib for your operating system.

3. **Compile the project**:
    ```sh
    g++ -o BladeAndStone main.cpp Character.cpp Prop.cpp Enemy.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
    ```

4. **Run the game**:
    ```sh
    ./BladeAndStone
    ```


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.