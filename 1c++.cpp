#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

class MateriaExistenteException : public std::exception {
public:
    const char* what() const throw() {
        return "La materia ya esta en la lista del estudiante.";
    }
};

class MateriaInexistenteException : public std::exception {
public:
    const char* what() const throw() {
        return "La materia no se encontro en la lista del estudiante.";
    }
};

struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<std::string> materias;
};

void mostrarEstudiante(const Estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Edad: " << estudiante.edad << std::endl;
    std::cout << "Promedio: " << estudiante.promedio << std::endl;
    std::cout << "Materias inscritas:" << std::endl;
    for (const auto& materia : estudiante.materias) {
        std::cout << "- " << materia << std::endl;
    }
}

void agregarMateria(Estudiante& estudiante, const std::string& nuevaMateria) {
    auto it = std::find(estudiante.materias.begin(), estudiante.materias.end(), nuevaMateria);
    if (it != estudiante.materias.end()) {
        throw MateriaExistenteException();
    } else {
        estudiante.materias.push_back(nuevaMateria);
    }
}

void eliminarMateria(Estudiante& estudiante, const std::string& materiaEliminar) {
    auto it = std::find(estudiante.materias.begin(), estudiante.materias.end(), materiaEliminar);
    if (it != estudiante.materias.end()) {
        estudiante.materias.erase(it);
    } else {
        throw MateriaInexistenteException();
    }
}

struct Asistencia {
    std::string fecha;
    std::string materia;
    std::string estado;
};

void registrarAsistencia(Estudiante& estudiante, const Asistencia& asistencia) {
    std::cout << "Registro de Asistencia:" << std::endl;
    std::cout << "Fecha: " << asistencia.fecha << std::endl;
    std::cout << "Materia: " << asistencia.materia << std::endl;
    std::cout << "Estado: " << asistencia.estado << std::endl;
    std::cout << "Asistencia registrada correctamente." << std::endl;
}

int main() {
    try {
        Estudiante estudiante1;
        estudiante1.nombre = "Juan";
        estudiante1.edad = 20;
        estudiante1.promedio = 8.5;

        agregarMateria(estudiante1, "Matematicas");
        agregarMateria(estudiante1, "Fisica");
        agregarMateria(estudiante1, "Programacion");

        mostrarEstudiante(estudiante1);

        eliminarMateria(estudiante1, "Fisica");

        mostrarEstudiante(estudiante1);

        Asistencia asistencia1 = {"14/12/2023", "Matematicas", "asistio"};
        registrarAsistencia(estudiante1, asistencia1);
    } catch (const MateriaExistenteException& e) {
        std::cerr << "Error al agregar materia: " << e.what() << std::endl;
    } catch (const MateriaInexistenteException& e) {
        std::cerr << "Error al eliminar materia: " << e.what() << std::endl;
    }

    return 0;
}



