# Blade & Stone

Blade & Stone is a 2D game built using the Raylib library. The game features a character navigating through a world filled with enemies and obstacles.


![GIF](https://i.giphy.com/media/v1.Y2lkPTc5MGI3NjExMWVzaDZpeDBqNTVpeDNiNG80ZHE2bjlwM2d3YzUxNDVva2RmeG0zNSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/q6WNjXvhrbMb0RxMtJ/giphy-downsized-large.gif)

## Building the Project

To build the project, follow these steps:

1. **Clone the repository**:
    ```sh
    git clone https://github.com/Tlamir/BladeAndStone.git
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
