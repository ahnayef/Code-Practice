import math


def minmax(currentDepth, currentNode, maxTurn, score, targetDepth):
    if currentDepth == targetDepth:
        return score[currentNode]

    if maxTurn:
        return max(minmax(currentDepth+1, currentNode*2, False,score, targetDepth), 
                   minmax(currentDepth+1, currentNode*2+1, False, score, targetDepth))
    else:
        return min(minmax(currentDepth+1, currentNode*2, True, score, targetDepth), 
                   minmax(currentDepth+1, currentNode*2+1, True, score, targetDepth))




score = []

x = int(input("Enter the number of leaf node: "))
for i in range(x):
    score.append(int(input("Enter the score of leaf node", str(i+1) + ": ")))


totalDepth = math.log2(len(score))

currentDepth = 0
startingNode = int(input("Enter the starting node: "))

maxTurn = True

print("The score of the leaf node is: ", end = "")

answer = minmax(currentDepth, startingNode, maxTurn, score, totalDepth)

print("The best score is: ", answer)

