def isPalindrome(s):
    s.lower()
    s.replace(" ","")
    s = "".join(e for e in s if e.isalnum())
    i = 0
    j = len(s)-1
    while i<j:
        if s[i]!=s[j]:
            return False
        i+=1
        j-=1
    return True



test1 = "aba"
test2 = "a  a    "
test3 = "kajdlfkjs"
test4 = "    aba    "
test5 = "a#ab&ba*a"

print test1, isPalindrome(test1)
assert isPalindrome(test1)
print test2, isPalindrome(test2)
print test3, isPalindrome(test3)
print test4, isPalindrome(test4)
print test5, isPalindrome(test5)
