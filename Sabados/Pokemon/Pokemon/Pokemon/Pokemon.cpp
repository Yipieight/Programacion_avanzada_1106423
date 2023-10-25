#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
struct Pokemon {
    int nationalidnumber;
    std::string nombre;
    int generacion;
};

// Función para imprimir la lista de Pokémon
void PrintPokemonList(const std::vector<Pokemon>& pokemonList) {
    for (const Pokemon& pokemon : pokemonList) {
        std::cout << "National ID: " << pokemon.nationalidnumber << ", Nombre: " << pokemon.nombre << ", Generación: " << pokemon.generacion << std::endl;
    }
}

// Algoritmo de Selection Sort
void SelectionSort(std::vector<Pokemon>& pokemonList, const std::string& key) {
    for (size_t i = 0; i < pokemonList.size(); i++) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < pokemonList.size(); j++) {
            if (key == "nationalidnumber") {
                if (pokemonList[j].nationalidnumber < pokemonList[minIndex].nationalidnumber) {
                    minIndex = j;
                }
            }
            else if (key == "nombre") {
                if (pokemonList[j].nombre < pokemonList[minIndex].nombre) {
                    minIndex = j;
                }
            }
            else if (key == "generacion") {
                if (pokemonList[j].generacion < pokemonList[minIndex].generacion) {
                    minIndex = j;
                }
            }
        }
        std::swap(pokemonList[i], pokemonList[minIndex]);
    }
}

// Algoritmo de Quick Sort
void QuickSort(std::vector<Pokemon>& pokemonList, const std::string& key, int left, int right) {
    if (left < right) {
        int pivotIndex = left;
        int pivotNewIndex = left;

        for (int i = left + 1; i <= right; i++) {
            if (key == "nationalidnumber") {
                if (pokemonList[i].nationalidnumber < pokemonList[pivotIndex].nationalidnumber) {
                    pivotNewIndex++;
                    std::swap(pokemonList[i], pokemonList[pivotNewIndex]);
                }
            }
            else if (key == "nombre") {
                if (pokemonList[i].nombre < pokemonList[pivotIndex].nombre) {
                    pivotNewIndex++;
                    std::swap(pokemonList[i], pokemonList[pivotNewIndex]);
                }
            }
            else if (key == "generacion") {
                if (pokemonList[i].generacion < pokemonList[pivotIndex].generacion) {
                    pivotNewIndex++;
                    std::swap(pokemonList[i], pokemonList[pivotNewIndex]);
                }
            }
        }

        std::swap(pokemonList[pivotIndex], pokemonList[pivotNewIndex]);

        QuickSort(pokemonList, key, left, pivotNewIndex - 1);
        QuickSort(pokemonList, key, pivotNewIndex + 1, right);
    }
}

// Algoritmo de Shell Sort
void ShellSort(std::vector<Pokemon>& pokemonList, const std::string& key) {
    int n = pokemonList.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Pokemon temp = pokemonList[i];
            int j = i;
            if (key == "nationalidnumber") {
                while (j >= gap && pokemonList[j - gap].nationalidnumber > temp.nationalidnumber) {
                    pokemonList[j] = pokemonList[j - gap];
                    j -= gap;
                }
            }
            else if (key == "nombre") {
                while (j >= gap && pokemonList[j - gap].nombre > temp.nombre) {
                    pokemonList[j] = pokemonList[j - gap];
                    j -= gap;
                }
            }
            else if (key == "generacion") {
                while (j >= gap && pokemonList[j - gap].generacion > temp.generacion) {
                    pokemonList[j] = pokemonList[j - gap];
                    j -= gap;
                }
            }
            pokemonList[j] = temp;
        }
    }
}

int main() {
    std::vector<Pokemon> pokemonList;

    // Llena la lista de Pokémon con datos de ejemplo
    for (int i = 1; i <= 100; i++) {
        Pokemon pokemon;
        pokemon.nationalidnumber = i;
        pokemon.nombre = "Pokémon" + std::to_string(i);
        pokemon.generacion = rand() % 8 + 1;
        pokemonList.push_back(pokemon);
    }

    // Lista original
    std::cout << "Lista original:" << std::endl;
    PrintPokemonList(pokemonList);

    // Ordenar por National ID
    SelectionSort(pokemonList, "nationalidnumber");
    std::cout << "\nOrdenada por National ID usando Selection Sort:" << std::endl;
    PrintPokemonList(pokemonList);

    QuickSort(pokemonList, "nationalidnumber", 0, pokemonList.size() - 1);
    std::cout << "\nOrdenada por National ID usando Quick Sort:" << std::endl;
    PrintPokemonList(pokemonList);

    ShellSort(pokemonList, "nationalidnumber");
    std::cout << "\nOrdenada por National ID usando Shell Sort:" << std::endl;
    PrintPokemonList(pokemonList);

    // Restaurar la lista original
    std::sort(pokemonList.begin(), pokemonList.end(), [](const Pokemon& x, const Pokemon& y) { return x.nationalidnumber < y.nationalidnumber; });

    // Ordenar por Nombre
    SelectionSort(pokemonList, "nombre");
    std::cout << "\nOrdenada por Nombre usando Selection Sort:" << std::endl;
    PrintPokemonList(pokemonList);

    QuickSort(pokemonList, "nombre", 0, pokemonList.size() - 1);
    std::cout << "\nOrdenada por Nombre usando Quick Sort:" << std::endl;
    PrintPokemonList(pokemonList);

    ShellSort(pokemonList, "nombre");
    std::cout << "\nOrdenada por Nombre usando Shell Sort:" << std::endl;
    PrintPokemonList(pokemonList);

    // Restaurar la lista original
    std::sort(pokemonList.begin(), pokemonList.end(), [](const Pokemon& x, const Pokemon& y) { return x.nombre < y.nombre; });

    // Ordenar por Generación
    SelectionSort(pokemonList, "generacion");
    std::cout << "\nOrdenada por Generación usando Selection Sort:" << std::endl;
    PrintPokemonList(pokemonList);

    QuickSort(pokemonList, "generacion", 0, pokemonList.size() - 1);
    std::cout << "\nOrdenada por Generación usando Quick Sort:" << std::endl;
    PrintPokemonList(pokemonList);

    ShellSort(pokemonList, "generacion");
    std::cout << "\nOrdenada por Generación usando Shell Sort:" << std::endl;
    PrintPokemonList(pokemonList);
}
