SELECT
    s1.id,
    s2.student
FROM 
    Seat s1
JOIN
    Seat s2
ON
    s1.id + 1 = s2.id AND s1.id % 2 = 1
UNION ALL 
(
    SELECT
        s1.id,
        s2.student
    FROM 
        Seat s1
    JOIN
        Seat s2
    ON
        s2.id = s1.id - 1 AND s1.id % 2 = 0   
) 
UNION ALL
(
    SELECT
        s1.id,
        s1.student
    FROM 
        Seat s1
    LEFT JOIN
        Seat s2
    ON
        s1.id + 1 = s2.id
    WHERE
        s1.id % 2 = 1 AND s2.id IS NULL
)
ORDER BY id ASC;

/* Much better solution */
/* Note that to find the number of rows in a table, you can use the following query: */

-- SELECT 
--     COUNT(*) 
-- FROM 
--     MyTable

SELECT
    CASE
        WHEN s.id % 2 = 1 THEN
            CASE 
                WHEN s.id = ( SELECT COUNT(*) FROM Seat) THEN s.id
                ELSE s.id + 1
            END
        ELSE s.id - 1
    END
    AS id, student
FROM 
    Seat as s
ORDER BY 
    id