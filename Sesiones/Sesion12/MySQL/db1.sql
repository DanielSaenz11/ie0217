-- Crear una base de datos
CREATE DATABASE IF NOT EXISTS ejemplo_db;

-- Usar la base de datos
USE ejemplo_db;

-- Crear una tabla llamada empleados
CREATE TABLE empleados (
	id INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(50) NOT NULL,
    edad INT NOT NULL,
    departamento VARCHAR(50),
    salario DECIMAL(10, 2)
);