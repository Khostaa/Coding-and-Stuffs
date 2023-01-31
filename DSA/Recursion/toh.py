def TOH(n,src,dst,temp):
    if(n==1):
        print("Move disk",n,"from",src,"to",dst)
    else:
        TOH(n-1,src,temp,dst)
        print("Move disk",n,"from",src,"to",dst)
        TOH(n-1,temp,dst,src)

n = int(input("Enter no. of discs: "))
TOH(n,'a','b','c')