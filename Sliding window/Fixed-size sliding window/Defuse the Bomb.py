# class Solution:
#     def decrypt(self, code: List[int], k: int) -> List[int]:
#         result = [0] * len(code)
#         if k == 0:
#             return result
#         for i in range(len(result)):
#             if k > 0:
#                 for j in range(i + 1, i + k + 1):
#                     result[i] += code[j % len(code)]
#             else:
#                 for j in range(i - abs(k), i):
#                     result[i] += code[(j + len(code)) % len(code)]
#         return result
        

class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        result = [0 for _ in range(len(code))]
        if k == 0:
            return result
        # Define the initial window and initial sum
        start, end, window_sum = 1, k, 0
        # If k < 0, the starting point will be end of the array.
        if k < 0:
            start = len(code) - abs(k)
            end = len(code) - 1
        for i in range(start, end + 1):
            window_sum += code[i]
        # Scan through the code array as i moving to the right, update the window sum.
        for i in range(len(code)):
            result[i] = window_sum
            window_sum -= code[start % len(code)]
            window_sum += code[(end + 1) % len(code)]
            start += 1
            end += 1
        return result
