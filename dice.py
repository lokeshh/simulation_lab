from random import choice
import matplotlib.pyplot as plt

def get_random_number():
	return choice(range(1, 7))

def trials(n):
	values = []
	for i in range(n):
		values.append(get_random_number())
	return values

def draw_graph(n):
	values = trials(n)
	x = range(1, 7)
	y = []
	for i in range(1, 7):
		y.append(values.count(i))
	plt.bar(x, y)
	plt.show()




