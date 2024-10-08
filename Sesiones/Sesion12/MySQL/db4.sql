-- Seleccionar empleados con un salario mayor a 3000.00
SELECT * FROM empleados WHERE salario > 3000.00;

-- Contar el número de empleados en cada departamento
SELECT departamento, COUNT(*) as numero_empleados
FROM empleados
GROUP BY departamento;

-- Calcular el salario promedio por departamento
SELECT departamento, AVG(salario) AS salario_promedio
FROM empleados
GROUP BY departamento;

-- Actualizar el salario de 'Juan Pérez'
UPDATE empleados
SET salario = 3500.00
WHERE nombre = 'Juan Pérez';

-- Eliminar el registro de 'Pedro Rodríguez'
DELETE FROM empleados
WHERE nombre = 'Pedro Rodríguez';

