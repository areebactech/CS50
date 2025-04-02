SELECT title
FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON movies.id = stars.movie_id JOIN ratings ON ratings.movie_id = movies.id
WHERE name = "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5;
