#Binary Search Tree

class Node:
    #constructor
    def __init__(self, val=0):
        self.left = None
        self.data = val
        self.right = None



class BST:
    #constructor
    def __init__(self):
        self.root = None

    #create a BST
    def create(self):

        #test for existence
        if self.root is not None:
            print("Tree Already Defined")
            return

        #create a BST
        ch = 'y'
        while ch == 'y':
            #create a node
            x = int(input("Enter value for node "))
            n = Node(x)

            #connect
            if self.root is None:
                #first node to be marked as root of the tree
                self.root = n
            else:
                #rest of the nodes
                #compare and connect
                flag = True
                p = self.root

                while flag == True:
                    if n.data < p.data: #left
                        if p.left is None:#free
                            p.left = n #connect
                            flag = False
                        else: #occupied
                            p= p.left #traverse

                    else: #right
                        if p.right is None:#free
                            p.right = n #connect
                            flag = False
                        else:#occupied
                            p=p.right #traverse

            #cycle
            ch = input("Conintue (y/n) ")


    def inorder(self):
        print("Inorder")
        self.r_inorder(self.root)
        print()

    def r_inorder(self, r):#LDR

        if r.left is not None:
            self.r_inorder(r.left) #L
        print(r.data, end= " ") #D
        if r.right is not None:
            self.r_inorder(r.right) #R

    def preorder(self):
        print("Preorder")
        self.r_preorder(self.root)
        print()

    def r_preorder(self, r):  # DLR
        print(r.data, end=" ")  # D
        if r.left is not None:
            self.r_preorder(r.left)  # L
        if r.right is not None:
            self.r_preorder(r.right)  # R

    def postorder(self):
        print("Postorder")
        self.r_postorder(self.root)
        print()

    def r_postorder(self, r):  # LRD
        if r.left is not None:
            self.r_postorder(r.left)  # L
        if r.right is not None:
            self.r_postorder(r.right)  # R
        print(r.data, end=" ")  # D


def main():
    bst = BST()
    bst.create()
    bst.preorder()
    bst.inorder()
    bst.postorder()


main()