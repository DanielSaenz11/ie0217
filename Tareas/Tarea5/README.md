# Tarea 5


## Modo de uso

## Preguntas teóricas

### 1. Explique la diferencia entre bases de datos relacionales y no relacionales en términos de estructura de datos, casos de uso y escalabilidad.

### 2. ¿Qué es SQL y cuál es su importancia en la gestión de bases de datos relacionales? Mencione algunos ejemplos de operaciones comunes que se pueden realizar con SQL.

### 3. Mencione y explique los componentes de una tabla de bases de datos SQL.

### 4. Explique en qué consisten las operaciones _CRUD_ cómo se implementan en bases de datos relacionales y no relacionales.

### 5. Mencione y explique tres comandos SQL básicos, indicando un ejemplo práctico de cómo y cuándo se utilizan.

### 6. Mencione y explique tres comandos SQL de nivel intermedio o avanzado y su importancia en la manipulación de datos.

### 7. Explique qué es un JOIN en SQL y describa al menos tres tipos de `JOIN` (INNER, LEFT, RIGHT). Mencione cuándo y por qué usar cada uno.

### 8. Dada la tabla `Productos`, realiza una consulta para obtener los nombres y precios de los productos de la categoría "Electrónica" o "Deportes", que están en stock y cuyo precio sea menor a 300. Además, utiliza un alias para que el campo precio se muestre como costo, y ordena los resultados de menor a mayor precio.

| id  | nombre               | precio | categoría        | en_stock | detalles_color | detalles_peso |
|-----|----------------------|--------|------------------|----------|----------------|---------------|
| 1   | Televisor 55" LED    | 499.99 | Electrónica      | true     | Negro          | 7.5           |
| 2   | Batidora de Mano     | 29.99  | Electrodomésticos| false    | Blanco         | 1.2           |
| 3   | Smartphone 64GB      | 699.99 | Electrónica      | true     | Azul           | 0.2           |
| 4   | Toalla de Microfibra | 15.50  | Hogar            | true     | Azul           | 0.4           |
| 5   | Pesas de 5kg         | 24.99  | Deportes         | true     | Negro          | 5.0           |
| 6   | Refrigerador         | 999.00 | Electrodomésticos| true     | Plateado       | 50.0          |
| 7   | Taza de Cerámica     | 7.99   | Hogar            | true     | Blanco         | 0.3           |
| 8   | Bicicleta de Montaña | 299.99 | Deportes         | false    | Rojo           | 12.0          |

### 9. ¿Cómo podrías seleccionar los nombres de los productos que tienen el color `azul` en su información de detalles (`detalles_color`) y que pesen menos de 1 kg (`detalles_peso`)? Ordena los resultados en orden alfabético por nombre.

### 10. Dada la tabla `Productos`, realiza una consulta para obtener el precio promedio de todos los productos en la categoría `Hogar` que están disponibles en inventario.

### 11. ¿En qué consiste un ataque de SQL Injection y cómo puede afectar a una base de datos? Menciona al menos tres prácticas recomendadas para prevenir este tipo de ataques en una aplicación que utiliza consultas SQL.

### 12. Explique el rol de un servidor y un cliente en un sistema de gestión de bases de datos (DBMS). ¿Cómo interactúan ambos en una arquitectura cliente-servidor y qué características tienen?

### 13. ¿Qué es un motor de bases de datos? Mencione tres ejemplos.

### 14. Explique en qué situaciones es conveniente usar MySQL, considerando el tamaño de la base de datos, el tipo de datos y el tipo de aplicación.

### 15. ¿Qué características de una base de datos hacen conveniente el uso de SQLite?

### 16. Explique cada uno de los tipos de bases de datos NoSQL vistos en clase (clave-valor, familia de columnas, grafos y documentales). Mencione un beneficio específico del uso de cada uno y proporcione un ejemplo de comando o consulta.

### 17. ¿Qué es una colección en MongoDB? ¿Cual es la diferencia que tiene con respecto a una tabla?

### 18. ¿Cuáles son las principales diferencias en el rendimiento y escalabilidad entre bases de datos SQL y NoSQL?

