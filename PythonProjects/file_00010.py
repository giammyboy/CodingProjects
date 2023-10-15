import matplotlib.pyplot as plt
import numpy as np

def game_of_life(state):
    # Get the number of rows and columns in the state
    rows, cols = state.shape
    
    # Create a new state with the same shape as the original state
    new_state = np.zeros((rows, cols))
    
    # Iterate over each cell in the state
    for i in range(rows):
        for j in range(cols):
            # Get the number of live neighbors for the current cell
            live_neighbors = get_live_neighbors(state, i, j)
            
            # Apply the rules of the Game of Life to the current cell
            if state[i, j] == 1:
                # Rule 1: Any live cell with fewer than two live neighbors dies (underpopulation)
                if live_neighbors < 2:
                    new_state[i, j] = 0
                # Rule 2: Any live cell with two or three live neighbors lives on to the next generation
                elif live_neighbors in (2, 3):
                    new_state[i, j] = 1
                # Rule 3: Any live cell with more than three live neighbors dies (overpopulation)
                elif live_neighbors > 3:
                    new_state[i, j] = 0
            else:
                # Rule 4: Any dead cell with exactly three live neighbors becomes a live cell (reproduction)
                if live_neighbors == 3:
                    new_state[i, j] = 1
    
    return new_state

def get_live_neighbors(state, row, col):
    # Get the number of rows and columns in the state
    rows, cols = state.shape
    
    # Initialize a count of live neighbors
    live_neighbors = 0
    
    # Iterate over the 3x3 neighborhood centered on the current cell
    for i in range(row-1, row+2):
        for j in range(col-1, col+2):
            # Ignore the current cell and any cells that are out of bounds
            if (i == row and j == col) or (i < 0 or i >= rows) or (j < 0 or j >= cols):
                continue
            # Increment the count of live neighbors if the cell is alive
            if state[i, j] == 1:
                live_neighbors += 1
    
    return live_neighbors

# Create an initial state with a glider
initial_state = np.array([[0, 0, 0, 0, 0],
                         [0, 0, 1, 0, 0],
                         [0, 0, 0, 1, 0],
                         [0, 1, 1, 1, 0],
                         [0, 0, 0, 0, 0]])

# Iterate the Game of Life for 10 generations
for i in range(10):
    # Plot the current state
    plt.imshow(initial_state, cmap='binary')
    plt.title(f'Generation {i+1}')
    plt.show()
    
    # Calculate the next state
