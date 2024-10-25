-- Creación de base de datos SistemaResenas
CREATE DATABASE IF NOT EXISTS SistemaResenas;

-- Usar base de datos creada
USE SistemaResenas;

-- Creación de tabla de 'Profesores'
CREATE TABLE Profesores (
	id_profesor INT AUTO_INCREMENT PRIMARY KEY, -- Clave primaria del profesor
    nombre VARCHAR(100) NOT NULL, -- Nombre del profesor
    escuela VARCHAR(50) NOT NULL -- Escuela del profesor
);

-- Creación de tabla 'Cursos'
CREATE TABLE Cursos (
	id_curso INT AUTO_INCREMENT PRIMARY KEY, -- Clave primaria del curso
    nombre_curso VARCHAR(100) NOT NULL, -- Nombre del curso
    id_profesor INT, -- Clave foránea de la tabla Profesores,
    CONSTRAINT fk_profesor_curso FOREIGN KEY (id_profesor) REFERENCES Profesores(id_profesor) -- Restricción clave foránea para el ID del profesor
);

-- Crear la tabla Resenas
CREATE TABLE Resenas (
	id_resena INT AUTO_INCREMENT PRIMARY KEY, -- Clave primaria de la reseña
    id_profesor INT, -- Clave foránea que hace referencia a la tabla Profesores
    id_curso INT, -- Clave foránea que hace referencia a la tabla Cursos
    calificacion_general INT CHECK (calificacion_general BETWEEN 1 AND 5), -- Calificación de 1 a 5
    nivel_dificultad INT CHECK (nivel_dificultad BETWEEN 1 AND 5),
    comentario TEXT, -- Comentario de la reseña
    revisado BOOLEAN DEFAULT 0, -- Estado de revisión de la reseña (0: no revisado, 1: revisado)
    eliminado BOOLEAN DEFAULT 0, -- Estado de eliminado de reseña (0: no eliminado, 1: eliminado)
    CONSTRAINT fk_profesor_resena FOREIGN KEY (id_profesor) REFERENCES Profesores(id_profesor), -- Restricción clave foránea para el ID del profesor
    CONSTRAINT fk_curso_resena FOREIGN KEY (id_curso) REFERENCES Cursos(id_curso) -- Restricción clave foránea para el ID del curso
);

-- Creación de índices para búsqueda rápida
CREATE INDEX idx_profesor ON Resenas(id_profesor); -- Índice para el ID del profesor
CREATE INDEX idx_calificacion ON Resenas(calificacion_general); -- Índice para la calificación general
CREATE INDEX idx_dificultad ON Resenas(nivel_dificultad); -- Índice para el nivel de dificultad


-- Insertar profesores a tabla 'Profesores'
INSERT INTO Profesores (nombre, escuela)
VALUES ('John Smith', 'Ingeniería Eléctrica'),
       ('Emily Johnson', 'Ingeniería Mecánica'),
       ('Michael Brown', 'Química'),
       ('Sarah Davis', 'Ingeniería Eléctrica'),
       ('James Williams', 'Ingeniería Mecánica'),
       ('Olivia Martinez', 'Química'),
       ('Robert Wilson', 'Ingeniería Eléctrica'),
       ('Emma Thompson', 'Química'),
       ('David Harris', 'Ingeniería Eléctrica'),
       ('Sophia Carter', 'Ingeniería Mecánica');


-- Insertar cursos a la tabla 'Cursos'
INSERT INTO Cursos (nombre_curso, id_profesor)
VALUES ('Electrónica I', 1),  -- John Smith, Electrónica I
       ('Electrónica I', 4),  -- Sarah Davis, Electrónica I
       ('Electrónica I', 7),  -- Robert Wilson, Electrónica I
       ('Circuitos Lineales', 1),  -- John Smith, Circuitos Lineales
       ('Circuitos Lineales', 9),  -- David Harris, Circuitos Lineales
       ('Mecánica II', 2),  -- Emily Johnson, Mecánica II
       ('Mecánica II', 5),  -- James Williams, Mecánica II
       ('Mecánica de Fluidos', 2),  -- Emily Johnson, Mecánica de Fluidos
       ('Mecánica de Fluidos', 10),  -- Sophia Carter, Mecánica de Fluidos
       ('Química Inorgánica', 3),  -- Michael Brown, Química Inorgánica
       ('Química Inorgánica', 6),  -- Olivia Martinez, Química Inorgánica
       ('Análisis Químico', 8),  -- Emma Thompson, Análisis Químico
       ('Análisis Químico', 3);  -- Michael Brown, Análisis Químico


-- Insertar reseñas en la tabla 'Resenas' para los profesores y cursos agregados
INSERT INTO Resenas (id_profesor, id_curso, calificacion_general, nivel_dificultad, comentario, revisado, eliminado)
VALUES (1, 1, 4, 3, 'Buen curso, pero un poco difícil.', 0, 0),  -- John Smith, Electrónica I
       (4, 2, 5, 4, 'Gran profesor, curso complicado.', 1, 0),  -- Sarah Davis, Electrónica I
       (7, 3, 3, 3, 'El curso fue claro pero con desafíos.', 0, 0),  -- Robert Wilson, Electrónica I
       (1, 4, 5, 3, 'Circuitos muy bien explicados.', 1, 0),  -- John Smith, Circuitos Lineales
       (9, 5, 4, 2, 'Curso claro y con buen contenido.', 1, 0),  -- David Harris, Circuitos Lineales
       (2, 6, 5, 2, 'Curso muy fácil de seguir.', 1, 0),  -- Emily Johnson, Mecánica II
       (5, 7, 4, 3, 'Curso útil, pero con algunos conceptos complejos.', 0, 0),  -- James Williams, Mecánica II
       (2, 8, 5, 2, 'Mecánica de Fluidos bien explicada.', 1, 0),  -- Emily Johnson, Mecánica de Fluidos
       (10, 9, 4, 2, 'Curso práctico y claro.', 0, 0),  -- Sophia Carter, Mecánica de Fluidos
       (3, 10, 3, 4, 'Curso complicado.', 0, 0),  -- Michael Brown, Química Inorgánica
       (6, 11, 5, 2, 'La profesora hizo el curso fácil de entender.', 1, 0),  -- Olivia Martinez, Química Inorgánica
       (8, 12, 3, 4, 'Análisis Químico fue desafiante pero interesante.', 1, 0),  -- Emma Thompson, Análisis Químico
       (3, 13, 4, 3, 'Buen curso, aunque algunos temas fueron difíciles.', 0, 0),  -- Michael Brown, Análisis Químico
       (4, 2, 4, 3, 'El curso fue retador, pero bien explicado.', 1, 0),  -- Sarah Davis, Electrónica I
       (7, 3, 3, 2, 'Algunos temas no quedaron claros.', 0, 0),  -- Robert Wilson, Electrónica I
       (1, 4, 5, 4, 'Excelente enfoque práctico en los circuitos.', 1, 0),  -- John Smith, Circuitos Lineales
       (9, 5, 4, 3, 'Contenido útil y bien estructurado.', 0, 0),  -- David Harris, Circuitos Lineales
       (2, 6, 4, 3, 'Curso con buenos ejercicios prácticos.', 1, 0),  -- Emily Johnson, Mecánica II
       (10, 9, 5, 2, 'Sophia es excelente explicando.', 1, 0),  -- Sophia Carter, Mecánica de Fluidos
       (5, 7, 4, 3, 'Curso práctico, pero con conceptos avanzados.', 0, 0),  -- James Williams, Mecánica II
       (6, 11, 5, 2, 'Olivia hace el contenido muy comprensible.', 1, 0),  -- Olivia Martinez, Química Inorgánica
       (8, 10, 4, 3, 'Un curso claro, aunque algo retador.', 0, 0),  -- Emma Thompson, Química Inorgánica
       (8, 12, 5, 2, 'Análisis Químico fue realmente interesante.', 1, 0), -- Emma Thompson, Análisis Químico
       (3, 13, 4, 3, 'Algunos temas fueron difíciles de seguir.', 0, 0),  -- Michael Brown, Análisis Químico
       (6, 11, 5, 1, 'Olivia explicó los conceptos complejos de manera simple.', 1, 0);  -- Olivia Martinez, Química Inorgánica


-- Consulta 1. Filtrado por Curso y Escuela
SELECT Profesores.nombre AS profesor, AVG(Resenas.calificacion_general) AS promedio_calificaciones
FROM Profesores
JOIN Cursos ON Profesores.id_profesor = Cursos.id_profesor
JOIN Resenas on Cursos.id_curso = Resenas.id_curso
WHERE Cursos.nombre_curso = 'Electrónica I' AND Profesores.escuela = 'Ingeniería Eléctrica' AND Resenas.eliminado = 0
GROUP BY Profesores.nombre;


-- Consulta 2. Consulta y Ordenamiento por Calificación y Dificultad
SELECT Cursos.nombre_curso, AVG(Resenas.calificacion_general) AS promedio_calificacion, AVG(Resenas.nivel_dificultad) AS promedio_dificultad
FROM Cursos
JOIN Resenas ON Cursos.id_curso = Resenas.id_curso
JOIN Profesores ON Profesores.id_profesor = Cursos.id_profesor
WHERE Profesores.escuela = 'Ingeniería Mecánica' AND Resenas.eliminado = 0
GROUP BY Cursos.nombre_curso
ORDER BY promedio_calificacion DESC, promedio_dificultad ASC;


-- Consulta 3. Búsqueda de Reseñas no Revisadas
SELECT Profesores.nombre AS profesor, Cursos.nombre_curso AS curso, Resenas.comentario
FROM Resenas
JOIN Profesores ON Resenas.id_profesor = Profesores.id_profesor
JOIN Cursos ON Resenas.id_curso = Cursos.id_curso
WHERE Resenas.revisado = 0 and Resenas.eliminado = 0;


-- Consulta 4. Actualización de Estado con Reseñas
UPDATE Resenas
SET revisado = 1
WHERE id_resena = 1; -- John Smith, Electrónica I


-- Consulta 5. Consulta con Filtración Compleja y Alias
SELECT P.nombre AS Profesor, C.nombre_curso AS Curso, R.comentario AS Comentario, 
       R.calificacion_general AS 'Calificacion', R.nivel_dificultad AS 'Dificultad'
FROM Resenas R
JOIN Profesores P ON R.id_profesor = P.id_profesor
JOIN Cursos C ON R.id_curso = C.id_curso
WHERE R.calificacion_general >= 4 AND R.nivel_dificultad < 3 AND R.eliminado = 0;


-- Consulta 6. Consulta para eliminar Reseñas
DELETE FROM Resenas
WHERE id_resena = 1; -- ID arbitrario de reseña

UPDATE Resenas 
SET eliminado = 1
WHERE id_resena = 6;  -- Cambia por el id_resena correspondiente

-- Contar cuántas reseñas se han eliminado de un curso específico
SELECT COUNT(*) AS resenas_eliminadas
FROM Resenas
WHERE id_curso IN (SELECT id_curso FROM Cursos WHERE nombre_curso = 'Electrónica I')
AND eliminado = TRUE;

