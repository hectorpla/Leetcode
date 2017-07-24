class Solution:
    # @param expression: A string list
    # @return: The root of expression tree
    def build(self, expression):
        # write your code here
        if len(expression) == 0:
            return None