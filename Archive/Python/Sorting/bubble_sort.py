"""
    Time Complexity: O(n^2)
    Space Complexity: O(1) Auxiliary
"""


def sort(seq):
    L = len(seq)
    for _ in range(L):
        for n in range(1, L):
            if seq[n] < seq[n - 1]:
                seq[n - 1], seq[n] = seq[n], seq[n - 1]
    return seq
