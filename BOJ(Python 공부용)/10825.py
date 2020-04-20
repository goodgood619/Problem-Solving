#!/usr/bin/env python

import sys

sys.setrecursionlimit(50000000)

n = int(sys.stdin.readline())
students = []
for i in range(n):
    student = sys.stdin.readline().split()
    student[1:] = map(int, student[1:])
    students.append(student)

students = sorted(students, key=lambda x: (-x[1], x[2], -x[3], x[0]))

for i in students:
    print("%s" % (i[0]))
