def shorten(s):
    count = 0
    result = ""
    for i in range(len(s)-1):
        if s[i] == s[i+1]:
            count += 1
        else:
            result += s[i]
            result += str(count+1)
            count = 0
    return result

print shorten("aaaabbbdnndsk")
