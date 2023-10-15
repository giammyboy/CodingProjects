import copy


class Number(object):

    digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

    # def __init__(self, s='0'):
    #     self.number = {}
    #     self.s = s
    #     power = 0
    #     for digit in s[::-1]:
    #         if digit not in Number.digits:
    #             raise IndexError
    #         self.number[power] = int(digit)
    #         power += 1
    #     self.max = power - 1

    def __init__(self, number='0'):
        self.s = number
        self.number = self.string_to_number(number)

    def __str__(self):
        s = ''
        flag = True
        for digit in sorted(self.number.keys())[::-1]:
            if flag:
                if digit == 0:
                    break
                flag = False
            s += str(self.number[digit]) + ' '
        return s

    def __len__(self):
        return len(self.number.keys())

    def __add__(self, other):
        power = 0
        add1 = Number(self.s)
        add2 = Number(other.s)
        result = Number()
        add1.equalize(add2)
        result.equalize(add1)
        while power <= len(result) - 1:
            sum = add1.number[power] + add2.number[power] + result.number[power]
            if sum >= 10:
                sum -= 10
                result.number[power + 1] = 1
            result.number[power] = sum
            power += 1
        if result.number[power - 1] == 0:
            result.remove(power - 1)
        return result
    
    def __sub__(self, other):
        power = 0
        sub1 = Number(self.s)
        sub2 = Number(other.s)
        result = Number()
        sub1.equalize(sub2)
        result.equalize(sub1)
        while power <= len(result) - 1:
            sub = sub1.number[power] - sub2.number[power] - result.number[power]
            if sub < 0:
                sub1.number[power + 1] -= 1
                result.number[power] = 10 + sub
            else:
                result.number[power] = sub
            power += 1
        return result
    
    def __mul__(self, other):
        power = 0
        mul1 = Number(self.s)
        mul2 = Number(other.s)
        result = Number()
        mul1.equalize(mul2)
        result.equalize(mul1)

    def remove(self, power: int):
        del self.number[power]

    def string_to_number(self, string):
        self.number = {}
        power = 0
        for digit in string[::-1]:
            self.number[power] = int(digit)
            power += 1
        return self.number

    def equalize(self, other):
        index = max(self.max, other.max)
        for i in range(index + 2):
            if i not in self.number:
                self.number[i] = 0
            if i not in other.number:
                other.number[i] = 0



s = '1000'
s1 = '100'
a = Number(s)
b = Number(s1)
print(a + b)
