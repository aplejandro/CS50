SELECT name FROM people
WHERE people.id IN
(SELECT DISTINCT stars.person_id FROM stars
JOIN movies ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
WHERE movies.id IN
(SELECT movies.id FROM movies 
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE name = "Kevin Bacon" AND birth = 1958) AND name != "Kevin Bacon")
ORDER by name;
