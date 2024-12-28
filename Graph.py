import matplotlib.pyplot as plt

# Giriş boyutları
sizes = [400, 1600, 3200, 6400, 12800, 25600, 51200, 102400]

# Her algoritma için zaman verileri (örnek değerler)
precompute_all = [0.05, 0.1, 0.2, 0.4, 0.8, 1.6, 3.2, 6.4]
sparse_table = [0.02, 0.03, 0.05, 0.1, 0.2, 0.4, 0.8, 1.6]
blocking = [0.04, 0.07, 0.1, 0.2, 0.4, 0.8, 1.6, 3.2]
precompute_none = [0.2, 0.5, 1, 2, 4, 8, 16, 32]

# Sonuçları görselleştirme
plt.plot(sizes, precompute_all, label="Compute All", marker='o')
plt.plot(sizes, sparse_table, label="Sparse Table", marker='o')
plt.plot(sizes, blocking, label="Blocking", marker='o')
plt.plot(sizes, precompute_none, label="Compute None", marker='o')

plt.xlabel("Input Size")
plt.ylabel("Time (ms)")
plt.title("Performance Comparison of Algorithms")
plt.legend()
plt.grid(True)
plt.show()
