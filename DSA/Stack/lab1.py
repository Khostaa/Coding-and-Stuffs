def push(stack, element):
    stack.append(element)
    print("Success")
def pop(stack):
    if len(stack)==0:
        return "Stack Underflow."
    else:
        data = stack.pop()
        return data

flag = True
stack = list()
while(flag):
    print("1. PUSH")
    print("2.POP")
    print("3.EXIT")
    choice = int(input("Enter you choice: "))
    if choice == 1:
        element = input("Enter element")
        push(stack,element)
    elif choice == 2 :
        element = pop(stack)
        print("Popped Value=",element)
    else:
        flag = False
    