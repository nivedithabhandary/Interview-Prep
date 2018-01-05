

matrix = [[1,0,0,0,1,0,0,1],[0,0,1,0,0,0,0,0],[1,0,0,0,1,0,0,1],[1,0,0,0,1,0,0,1]]
N = 4
M = 8


def isLonely(x, y):
    for i in range(0, M):
        if matrix[x][i] == 1 and i != y:
            return False

    for j in range(0, N):
        if matrix[j][y] == 1 and j != x:
            return False

    return True

def getLonelyPixel(matrix):
    count = 0
    l = []
    for i in range(0,N):
        for j in range(0,M):
            if(isLonely(i,j)):
                count = count + 1;
                l.append((i+1,j+1))

    return count , l


print getLonelyPixel(matrix)
