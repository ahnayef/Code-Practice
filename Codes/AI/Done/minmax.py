import math


def minmax(currentDepth, currentNode, maxTurn, score, totalDepth):
    if currentDepth == totalDepth:
        return score[currentNode]

    if maxTurn:
        return max(minmax(currentDepth+1, currentNode*2, False,score, totalDepth), 
                   minmax(currentDepth+1, currentNode*2+1, False, score, totalDepth))
    else:
        return min(minmax(currentDepth+1, currentNode*2, True, score, totalDepth), 
                   minmax(currentDepth+1, currentNode*2+1, True, score, totalDepth))



score = []

x = int(input("Enter the number of leaf node: "))
for i in range(x):
    score.append(int(input("Enter the score of leaf node" + str(i+1) + ": ")))

 
totalDepth = int(math.log2(len(score)))

startingDepth = 0
startingNode = 0

maxTurn = True

print("The score of the leaf node is:", end = "")

answer = minmax(startingDepth, startingNode, maxTurn, score, totalDepth)

print("The best score is: ", answer)

