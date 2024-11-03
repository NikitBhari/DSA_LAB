import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file into a pandas DataFrame
df = pd.read_csv('pair.csv', header=None, names=['ExecutionTime', 'ArraySize'])

# Plot the graph
plt.figure(figsize=(10, 6))
plt.plot(df['ArraySize'], df['ExecutionTime'], marker='o', linestyle='-', color='b')

# Add title and labels
plt.title('Execution Time vs. Array Size')
plt.xlabel('Array Size')
plt.ylabel('Execution Time (nanoseconds)')
plt.grid(True)

# Show the plot
plt.show()
