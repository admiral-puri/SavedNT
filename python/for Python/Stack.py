class Stack:
    #constructor
    def __init__(self):
        self.mem = [] # an empty list ( a linear data structure)

    #method to add a value at the top of the stack
    def push(self, val):
        self.mem.append(val)

    #method  to remove the topmost value from the stack
    def pop(self):
        if len(self.mem) > 0:
            return self.mem.pop()
        else:
            print("Stack Underflow")
            return 0

    #method to fetch the topmost value of the stack, no deletion
    def peek(self):
        x = len(self.mem)
        if x > 0:
            return self.mem[x-1]
        else:
            print("Stack Underflow")
            return 0

    #not a valid method for stack , but we have it for test
    def display(self):
        x = len(self.mem)
        if x > 0:
            x-=1
            while x >= 0:
                print(self.mem[x])
                x-=1
        else:
            print("Stack is empty")



def main():
    #create objects of the class
    s = Stack()
    ch = 0
    while ch != 5:
        print("1 push ")
        print("2 pop ")
        print("3 peek ")
        print("4 display ")
        print("5 exit")

        ch = int(input("enter choice : "))

        if ch == 1:
            val = int(input("enter value to push "))
            s.push(val)
        elif ch == 2:
            val = s.pop()
            print(" pop : ", val)
        elif ch == 3:
            val = s.peek()
            print(" peek : ", val)
        elif ch == 4:
            s.display()
        elif ch == 5:
            break
        else:
            print("Wrong choice")


main()
