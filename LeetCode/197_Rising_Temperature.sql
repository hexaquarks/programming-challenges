SELECT 
    w2.id
FROM 
    Weather w1, Weather w2
WHERE 
    w2.recordDate = DATE_ADD(w1.recordDate, INTERVAL 1 DAY) AND w2.temperature > w1.temperature 


/* Alternative faster solution */
SELECT 
    w1.id
FROM 
    Weather w1, Weather w2
WHERE 
    DATEDIFF(w1.recordDate, w2.recordDate) = 1 AND w1.temperature > w2.temperature 