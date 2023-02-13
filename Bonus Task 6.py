def Tower_Of_Hanoi_3_Rods(discs, arr={}):
    '''
    input: number of discs
    output: number of steps calculated to transfer discss transfer from 1st rod 'A' to
    2nd rod 'B'
    '''
    # case-0 of dynamic programming
    if (discs in arr.keys()):
        return arr[discs]
    # case 1
    if (discs == 0):
        return discs
    # case 2
    if (discs == 1):
        return discs
    # recursion relation:
    Toi = Tower_Of_Hanoi_3_Rods(discs - 1, arr)
    arr[discs] = Toi * 2 + 1
    return Toi * 2 + 1
    
def Tower_Of_Hanoi_4_Rods(discs, arr={}):
    '''
    input: number of discs
    output: number of steps calculated to transfer discss transfer from 1st rod 'A' to
    2nd rod 'B'
    '''
    # case-0 of dynamic programming
    if discs in arr.keys():
        return arr[discs]
    # case 1
    if discs == 0:
        return discs
    # case 2
    if discs == 1:
        return discs
    # case 3
    if discs == 2:
        return 3
    # recursion relation:
    Toi = Tower_Of_Hanoi_4_Rods(discs - 2, arr)
    arr[discs] = Toi * 2 + 3
    return Toi * 2 + 3
def Frame_Stewart_algorithm (r, kth): # r:number of disks , kth:number of steps 
    nod1 = None
    nod2 = None
    nod3 = None
    if (r <= kth):
        return Tower_Of_Hanoi_3_Rods(r) 
    else:
        nod1 = Tower_Of_Hanoi_4_Rods(r - kth) 
        nod2 = Tower_Of_Hanoi_3_Rods(kth) 
        nod3 = Tower_Of_Hanoi_4_Rods(r - kth) 
    return nod1 + nod2 + nod3

def main():
    bestcase = 1e10
    best_kth = 0
    r = int(input("Enter the number of disks needed (r): "))
    print("")
    kth = int(input("Enter the number of kth (kth): "))
    print("")
    print("        Progressing , I'm Still Here with you!!!               ")
    print("")
    for i in range(1,kth+1):
        steps = Frame_Stewart_algorithm(r,i)
        if steps <= bestcase:
            best_kth = i
            bestcase = steps
        print(f"Total of steps for {r} disks is : {steps} with kth = {i}")
    print("Best Kth is :",best_kth)
if __name__=="__main__":
    main()
