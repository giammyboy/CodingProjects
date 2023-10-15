class Point2D:

    def __init__(self, x: int = 0, y: int = 0) -> None:
        self.x = x
        self.y = y

    def __str__(self) -> str:
        return f'({self.x}, {self.y})'

    def modify(self, **modifications):
        """
        It takes a dictionary of axis/lenght pairs and adds the lenght to the corresponding axis
        
        :param axis = lenght
        """
        for axis, lenght in modifications.items():
            if axis == ('x' or 'X'):
                self.x += lenght
            if axis == ('y' or 'Y'):
                self.y += lenght

    def set(self, **new_set):
        """
        The function takes a dictionary of axis and position pairs and sets the position of the axis to
        the position in the dictionary

        :param axis = set_position
        """
        for axis, new_position in new_set.items():
            if axis == ('x' or 'X'):
                self.x = new_position
            if axis == ('y' or 'Y'):
               self.y = new_position

    def distance(self, other):
        """
        It returns the distance between two points
        
        :param other: Point2D
        :type other: Point2D
        :return: The distance between two points.
        """
        delta_x = abs(self.x - other.x)
        delta_y = abs(self.y - other.y)

        return (delta_x ** 2 + delta_y ** 2) ** 0.5 


p = Point2D(0, 0)
p.modify(x = -1, y = 3)
print(p)