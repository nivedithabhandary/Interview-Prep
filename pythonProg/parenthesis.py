
def helper(result, left_count, right_count, temp_str):
    if (right_count < left_count or left_count < 0): 
        return
    if (left_count == 0 and right_count == 0): 
        result.append(temp_str)
        return
    else:
        if left_count > 0:
            temp_str = temp_str + "("
            helper(result, left_count-1, right_count, temp_str)
        if right_count > left_count:
            temp_str = temp_str + ")"
            helper(result, left_count, right_count-1, temp_str)
            
def generateParenthesis(n):
    """
    :type n: int
    :rtype: List[str]
    """
    
    result = []
    temp = ""
    val = helper(result, n, n, temp)
    return result
    
print "hellooooo"
print generateParenthesis(3)