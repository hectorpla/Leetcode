class Solution(object):
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        res = set()
        start = self.next_operator(input, 0)
        start_val = eval(input[:start])
        self.helper(res, input, start_val, start)
        return list(res)
    def helper(self, results, data, cur_val, start, d=0):
        """start is the position of the operator"""
        # print(' ' * d + str(results))
        if start >= len(data):
            results.add(cur_val)
            print(' ' * d + str(results))
            return
        p = start + 1
        while p < len(data):
            p = self.next_operator(data, p)
            # print(' ' * d,end='')
            # print(str(cur_val), data[start:p])
            rhs = eval(data[start+1:p])
            self.helper(results, data, eval(str(cur_val) + data[start] + str(rhs)), p, d+1)
            p += 1
    def next_operator(self, seq, pos):
        while pos < len(seq) and seq[pos].isdigit():
            pos += 1
        return pos

s = Solution()
print(s.diffWaysToCompute('2*6+3-8'))