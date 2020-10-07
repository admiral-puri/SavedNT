#a python program to study functions

#a function
def fx1():
 print("i am a function")
 print("i execute on call")
 print("i perform a sub task for the program")
 
#default values to formal parameter
def fx2(x=10):
 print() #line change
 i = 1
 while i<=x:
  print(i, end = " ")#included \n to be replaced by a " "
  i+=1
 print() #line change


#demonstrate pass by ref/val
def fx3(formalParam):
 print(formalParam)
 formalParam += 1
 print(formalParam)


#demonstrate return
def fx4(q):
 w = q*q*q
 return w

def main():
 ch = 0
 while ch != 5: 
  print("1 : function demo ")
  print("2 : function with parameter demo ")
  print("3 : pass by val/ref demo ")
  print("4 : function return demo ")
  print("5 : exit ")
  ch = int(input("enter choice "))
  
  if ch==1:
   fx1()
  elif ch==2:
   fx2() 
  elif ch==3:
   val = 100
   fx3(val)
   print("val : ", val)
  elif ch==4:
   a=10
   b=fx4(a) 
   print("cube of ",a," is ",b)
  elif ch == 5:
   break
  else:
   print("Wrong choice")
       