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

def get_neighbors(node, rows, cols):
    i, j = node
    neighbors = [(i - 1, j - 1), (i - 1, j), (i - 1, j + 1),
                 (i, j - 1), (i, j + 1),
                 (i + 1, j - 1), (i + 1, j), (i + 1, j + 1)]
    return [n for n in neighbors if (0 <= n[0] <= rows - 1) and
            (0 <= n[1] <= cols - 1)]


def trace_island(node, metrix, island, visited):
    visited.add(node)
    if not (metrix[node[0]][node[1]]):
        return
    print island
    island.append(node)
    neighbors = get_neighbors(node, len(metrix), len(metrix[0]))
    neighbors = [n for n in neighbors if n not in visited]
    for n in neighbors:
        trace_island(n, metrix, island, visited)

def count_islands(metrix):
    islands = []
    visited = set()
    for i, r in enumerate(metrix):
        for j, v in enumerate(r):
            if (i, j) in visited:
                continue
            if not v:
                visited.add((i, j))
                continue
            island = []
            trace_island((i, j), metrix, island, visited)
            print "traced island: %s" % island
            if island:
                islands.append(island)
                print islands
    return len(islands)


def main():
    input = [[1, 1, 0, 0, 0],
             [0, 1, 0, 0, 1],
             [1, 0, 0, 1, 1],
             [0, 0, 0, 0, 0],
             [1, 0, 1, 0, 1]]
    print "Number of islands: {}".format(count_islands(input))


if __name__ == "__main__":
    main()
