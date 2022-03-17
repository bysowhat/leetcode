import queue

class TreeNode:
  def __init__(self, data, left=None, right=None):
    self.data = data
    self.left = left
    self.right = right

class Traversal:
  def preOrder(self, root):
    print(root.data)
    if root.left is not None:
      self.preOrder(root.left)
    if root.right is not None:
      self.preOrder(root.right)

  def inOrder(self, root):
    if root.left is not None:
      self.inOrder(root.left)
    print(root.data)
    if root.right is not None:
      self.inOrder(root.right)

  def postOrder(self, root):
    if root.left is not None:
      self.postOrder(root.left)
    if root.right is not None:
      self.postOrder(root.right)
    print(root.data)

  def levelOrder(self, root):
    q = queue.Queue()
    if root is not None:
      q.put(root)
    else:
      return
    while not q.empty():
      tempt = q.get()
      print(tempt.data)
      if tempt.left is not None:
        q.put(tempt.left)
      if tempt.right is not None:
        q.put(tempt.right)


def main():
  root = TreeNode('f')
  nodeb = TreeNode('b')
  nodeg = TreeNode('g')
  nodea = TreeNode('a')
  noded = TreeNode('d')
  nodei = TreeNode('i')
  nodec = TreeNode('c')
  nodee = TreeNode('e')
  nodeh = TreeNode('h')

  root.left = nodeb
  root.right = nodeg
  nodeb.left = nodea
  nodeb.right = noded
  noded.left = nodec
  noded.right = nodee
  nodeg.right = nodei
  nodei.left = nodeh

  tv = Traversal()
  # tv.preOrder(root)
  # tv.inOrder(root)
  # tv.postOrder(root)
  tv.levelOrder(root)


if __name__ == '__main__':
    main()
