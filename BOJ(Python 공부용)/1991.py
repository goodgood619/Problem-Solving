import sys

input = sys.stdin
sys.setrecursionlimit(100)

n = int(input.readline())
tree = [[] for _ in range(n + 1)]


def preorder(here):
    print(chr(here + 65), end="")
    if tree[here][0][0] >= 0:
        preorder(tree[here][0][0])
    if tree[here][0][1] >= 0:
        preorder(tree[here][0][1])


def inorder(here):
    if tree[here][0][0] >= 0:
        inorder(tree[here][0][0])
    print(chr(here + 65), end="")
    if tree[here][0][1] >= 0:
        inorder(tree[here][0][1])


def postorder(here):
    if tree[here][0][0] >= 0:
        postorder(tree[here][0][0])
    if tree[here][0][1] >= 0:
        postorder(tree[here][0][1])
    print(chr(here + 65), end="")


for _ in range(n):
    here, left, right = map(str, input.readline().split())
    tree[ord(here) - 65].append((ord(left) - 65, ord(right) - 65))

preorder(0)
print()
inorder(0)
print()
postorder(0)
