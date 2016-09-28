import math
import unittest


class Point:

    def __init__(self, x, y):
        """
        Create a (X, Y) coordinate object vector.
        """
        self.x = x
        self.y = y

    def __eq__(self, p):
        return p.x == self.x and p.y == self.y

    def __sub__(self, p):
        return Point(self.x - p.x, self.y - p.y)

    def __mul__(self, p):
        """
        Return cross product of two vector.
        """
        return self.x * p.y - self.y * p.x

    def __dict__(self):
        return {'X': self.x, 'Y': self.y}

    @classmethod
    def dist(cls, P, Q=None):
        """
        Distance between two given points P and Q. Default Q is origin.
        """
        if Q is None:
            Q = Point(0,0)
        return math.sqrt((P.x - Q.x)**2 + (P.y - Q.y)**2)

    @classmethod
    def dot(cls, P, Q):
        """
        Return dot product of two vector: Q.P
        """
        return P.x * Q.x + P.y * Q.y

    @classmethod
    def direction(cls, P, Q, R):
        """
        Find the direction of rotation of angle pqr.
        CCW is positive and CW is negative.
        """
        return (P-Q) * (R-Q)

    @classmethod
    def angle(cls, P, Q, R=None):
        """
        Find the angle pqr if either q and r are distinct or R is None otherwise
        angle between PQ and X axis is returned.
        :param P, Q, R: The coordinate of three points.
        :return: Angle in radian rounded with a precision of 5.
        """
        if R is None or Q == R:
            # A point on line parallel to X axis and passing through Q.
            R = Point(abs(P.x + Q.x) / 2.0, 0) if P.x + Q.x else Point(1, 0)

        if P != Q and Q != R:
            acute = math.acos(cls.dot(P-Q, R-Q) / (cls.dist(P-Q) * cls.dist(R-Q)))
            return (round(2*math.pi - acute, 5) if (P-Q).y < 0
                                                else round(acute, 5))

        raise Exception("Invalid Points")

    @classmethod
    def on_segment(cls, q, p, r):
        """
        Check if point p lies on segment qr.
        """
        return (min(q.x, r.x) <= p.x and p.x <= max(q.x, r.x) and
                min(q.y, r.y) <= p.y and p.y <= max(q.y, r.y))

    @classmethod
    def polar_sort(cls, p0, *P):
        """
        Sort a sequence <p1, p2, ..., pN> of n points according to their polar
        angles w.r.t a given original point p0. Time Complexity: O(n log(n))
        :param p0: The reference point.
        :param P: A sorted sequence of tuple of Point object and its angle.
                  Sorting is done by angle.
        """
        point_and_angle = map(lambda p: (p, cls.angle(p, p0)), P)
        return sorted(point_and_angle, key = lambda p_tuple: p_tuple[1])

class SegmentsIntersect(Point):
    def __init__(self, p1, p2, p3, p4):
        """
        Check if the line segments (p1-p2) and (p3-p4) straddle each other.
        :param pi: i'th point with coordinate (Xi,Yi) input as tuple.
        """
        self.p1 = p1
        self.p2 = p2
        self.p3 = p3
        self.p4 = p4

    def intersect(self):
        if (Point.direction(self.p1, self.p3, self.p2)*
            Point.direction(self.p1, self.p4, self.p2) < 0 and
            Point.direction(self.p3, self.p1, self.p4)*
            Point.direction(self.p3, self.p2, self.p4) < 0):
            return True
        elif (not Point.direction(self.p1, self.p3, self.p2)
              and Point.on_segment(self.p1, self.p3, self.p2)):
            return True
        elif (not Point.direction(self.p1, self.p4, self.p2)
              and Point.on_segment(self.p1, self.p4, self.p2)):
            return True
        elif (not Point.direction(self.p3, self.p1, self.p4)
              and Point.on_segment(self.p3, self.p1, self.p4)):
            return True
        elif (not Point.direction(self.p3, self.p2, self.p4)
              and Point.on_segment(self.p3, self.p2, self.p4)):
            return True

        return False


class ConvexHull:
    def __init__(self, *P):
        self._input = P
        self._graham_output = None
        self._jarvis_output = None

    def graham_scan(self):
        def find_p0():
            min_p = self._input[0]
            for p in self._input:
                if p.y <= min_p.y:
                    if p.x <= min_p.x:
                        min_p = p
            return min_p
        def filter_farthest(rp, p0):
            p_min = rp[0]
            result = [rp[0]]
            for p in rp:
                if p[1] == p_min[1]:
                    if Point.dist(p[0], p0) > Point.dist(p_min[0], p0):
                        result[-1] = p
                        p_min = p
                else:
                    p_min = p
                    result.append(p_min)

            return result

        p0 = find_p0()
        remaining_p = filter(lambda p: p != p0, self._input)
        remaining_p = Point.polar_sort(p0, *remaining_p)
        remaining_p = filter_farthest(remaining_p, p0)
        point_stack = []
        point_stack.append(p0)
        point_stack.append(remaining_p[0][0])
        point_stack.append(remaining_p[1][0])
        for i in xrange(2, len(remaining_p)):
            while Point.direction(remaining_p[i][0], point_stack[-1], point_stack[-2]) < 0:
                point_stack.pop()

            point_stack.append(remaining_p[i][0])

        return point_stack

    def jarvis_march(self):
        pass


class ConvexHullTest(unittest.TestCase):
    def test_graham_scan(self):
        ch = ConvexHull(Point(0, 0), Point(1,0), Point(1,1),
                        Point(5, 5), Point(0,2), Point(0,6), Point(-1,1))
        self.assertEqual(ch.graham_scan(), [Point(0,0), Point(1,0), Point(5,5),
                                            Point(0,6), Point(-1, 1)])

    def test_jarvis_march(self):
        pass


class PointTest(unittest.TestCase):
    def test_polar_sort(self):
        p1 = Point(0, 0); p2 = Point(5, 5)
        p3 = Point(0, 5); p4 = Point(5, 0)
        self.assertEqual(Point.polar_sort(p1, p2, p3, p4),
                         [(p4, 0), (p2, round(math.pi/4, 5)),
                          (p3, round(math.pi/2, 5))])

    def test_angle(self):
        p1 = Point(1, 1)
        p2 = Point(0, 0)
        p4 = Point(2, 0)
        p3 = Point(-1, 1)
        p5 = Point(-1, -1)
        self.assertEqual(Point.angle(p1, p2, p4), round(math.pi/4 ,5))
        self.assertEqual(Point.angle(p3, p2, p4), round(3*math.pi/4 ,5))
        self.assertEqual(Point.angle(p3, p2), round(3*math.pi/4 ,5))
        self.assertEqual(Point.angle(p5, p2, p4), round(5*math.pi/4 ,5))


class SegmentsIntersectTest(unittest.TestCase):
    def test_intersect(self):
        p1 = Point(0, 0); p2 = Point(5, 5)
        p3 = Point(0, 5); p4 = Point(5, 0)
        segments = SegmentsIntersect(p1, p2, p3, p4)
        self.assertTrue(segments.intersect())
        p1 = Point(0, 0); p2 = Point(5, 5)
        p3 = Point(0, 5); p4 = Point(0, 10)
        segments = SegmentsIntersect(p1, p2, p3, p4)
        self.assertFalse(segments.intersect())


if __name__ == "__main__":
    unittest.main()
