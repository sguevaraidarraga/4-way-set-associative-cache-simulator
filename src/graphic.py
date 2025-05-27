import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('../files/log.csv', delimiter=';')

fig, ax = plt.subplots(figsize=(8, 5))
metrics = ['Hits', 'Misses']
totals = df.set_index('Metric').loc[metrics, ['Total', 'Read', 'Write']].astype(int)

totals.plot(kind='bar', ax=ax)
plt.title('Cache Hits and Misses')
plt.ylabel('Count')
plt.xticks(rotation=0)
plt.legend(title='Tipo')
plt.tight_layout()
plt.show()

miss_rates = df.set_index('Metric').loc['Miss Rate', ['Total', 'Read', 'Write']].astype(float)

plt.figure(figsize=(6, 4))
miss_rates.plot(kind='bar', color='tomato')
plt.title('Miss Rate')
plt.ylabel('Miss Rate')
plt.ylim(0, 1)
plt.xticks(rotation=0)
plt.tight_layout()
plt.show()