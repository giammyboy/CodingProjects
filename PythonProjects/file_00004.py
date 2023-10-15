class Student:

    code = 0

    def __init__(self, name: str, age: int) -> None:
        self.name = name
        self.age = age
        self.code = Student.generate_code()

    def __str__(self) -> str:
        return f"Student: name={self.name}, age={self.age}, code={self.code}"

    def show(self):
        print(str(self))

    @classmethod
    def generate_code(cls) -> str:
        cls.code += 1
        return "%.4d" % cls.code


class Course:

    def __init__(self, name: str, max_students: int = 10, description: str = "No description provided") -> None:
        self.name = name
        self.max_students = max_students
        self.description = description
        self.students = []
        
    def __str__(self) -> str:
        return f"Course(name={self.name}) \n {self.description}"

    def show(self):
        print(str(self))

    def add_students(self, *students):
        for student in students:
            if len(self.students) > self.max_students:
                return False
            else:
                self.students.append(student)
