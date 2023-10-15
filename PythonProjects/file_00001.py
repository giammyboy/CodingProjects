from ast import Num
import re
from numpy import number


class Digit:

    def __init__(self, digit: int = 0, power = None) -> None:
        """
        This function takes in a digit and a power and returns a number
        
        :param digit: The digit of the number, defaults to 0
        :type digit: int (optional)
        :param power: The power of the digit
        """
        self.digit = digit 
        self.power = power

    def __str__(self) -> str:
        return str(self.digit)


class Number:

    def __init__(self, number: str = '0') -> None:
        """
        This function takes a string as an argument and converts it into a dictionary
        
        :param number: str = '0', defaults to 0
        :type number: str (optional)
        """
        self.str = number
        self.number = {} 
        self.str_to_Number()

    def __str__(self) -> str:
        """
        It takes the number, and then it takes the power, and then it takes the string to return, and
        then it takes the while loop, and then it takes the try, and then it takes the
        self.number[power], and then it takes the except, and then it takes the return string to return,
        and then it takes the else, and then it takes the string to return, and then it takes the
        str(self.number[power]), and then it takes the string to return, and then it takes the power,
        and then it takes the power += 1
        :return: The number in the form of a string.
        """
        power = 0
        string_to_return = ''
        while True:
            try:
                self.number[power]
            except:
                return string_to_return
            else:
                string_to_return = str(self.number[power]) + string_to_return
                power += 1

    def strip_leading_zeros(self):
        """
        It deletes all the leading zeros from the number
        """
        max_power = len(self.number.keys()) - 1
        while self.number[max_power].digit == 0:
            del self.number[max_power]
            max_power -= 1

    def str_to_Number(self):
        """
        It takes a string of numbers, and converts it into a list of Digit objects
        """
        power = 0 
        for digit in self.str[::-1]:
            self.number[power] = Digit(int(digit), power)
            power += 1

    def add(self, other):
        """
        It adds two numbers together, digit by digit, and carries the 1 if the sum of the digits is
        greater than 10
        
        :param other: the number to be added to the current number
        :return: The result of the addition of two numbers.
        """
        power = 0
        result = Number()
        self.strip_leading_zeros()
        other.strip_leading_zeros()
        while True:
            try: 
                self.number[power].digit + other.number[power].digit
            except:
                break
            else:
                digit = self.number[power].digit + other.number[power].digit
                if digit >= 10: 
                    digit -= 10
                    result.number[power + 1] = Digit(1, power + 1)
                result.number[power] = Digit(digit, power)
                power += 1
        if len(self.number.keys()) > len(other.number.keys()):
            while True:
                try: 
                    self.number[power]
                except:
                    break
                else:
                    try: 
                        result.number[power]
                    except:
                        digit = self.number[power].digit
                    else: 
                        digit = self.number[power].digit + result.number[power].digit
                    if digit >= 10: 
                        digit -= 10
                        result.number[power + 1] = Digit(1, power + 1)
                    result.number[power] = Digit(digit, power)
                    power += 1
        else:
            while True:
                try: 
                    other.number[power]
                except:
                    break
                else:
                    try: 
                        result.number[power]
                    except:
                        digit = other.number[power].digit
                    else: 
                        digit = other.number[power].digit + result.number[power].digit
                    if digit >= 10: 
                        digit -= 10
                        result.number[power + 1] = Digit(1, power + 1)
                    result.number[power] = Digit(digit, power)
                    power += 1
        return result


