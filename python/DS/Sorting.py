class Sorting:
     def __init__(self):
         self.arr = []

     def scanArray(self):
         #clear and deallocate the existing list
         self.arr.clear()

         #take new array size
         n = int(input("Enter number of elements needed "))

         #append those many elements
         i = 0
         while i <n:
             self.arr.append( int(input ("Enter a number ")))
             i+=1

     def printArray(self):
         print()
         for x in self.arr:
             print(x, end=" ")

     def quickSort(self, x, y):
         #if lower boundary < upper boundary
         if x < y:
             key = self.arr[x]
             i = x # @ lower boundary
             j = y # @ upper boundary

             #until they cross
             while i < j:
                 while key >= self.arr[i] and i < y:
                     i+=1
                 while key < self.arr[j] and j > x:
                     j-=1

                 #if not crossed
                 if i < j:
                     #swap
                     temp = self.arr[j]
                     self.arr[j] = self.arr[i]
                     self.arr[i] = temp

             #i and j have crossed
             #j is the final position of key in sorted array
             #swap arr[j] and arr[x]
             temp = self.arr[j]
             self.arr[j]  = self.arr[x]
             self.arr[x] = temp

             #j is the pivot point as well
             #quick sort its left
             self.quickSort(x, j-1)

             # quick sort its right
             self.quickSort(j+1,y)


def main():
    #object of Sorting
    srt = Sorting()
    srt.scanArray()
    srt.printArray()
    srt.quickSort(0, len(srt.arr) -1)
    srt.printArray()

main()