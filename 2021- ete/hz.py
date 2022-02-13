import sys
import itertools

def harmonious(strs):
    num_of_e = 0
    str_before = ''

    for ch in strs:
        if ch == 'e':
            num_of_e = num_of_e + 1
        else:
            num_of_e = 0
            if ch == str_before:
                return False
        str_before = ch
        if num_of_e == 3:
            return False
    
    return True

def produce_harmonious(n,k):
    vowel = ['a','e','i','o','u']
    num = 0 
    res_str = ""
    
    list_strs = [''.join(i) for i in itertools.product(vowel, repeat = n)]

    for str_temp in list_strs:
        if harmonious(str_temp):
            num = num + 1
        if num == k:
            res_str = str_temp
            return res_str

    return res_str


# ------------------------------------------------ main program

for line in sys.stdin:
    a = line.split()
    print(produce_harmonious(int(a[0]),int(a[1]))) 