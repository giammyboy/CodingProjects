class Coord(object):
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __str__(self):
        return f'({self.x} {self.y})'

    def __add__(self, other):
        result = Coord()
        result.x = self.x + other.x
        result.y = self.y + other.y
        return result

    def __sub__(self, other):
        result = Coord()
        result.x = self.x - other.x
        result.y = self.y - other.y
        return result

    def __mul__(self, other):
        result = Coord()
        result.x = self.x * other.x
        result.y = self.y * other.y
        return result

    def increase(self):
        self.x += 1
        self.y += 1

    def increase_x(self):
        self.x += 1

    def increase_y(self):
        self.y += 1

    def decrease(self):
        self.x -= 1
        self.y -= 1

    def decrease_x(self):
        self.x -= 1

    def decrease_y(self):
        self.y -= 1

    def iterate(self, other):
        result = []
        for Y in range(self.y, other.y):
            for X in range(self.x, other.x):
                result.append(Coord(X, Y))
        return result


class Cell(object):
    def __init__(self, position, data):
        self.position = position
        self.data = data


class Grid(object):
    def __init__(self, x_wide=3, y_wide=3):
        self.x_wide = x_wide
        self.y_wide = y_wide
        self.grid = []
        self.generate()

    def __str__(self):
        s = ''
        connector = ' '
        current_y = 0
        for element in self.grid:
            if current_y != element.position.y:
                current_y += 1
                s += '\n'
            s += str(element.data) + connector
        return s

    def generate(self):
        position_list = Coord.iterate(Coord(), Coord(self.x_wide, self.y_wide))
        for position in position_list:
            self.grid.append(Cell(position, position))

    def search(self, cell_position):
        if type(cell_position) is not Coord:
            cell_position = Coord(cell_position)
        for element in self.grid:
            if element.position == cell_position:
                return element
        return None


a = Grid(4, 5)
x = a.search(Coord(1, 2))
print(x.data)