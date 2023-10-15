class Number:

    DIGITS = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

    def __init__(self, string: str = '0'):
        self.string = Number.polish(string)
        self.number = {}
        Number.build(self)

    def __str__(self) -> str:
        string_to_return = ''
        for power in range(len(self.number)):
            string_to_return = str(self.number[power]) + string_to_return
        return string_to_return

    def __add__(self, other):
        if type(other) is not Number:
            raise TypeError
        result = self.copy()
        power = 0
        while power < other.get_len():
            result.add_digit(other.number[power], power)
            power += 1
        return result

    def __mul__(self, other):
        result = Number()
        temp = [Number() for _ in range(other.get_len())]
        max_power = other.get_len() 
        for power in range(max_power):
            for _ in range(other.number[power]):
                temp[power] = temp[power] + self
            temp[power].power_10(power)       
        for element in temp:
            result += element
        return result
              
    def get_len(self):
        return len(self.number)

    def get_power(self):
        return self.get_len() - 1

    def add_digit(self, digit: int = 0, power:int = 0):
        """
        If the digit is not in [0-9], return False. If the power is in the dictionary, add the
        digit to the power. If the sum is greater than 10, add 1 to the next power and subtract 10 from
        the current power. If the power is not in the dictionary, add it to the dictionary
        
        :param digit: The digit to add to the number, defaults to 0
        :type digit: int (optional)
        :param power: the power of 10 that the digit is in, defaults to 0
        :type power: int (optional)
        :return: A dictionary with the power as the key and the digit as the value.
        """
        if digit not in Number.DIGITS:
            return False
        if power in self.number:
            self.number[power] += digit
            if self.number[power] >= 10:
                if power + 1 in self.number:
                    self.number[power + 1] += 1
                    self.number[power] -= 10
                else:
                    self.number[power + 1] = 1
                    self.number[power] -= 10
        else:
            self.number[power] = digit

    def power_10(self, power: int = 1):
        index = self.get_power() + power 
        while index != power - 1:
            self.number[index] = self.number[index - power]
            index -= 1
        while index >= 0:
            self.number[index] = 0
            index -= 1

    def copy(self):
        """
        It returns a new Number object with the same value as the original
        :return: A new Number object with the same value as the original.
        """
        return Number(str(self))

    def build(self):
        max_power = len(self.string) - 1
        while max_power >= 0:
            self.number[max_power] = int(self.string[-max_power])
            max_power -= 1
        
    @staticmethod
    def polish(string):
        """
        It removes all the leading zeros from a string.
        
        :param string: The string to be polished
        :return: the string with the leading zeros removed.
        """
        index = 0
        # convert string to str
        if type(string) is not str:
            string = str(string)
        # check id string is numeric
        if not string.isnumeric():
            print('String is not Numeric')
        # remove all the leading zeros
        string = string.lstrip('0')
        if len(string) == 0:
            string = '0'
        return string