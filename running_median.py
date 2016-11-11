from __future__ import division
import heapq
import time
"""
Problem: https://www.hackerrank.com/challenges/find-the-running-median/
"""

t = 10000#input()
min_heap = []
max_heap = []
heapq.heapify(min_heap)
heapq.heapify(max_heap)

max_heap_len = 0
min_heap_len = 0
ct = t
S = 0
# while ct:
with open('Median.txt') as mfile:
    start = time.time()
    for nelem in mfile:
        if not ct:
            break
        n = int(nelem.strip())
        if ct > t - 2:
            if ct == t:
                heapq.heappush(max_heap, -1*n)
                max_heap_len += 1
                #print "%.1f" % n
                S += n
            else:
                if n < -1*max_heap[0]:
                    heapq.heappush(min_heap, -1*heapq.heappop(max_heap))
                    heapq.heappush(max_heap, -1*n)
                else:
                    heapq.heappush(min_heap, n)
                min_heap_len += 1
                #print "%.1f" % ((-1*max_heap[0]+min_heap[0])/2)
                S += ((-1*max_heap[0]+min_heap[0])/2)
            ct -= 1
            continue

        if max_heap_len - min_heap_len > 0:
            if n >= -1*max_heap[0]:
                heapq.heappush(min_heap, n)
            else:
                heapq.heappush(min_heap, -1*heapq.heappop(max_heap))
                heapq.heappush(max_heap, -1*n)
            min_heap_len += 1
        else:
            if n <= min_heap[0]:
                heapq.heappush(max_heap, -1*n)
            else:
                heapq.heappush(max_heap, -1*heapq.heappop(min_heap))
                heapq.heappush(min_heap, n)
            max_heap_len += 1

        if (max_heap_len + min_heap_len) & 1:
            if max_heap_len > min_heap_len:
                #print "%.1f" % (-1*max_heap[0])
                S += (-1*max_heap[0])
            else:
                #print "%.1f" % (min_heap[0])
                S += (min_heap[0])
        else:
            #print "%.1f" % ((-1*max_heap[0] + min_heap[0])/2)
            S += ((-1*max_heap[0] + min_heap[0])/2)
        ct -= 1
print "%f seconds taken" %(time.time() - start)
print S%t
