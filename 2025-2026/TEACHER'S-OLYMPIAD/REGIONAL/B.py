a = input()
b = input()

def find_hash(s):
    ans = 1
    for i in range(len(s)):
        num = ord(s[i]) - ord('A') + 1
        ans = (ans * num) % 47

    return ans
    
if find_hash(a) == find_hash(b):
    print("Welcome")
else:
    print("Try again")