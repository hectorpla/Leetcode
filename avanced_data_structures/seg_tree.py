neg_inf = float('-inf')
class SegmentTreeNode:
	def __init__(self, start, end, max):
		self.start, self.end, self.max = start, end, max
		self.left, self.right = None, None

class Solution:	
	# @param root, start, end: The root of segment tree and 
	#                          an segment / interval
	# @return: The maximum number in the interval [start, end]
	def query(self, root, start, end):
		'''
					cond 1	cond 2		cond 3		otherwise
		target		|____|	|____|		|________|	 |____|		or ...
		root	|_|				  |_|	  |____|	|________|
		todo		ignore	ignore		return max 	leave them to left
		'''
		print root.start, root.end
		if root.start > end or root.end < start:
			return neg_inf
		if root.start >= start and root.end <= end:
			return root.max
		# print root.start, root.end, root.max
		lmax = self.query(root.left, start, end) if root.left else neg_inf
		rmax = self.query(root.right, start, end) if root.right else neg_inf
		# print '--', lmax, rmax
		return max(lmax, rmax)

	def modify(self, root, index, value):
		if root.start == root.end:
			# assert root.start == index
			root.max = value
			return
		m = (root.start + root.end) / 2
		if index <= m:
			self.modify(root.left, index, value)
		else:
			self.modify(root.right, index, value)
		root.max = max(root.left.max, root.right.max)

if __name__ == "__main__":
	root = SegmentTreeNode(0,3,4)
	root.left = SegmentTreeNode(0,1,4)
	root.left.left = SegmentTreeNode(0,0,1)
	root.left.right = SegmentTreeNode(1,1,4)
	root.right = SegmentTreeNode(2,3,3)
	root.right.left = SegmentTreeNode(2,2,2)
	root.right.right = SegmentTreeNode(3,3,3)

	sol = Solution()
	print sol.query(root,1,2)
