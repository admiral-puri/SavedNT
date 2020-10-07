import numpy as np
#Hands-On numpy
#Q) Why numpy?
#A) Array oriented programming
#A) numpy.types are used as a data structure by other AI/ML packages like (cv, sklearn,...)
#A) A best in class library for numerical processing
#A) Arrays are processed like scalars
#A) Compatibility with lower level routines


#I) create a numpy.ndarray from various python sequences
arr = np.array([1,2,3,4,5])
#arr = np.array((1,2,3,4,5))
#arr = np.array({1,2,3,4,5})

#II) create a numpy.ndarray from a range of values
arr = np.arange(1,10)
print(arr)
print(type(arr))
#for reshape to be successful, the size of array and the product of the matrix axes must be same
mat = arr.reshape((3,3))
print(mat)

#know that the base array and the reshaped matrix, share the same memory
#mat[0][2] = 100
#print(arr)
#print(mat)

#III) views
print(mat[:2,1:]) #top-right 2 rows x 2 cols
print(mat[:,1]) #second col
print(mat[2,:2]) #first two cols of last row