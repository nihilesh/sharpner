# Input : mat[][] = {{1, 1, 0, 0, 0},
#                    {0, 1, 0, 0, 1},
#                    {1, 0, 0, 1, 1},
#                    {0, 0, 0, 0, 0},
#                    {1, 0, 1, 0, 1}
# Output : 5

# island stack, visited nodes list, node is tuple
# iterate matrix for each element,
#     if val==1 push node into stack
#          find boundaries
#     else:
#          add node to visited.

class IslandFinder(object):
    def __init__(self, metrix):
        self.metrix = metrix
        self.visited = set()
        self.islands = []

    def get_neighbors(self, node):
        i, j = node
        neighbors = [(i - 1, j - 1), (i - 1, j), (i - 1, j + 1),
                     (i, j - 1), (i, j + 1),
                     (i + 1, j - 1), (i + 1, j), (i + 1, j + 1)]
        return [n for n in neighbors if (0 <= n[0] <= len(self.metrix) - 1) and
                (0 <= n[1] <= len(self.metrix[0]) - 1)]

    def trace_island(self, node):
        island = []
        stack = [node]
        while stack:
            node = stack.pop()
            self.visited.add(node)
            if not self.metrix[node[0]][node[1]]:
                continue
            island.append(node)
            print "tracing node {}".format(node)
            neighbors = self.get_neighbors(node)
            print "neighbors = {}".format(neighbors)
            for n in neighbors:
                if n not in self.visited:
                    stack.append(n)
        return island

    def get_count(self):
        for i, r in enumerate(self.metrix):
            for j, v in enumerate(r):
                if (i, j) in self.visited:
                    continue
                if not v:
                    self.visited.add((i, j))
                    continue
                island = self.trace_island((i, j))
                if island:
                    self.islands.append(island)
        return len(self.islands)


def main():
    input = [[1, 1, 0, 0, 0],
             [0, 1, 0, 0, 1],
             [1, 0, 0, 1, 1],
             [0, 0, 0, 0, 0],
             [1, 0, 1, 0, 1]]
    print "Number of islands: {}".format(IslandFinder(input).get_count())


if __name__ == "__main__":
    main()
