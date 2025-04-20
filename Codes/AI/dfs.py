graph = {
  'A' : ['B','G'],
  'B' : ['C', 'D', 'E'],
  'C' : [],
  'D' : [],
  'E' : ['F'],
  'F' : [],
  'G' : ['H'],
  'H' : ['I'],
  'I' : [],
}

def dfs(graph, node):
    visited = set()
    stack = []

    visited.add(node)
    stack.append(node) 

    while stack:
        s = stack.pop()
        print(s, end = ' ')


        for n in graph[s][::-1]:
            if n not in visited:
                visited.add(n)
                stack.append(n)


def main():
    dfs(graph, 'A')


main()