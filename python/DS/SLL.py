class Node:
    #constructor
    def __init__(self, value = 0):
        self.data = value
        self.next = None #NULL


    #accessors (that allow fetching values)
    #def getData(self):
    #    return decrypt(self.data)

    #def getNext(self):
    #    return self.next

    #mutators (that allow changing values)
    #def setData(self, val):
    #    self.data = encrypt(val)

    #def setNext(self, ref):
    #    self.next = ref


class SLL: #SinglyLinkedList
    #constructor
    def __init__(self):
        self.head = None
        self.size = 0

    #create
    def create(self):
        if self.size > 0:
            print("Linked List already created ")
            return False


        print("Creating a singly linked list")
        ch = 'y'
        while ch == 'y':

            #create a new node
            x = int(input("Enter value for node "))
            n = Node(x)

            #connect the node to the SLL
            if self.head is None:
                self.head = n
            else:
                shadow.next = n

            #increment the size
            self.size +=1

            #maintain a shadow
            shadow = n

            #cycle
            ch = input("create more nodes (y/n) : ")

    def count(self):
        return self.size

    def display(self):
        if self.size == 0:
            print("List is Empty")
        else:
            print()
            p = self.head
            while p is not None:
                print(p.data, end=" ")
                p = p.next #hop


    def insertNode(self, pos):
        if pos < 1 or pos > self.size + 1:
            print("Invalid Position for list of size ", self.size)
        else:
            # make a node
            x = int(input("Enter value for new node "))
            n = Node(x)

            # connect
            if pos == 1:
                n.next = self.head
                # update the head
                self.head = n
            else:
                p = self.head
                i = 1
                while i < pos:
                    shadow = p
                    p = p.next
                    i += 1

                # now shadow is at node : pos-1
                # and p is at node : pos

                shadow.next = n
                n.next = p

    def reverseList(self):
        if self.size > 1:
            b = self.head
            c = None

            while b is not None:
                a = b.next # track of the node ahead, so that we dont lose rest of the list on reversal
                b.next = c # reverse
                #advance
                c = b
                b = a

            self.head = c

    def sortAndCreate(self):
        if self.size > 0:
            print("Linked List already created ")
            return False


        print("Creating a sorted singly linked list")
        ch = 'y'
        while ch == 'y':
            #create a node
            x = int(input("Enter data for node "))
            n = Node(x)

            if self.head is None:
                #connect as head
                self.head = n
            else:
                #connect by comparison
                p = self.head
                flag = 0
                while flag == 0 and p is not None:
                    if n.data < p.data:
                        #new node data is less than current node data
                        if p is self.head:
                            n.next = p
                            self.head = n
                            flag = 1
                        else:
                            shadow.next = n
                            n.next = p
                            flag = 1
                    else:
                        shadow = p
                        p = p.next #traverse

                if flag == 0:
                    #connection not done yet
                    shadow.next = n

            #update the size
                self.size += 1
            #cycle
            ch = input("create more nodes (y/n) : ")


    def append(self):
        # add a new node next to the tail node of the linked list
        x = int(input("Enter data for node "))
        n = Node(x)

        if self.head is None:
            # linked list is not created
            self.head = n
        else:
            # traverse to the last node
            p = self.head
            while p.next is not None:
                p = p.next

                # connect as tail
            p.next = n

            self.size += 1


def main():
    #create an object of SLL
    mylist = SLL()

    #create the singly linked list
    #mylist.create()
    mylist.sortAndCreate()

    print("Number of nodes in SLL : ", mylist.count())

    mylist.append()

    mylist.display()
    #mylist.insertNode(1)
    #mylist.insertNode(4)

    #mylist.display()

    mylist.reverseList()

    mylist.display()

main()