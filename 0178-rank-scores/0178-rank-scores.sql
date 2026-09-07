# Write your MySQL query statement below
Select score,Dense_Rank() OVER( order by score desc) AS 'rank'
FROM scores;