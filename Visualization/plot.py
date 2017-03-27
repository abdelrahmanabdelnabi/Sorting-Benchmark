# Imports
import numpy as np
import matplotlib.pyplot as plt

#read the input file
file = open('testfile.txt', 'r')

# Read number of algorithms (i), and number of tests/points (n)
i = int(file.readline()) 
n = int(file.readline())

# Read the array size for each test point
input_sizes = [int(x) for x in file.readline().split()]

print (input_sizes)

# Algorithms names
sorting_names = []

# Matrix for the execution time for algorithm[i] for each input size
duration_matrix = [[0 for x in range(int(n))] for y in range(int(i))] 

for x in range(int(i)):
	sorting_names.append(file.readline())
	duration_matrix[x] = [float(z) for z in file.readline().split()]

for x in range(int(i)):
	print (sorting_names[x])
	print (duration_matrix[x])

n = [10, 100, 200, 300, 400, 500]
times = [0.01, 0.02, 0.04, 0.09, 0.16, 0.25]

for x in range(int(i)):
	plt.scatter(input_sizes, duration_matrix[x])
	plt.plot(input_sizes, duration_matrix[x], label=sorting_names[x])

plt.legend(loc='upper left')
plt.show()