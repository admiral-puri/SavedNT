class Student:
    #constructor
    def __init__(self, r=10, n="vikas", p=66.3):
        self.rno = r
        self.name = n
        self.percentage = p
    #method
    def display(self):
        print("rno : ", self.rno)
        print("name : ", self.name)
        print("percentage : ", self.percentage)


def main():
    #create objects of the class
    s1 = Student()
    s2 = Student(11, "manoj")

    #call methods on the objects
    s1.display()
    s2.display()

main()
