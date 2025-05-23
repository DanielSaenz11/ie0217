# Sesión 11

Esta sesión corresponde a la realizada para el 1 de octubre del 2024. Se trata el tema de __bases de datos SQL__.

En este README, se van a detallar la teoría y comandos vistos en el video de la sesión.

## Base de datos

Una base de datos es un sistema organizado de almacenamiento de datos que permite almacenar y recuperar información de manera eficiente y estructurada.

### __Bases de datos relacionales__

De forma generl, consiste de una tabla compuesta por filas (registros) y columnas (atributos). Las partes detalladas son las siguientes:

- __Tabla/_Table_:__ Estructura de principal de almacenamiento.

- __Fila (Registro)/_Row_ (_Record_):__ Único registro en la tabla.

- __Columna (Campo)/_Column_ (_Field_):__ Representa un atributo de la entidad.

- __Clave Primaria/_Primary Key_:__ Campo que identifica cada fila en una tabla. Se suele utilizar `ID` para hacer referencia a este tipo.

- __Clave Extranjera/_Foreign Key_:__ Campo que establece una relación entre <ins>dos tablas</ins>. Ejemplo: la relación entre la clave de una orden de compra y la información del cliente que la realizó.

- __Índice/_Index_:__ Estructura de datos para incrementar la velocidad de las operaciones.

- __Vista/_View_:__ Tabla virtual que resulta de una consulta sobre las tablas.

<p align="center">
  <img width="500" src="./images/tabla.png">
</p>

### __Bases de datos no relacionales__

- __Documento/_Document_:__ Para bases de datos orientadas a documentos.

- __Clave-Valor/_Key-Value_:__ Colección de pares clave-valor (similar a diccionario).

- __Grafo/_Graph_:__ Representación de nodos y aristas en un grafo.

- __Columna Ancha/_Wide Column Store_:__ Datos en columnas.

- __Contenedor/_Bucket_:__ Agrupaciones de datos relacionados en contenedores.

## SQL

SQL (_structured query language_) es un lenguaje especializado para administrar y manipular bases de datos relacionales. Se suele interactuar con un sistema de gestión de bases de datos (DBMS).

Se emplean las operaciones del tipo __CRUD__ para trabajar en sus bases de datos. Estas corresponden a:

- _Create_: Crear tablas o bases de datos.
- _Read_: Leer datos de una tabla.
- _Update_: Actualizar datos en una tabla.
- _Delete_: Eliminar tablas o bases de datos.

### Elementos de tablas en SQL

- __Clave candidata:__ Atributo(s) que puede identificar de manera única una tabla.

- __Súper clave:__ Un conjunto de atributos que puede identificar de manera única una tupla (claves candidatas, claves primarias y claves únicas).

- __Clave primaria:__ Atributo utilizado para identificar de manera única cada tupla en una tabla. Es el principal identificador de la tabla.

- __Clave alterna:__ Claves candidatas distintas de la clave primaria.

- __Clave única:__ Similar a la clave primaria, pero puede admitir un valor `NULL` en la columna.

- __Clave externa:__ Atributo que solo puede tomar valores presentes en otra tabla como referencia.

- __Clave compuesta:__ Combinación de columnas
que identifican de manera única cada tupla en una tabla.

### Comando `SELECT`

Este comando es utilizado para seleccionar columnas a partir de una tabla; es decir, permite filtrar información de la tabla original. La sintaxis más básica es la siguiente:

```sql
SELECT first_name, last_name
FROM Customers;
```

Se seleccionan las columnas `first_name`, `last_name` de la tabla `Customers`. Además, se puede seleccionar todas las columnas con `*`.

#### Directiva `WHERE`

Si se desea __filtrar datos__ a partir de la información de una cierta columna, se utiliza el comando `WHERE` seguido de la condición de filtrado. Por ejemplo:

```sql
SELECT *
FROM Customers
WHERE last_name = 'Doe';
```

La porción anterior de código se encarga de buscar todas las filas coincidentes con `last_name = 'Doe'`.

#### Operadores lógicos

SQL también permite utilizar __operadores lógicos__ como `AND` y `OR` si se desea que se cumplan dos condiciones a la vez o que se cumpla una de ellas, respectivamente. Esto se puede implementar con `WHERE` para realizar búsquedas más específicas. Si se desea negar la condición, se utiliza `NOT`.

#### Valores únicos

Se pueden obtener los valores únicos de una columna con el comando `SELECT DISTINCT`; es decir, se muestran los valores sin repeticiones.

Además, permite establecer distintas condiciones de búsqueda de valores distintos. Esto se refiere a que se pueden buscar pares de columnas distintas (ambos valores deben ser iguales para que cuente como repetido). Simplemente, se agregan los nombres de las dos columnas en `SELECT DISTINCT`.

Si se desea contar la cantidad de valores únicos, se utiliza `COUNT(DISTINCT <nombre_columna>)`. Además, `COUNT` cuenta los valores que no sean nulos.

#### Directiva `AS`

Esta indicación permite seleccionar columnas y trabajar __como__ una forma determinada. Se tiene el siguiente ejemplo que concatena el primer nombre y el apellido y se trabaja con esa columna como el nombre completo:

```sql
SELECT CONCAT(first_name, ' ', last_name) AS full_name
FROM Customers;
```

#### Directiva `TOP`/`LIMIT`

En motores como MySQL, PostgreSQL, SQLite, se utiliza el comando `LIMIT` para seleccionar una determinada cantidad de filas a partir de una búsquda con `SELECT`. Se puede también realizar `OFFSET n` de _n_ cantidad de filas para buscar a partir de la (n+1)-ésima fila.

```sql
SELECT first_name, last_name
FROM Customers
LIMIT 2 OFFSET 3;
```

En los motores SQL Server, MS Access, se utiliza el comando `TOP` para realizar una función similar. En el ejemplo siguiente, se seleccionan las primeras dos filas completas (indicado por `*`).

```sql
SELECT TOP 2 *
FROM Customers;
```

#### Directiva `IN`

Se utiliza para realizar una búsqueda donde se desea que un elemento se encuentre __en__ otro. Por ejemplo, en el siguiente ejemplo, se busca que el país se encuentre en `'USA'` o `'UK'`.

```sql
SELECT first_name, last_name
FROM Customers
WHERE country IN ('USA', 'UK');
```

También, se puede unir la funcionalidad de `IN` con `NOT` para buscar elementos que NO se encuentren en el otro elemento.

#### Directiva `BETWEEN`

Se utiliza junto a `WHERE` para buscar elementos __dentro de un rango__. Este rango puede ser tanto numérico como alfabético.

#### Valor `NULL`

Permite asignar campos que no contienen un valor definido. Se puede filtrar con `WHERE` para buscar elementos nulos o no nulos.

```sql
SELECT *
FROM Employee
WHERE email is NULL;
```

#### Directiva `MAX()` y `MIN()`

Permite buscar el valor máximo y mínimo almacenado en una columna. De igual forma, aplica para valores numéricos y alfabéticos.

En el caso de que se quiera buscar cuáles filas contienen el valor mínimo (pues puede estar repetido), se puede agregar como condición del `WHERE` que se busque el atributo mínimo.

#### Directiva `SUM` y `AVG`

`SUM()` se encarga de calcular la suma de los valores de la columna indicada como parámetro. Mientras que, `AVG()` calcula el promedio de los datos. Un ejemplo del uso de `SUM` se muestra a continuación:

```sql
SELECT SUM(amount) as total_sales
FROM Orders;
```

Se indica explícitamente que se tome como `total_sales`.

#### Agrupaciones `GROUP BY` y ordenamientos `ORDER BY`

La directiva `GROUP BY` sirve para agrupar los elementos de la tabla a partir de la columna indicada. En el siguiente ejemplo, se agrupan las órdenes de compra por el ID del cliente:

```sql
SELECT customer_id, AVG(amount) AS average_spends
FROM Orders
GROUP BY customer_id;
```

La directiva `ORDER BY` se encarga de ordenar los elementos de la(s) columna(s) a partir de cierta columna indicada. Se puede ordenar tanto numéricamente como alfabéticamente. La forma de indicar el tipo de ordenamiento (ascendente o descendente) se coloca después del nombre de la columna que define el criterio. 

```sql
SELECT *
FROM Customers
ORDER BY age DESC;
```

En el ejemplo anterior, se selecciona la tabla de manera descendente basándose en la columna de la edad.

En el caso en que se indiquen varias columnas en el criterio de ordenamiento, se sigue la prioridad de izquierda a derecha.

#### Directiva `LIKE`

Esta directiva es utilizada como condición de filtrado con `WHERE`. Sirve para indicar que se busque una columna __similar a__ un valor. Este valor puede ser un string exacto o que contenga una substring específico y con eso ya se hace match.

#### Directiva `UNION`

Es utilizada cuando se requiere hacer análisis o consultas para dos tablas, por ejemplo. Entonces, consiste en que se __unen__ dos columnas de dos tablas de interés. Sin embargo, observe que los elementos repetidos se incluyen una vez únicamente. Si se quieren incluir los repetidos, se utiliza el comando `UNION ALL`.

```sql
SELECT age
FROM Teachers
UNION
SELECT age
FROM Students;
```

#### Vistas

Las vistas en SQL contienen filas y columnas similares a una tabla. Con la diferencia de que, las vistas no contienen los datos reales. 

Es similar a un entorno de tabla virtual creado a partir de una o más tablas para facilitar el trabajo con datos. Son utilizadas para hacer consultas.

Se utiliza la siguiente sintaxis:

```sql
CREATE VIEW us_customers AS
SELECT customer_id, first_name
FROM Customers
WHERE Country = 'USA';
```

En el ejemplo anterior, se crea una tabla virtual que contiene únicamente los clientes pertenecientes a `'USA'`.

#### Directiva `CASE`

Permite crear una columna extra a la salida de `SELECT` que aplica las condiciones indicadas en el bloque indentado (`WHEN-ELSE`). Después `WHEN`, se coloca la condición de comparación, seguido de `THEN` y el valor a colocar.

Un ejemplo de su uso se muestra a continuación, donde utiliza `CASE` para definir una serie de casos que se colocan en la columna `country_name`.

```sql
SELECT customer_id, first_name
CASE
    WHEN country = 'USA' THEN 'United States of America'
    WHEN country = 'UK' THEN 'United Kingdom'
    ELSE 'Uknown Country'
END AS country_name
FROM Customers;
```

#### Directiva `HAVING`

Sirve para verificar una condición para un __grupo__ de filas. Se ejecuta después de `GROUP BY`.

En el siguiente ejemplo, muestran únicamente los grupos de `customer_id` con más de una aparición.

```sql
SELECT COUNT(customer_id), country
FROM Customers
GROUP BY country
HAVING COUNT(customer_id) > 1;
```

#### Operador `EXISTS`

Este operador funciona de tal forma que verifica primero el _query_ interno y dependiendo de la salida, se ejecuta o no el externo (si es `NULL`).

En el ejemplo a continuación, se utiliza la presente directiva para determinar las coincidencias entre los clientes con órdenes y clientes en la base de datos. Finalmente, los que __existen__ se coloca su `customer_id` y `first_name` como salida.

```sql
SELECT customer_id, first_name
FROM Customers
WHERE EXISTS (
    SELECT order_id
    FROM Orders
    WHERE Orders.customer_id = Customer.customer_id
);
```

### Comando `JOIN`

Este comando es utilizado para combinar filas de dos tablas en función de una columna en común. Selecciona los registros que poseen valores coincidentes en estas columnas.

```sql
SELECT Customers.customer_id, Customers.first_name, Orders.amount
FROM Customers
JOIN Orders
ON Customers.customer_id = Orders.customer
```

En el ejemplo anterior, se unen las tablas `Customers` y `Orders`, a partir del criterio de su `customer_id`. Entonces, los clientes que están presentes en ambas tablas se colocan en la salida.

#### Comando `INNER JOIN`

Este comando se encarga de unir dos tablas de una columna común y selecciona filas que tienen valores coincidentes en estas columnas.

```sql
SELECT Customers.customer_id, Customers.first_name, Orders.amount
FROM Customers
INNER JOIN Orders
ON Customers.customer_id = Orders.customer
```

Es equivalente a `SQL JOIN`.

#### Comando `LEFT JOIN`

Se encarga de combinar dos tablas basadas en una columna común. Selecciona los registros que tienen valores coincidentes en estas columnas y filas restas de la tabla de la izquierda.

Los elementos presentes en ambas tablas (a partir del criterio de comparación) se les coloca el valor de la tabla comparada. Los que no se encuentran en al tabla comparada, quedan vacíos en la nueva columna agregada.

Se toma la tabla izquierda como las de la tabla base.

#### Comando `RIGHT JOIN`

Funciona de forma similar al comando anterior. con la diferencia que selecciona registros que tienen valores coincidentes en las columnas y las filas restantes de la columna derecha (lo que sobró).

Entonces, las columnas que hicieron _match_ se muestran con toda la información. Las que no hicieron, se muestran las restantes filas de la tabla comparada (distinta de la base).

#### Comando `FULL OUTER JOIN`

Este comando es similar a combinar el comando `LEFT JOIN` con `RIGHT JOIN`, pues se seleccionan registros que tienen valores coincidentes y las filas restantes de ambas tablas.

#### Comando `CROSS JOIN`

Permite combinar filas de dos o más tablas sin ninguna relación específica entre ellas. Básicamente, se encarga de relacionar todos los elementos de una tabla con todos los elementos de la otra.

#### Comando `Self JOIN`

Permite unir una tabla __consigo misma__, creando una relación entre filas dentro de una misma tabla. 

```sql
SELECT
    c1.first_name,
    c1.country,
    c2.first_name AS friend_name
FROM Customers c1
JOIN Customers c2 ON c1.country = c2.country
WHERE c1.customer_id <> c2.customer_id;
```

En el ejemplo anterior, se selecciona los clientes con el mismo país y diferente `customer_id`.

### Database y Tables

#### Comando `CREATE DATABASE`

Es utilizado para crear bases de datos, como su nombre lo indica. Después de este, se indica su nombre. Se puede aplicar `CREATE DATABASE IF NOT EXISTS` para crearla en caso de que no exista una con el mismo nombre, como forma de prevención.

Para comenzar a usarla, se utiliza `USE <nombreDB>;`.

#### Comando `CREATE TABLE`

Se emplea para crear una tabla de una base de datos, la cual es utilizada para almacenar registros.

La sintaxis para el comando se muestra a continuación:

```sql
CREATE TABLE table_name (
    column1 datatype,
    column2 datatype,
    column3 datatype,
    ...
);
```

Al igual que el comando de crear una base de datos, se puede utilizar `CREATE TABLE IF NOT EXISTS` como forma de prevención, en caso de que ya existiera una tabla con ese nombre.

#### Comando `DROP`

Se utiliza para eliminar bases de datos o tablas. En el caso de las bases de datos, la sintaxis es la siguiente:

```sql
DROP DATABASE database_name;
```

Para las tablas, se utiliza la siguiente sintaxis:

```sql
DROP TABLE table_name;
```

También, se puede aplicar el comando `DROP TABLE IF EXISTS` para eliminar únicamente si ya existe una tabla con el nombre ingresado.

#### Comando `ALTER TABLE`

Es utilizada para modificar la estructura de una tabla existente. Entre las acciones se encuentra: agregar y eliminar columnas, cambiar el nombre de la tabla o columnas, modificar una columna, entre otros.

Se utiliza la sintaxis a continuación:

```sql
ALTER TABLE table_name
ADD <column_name> datatype
RENAME COLUMN <column_name> TO <new_column_name>
DROP COLUMN <column_name>
RENAME TO <new_table_name>
... ;
```

#### Comando `BACKUP DATABASE`

Este comando es utilizado para crear copias de seguridad (respaldos) de las bases de datos.

La sintaxis empleada es la siguiente:

```sql
BACKUP DATABASE database_name
TO <medium> = 'path\file_name';
```

Si se quiere guardar los últimos cambios realizados a la base de datos, se le agrega al final del bloque anterior `WITH DIFFERENTIAL`.

Ahora bien, una copia de seguridad del registro de transacciones captura todos los cambios realizados en la base de datos desde la última copia de seguridad del registro de transacciones o la creación de la base de datos. Permite crear una copia de seguridad de un momento determinado de su base de datos.

La sintaxis utilizada para este caso se muestra a continuación:

```sql
BACKUP LOG database_name
TO <medium> = 'path/filename';
```

Para restaurar la base de datos a cierto _backup_ previo, se utiliza:

```sql
RESTORE DATABASE database_name
FROM <medium> = 'path/filename';
```

### Comandos `INSERT`, `UPDATE` y `DELETE`

#### Comando `INSERT INTO`

Este comando es utilizado para insertar nuevas filas en una tabla de base de datos. Se utiliza la siguiente sintaxis:

```sql
INSERT INTO Customers(customer_id, first_name, last_name, age, country)
VALUES (5, 'Harry', 'Potter', 31, 'USA');
```

Como se observa, se coloca la tabla a la que se desea agregar y las columnas para las que se va a agregar el valor. Luego, en `VALUES` se indican los valores específicos a almacenar. Si no se indica un valor, se coloca de forma predeterminada como `NULL` (a menos que de que indique lo contrario).

#### Comando `UPDATE`

Este comando se encarga de modificar registros existentes en una tabla de bases de datos. Se utiliza la sintaxis a continuación:

```sql
UPDATE Customers
SET first_name = 'Johnny', last_name = 'Depp'
WHERE customer_id = 1;
```

Entonces, en el ejemplo anterior, se actualiza la tabla `Customers`, para el cliente con `customer_id = 1`, pues se cambia su nombre y apellido.

Dependiendo de la condición de búsqueda `WHERE`, se puede modificar el valor de varios registros con un comando. Si no se indica esta condición, se cambia los valores de todas las filas de la tabla.

#### Comando `SELECT INTO`

El presente comando se utiliza para copiar los datos de una tabla a otra. Se utiliza la sintaxis:

```sql
SELECT column1, column2, column3, ...
INTO destination_table
FROM source_table
```

Se pueden copiar columnas específicas ingresadas como `column1`, `column2`, entre otros. Asimismo, se puede copiar filas a partir de una condición de filtrado con `WHERE`.

Este comando también es posible mezclarlo con `JOIN` para copiar el contenido de dos tablas en una tabla nueva.

#### Comando `INSERT INTO SELECT`

Esta directiva es utilizada para copiar registros de una tabla a otra __existente__. Emplea la siguiente sintaxis:

```sql
INSERT INTO destination_table (column1, column2, column3, ...)
SELECT column1, column2, column3, ...
FROM source_table;
```

Como aclaración, en la parte de `SELECT`, se colocan las columnas de la tabla fuente.

Hay distintas formas de implementar este comando, pues depende de las necesidades específicas del momento. Se pueden copiar columnas específicas de la tabla, filas que cumplan una condición de filtrado con `WHERE`, copiar los contenidos al unir otras dos tablas, entre otros.

#### Comando `DELETE`

Se utiliza para eliminar filas de una tabla de una base de datos. Sigue la sintaxis que se muestra a continuación:

```sql
DELETE FROM table_name
WHERE <condition>;
```

Si no se indica condición `WHERE`, se elimina toda la tabla. Otra forma de hacer esto es con `TRUNCATE TABLE`.

### Constraints (Restricciones)

En una tabla, se pueden agregar reglas a una columna, para controlar los datos que se pueden almacenar en esta.

Se utiliza la siguiente sintaxis:

```sql
CREATE TABLE table_name (
    column1 data_type,
    ... ,
    CONSTRAINT <constraint_name> <CONSTRAINT_TYPE> (<column_name>)
);
```

Algunas restricciones corresponden a:

- __`NOT NULL`__: Limita los valores para que sean distintos de `NULL`.

- __`UNIQUE`__: Indica que los valores no pueden ser iguales a otros almacenados previamente.

- __`PRIMARY KEY`__: Sirve para identificar de forma única una fila o registro de una tabla. Un _primary key_ envuelve los conceptos de que sean únicos y no nulos.

```sql
CREATE TABLE Colleges (
    college_id INT,
    college_code VARCHAR(20) NOT NULL,
    college_name VARCHAR(50),
    CONSTRAINT CollegePK PRIMARY KEY (college_id)
);
```
> Indica que el código del _college_ no puede ser nulo y añade una restricción al _college\_id_ que tiene que ser único.

- __`FOREIGN KEY`__: Para añadir una restricción de llave foránea, se agrega la directiva `FOREIGN KEY (column_name)` al crear la tabla, junto con la referencia a la tabla de la que se desea obtener la llave con `REFERENCES referenced_table_name (referenced_column_name)`. Un ejemplo de su uso corresponde al caso de la tabla de clientes y órdenes, pues se realiza la referencia en la tabla de órdenes a los clientes almacenados, por medio de una llave foránea.

- __`CHECK`__: Esta restricción es utilizada para verificar que se cumpla una condición determinada. Por ejemplo, si se requiere que un elemento únicamente contenga elementos positivos, se utiliza: `number INT CHECK (number > 0)`. Por lo tanto, resulta en un error si se ingresa un valor que no cumple con la condición.

- __`DEFAULT`__: Agrega un valor por defecto si no se especifica el valor de esa columna al insertar un registro a la tabla. Sigue la sintaxis: `column_name data_type DEFAULT default_value` dentro de la creación de la tabla.

- __`CREATE INDEX`__: Acelera el proceso de obtención de datos al consultar la columna en cuestión. La creación del `INDEX` se coloca después de la creación de la tabla. Sigue la sintaxis:

```sql
CREATE INDEX index_name
ON table_name (column1, column2, ...);
```

### Contenido extra de SQL

#### Comentarios

Para hacer __comentarios multilínea__ se rodea este con `/* */`, de forma similar a C/C++.

En cuanto a los __comentarios de una línea__, se emplea `--` al inicio del comentario. 

#### Tipos de datos

En SQL, se pueden almacenar varios tipos de datos. A continuación se muestra un resumen de estos:

- __BIT(x)__: 1 - 64
- __TINYINT__: -128 - 127
- __SMALLINT__: -32768 - 32767
- __MEDIUMINT__: -8388608 - 8388607
- __INT__: -2147483648 - 2147483647
- __BIGINT__: -9223372036854775808 - 9223372036854775807
- __DECIMAL(x,y)__: Número decimal con un total máximo de 65 dígitos (x), de los cuales como máximo 30 pueden estar después del punto decimal (y).
- __CHAR(x)__: Caracteres de un largo fijo (máximo 8000).
- __VARCHAR(x)__: Caracteres hasta un largo (máximo 8000).
- __BINARY(x)__: Strings binarios de un tamaño fijo.
- __VARBINARY(x)__: Strings binarios hasta un tamaño establecido.
- __TINYTEXT__: Hasta 255 caracteres.
- __TEXT(x)__: Caracteres hasta un límite (máximo 65535 bytes).
- __MEDIUMTEXT__: Hasta 16777215 caracteres.
- __LONGTEXT__: Hasta 4294967295 caracteres.
- __BLOB(x)__: _Binary large object_ hasta 65535 bytes.
- __MEDIUMBLOB__: _Binary large object_ hasta 16777215 bytes.
- __LONGBLOB__: _Binary large object_ hasta 4294967295 bytes.
- __DATE__: Fecha en formato `YYYY-MM-DD`.
- __DATETIME__: Fecha y hora en formato `YYYY-MM-DD hh:mm:ss`.
- __TIME__: Hora en formato `hh:mm:ss`.
- __YEAR__: Año en formato de 4 dígitos. Rango va de 1901-2155 pues únicamente utiliza 1 byte para almacenarlos.
- __TIMESTAMP__: Franja temporal actual respecto al UTC.

#### Operadores

Entre los operadores utilizados en SQL, se encuentran los siguientes:

- __`+`__: Suma
- __`-`__: Resta
- __`*`__: Multiplicación
- __`/`__: División
- __`%`__: Residuo
- __`=`__: Igual a
- __`<`__: Menor que
- __`>`__: Mayor que
- __`<=`__: Menor o igual que
- __`>=`__: Mayor o igual que
- __`<>` o `!=`__: Distinto de

#### SQL Injection

Corresponde a un tipo de piratería donde si la búsqueda en la base de datos no está implementada correctamente, es posible ejecutar comandos SQL a partir de está y eliminar la base de datos, dar acceso a personas no deseadas, modificar credenciales, entre otros.