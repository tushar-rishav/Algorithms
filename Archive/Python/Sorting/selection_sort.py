"""
    Time Complexity:  O(n^2)
    Space Complexity: O(1) Auxiliary

"""


def sort(seq):

    for i in range(0, len(seq)):
        iMin = i
        for j in range(i+1, len(seq)):
            if seq[iMin] > seq[j]:
                iMin = j
        if i != iMin:
            seq[i], seq[iMin] = seq[iMin], seq[i]

    return seq
