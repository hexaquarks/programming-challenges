SELECT
    score,
    (SELECT
        COUNT(DISTINCT score) + 1 
    FROM 
        Scores s2 
    WHERE 
        s2.score > s1.score 
    ) AS 'rank'
FROM
    Scores s1
ORDER BY
    score DESC


/* In-built solution */
SELECT 
    score,
    DENSE_RANK() OVER (ORDER_BY score DESC) AS 'rank'
FROM 
    Scores