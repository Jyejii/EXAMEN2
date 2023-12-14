#include <stdio.h>
#include <string.h>

#define MAX_MATERIAS 10
#define MAX_NOMBRE 50

struct Estudiante {
    char nombre[MAX_NOMBRE];
    int edad;
    float promedio;
    char materias[MAX_MATERIAS][MAX_NOMBRE];
    int cantidadMaterias;
};

void mostrarEstudiante(const struct Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d anios\n", estudiante->edad);
    printf("Promedio: %.2f\n", estudiante->promedio);
    printf("Materias inscritas:\n");
    for (int i = 0; i < estudiante->cantidadMaterias; ++i) {
        printf("- %s\n", estudiante->materias[i]);
    }
}

void agregarMateria(struct Estudiante* estudiante, const char* nuevaMateria) {
    for (int i = 0; i < estudiante->cantidadMaterias; ++i) {
        if (strcmp(estudiante->materias[i], nuevaMateria) == 0) {
            printf("La materia ya esta en la lista del estudiante.\n");
            return;
        }
    }

    if (estudiante->cantidadMaterias < MAX_MATERIAS) {
        strcpy(estudiante->materias[estudiante->cantidadMaterias], nuevaMateria);
        estudiante->cantidadMaterias++;
    } else {
        printf("No se pueden agregar mas materias, limite alcanzado.\n");
    }
}

void eliminarMateria(struct Estudiante* estudiante, const char* materiaEliminar) {
    for (int i = 0; i < estudiante->cantidadMaterias; ++i) {
        if (strcmp(estudiante->materias[i], materiaEliminar) == 0) {
            for (int j = i; j < estudiante->cantidadMaterias - 1; ++j) {
                strcpy(estudiante->materias[j], estudiante->materias[j + 1]);
            }
            estudiante->cantidadMaterias--;
            printf("Materia eliminada correctamente.\n");
            return;
        }
    }
    printf("La materia no se encontro en la lista del estudiante.\n");
}

struct Asistencia {
    char fecha[MAX_NOMBRE];
    char materia[MAX_NOMBRE];
    char estado[MAX_NOMBRE];
};

void registrarAsistencia(const struct Estudiante* estudiante, const struct Asistencia* asistencia) {
    printf("Registro de Asistencia:\n");
    printf("Fecha: %s\n", asistencia->fecha);
    printf("Materia: %s\n", asistencia->materia);
    printf("Estado: %s\n", asistencia->estado);
    printf("Asistencia registrada correctamente.\n");
}

int main() {
    struct Estudiante estudiante1 = {"Juan", 20, 8.5, {{"Matematicas"}, {"Fisica"}, {"Programacion"}}, 3};

    mostrarEstudiante(&estudiante1);

    eliminarMateria(&estudiante1, "Fisica");

    mostrarEstudiante(&estudiante1);

    struct Asistencia asistencia1 = {"14/12/2023", "Matematicas", "asistio"};
    registrarAsistencia(&estudiante1, &asistencia1);

    return 0;
}

