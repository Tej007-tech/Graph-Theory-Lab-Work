# // Objective: To perform spectral clustering on a graph using the Laplacian matrix and eigenvectors. 
# // Problem: Write a program to perform spectral clustering on an undirected graph by using the graph Laplacian 
# // matrix.  
# // The program should:  
# // 1. Construct the adjacency matrix of the graph. 
# // 2. Compute the degree matrix. 
# // 3. Construct the Laplacian matrix. 
# // 4. Compute eigenvalues and eigenvectors of the Laplacian matrix.  
# // 5. Partition the graph into clusters using spectral properties. 
# // Input: 
# // N = 6 
# // Edges = {(0,1),(0,2),(1,2),(3,4),(4,5),(3,5)} 
# // Output: 
# // Cluster 1: {0,1,2} 
# // Cluster 2: {3,4,5}

import numpy as np

N = 6

edges = [(0, 1), (0, 2), (1, 2),
         (3, 4), (4, 5), (3, 5)]



A = np.zeros((N, N))

for u, v in edges:
    A[u][v] = 1
    A[v][u] = 1     

print("Adjacency Matrix:")
print(A)



D = np.diag(np.sum(A, axis=1))

print("\nDegree Matrix:")
print(D)

L = D - A

print("\nLaplacian Matrix:")
print(L)



eigenvalues, eigenvectors = np.linalg.eigh(L)

print("\nEigenvalues:")
print(eigenvalues)

print("\nEigenvectors:")
print(eigenvectors)



fiedler_vector = eigenvectors[:, 1]

print("\nFiedler Vector:")
print(fiedler_vector)


cluster1 = []
cluster2 = []

for i in range(N):
    if fiedler_vector[i] < 0:
        cluster1.append(i)
    else:
        cluster2.append(i)

print("\nClusters:")
print("Cluster 1:", cluster1)
print("Cluster 2:", cluster2)