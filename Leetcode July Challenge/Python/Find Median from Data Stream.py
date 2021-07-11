from heapq import *

class MedianFinder:

    def __init__(self):
        self.min_heap: List[int] = []
        self.max_heap: List[int] = []
        

    def addNum(self, num: int) -> None:
        heappush(self.max_heap, -heappushpop(self.min_heap, num))
        
        if len(self.max_heap) > len(self.min_heap):
            heappush(self.min_heap, -heappop(self.max_heap))
        

    def findMedian(self) -> float:
        has_even_count = len(self.max_heap) == len(self.min_heap)

        if has_even_count:
            return (-self.max_heap[0] + self.min_heap[0]) / 2.0
        return float(self.min_heap[0])
