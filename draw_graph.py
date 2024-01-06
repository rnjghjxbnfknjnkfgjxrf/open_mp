import sys
import matplotlib.pyplot as plt

if __name__ == '__main__':
    results = list(map(float, sys.argv[1:]))
    threads_number = [i for i in range(1, len(results)+1)]
    fig = plt.figure(figsize=(8, 5))
    fig.canvas.manager.set_window_title('Результат')
    plt.plot(threads_number, results, '-o', label='Зависимость времени выполнения от числа потоков')
    plt.xticks(threads_number)
    plt.xlabel('Количество потоков')
    plt.ylabel('Время выполнения (в секундах)')
    plt.legend()
    plt.show()
