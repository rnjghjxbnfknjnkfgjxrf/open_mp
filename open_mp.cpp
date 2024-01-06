#include <iostream>
#include <omp.h>

using namespace std;

const int N = 1500;

int **generate_matrix(bool randomize) {
    int **generated_matrix = new int*[N];
    for (int i = 0; i < N; i++) {
        generated_matrix[i] = new int[N];
        for (int j = 0; j < N; j++){
            generated_matrix[i][j] = randomize? rand() : 0;
        }
    }
    return generated_matrix;
}

// Перемножить матрицы на заданном числе поток и вернуть время выполнения
double make_a_measurement(int number_of_threads, int **first_matrix, int **second_matrix, int **multiplied){
    time_t start, end;
    omp_set_num_threads(number_of_threads);
    time(&start);
    #pragma omp parallel for
    for (int i = 0; i < N; i++){
        multiplied[i] = new int[N];
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k ++) {
                multiplied[i][j] = first_matrix[i][k] + second_matrix[k][j];
            }
        }
    }
    time(&end);
    return difftime(end, start);
}

int main(){
    srand((unsigned)time(nullptr));
    int **first_matrix = generate_matrix(true);
    int **second_matrix = generate_matrix(true);
    int **multiplied = generate_matrix(false);
    int max_threads = omp_get_max_threads();
    // Команда для запуска питоновского скрипта для рисования графика
    string command = "python .\\draw_graph.py";
    for (int i = 0; i < max_threads; i++) {
        command += ' '  + to_string(make_a_measurement(i+1, first_matrix, second_matrix, multiplied));
    }
    system(command.c_str());
    return 0;
}