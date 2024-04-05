import random
import numpy as np


data = []
for i in range(100):
    rate = 0.0
    rate += random.uniform(0.0, 1.0) * 0.5
    rate += random.uniform(0.0, 1.0) * 0.1
    rate += random.uniform(0.0, 1.0) * 0.1
    rate += random.uniform(0.0, 1.0) * 0.1
    rate += random.uniform(0.0, 1.0) * 0.2
    data.append(rate)


mean = np.mean(data)
std_dev = np.std(data)

n = len(data)

CI_1 = mean - 1.96 * (std_dev / np.sqrt(n))
CI_2 = mean +1.96 * (std_dev / np.sqrt(n))

print("Mean:", mean)
print("Standard Deviation:", std_dev)
print("Confidence Interval:", CI_1, "to", CI_2)

investment=input("how much did you invest: ")
investment=float(investment)
print("Confidence Interval Say's Your Return Can be: ",investment*CI_1, " -or- ", investment*CI_2," With in a year!")
