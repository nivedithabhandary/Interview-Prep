def insertat(word, first, i):
    start = word[0:i]
    end = word[i:]
    return start + first + end

def get_perm (letters):
    if letters == None :
        return None
    permutations = []
    if len(letters) == 0:
        permutations.append(" ")
        return permutations
        
    first = letters[0]
    remaining = letters[1:]
           
    words = get_perm(remaining)
    for word in words:
        for i in range(0,len(word)):
            s = insertat(word, first, i)
            permutations.append(s)
    
    return permutations
    
print get_perm("ABC")