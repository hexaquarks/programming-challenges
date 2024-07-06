/* 
   Note that a self-join can be performed in
   multiple ways in SQL. Among them we can 
   use LEFT JOIN, INNER JOIN, but also by 
   creating multiple references in the FROM
   clause
*/

/* First solution */
DELETE 
    p1 
FROM 
    Person p1, Person p2
WHERE 
    p1.email = p2.email AND p1.id > p2.id


/* Second solution */
DELETE
    p1
FROM 
    Person p1
INNER JOIN
    Person p2
ON 
    p1.email = p2.email AND p1.id > p2.id

/* Third solution */
DELETE 
    p1