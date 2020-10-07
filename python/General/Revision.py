def main():
    arr = [] # create an empty list
    i = 1
    while i < 11:
        arr.append(100+i) # add values to it
        i+=1

    #menu
    print("1 : print array ")
    print("2 : iterate over the array ")
    ch = int(input("enter choice"))

    #conditional branching
    if ch == 1:
        print(arr)
    elif ch == 2:
        for i in arr: #used as iterator
            print(i)
    else:
        print("wrong choice ")


main()
