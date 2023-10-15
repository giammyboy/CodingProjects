class Coord(object):
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __str__(self):
        return f'({self.x} {self.y})'

    def __add__(self, other):
        result = Vec2()
        result.x = self.x + other.x
        result.y = self.y + other.y
        return result

    def __sub__(self, other):
        result = Vec2()
        result.x = self.x - other.x
        result.y = self.y - other.y
        return result

    def __mul__(self, other):
        result = Vec2()
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

    # def iterate(self, destination):
    #     direction = self - destination
    #     versor = Vec2(1, 1)
    #     if direction.x < 0:
    #         versor.x = -1
    #     if direction.y < 0:
    #         versor.y = -1
    #     while
