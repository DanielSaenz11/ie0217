-- Crear una base de datos llamada InventarioTienda
CREATE DATABASE IF NOT EXISTS InventarioTienda;

-- Usar la base de datos creada
USE InventarioTienda;

-- Crear una tabla llamada Productos
CREATE TABLE Productos (
	IDProducto INT AUTO_INCREMENT PRIMARY KEY,
    NombreProducto VARCHAR(50) NOT NULL,
    Cantidad INT NOT NULL,
    Precio DECIMAL(10, 2)
);

-- Insertar registros solicitados en la tabla 'Productos'
INSERT INTO Productos (NombreProducto, Cantidad, Precio) VALUES
('Laptop', 10, 1000.50),
('Teclado', 50, 20.99),
('Mouse', 30, 15.50);

-- Consulta 1: Seleccionar todos los productos
SELECT * FROM Productos;

-- Consulta 2: Actualizar la cantidad del producto 'Mouse' a 25
UPDATE Productos
SET Cantidad = 25
WHERE NombreProducto = 'Mouse';

-- Consulta 3: Elimina el producto 'Teclado'
DELETE FROM Productos
WHERE NombreProducto = 'Teclado';

-- Consulta 4: Consulta el precio del producto 'Laptop'
SELECT Precio
FROM Productos
WHERE NombreProducto = 'Laptop';

